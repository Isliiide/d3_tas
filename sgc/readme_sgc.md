sgc file structure

it contains snapshots of gameControls object

NEW VERSION ==========================================
(takes more space but lossless capture)
[byte length]
- [4] tag 0xFFAFAFAF for legibility purpose
- [4] clock = number of calls to the controls handler
- [4] float pitch_thrust
- [4] float heading_thrust
- [4] float bank_thrust
- [4] float vertical_thrust
- [4] float sideways_thrust
- [4] float forward_thrust 
- [4] float afterburn_thrust
- [4] int fire_primary_down_count
- [4] float fire_primary_down_time 
- [4] int fire_secondary_down_count
- [4] float fire_secondary_down_time
- [4] int fire_flare_down_count
- [4] int rearview_down_count
- [4] several 1b booleans :
- - toggle_slide
  - toggle_bank
  - fire_primary_down_state
  - fire_secondary_down_state
  - rearview_down_state
  - 3 empty bits



OLD VERSION ==========================================
one snapshot is structured like this
[byte length]
- [2] number of the call to ReadPlayerInputs
- [1] slide
- [1] rotation
- [1] afterburner (from float to uint8_t)
- [1] firing weapons
- [1] fire1 time
- [1] fire2 time
- [1] flare/misc
- [1] useless padding
