# d3_tas

Developping TAS tools from DescentDevelopers/Descent3

As of now (commit d7515d8) (and next commit is this readme.md) : 

## Recording/Replaying control inputs (works but not good)

it's possible to press F9 to start recording inputs in game, F9 again to stop, then F10 to play back the recorded inputs
It works because F9 and F10 handling has been modified in GameLoop.cpp, and Controls.cpp got updated with functions, to rec/play inputs to/from memory, as well as to/from local files. Format used was first .txt, then a custom binary format .sgc (for shrunk game controls). These can be modified with HexEdit, or viewed with the html sgc parser provided. 

sgc files should be in the game directory, but this ends up being Appdata/Roaming/Outrage Entertainment/Descent3. The sgc file used by the game then needs to be named log_shrunk.sgc

## Playing in slowmotion/stopmotion (works nice!)

Stop motion and slow motion are also possible. ***Pressing K will toggle slow motion, base on the slomoFactor given in d3_tas_config.txt***. It works by hacking FrameTime, a value used for all physics computations of the game (normally?). Pressing J will enter step_by_step mode, so the game logic will freeze, and then pressing K will allow a single step. Press J again to escape this mode.

In order to adjust the sound sample rate to the slomo factor, so one can speed up a recording and end up with both audio and video at correct speed, it's possible to ***change the value slomoAudioFactor in d3_tas_config.txt*** (in Appdata/Roaming/Outrage Entertainment/Descent3), and write the desired ***slow motion factor inside. Normal rate is 22050 Hz with a factor of 1, 11025 for slomo x2, 5513 for slomo x4 and 2757 for slomo x8. It's necessary to restart the game for this change to take effect.***

## Diagonal control scheme (works but not good)

Pressing the key L allows to enter in "diagonal control" mode, so pressing forward is replaced by a whole trichording movement (= like pressing forward, up, and right at the same time), and side keys are modified to be banking so the control scheme stays somewhat useable.

## Demo analyser (works nice)

The demo_parser.html allows to open a .dem file and view a timeline of events happening inside. It also links to the correct game frame and hex offset in the demo file. The purpose would be to find a timestamp in the demo, and ask the game to load from there, instead of using regular save files.

## Demo hacking (wip)

((The demo reading method has been reworked, so it first makes a first pass on the demo file and gathers all newFrames indices)) ***no more***. It's then possible to freely jump at any point in the demo. The problem is that causality is altered, and if you get back in time, maybe some enemies will already be dead because they have been killed in "the future" and kill flags are still raised for the game engine. Even if we always begin at the start of the demo and then fast forward, these flags need the whole demo file to be reloaded from the main menu to disappear.

The method to seek one frame forward or backward somewhat works, but can cause the demo to abort, or the game to crash. (it's not implemented on this commit)

One feature works though : you can ***change the demoStartFrame parameter in d3_tas_config.txt (in Appdata/Roaming/Outrage Entertainment/Descent3)***, with the desired frame number, and start a demo. After a short black screen the demo will start on the wanted frame. (you can get an idea of the wanted frame through the html demo analyser)

Pressing key M in a demo playback will cancel the demo flag, and you'll be able to take control of the ship and play normally. Although this only works if you started the demo record when controls were allowed for the ship (ie: not during a cutscene)

The current velocity ***and rotational velocity of the ship are also printed in HUD messages.*** It's a way to save this info in the demo file, so when the demo is canceled, the ship is given the velocity it should have had, instead of stopping still. 

When playing a level, an automatic demo recording will trigger when the intro cutscene ends. The name of the file is "autodemo.dem". Don't forget to end the demo before the level ends, or then the next level will be loaded and this file will be overwritten. When exiting demo playback using key_m, an automatic demo will also be triggerd on the same frame, with the name "autodemo" + the gameFrame value displayed in the hud. This is meant to avoid naming collisions, but the runner should handle these files themselves.

## Afterburner hack (works great)

The afterburner hack can be toggled using U. It's made so there's no need to mash the key to gain optimal speed, it automatically mashes and stays around 90% of the gauge. This way, the acceleration is maximized, while it's still possible to make a big burst from 100% to 90%

## Keys recap

- F9 : record inputs
- F10 : replay inputs
- U : toggle afterburner hack
- J : toggle step by step mode
- K : change slomo factor (or advance one step in step by step mode)
- L : toggle diagonal controls
- M : (in demo playback) escapes the playback

## Known problems :

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
- The Descent3 open source repository issued a build where a demo opcode was faulty. Demos recorded on this version of the game are likely to bug the demo_parser.html. (Issue fixed on newer versions)
- The demo_parser.html is still subject to change, and is famously missing a couple of rare opcodes, so other demo files might also make it bug
- Especially, demo_parser hasn't been tested in multiplayer, and hasn't been tested on fan-made levels.
- ship paralyzed if demo started recording during a cutscene, investigate why
- the autodemo features triggers on the end of the first cutscene, but in fact this doesn't work if the "first cutscene" is not the intro cutscene (in a demo started mid level for example), or if the intro cutscene has several camera shots (like lv10, lv13...)
- crashes/aborts on +1/-1 demo frames (this feature is disabled on this build)
- causality problems when jumping around in a demo playback
- ***using demoStartFrame hack can mess with the physics of events before the said frame (like the progression of projectiles in space)***

