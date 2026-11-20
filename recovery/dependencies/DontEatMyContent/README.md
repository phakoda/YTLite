# Don’t Eat My Content integration

Safe-area fullscreen video protection is adapted from
https://github.com/therealFoxster/DontEatMyContent, by Foxster, under the MIT license.
The source and license were retrieved on 2026-11-20. The upstream source is
available at https://github.com/therealFoxster/DontEatMyContent/blob/master/Tweak.x.

The integration lives in `recovery/source/Hooks/ContentLayout.x`. It uses each
player’s state and the window’s safe area, leaves intentional zoom alone, and
releases protection while a landscape engagement panel is shown. Controls live
under Player in the YouTube Plus settings and share its preference suite.
No second dylib or preference bundle is required.
