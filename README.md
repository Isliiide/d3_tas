# d3_tas
developping TAS tools from DescentDevelopers/Descent3

As of now (commit 53fb079) (and next commit is this readme.md), 
it's possible to press F9 to start recording inputs in game, F9 again to stop, then F10 to play back the recorded inputs
It works because F9 and F10 handling has been modified in GameLoop.cpp, and Controls.cpp got updated with functions, to rec/play inputs to/from memory, as well as to/from local files. Format used was first .txt, then a custom binary format .sgc (for shrunk game controls). These can be modified with HexEdit.

known problems :

- the playback of inputs is tied to the ReadPlayerControls loop, which isn't in sync with the game engine itself. Hence playing back inputs will quickly desync with the game, and the mere fact of leaving the first lv1 room gets complicated.
- robots don't reliably act the same upon playing back / restarting level
- more desync problems can be due to robot collision
- the .sgc format attempts to store a gameControls object in the shortest possible form, hence using narrowing conversions from float (32b) to u8int_t. The loss in precision could also produce desync problems (like the afterburner thrust being weaker)
- recording inputs only records pressed keys tied to player actions. That means no menuing keys (for now) and no mouse/joypad movements (for now)
- the function RenderHUDText has no visible effect in game, investigate.
- the case of recording and playing back at the same time was not handle (it writes/reads the same .sgc file)
- convenient editing of .sgc file should be made possible (in game? html editor?)
- ((trying to play the game frame by frame reveals that GameLoop only deals with rendering, and even if it is suspended the game engine continues normally)) suspicion

sgc files should be in the game directory, but this ends up being Appdata/Roaming/Outrage Entertainment/Descent3. The sgc file used by the game then needs to be named log_shrunk.sgc
