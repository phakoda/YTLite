"""Compare complete optimized factory bodies with original data-flow events."""
import re


def verify_factory_llvm(text,method,contract):
    selector=method['selector']
    definition=next(l for l in text.splitlines() if l.startswith('define internal ') and '+[DVNCell '+selector+']' in l)
    body=text[text.index(definition):].split('\n}',1)[0].splitlines()[1:];lines=[]
    for line in body:
        line=line.strip().split(', !')[0]
        line=re.sub(r' #\d+','',line);line=re.sub(r'\b(?:noundef|nonnull) ','',line)
        if line:lines.append(line)
    expected=[];temporary=len(contract['arguments'])+3;constructed=None
    def argument(value):
        if value[0]=='constant':return f'i64 {value[1]}'
        assert value[0]=='argument';typ='double' if value[2]=='d' else 'i64' if value[2]=='q' else 'ptr'
        return f'{typ} %{value[1]}'
    forwarding=contract['events'][0][0]=='forward'
    if not forwarding:
        reference='@"OBJC_CLASSLIST_REFERENCES_$_.1"'
        assert re.search(re.escape(reference)+r' = .*ptr @"OBJC_CLASS_\$_DVNCell"',text)
        expected.append(f'%{temporary} = load ptr, ptr {reference}, align 8');class_value=temporary;temporary+=1
    for event in contract['events']:
        op=event[0]
        if op=='retain':
            expected.append(f'%{temporary} = tail call ptr @llvm.objc.retain({argument(event[1])})');temporary+=1
        elif op=='release':expected.append(f'tail call void @llvm.objc.release({argument(event[1])})')
        elif op=='construct':
            assert event[1]=='DVNCell';constructed=temporary
            expected.append(f'%{temporary} = tail call ptr @objc_alloc_init(ptr %{class_value})');temporary+=1
        elif op=='set':
            assert constructed is not None
            expected.append(f'tail call void @"objc_msgSend${event[1]}"(ptr %{constructed}, ptr undef, {argument(event[2])})')
        elif op=='return':
            assert constructed is not None and event[1][0]=='constructed'
            expected.extend([f'%{temporary} = tail call ptr @llvm.objc.autoreleaseReturnValue(ptr %{constructed})',f'ret ptr %{constructed}']);temporary+=1
        elif op=='forward':
            args=', '.join(argument(v) for v in event[2])
            expected.extend([f'%{temporary} = tail call ptr @"objc_msgSend${event[1]}"(ptr %0, ptr undef, {args})',f'ret ptr %{temporary}']);temporary+=1
        else:raise AssertionError(op)
    assert lines==expected,(selector,lines,expected)
    return lines
