# d3_tas
developping TAS tools from DescentDevelopers/Descent3

As of now (commit e9f08ad) (and next commit is this readme.md), 
it's possible to press F9 to start recording inputs in game, F9 again to stop, then F10 to play back the recorded inputs
It works because F9 and F10 handling has been modified in GameLoop.cpp, and Controls.cpp got updated with functions, to rec/play inputs to/from memory, as well as to/from local files. Format used was first .txt, then a custom binary format .sgc (for shrunk game controls). These can be modified with HexEdit, or viewed with the html sgc parser provided.

Stop motion and slow motion are also possible. Pressing K will cycle through normal speed, speed/2, speed/4 and speed/8. It works by hacking FrameTime, a value used for all physics computations of the game (normally?). Pressing J will enter step_by_step mode, so the game logic will freeze, and then pressing K will allow a single step. Press J again to escape this mode.

sgc files should be in the game directory, but this ends up being Appdata/Roaming/Outrage Entertainment/Descent3. The sgc file used by the game then needs to be named log_shrunk.sgc

In order to adjust the sound sample rate to the slomo factor, so one can speed up a recording and end up with both audio and video at correct speed, it's possible to create a file named hackAudioSampleRate.txt (in Appdata/Roaming/Outrage Entertainment/Descent3), and write the desired rate inside. Normal rate is 22050, 11025 for slomo x2, 5513 for slomo x4 and 2757 for slomo x8. It necessary to restart the game for this change to take effect.

Pressing the key L allows to enter in "diagonal control" mode, so pressing forward is replaced by a whole trichording movement (= like pressing forward, up, and right at the same time), and side keys are modified to be banking so the control scheme stays somewhat useable.

known problems :

- the playback of inputs is still subject to desync issues, and the mere fact of leaving the first lv1 room gets complicated.
- robots don't reliably act the same upon playing back / restarting level
- more desync problems can be due to robot collision
- recording inputs only records pressed keys tied to player actions. That means no menuing keys (for now) and no mouse/joypad movements (for now)
- ((the function RenderHUDText has no visible effect in game, investigate))
- the case of recording and playing back at the same time was not handle (it writes/reads the same .sgc file)
- convenient editing of .sgc file should be made possible (in game? html editor?)
- ((trying to play the game frame by frame reveals that GameLoop only deals with rendering, and even if it is suspended the game engine continues normally)) suspicion -> now the rendering part / physics part has been figured out
- ((RTP stands for real time profiling, and is just a measure for debug purpose, it doesn't affect gameplay))
- ((trying to modify the hlsSystem and llsSystem to update samplerate dynamically lead to a crash, bad prototype for the moment))


