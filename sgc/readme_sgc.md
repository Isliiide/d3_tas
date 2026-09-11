sgc file structure

it contains snapshots of gameControls object

one snapshot is structured like this
- [byte length]
- [2] number of the call to ReadPlayerInputs
- [1] slide
- [1] rotation
- [1] afterburner (from float to uint8_t)
- [1] firing weapons
- [1] fire1 time
- [1] fire2 time
- [1] flare/misc
- [1] useless padding
