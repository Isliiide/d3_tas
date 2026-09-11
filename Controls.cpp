/*
* Descent 3 
* Copyright (C) 2024 Parallax Software
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.

--- HISTORICAL COMMENTS FOLLOW ---

 * $Logfile: /DescentIII/main/Controls.cpp $
 * $Revision: 106 $
 * $Date: 4/19/00 5:28p $
 * $Author: Matt $
 *
 * Game controls processor
 *
 * $Log: /DescentIII/main/Controls.cpp $
 *
 * 106   4/19/00 5:28p Matt
 * From Duane for 1.4
 * Changed "ifdef Mac" to "ifndef Mac"
 *
 * 105   3/20/00 12:03p Matt
 * Merge of Duane's post-1.3 changes.
 * Misc Mac controller stuff (Mac only)
 *
 * 104   1/25/00 12:11a Jason
 * Fixed keyboard ramping that got commented out during a mac merge.
 *
 * 103   10/22/99 1:16p Matt
 * Fixed bug from previous integration.
 *
 * 102   10/22/99 1:12p Matt
 * Mac merge
 *
 * 101   10/22/99 12:50p Matt
 * Restored whitespace removed in version 99, and changed the controller
 * table to its version 1.0 state.  (This actually removes all the changes
 * made for version 99.)
 *
 * 100   8/11/99 6:06p Samir
 * mouse invert toggle slide functional.
 *
 * 99    7/28/99 4:20p Kevin
 * Mac
 *
 * 98    7/20/99 4:53p Samir
 * added ability to manually set the deadzone for a controller.
 *
 * 97    7/16/99 11:16a Samir
 * fixed afterburner thrust clipping bug.
 *
 * 96    5/10/99 9:25p Jeff
 * first phase of Rock 'n' Ride support added
 *
 * 95    4/30/99 10:52p Samir
 * fixed energy-to-shield usage and made Load and Save COnfig take a
 * pilot.
 *
 * 94    4/24/99 6:44p Jeff
 * added functions for theif so he can steal things other than weapons
 *
 * 93    4/14/99 2:50a Jeff
 * fixed some case mismatched #includes
 *
 * 92    4/01/99 11:27a Samir
 * added default mouse button bindings.
 *
 * 91    3/25/99 9:57a Kevin
 * Fixed the way toggle slide works
 *
 * 90    3/22/99 6:20p Jeff
 * added 2 more audio taunts.  a mulitplayer event when someone plays an
 * audio taunt.  option to disable audio taunts.
 *
 * 89    3/05/99 5:23p Samir
 * joystick button audio taunt control fixed.
 *
 * 88    3/05/99 2:44p Samir
 * needs to be cleaned up later, but mouse and joystick sensitivities are
 * read in always, and set by the controller system.   A cancel method
 * needs to be implemented for these functions.
 *
 * 87    3/04/99 8:07p Samir
 * pre assignment of r axis enabled once again.
 *
 * 86    3/01/99 12:19a Samir
 * mask controller states on create controller.
 *
 * 85    2/26/99 2:13a Samir
 * added audio taunt keys.
 *
 * 84    2/23/99 7:33p Samir
 * don't configure bank through joystick by default.
 *
 * 83    2/23/99 2:00p Samir
 * added keyboard ramping slider.
 *
 * 82    2/15/99 7:48p Jeff
 * new pilot file class and read/write system checked in...should be more
 * robust than old
 *
 * 81    2/09/99 1:28a Jeff
 * added code to let D3 process multiplayer games in the background if
 * game is not in focus.
 *
 * 80    2/06/99 6:58p Jeff
 * removed mprintf for suspend/resume (annoying in automap)
 *
 * 79    2/04/99 4:22p Jeff
 * put in sanity mprintf's in suspend/resume controls
 *
 * 78    1/31/99 7:25p Matt
 * Renamed a bunch of functions to have HUD capitalized
 *
 * 77    1/28/99 3:58p Jeff
 * localization update
 *
 * 76    1/06/99 6:45p Kevin
 *
 * 75    12/14/98 11:06a Jason
 * changes for 1.1
 *
 * 74    12/08/98 10:27a Samir
 * default player controls include mouse controls.
 *
 * 73    12/07/98 5:37p Jason
 * first pass at automap
 *
 * 72    12/03/98 11:06a Samir
 * added axis sensitivity
 *
 * 71    12/02/98 7:02p Samir
 * reduces key pitch and heading ramp times.
 *
 * 70    12/02/98 12:23p Samir
 * fixed behavior of bank and slide toggles so they are read before both
 * keyboard and joystick.
 *
 * 69    12/02/98 11:37a Samir
 * improved ramping of keyboard.
 *
 * 68    11/30/98 4:56p Samir
 * oops. took out mprintf.
 *
 * 67    11/30/98 4:54p Samir
 * added rear view config item.
 *
 * 66    11/30/98 1:09p Samir
 * added rear view toggle.
 *
 * 65    10/24/98 2:16p Samir
 * moved pollcontrols to controls.cpp, readplayercontrols.
 *
 * 64    10/22/98 4:11p Samir
 * put inventory keys back in.
 *
 * 63    10/22/98 2:40p Samir
 * took out inventory keys for demo.
 *
 * 62    10/21/98 11:55p Samir
 * added sensitivity slider functionality.
 *
 * 61    10/21/98 7:03p Samir
 * D2 Default controls
 *
 * 60    10/21/98 10:36a Samir
 * added code to turn on or off joystick or mouse.
 *
 * 59    10/18/98 7:24p Samir
 * cycle down weapons, use Frametime for controller buttons.
 *
 * 58    10/17/98 7:32p Samir
 * added to controller needs, the extra flags section per function.
 *
 * 57    10/14/98 1:02p Jason
 * fixed FindSoundName issues
 *
 * 56    10/12/98 5:12p Samir
 * toggle bank key works.
 *
 * 55    10/11/98 2:58a Jeff
 * hooked in Automap key
 *
 * 54    10/08/98 6:43p Samir
 * took out mprintf.
 *
 * 53    10/08/98 1:24p Samir
 * use ramping technique for keyboard pitch and heading.
 *
 * 52    10/08/98 10:52a Samir
 * added countermeasure and weapon cycling.
 *
 * 51    9/28/98 10:07a Jason
 * fixed MISC keyboard input while inputting messages
 *
 * 50    9/21/98 3:21p Jason
 * bound headlight to a key
 *
 * 49    9/17/98 3:24p Samir
 * added headlight configuration.
 *
 * 48    9/01/98 5:11p Samir
 * no additvie afterburner control.
 *
 * 47    8/31/98 6:49p Jeff
 * made inventory and countermeasure keys customizable
 *
 * 46    8/31/98 12:39p Samir
 * added code to resume controllers when restoring game mode.
 *
 * 45    8/15/98 2:45p Matt
 * Took out unneeded include
 *
 * 44    6/29/98 7:17p Samir
 * took out annoying mprintf
 *
 * 43    6/29/98 6:42p Samir
 * Properly handle controller pausing and resumption.
 *
 * 42    6/18/98 4:44p Samir
 * added changes for multiple configs for joystick controls.
 *
 * 41    6/16/98 10:38a Jeff
 * localization, strings pulled out to stringtable.h and d3.str
 *
 * 40    5/28/98 1:08p Samir
 * flipped bank button calcs.
 *
 * 39    5/26/98 7:09p Samir
 * pitch now 75% of maximum instead of 50% as asked by Chris and Craig.
 *
 * 38    5/19/98 3:36p Samir
 * added automap key.
 *
 * 37    5/12/98 3:04p Samir
 * added button control for pbh.
 *
 * 36    5/12/98 10:38a Samir
 * pitch rate halved.
 *
 * 35    5/11/98 4:53p Samir
 * added axis sliding, config.
 *
 * 34    5/01/98 3:52p Samir
 * fixed up hat and keyboard sliding.
 *
 * 33    4/30/98 7:00p Samir
 * reset afterburner thrust every frame.
 *
 * 32    4/28/98 11:45a Samir
 * make keyboard controls match to framerate.
 *
 * 31    4/27/98 7:24p Samir
 * poll controller at specified rate.
 *
 * 30    4/09/98 2:22p Jason
 * added guided/afterburner stuff
 *
 * 29    4/08/98 3:44p Samir
 * added toggle bank and configuration for afterburner
 *
 * 28    4/02/98 7:58p Samir
 * Fixed up control setting saving and restoring.
 *
 * 27    3/24/98 11:21a Samir
 * adjusted key sensitivity.
 *
 * 26    3/20/98 1:19p Jeff
 * Changes made to use Default_pilot string for pilot filename to use.
 *
 * 25    3/16/98 3:53p Jason
 * added hud input message stuff
 *
 * 24    3/16/98 3:26p Samir
 * Fixed controller need ID and index discrepancy.
 *
 * 23    3/16/98 11:03a Luke
 * Don't reset controls again.,
 *
 * 22    3/13/98 8:55p Jeff
 * Various changes to move control configuration into Pilot file
 *
 * 21    3/10/98 5:21p Samir
 * banking should be proper.
 *
 * 20    3/02/98 5:54p Samir
 * Don't run any controls if not in game interface mode.
 *
 * 19    2/16/98 9:27p Samir
 * Added banking.
 *
 * 18    2/16/98 3:01p Samir
 * Added fire_primary_down_state and changed some configuration.
 *
 * 17    2/15/98 7:06p Samir
 * Added functions to save controller state.
 *
 * 16    2/12/98 8:48p Matt
 * Changed controls system to keep the reading of the controls separate
 * from using the results.  Got rid of the Controls global.
 *
 * 15    1/23/98 6:25p Jason
 * Got spray weapons working
 *
 * 14    1/12/98 6:28p Samir
 * New keys for sliding and use RCTRL for firing too.
 *
 * 13    12/10/97 12:18p Samir
 * Tooke oute annoiing printe Fs.
 *
 * 12    12/10/97 11:16a Samir
 * Joystick button timing should be fixed.
 *
 * 11    12/05/97 12:49p Samir
 * Much better hat sliding.
 *
 * 10    12/05/97 10:59a Samir
 * Somewhat revised controls for keyboard.   Joystick now has variable
 * sensitivity.
 *
 * 9     12/03/97 7:32p Samir
 * More D2 like keyboard movement.
 *
 * 8     11/12/97 1:13p Jason
 * added weapons that can ramp up
 *
 * 7     11/05/97 3:45p Samir
 * InitControls will close the previous call to InitControls.
 *
 * 6     11/04/97 4:20p Samir
 * replaced ctDigital with ctDownCount in some joystick button functions.
 *
 * 5     10/30/97 4:02p Matt
 * Added the flare
 *
 * 4     9/04/97 4:01p Samir
 * This should fix slide toggling with joystick.
 *
 * 3     8/29/97 1:49p Samir
 * Added toggling slide.
 *
 * 2     8/20/97 5:03p Samir
 * Fixed banking controls.
 *
 * 24    5/21/97 3:53p Samir
 * changed ct_need to ct_function.
 *
 * 23    5/12/97 1:22p Samir
 * Don't use timer hook functions anymore.  taken care of in controller
 * library.
 *
 * 22    4/24/97 2:09p Samir
 * Fixed firing key problems.
 *
 * 21    4/24/97 12:32p Samir
 * Fixed booboo in controls structure.
 *
 * 20    4/24/97 12:10p Samir
 * Added weapon firing for primary and secondary weapons.
 *
 * 19    4/23/97 1:06p Samir
 * Implemented Suspend and Resume Controls as well as newer control system
 *
 * 18    4/17/97 2:48p Samir
 * ReadFlyingControls renamed from read_flying_controls to match naming
 * convention rules.
 *
 * 17    4/16/97 3:28p Samir
 * Poll twice for better keeping track of buttons.  Should find a lot
 * better way of doing this.
 *
 * 16    4/16/97 1:03p Samir
 * Added fire primary button information
 *
 * 15    4/14/97 3:29p Samir
 * Implemented game controls structure.
 *
 * 14    4/14/97 12:55p Samir
 * Added primary fire button
 *
 * 13    4/11/97 5:11p Samir
 * Added external controller throttle control.
 *
 * 12    4/11/97 4:54p Samir
 * Fixed joystick pitch translation (invert for real flight stick control)
 *
 * 11    4/11/97 4:09 PM Jeremy
 * changed include of "stdlib.h" to <stdlib.h>
 *
 * 10    4/11/97 2:14p Samir
 * Revamped input of controller data.
 *
 * $NoKeywords: $
 */

#include <cstdlib>
#include <fstream> //islide
#include <vector> //islide

#include "controls.h"

#include "object.h"
#include "pserror.h"
#include "game.h"
#include "ddio.h"
#include "joystick.h"
#include "descent.h"
#include "log.h"
#include "weapon.h"
#include "controller.h"
#include "gamesequence.h"
#include "pilot.h"
#include "hud.h"
#include "stringtable.h"
#include "multi.h"
#include "args.h"
#include "player.h"
#include "hlsoundlib.h"
#include "sounds.h"


float Key_ramp_speed = 0.5f;

#define CONTROL_POLL_RATE (1.0f / 25.0f)
#define KEY_RAMPUP_TIME Key_ramp_speed
#define POV_SENSITIVITY 1.3f
#define LIMIT_PITCH 0.75f
#define LIMIT_HEADING 1.0f
#define LIMIT_BANK 1.0f
#define LIMIT_HORIZ 1.0f
#define LIMIT_VERT 1.0f
#define LIMIT_FORWARD 1.0f

struct tSensitivity {
  float p, b, h, x, y, z;
  float op, ob, oh, ox, oy, oz;
};

//	GLOBALS

gameController *Controller = NULL;
bool Control_poll_flag = false; // determines if system is polling controls now.

static bool Control_system_init = false;
static float Control_interval_time = 0.0f;
static float Control_current_time;
// static float Control_frametime;


//--------------------------------------------------------------------------------------
static int counting_calls = 0; //islide
std::vector<game_controls*> vec_gc; //islide
std::vector<shrunk_gc*> vec_sgc; //islide

void fill_vec_gc(std::vector<game_controls*> *vec_gc) {

  game_controls *gc0 = new game_controls;
  game_controls *gc1 = new game_controls;

  gc1->forward_thrust = 1;

  // warning : don't use the same pointer several times in the array (sigsev at deletion)
  //vec_gc->push_back(gc0);
  //vec_gc->push_back(gc0);
  //vec_gc->push_back(gc0);
  vec_gc->push_back(gc0);
  vec_gc->push_back(gc1);

  return;
}

void delete_vec_gc(std::vector<game_controls *> *vec_gc) {


  for (std::vector<game_controls *>::iterator i = vec_gc->begin(); i != vec_gc->end(); ++i) {

    delete *i; // warning : don't use the same pointer several times in the array
  }

  vec_gc->clear();
  //delete vec_gc; // tied to global scope

  return;
}

void fill_vec_sgc(std::vector<shrunk_gc *> *vec_sgc) {

  shrunk_gc *sgc0 = new shrunk_gc;
  shrunk_gc *sgc1 = new shrunk_gc;
  shrunk_gc *sgc2 = new shrunk_gc;
  shrunk_gc *sgc3 = new shrunk_gc;
  shrunk_gc *sgc4 = new shrunk_gc;
  shrunk_gc *sgc5 = new shrunk_gc;
  shrunk_gc *sgc6 = new shrunk_gc;
  shrunk_gc *sgc7 = new shrunk_gc;
  shrunk_gc *sgc8 = new shrunk_gc;
  shrunk_gc *sgc9 = new shrunk_gc;
  shrunk_gc *sgc10 = new shrunk_gc;
  shrunk_gc *sgc11 = new shrunk_gc;
  shrunk_gc *sgc12 = new shrunk_gc;
  shrunk_gc *sgc13 = new shrunk_gc;
  shrunk_gc *sgc14 = new shrunk_gc;
  shrunk_gc *sgc15 = new shrunk_gc;
  shrunk_gc *sgc16 = new shrunk_gc;
  shrunk_gc *sgc17 = new shrunk_gc;
  shrunk_gc *sgc18 = new shrunk_gc;
  shrunk_gc *sgc19 = new shrunk_gc;
  shrunk_gc *sgc20 = new shrunk_gc;

  sgc1->xyz = 0b01000000; // +x means sliding right
  sgc2->xyz = 0b00010000; // +y means sliding up
  sgc3->xyz = 0b00000100; // +z means sliding fwd
  sgc4->xyz = 0b10000000; // -x 
  sgc5->xyz = 0b00100000; // -y 
  sgc6->xyz = 0b00001000; // -z 

  sgc7->xyz_rot =  0b01000000;
  sgc8->xyz_rot =  0b00010000;
  sgc9->xyz_rot =  0b00000100;
  sgc10->xyz_rot = 0b10000000;
  sgc11->xyz_rot = 0b00100000;
  sgc12->xyz_rot = 0b00001000;

  sgc13->ab = 0b00111111; //max positive thrust * 1/4, should be around 0.25

  sgc14->atk = 0b10000000; //1_laser
  sgc15->atk = 0b01000000; //2_missile
  sgc16->atk = 0b00100000; //?
  sgc17->atk = 0b00010000; //?
  sgc18->atk1f = 0b00111111; //time1
  sgc19->atk2f = 0b00111111; //time2

  sgc20->misc = 0b10000000; //flare

  // warning : don't use the same pointer several times in the array (sigsev at deletion)
  vec_sgc->push_back(sgc0);
  vec_sgc->push_back(sgc1);
  vec_sgc->push_back(sgc2);
  vec_sgc->push_back(sgc3);
  vec_sgc->push_back(sgc4);
  vec_sgc->push_back(sgc5);
  vec_sgc->push_back(sgc6);
  vec_sgc->push_back(sgc7);
  vec_sgc->push_back(sgc8);
  vec_sgc->push_back(sgc9);
  vec_sgc->push_back(sgc10);
  vec_sgc->push_back(sgc11);
  vec_sgc->push_back(sgc12);
  vec_sgc->push_back(sgc13);
  vec_sgc->push_back(sgc14);
  vec_sgc->push_back(sgc15);
  vec_sgc->push_back(sgc16);
  vec_sgc->push_back(sgc17);
  vec_sgc->push_back(sgc18);
  vec_sgc->push_back(sgc19);
  vec_sgc->push_back(sgc20);


  return;
}

void delete_vec_sgc(std::vector<shrunk_gc *> *vec_sgc) {

  for (std::vector<shrunk_gc *>::iterator i = vec_sgc->begin(); i != vec_sgc->end(); ++i) {

    delete *i; // warning : don't use the same pointer several times in the array
  }

  vec_sgc->clear();
  // delete vec_gc; // tied to global scope

  return;
}

void shrink_gc(shrunk_gc* sgc_dest, game_controls *gc_src) {

  uint8_t buffer;

  // xx yy zz __      with +z being fwd
  // 00 -> 0
  // 10 -> -1
  // 01 -> +1
  sgc_dest->xyz += ((gc_src->sideways_thrust < 0) << 7);
  sgc_dest->xyz += ((gc_src->sideways_thrust > 0) << 6);
  sgc_dest->xyz += ((gc_src->vertical_thrust < 0) << 5);
  sgc_dest->xyz += ((gc_src->vertical_thrust > 0) << 4);
  sgc_dest->xyz += ((gc_src->forward_thrust < 0) << 3);
  sgc_dest->xyz += ((gc_src->forward_thrust > 0) << 2);

  //rot
  sgc_dest->xyz_rot += ((gc_src->bank_thrust < 0) << 7);
  sgc_dest->xyz_rot += ((gc_src->bank_thrust > 0) << 6);
  sgc_dest->xyz_rot += ((gc_src->heading_thrust < 0) << 5);
  sgc_dest->xyz_rot += ((gc_src->heading_thrust > 0) << 4);
  sgc_dest->xyz_rot += ((gc_src->pitch_thrust < 0) << 3);
  sgc_dest->xyz_rot += ((gc_src->pitch_thrust > 0) << 2);
  
  // float to uint8_t sortof, TODO ensure precision degration causes no problem
  // afterburner can't be negative btw
  // 1.00 goes to 128.00 then 127.00, then 127 and then 0b01111111
  // 0.01 goes to   1.18 then   0.18, then   0 and then 0b00000000 
  if (gc_src->afterburn_thrust > 0.004) {
    //sgc_dest->ab += (int)((gc_src->afterburn_thrust * 128 - 1)); 
    sgc_dest->ab += (int)((gc_src->afterburn_thrust * 256 - 1)); 

  } else {
    //sgc_dest->ab = 0x80; // sign bit
    //sgc_dest->ab += (int)((gc_src->afterburn_thrust * (-128) - 1));
  }
  
  // atk
  sgc_dest->atk += (gc_src->fire_primary_down_count << 7);
  sgc_dest->atk += (gc_src->fire_secondary_down_count << 6);
  sgc_dest->atk += (gc_src->fire_primary_down_state << 5);
  sgc_dest->atk += (gc_src->fire_secondary_down_state << 4);

  if (gc_src->fire_primary_down_time > 0.004) {
    sgc_dest->atk1f += (int)((gc_src->fire_primary_down_time * 256 - 1));
  } 
  if (gc_src->fire_secondary_down_time > 0.004) {
    sgc_dest->atk2f += (int)((gc_src->fire_secondary_down_time * 256 - 1));
  } 

  // misc
  sgc_dest->misc += (gc_src->fire_flare_down_count << 7);

  return;
}

void unshrink_gc(game_controls *gc_dest, shrunk_gc *sgc_src) {

  memset(gc_dest, 0, sizeof(game_controls));


  // xx yy zz __      with +z being fwd
  // 00 -> 0
  // 10 -> -1
  // 01 -> +1
  uint8_t xyz = sgc_src->xyz;
  if (((xyz >> 7) & 0x01) == 1) {
    gc_dest->sideways_thrust = -1;
  }
  if (((xyz >> 6) & 0x01) == 1) {
    gc_dest->sideways_thrust = 1;
  }
  if (((xyz >> 5) & 0x01) == 1) {
    gc_dest->vertical_thrust = -1;
  }
  if (((xyz >> 4) & 0x01) == 1) {
    gc_dest->vertical_thrust = 1;
  }
  if (((xyz >> 3) & 0x01) == 1) {
    gc_dest->forward_thrust = -1;
  }
  if (((xyz >> 2) & 0x01) == 1) {
    gc_dest->forward_thrust = 1;
  }

  // rot
  uint8_t xyz_rot = sgc_src->xyz_rot;
  if (((xyz_rot >> 7) & 0x01) == 1) {
    gc_dest->bank_thrust = -1;
  }
  if (((xyz_rot >> 6) & 0x01) == 1) {
    gc_dest->bank_thrust = 1;
  }
  if (((xyz_rot >> 5) & 0x01) == 1) {
    gc_dest->heading_thrust = -1;
  }
  if (((xyz_rot >> 4) & 0x01) == 1) {
    gc_dest->heading_thrust = 1;
  }
  if (((xyz_rot >> 3) & 0x01) == 1) {
    gc_dest->pitch_thrust = -1;
  }
  if (((xyz_rot >> 2) & 0x01) == 1) {
    gc_dest->pitch_thrust = 1;
  }

  //afterburner
  uint8_t ab = sgc_src->ab;
  float ab_f = ab; // (ab & 0x7F); //not need, no sign bit
  if (ab_f == 0) {

    gc_dest->afterburn_thrust = 0;

  } else {

    ab_f = (ab_f + 1) / 256;
   // if (((ab >> 7) & 0x01) == 1) {
   //   ab_f = ab_f * (-1);
   // }
    gc_dest->afterburn_thrust = ab_f; 
  }
 
 //atk
  uint8_t atk = sgc_src->atk;
  gc_dest->fire_primary_down_count = (atk >> 7) & 0x01;
  gc_dest->fire_secondary_down_count = (atk >> 6) & 0x01;
  gc_dest->fire_primary_down_state = (atk >> 5) & 0x01;
  gc_dest->fire_secondary_down_state = (atk >> 4) & 0x01;

  float atk1f = (sgc_src->atk1f & 0x7F);
  if (atk1f == 0) {

    gc_dest->fire_primary_down_time = 0;

  } else {
    gc_dest->fire_primary_down_time = (atk1f + 1) / 256;
  }

   float atk2f = (sgc_src->atk2f & 0x7F);
  if (atk2f == 0) {

    gc_dest->fire_secondary_down_time = 0;

  } else {
    gc_dest->fire_secondary_down_time = (atk2f + 1) / 256;
  }
  
  //misc
  gc_dest->fire_flare_down_count = (sgc_src->misc >> 7) & 0x01; //flare

  return;
}
      /*

clk	[8]

x	[2]  -1 0 +1
y	[2]
z	[2]
x_rot	[2]
y_rot	[2]
z_rot	[2]
  =[16]
ab	[16]	float

atk1	[2]
atk2	[2]
  [2]
  [2]
  =[16]
  [16]	float
  [16]	float

flare	[1]
cy1	[1]
cy2	[1]
cy_item	[1]
use_item[1]

load	[1]
save	[1]
demo	[1]
  =[8]

=[88] ~ [96] 12oc

*/

std::ofstream inputs_rec_to;
bool b_record_inputs = false;
bool b_record_inputs_old = false;
void toggle_record_inputs() { 

  b_record_inputs = !b_record_inputs;
}

std::ifstream inputs_feed_from;
bool b_feed_inputs = false;
bool b_feed_inputs_old = false;
void toggle_feed_inputs() { 

  b_feed_inputs = !b_feed_inputs;
}


//----------------------------------------------------------------

static tSensitivity Key_ramp;

//	PROTOTYPES

static void DoKeyboardMovement(game_controls *controls);
static void DoControllerMovement(game_controls *controls);
static void DoWeapons(game_controls *controls);
static void DoKeyboardWeapons(game_controls *controls);
static void DoControllerWeapons(game_controls *controls);
static void DoMisc(game_controls *contols);
static void DoKeyboardMisc(game_controls *controls);
static void DoControllerMisc(game_controls *controls);
// MTS: no implementation!
void DoCommands();

static void ToggleHeadlightControlState();

//	LIST OF NEEDS
ct_function Controller_needs[NUM_CONTROLLER_FUNCTIONS] = {
    {ctfFORWARD_THRUSTAXIS, ctAnalog, ctAxis, ctAxis, 0, 0, 0, 0},
    {ctfFORWARD_THRUSTKEY, ctTime, ctKey, ctKey, KEY_A, 0, 0, 0},
    {ctfREVERSE_THRUSTKEY, ctTime, ctKey, ctKey, KEY_Z, 0, 0, 0},
    {ctfFORWARD_BUTTON, ctTime, ctButton, ctButton, 0, 0, 0, 0},
    {ctfREVERSE_BUTTON, ctTime, ctButton, ctButton, 0, 0, 0, 0},
    {ctfUP_THRUSTAXIS, ctAnalog, ctAxis, ctAxis, CT_V_AXIS, 0, 0, 0},
    {ctfUP_BUTTON, ctDigital, ctPOV, ctButton, JOYPOV_UP, 0, 0, 0},
    {ctfUP_THRUSTKEY, ctTime, ctKey, ctKey, KEY_PADMINUS, 0, 0, 0},
    {ctfDOWN_BUTTON, ctDigital, ctPOV, ctButton, JOYPOV_DOWN, 0, 0, 0},
    {ctfDOWN_THRUSTKEY, ctTime, ctKey, ctKey, KEY_PADPLUS, 0, 0, 0},
    {ctfRIGHT_THRUSTAXIS, ctAnalog, ctAxis, ctAxis, CT_U_AXIS, 0, 0, 0},
    {ctfRIGHT_BUTTON, ctDigital, ctPOV, ctButton, JOYPOV_RIGHT, 0, 0, 0},
    {ctfRIGHT_THRUSTKEY, ctTime, ctKey, ctKey, KEY_PAD3, 0, 0, 0},
    {ctfLEFT_BUTTON, ctDigital, ctPOV, ctButton, JOYPOV_LEFT, 0, 0, 0},
    {ctfLEFT_THRUSTKEY, ctTime, ctKey, ctKey, KEY_PAD1, 0, 0, 0},
    {ctfPITCH_DOWNAXIS, ctAnalog, ctAxis, ctMouseAxis, CT_Y_AXIS, CT_Y_AXIS, 0, 0},
    {ctfPITCH_DOWNKEY, ctTime, ctKey, ctKey, KEY_UP, KEY_PAD8, 0, 0},
    {ctfPITCH_DOWNBUTTON, ctDigital, ctButton, ctButton, 0, 0, 0, 0},
    {ctfPITCH_UPKEY, ctTime, ctKey, ctKey, KEY_DOWN, KEY_PAD2, 0, 0},
    {ctfPITCH_UPBUTTON, ctDigital, ctButton, ctButton, 0, 0, 0, 0},
    {ctfBANK_RIGHTAXIS, ctAnalog, ctAxis, ctAxis, CT_R_AXIS, 0, 0, 0},
    {ctfBANK_RIGHTKEY, ctTime, ctKey, ctKey, KEY_E, KEY_PAD9, 0, 0},
    {ctfBANK_RIGHTBUTTON, ctDigital, ctButton, ctButton, 0, 0, 0, 0},
    {ctfBANK_LEFTKEY, ctTime, ctKey, ctKey, KEY_Q, KEY_PAD7, 0, 0},
    {ctfBANK_LEFTBUTTON, ctDigital, ctButton, ctButton, 0, 0, 0, 0},
    {ctfHEADING_RIGHTAXIS, ctAnalog, ctAxis, ctMouseAxis, CT_X_AXIS, CT_X_AXIS, 0, 0},
    {ctfHEADING_RIGHTKEY, ctTime, ctKey, ctKey, KEY_RIGHT, KEY_PAD6, 0, 0},
    {ctfHEADING_RIGHTBUTTON, ctDigital, ctButton, ctButton, 0, 0, 0, 0},
    {ctfHEADING_LEFTKEY, ctTime, ctKey, ctKey, KEY_LEFT, KEY_PAD4, 0, 0},
    {ctfHEADING_LEFTBUTTON, ctDigital, ctButton, ctButton, 0, 0, 0, 0},
    {ctfFIREPRIMARY_BUTTON, ctTime, ctButton, ctMouseButton, 1, 1, 0, 0},
    {ctfFIREPRIMARY_KEY, ctTime, ctKey, ctKey, KEY_LCTRL, KEY_RCTRL, 0, 0},
    {ctfFIREPRIMARY_KEY2, ctTime, ctKey, ctKey, 0, 0, 0, 0},
    {ctfFIRESECONDARY_BUTTON, ctTime, ctButton, ctMouseButton, 2, 2, 0, 0},
    {ctfFIRESECONDARY_KEY, ctTime, ctKey, ctKey, KEY_SPACEBAR, 0, 0, 0},
    {ctfTOGGLE_SLIDEBUTTON, ctTime, ctButton, ctButton, 0, 0, 0, 0},
    {ctfTOGGLE_SLIDEKEY, ctTime, ctKey, ctKey, KEY_LALT, 0, 0, 0},
    {ctfTOGGLE_BANKBUTTON, ctTime, ctButton, ctButton, 0, 0, 0, 0},
    {ctfTOGGLE_BANKKEY, ctTime, ctKey, ctKey, 0, 0, 0, 0},
    {ctfFIREFLARE_BUTTON, ctTime, ctButton, ctMouseButton, 3, 3, 0, 0},
    {ctfFIREFLARE_KEY, ctDownCount, ctKey, ctKey, KEY_F, 0, 0, 0},
    {ctfAFTERBURN_BUTTON, ctTime, ctButton, ctButton, 0, 0, 0, 0},
    {ctfAFTERBURN_KEY, ctTime, ctKey, ctKey, KEY_S, 0, 0, 0},
    {ctfAUTOMAP_KEY, ctDownCount, ctKey, ctKey, KEY_TAB, 0, 0, 0},
    {ctfPREV_INVKEY, ctDownCount, ctKey, ctKey, KEY_LBRACKET, 0, 0, 0},
    {ctfNEXT_INVKEY, ctDownCount, ctKey, ctKey, KEY_RBRACKET, 0, 0, 0},
    {ctfINV_USEKEY, ctDownCount, ctKey, ctKey, KEY_BACKSLASH, 0, 0, 0},
    {ctfPREV_CNTMSKEY, ctDownCount, ctKey, ctKey, KEY_SEMICOL, 0, 0, 0},
    {ctfNEXT_CNTMSKEY, ctDownCount, ctKey, ctKey, KEY_RAPOSTRO, 0, 0, 0},
    {ctfCNTMS_USEKEY, ctDownCount, ctKey, ctKey, KEY_ENTER, 0, 0, 0},
    {ctfHEADLIGHT_KEY, ctDownCount, ctKey, ctKey, KEY_H, 0, 0, 0},
    {ctfHEADLIGHT_BUTTON, ctDownCount, ctButton, ctButton, 0, 0, 0, 0},
    {ctfAUTOMAP_BUTTON, ctDownCount, ctButton, ctButton, 0, 0, 0, 0},
    {ctfPREV_INVBTN, ctDownCount, ctButton, ctButton, 0, 0, 0, 0},
    {ctfNEXT_INVBTN, ctDownCount, ctButton, ctButton, 0, 0, 0, 0},
    {ctfINV_USEBTN, ctDownCount, ctButton, ctButton, 0, 0, 0, 0},
    {ctfPREV_CNTMSBTN, ctDownCount, ctButton, ctButton, 0, 0, 0, 0},
    {ctfNEXT_CNTMSBTN, ctDownCount, ctButton, ctButton, 0, 0, 0, 0},
    {ctfCNTMS_USEBTN, ctDownCount, ctButton, ctMouseButton, 4, 4, 0, 0},
    {ctfWPNSEL_PCYCLEKEY, ctDownCount, ctKey, ctKey, KEY_COMMA, 0, 0, 0},
    {ctfWPNSEL_PCYCLEBTN, ctDownCount, ctButton, ctMouseButton, 0, 5, 0, 0},
    {ctfWPNSEL_SCYCLEKEY, ctDownCount, ctKey, ctKey, KEY_PERIOD, 0, 0, 0},
    {ctfWPNSEL_SCYCLEBTN, ctDownCount, ctButton, ctMouseButton, 0, 6, 0, 0},
    {ctfREARVIEW_KEY, ctDownCount, ctKey, ctKey, KEY_R, 0, 0, 0},
    {ctfREARVIEW_BTN, ctDownCount, ctButton, ctButton, 0, 0, 0, 0},
    {ctfAUDIOTAUNT1_KEY, ctDownCount, ctKey, ctKey, 0, 0, 0, 0},
    {ctfAUDIOTAUNT1_BTN, ctDownCount, ctButton, ctButton, 0, 0, 0, 0},
    {ctfAUDIOTAUNT2_KEY, ctDownCount, ctKey, ctKey, 0, 0, 0, 0},
    {ctfAUDIOTAUNT2_BTN, ctDownCount, ctButton, ctButton, 0, 0, 0, 0},
    {ctfAUDIOTAUNT3_KEY, ctDownCount, ctKey, ctKey, 0, 0, 0, 0},
    {ctfAUDIOTAUNT3_BTN, ctDownCount, ctButton, ctButton, 0, 0, 0, 0},
    {ctfAUDIOTAUNT4_KEY, ctDownCount, ctKey, ctKey, 0, 0, 0, 0},
    {ctfAUDIOTAUNT4_BTN, ctDownCount, ctButton, ctButton, 0, 0, 0, 0}};

// ramping macros
static inline float ramp_control_value(float val, float limit, float &ramp_state, float &old_ramp_delta) {
  float sign = val / fabs(val), old_sign = old_ramp_delta / fabs(old_ramp_delta);
  if (sign != old_sign)
    ramp_state = -ramp_state;
  ramp_state = (val != 0) ? (ramp_state + val) : 0.0f;
  ramp_state = (ramp_state > limit) ? limit : (ramp_state < -limit) ? (-limit) : ramp_state;
  old_ramp_delta = val;

  return ramp_state;
}

//	INITIALIZATION FUNCTIONS

void InitControls() {
  //	Create controller object
  if (Control_system_init)
    return;

  Control_system_init = true;

  Controller = CreateController(NUM_CONTROLLER_FUNCTIONS, Controller_needs);
  if (Controller == NULL)
    Error(TXT_ERRUNINITCNT);
  Controller->mask_controllers(false, false);
  Controller->mask_controllers(true, true);

  Controller->mask_controllers((Current_pilot.read_controller & READF_JOY) ? true : false,
                               (Current_pilot.read_controller & READF_MOUSE) ? true : false);

  Controller->set_axis_sensitivity(ctMouseAxis, CT_X_AXIS, Current_pilot.mouse_sensitivity[0]);
  Controller->set_axis_sensitivity(ctMouseAxis, CT_Y_AXIS, Current_pilot.mouse_sensitivity[1]);
  Controller->set_axis_sensitivity(ctMouseAxis, CT_Z_AXIS, Current_pilot.mouse_sensitivity[0]);
  Controller->set_axis_sensitivity(ctAxis, CT_X_AXIS, Current_pilot.joy_sensitivity[0]);
  Controller->set_axis_sensitivity(ctAxis, CT_Y_AXIS, Current_pilot.joy_sensitivity[1]);
  Controller->set_axis_sensitivity(ctAxis, CT_Z_AXIS, Current_pilot.joy_sensitivity[2]);
  Controller->set_axis_sensitivity(ctAxis, CT_R_AXIS, Current_pilot.joy_sensitivity[3]);
  Controller->set_axis_sensitivity(ctAxis, CT_U_AXIS, Current_pilot.joy_sensitivity[4]);
  Controller->set_axis_sensitivity(ctAxis, CT_V_AXIS, Current_pilot.joy_sensitivity[5]);

  int i;
  i = FindArg("-deadzone0");
  if (i > 0) {
    Controller->set_controller_deadzone(0, atof(GameArgs[i + 1]));
  }
  i = FindArg("-deadzone1");
  if (i > 0) {
    Controller->set_controller_deadzone(1, atof(GameArgs[i + 1]));
  }

  Key_ramp_speed = Current_pilot.key_ramping; // DAJ added to restore ramping

  SuspendControls();

  //	start controller time.
  Control_current_time = Control_interval_time = timer_GetTime();
  Key_ramp.op = Key_ramp.p = 0.0f;
  Key_ramp.ob = Key_ramp.b = 0.0f;
  Key_ramp.oh = Key_ramp.h = 0.0f;
  Key_ramp.ox = Key_ramp.x = 0.0f;
  Key_ramp.oy = Key_ramp.y = 0.0f;
  Key_ramp.oz = Key_ramp.z = 0.0f;

  //	Initialize preemptive controller system for non-positonal data.
  LOG_INFO << "Initialized control system.";
}

void CloseControls() {
  if (!Control_system_init)
    return;
  ResumeControls();
  DestroyController(Controller);
  Controller = NULL;
  LOG_INFO << "Closing control system.";
  Control_system_init = false;
}

//	reinits the controller, hence restoring default controller configurations
void RestoreDefaultControls() {
  ResumeControls();
  DestroyController(Controller);
  Controller = CreateController(NUM_CONTROLLER_FUNCTIONS, Controller_needs);
  if (Controller == NULL)
    Error(TXT_ERRUNINITCNT);
  SuspendControls();

  Controller->mask_controllers((Current_pilot.read_controller & READF_JOY) ? true : false,
                               (Current_pilot.read_controller & READF_MOUSE) ? true : false);
  Controller->set_axis_sensitivity(ctMouseAxis, CT_X_AXIS, Current_pilot.mouse_sensitivity[0]);
  Controller->set_axis_sensitivity(ctMouseAxis, CT_Y_AXIS, Current_pilot.mouse_sensitivity[1]);
  Controller->set_axis_sensitivity(ctMouseAxis, CT_Z_AXIS, Current_pilot.mouse_sensitivity[0]);
  Controller->set_axis_sensitivity(ctAxis, CT_X_AXIS, Current_pilot.joy_sensitivity[0]);
  Controller->set_axis_sensitivity(ctAxis, CT_Y_AXIS, Current_pilot.joy_sensitivity[1]);
  Controller->set_axis_sensitivity(ctAxis, CT_Z_AXIS, Current_pilot.joy_sensitivity[2]);
  Controller->set_axis_sensitivity(ctAxis, CT_R_AXIS, Current_pilot.joy_sensitivity[3]);
  Controller->set_axis_sensitivity(ctAxis, CT_U_AXIS, Current_pilot.joy_sensitivity[4]);
  Controller->set_axis_sensitivity(ctAxis, CT_V_AXIS, Current_pilot.joy_sensitivity[5]);
}

void SuspendControls() {
  if (!Controller)
    return;

  Control_poll_flag = false;
  Controller->suspend();
}

void ResumeControls() {
  if (!Controller)
    return;

  Controller->resume();
  Controller->flush();
  ddio_KeyFlush();
  ddio_MouseQueueFlush();

  Control_poll_flag = true;

  // set pilot defaults for controller outside of assignment
  Controller->mask_controllers((Current_pilot.read_controller & READF_JOY) ? true : false,
                               (Current_pilot.read_controller & READF_MOUSE) ? true : false);
  Controller->set_axis_sensitivity(ctMouseAxis, CT_X_AXIS, Current_pilot.mouse_sensitivity[0]);
  Controller->set_axis_sensitivity(ctMouseAxis, CT_Y_AXIS, Current_pilot.mouse_sensitivity[1]);
  Controller->set_axis_sensitivity(ctMouseAxis, CT_Z_AXIS, Current_pilot.mouse_sensitivity[0]);
  Controller->set_axis_sensitivity(ctAxis, CT_X_AXIS, Current_pilot.joy_sensitivity[0]);
  Controller->set_axis_sensitivity(ctAxis, CT_Y_AXIS, Current_pilot.joy_sensitivity[1]);
  Controller->set_axis_sensitivity(ctAxis, CT_Z_AXIS, Current_pilot.joy_sensitivity[2]);
  Controller->set_axis_sensitivity(ctAxis, CT_R_AXIS, Current_pilot.joy_sensitivity[3]);
  Controller->set_axis_sensitivity(ctAxis, CT_U_AXIS, Current_pilot.joy_sensitivity[4]);
  Controller->set_axis_sensitivity(ctAxis, CT_V_AXIS, Current_pilot.joy_sensitivity[5]);

  int i;
  i = FindArg("-deadzone0");
  if (i > 0) {
    Controller->set_controller_deadzone(0, atof(GameArgs[i + 1]));
  }
  i = FindArg("-deadzone1");
  if (i > 0) {
    Controller->set_controller_deadzone(1, atof(GameArgs[i + 1]));
  }
}

//	INTERFACE FUNCTIONS

void PollControls() {
  //	only read at the specified rate to keep things consistant. manager control system timer
  if (!Control_poll_flag)
    return;
  if (Controller)
    Controller->poll();
  /*
  Control_current_time += Frametime;
  Control_frametime = Control_current_time - Control_interval_time;
  if (Control_frametime >= CONTROL_POLL_RATE) {
          Control_interval_time = Control_current_time;
          if (Controller)
                  Controller->poll();
  }
  */
}

// Read the keyboard & other controllers.  Fills in the specified structure.
void ReadPlayerControls(
	game_controls *controls
	//std::ofstream *log_inputs	//islide
) {
  if (!Control_system_init) {
    memset(controls, 0, sizeof(game_controls));
    return;
  }
  //@@	Control_frametime = Frametime;
  //	keyboard uses game frametime
  // controller uses polled control frametime

  if (!Control_poll_flag) {
    memset(controls, 0, sizeof(game_controls));
    return;
  }

  PollControls();
    
  DoWeapons(controls); // controls for weapon firing operations
  DoMisc(controls);
  DoMovement(controls); // controls for moving the object


  // islide : setup a vector of game_controls
  int do_hack_controls = 0;
  if (do_hack_controls) {

    if (counting_calls == 0) {

      //fill_vec_gc(&vec_gc);
      fill_vec_sgc(&vec_sgc);
    }

    // islide : trying to hack movement
    
    // counting_calls reached 1123 when the gameloop display stated 1314, so maybe the timing of the cutscene lv1
    // explains this
    if (counting_calls < 1000) {

      //memcpy(controls, vec_gc.at(counting_calls % vec_gc.size()), sizeof(game_controls));
      unshrink_gc(controls, vec_sgc.at(counting_calls % vec_sgc.size()));
    }

    if (counting_calls == 1000) { //TODO find proper place to trigger this

      //delete_vec_gc(&vec_gc);
      delete_vec_sgc(&vec_sgc);
    }
  }

  if (b_feed_inputs) {

    shrunk_gc feed_sgc;
    //std::ifstream feed_shrunk;

    if (!b_feed_inputs_old && b_feed_inputs) {
    
      AddHUDMessage("starting feeding recorded inputs");
     //inputs_feed_from.open("./feed_shrunk.sgc", std::ios::binary);
      inputs_feed_from.open("./log_shrunk.sgc", std::ios::binary);
    }

    char buf[100];
    snprintf(buf, sizeof(buf), "feeding inputs");
    RenderHUDText(0x000000ff, HUD_ALPHA, 1, 20, 20, buf);
    
     //inputs_feed_from.seekg(counting_calls * 9, inputs_feed_from.beg);
    
    
    char buf_clk[2] = {};
    inputs_feed_from.read(buf_clk, 2); // clock check ?
    inputs_feed_from.read((char *)&(feed_sgc.xyz), 1);
    inputs_feed_from.read((char *)&(feed_sgc.xyz_rot), 1);
    inputs_feed_from.read((char *)&(feed_sgc.ab), 1);
    inputs_feed_from.read((char *)&(feed_sgc.atk), 1);
    inputs_feed_from.read((char *)&(feed_sgc.atk1f), 1);
    inputs_feed_from.read((char *)&(feed_sgc.atk2f), 1);
    inputs_feed_from.read((char *)&(feed_sgc.misc), 1);

    if (inputs_feed_from.eof()) { 
      inputs_feed_from.close(); // have to close it since it's recreated each call
      b_feed_inputs = false;
      AddHUDMessage("feeding inputs done");
    }

    unshrink_gc(controls, &feed_sgc);
    
  }

  if (b_feed_inputs_old && !b_feed_inputs) {

    inputs_feed_from.close();
    AddHUDMessage("feeding inputs done");
  }
  
   // islide : setup log_input file
   int fill_log_inputs = 0;
   if(fill_log_inputs){

      std::ofstream log_inputs;

      // clearing the log upon starting a level
      if (counting_calls == 0) {

        log_inputs.open("./log_input_islide.txt");
        log_inputs << "";
        log_inputs.close();
      }

	  
      log_inputs.open("./log_input_islide.txt", std::ios_base::app); // AppData\Roaming\Outrage Entertainment\Descent 3
	  
      // the thrust are just -1 0 or +1, but I guss it's for keyboard, and joypad will have a continuum of values
      log_inputs << counting_calls << "\t";
      log_inputs << timer_GetTime() << "\t";    // Control_current_time seems to be constant , around 2s
      // timer_GetTime does what it says - but it's persistent accross levels and reloading
      log_inputs << controls->pitch_thrust << "\t";
      log_inputs << controls->heading_thrust << "\t";
      log_inputs << controls->bank_thrust << "\t";
      log_inputs << controls->vertical_thrust << "\t";
      log_inputs << controls->sideways_thrust << "\t";
      log_inputs << controls->forward_thrust << "\t";
      log_inputs << controls->afterburn_thrust << "\t";
      log_inputs << "\t";
      log_inputs << controls->fire_primary_down_count << "\t";
      log_inputs << controls->fire_primary_down_state << "\t";
      log_inputs << controls->fire_primary_down_time << "\t";
      log_inputs << controls->fire_secondary_down_count << "\t";
      log_inputs << controls->fire_secondary_down_state << "\t";
      log_inputs << controls->fire_secondary_down_time << "\t";
      log_inputs << controls->fire_flare_down_count << "\t";
      log_inputs << "\n";
      // missing cycling items, using items, cycling weapons, save, load, demo
      // missing camera !!!



	  
      log_inputs.close(); // i dont like to open/close on each frame, TODO only 1 open/close
   }

   if (b_record_inputs) {

     if (!b_record_inputs_old && b_record_inputs) {
     
        // reset file
       AddHUDMessage("starting new record of inputs");
        inputs_rec_to.open("./log_shrunk.sgc", std::ios::binary);
       const char buf[1] = {0xF9};
       inputs_rec_to.write(buf, 0);
       inputs_rec_to.close();
       inputs_rec_to.open("./log_shrunk.sgc", std::ios::binary | std::ios::app);
      
     }

     char buf[100];
     snprintf(buf, sizeof(buf), "recording inputs");
     RenderHUDText(0x000000ff, HUD_ALPHA, 1, 20, 20, buf);

     //std::ofstream log_shrunk;

     // clearing the log upon starting a level
     if (counting_calls == 0) {

       //log_shrunk.open("./log_shrunk.sgc", std::ios::binary);
       const char buf[1] = {0xF9};
       //log_shrunk.write(buf, 0);
       //log_shrunk.close();
     }

     shrunk_gc sgc;
     shrink_gc(&sgc, controls);

     //log_shrunk.open("./log_shrunk.sgc", std::ios::binary | std::ios::app); // AppData\Roaming\Outrage Entertainment\Descent 3

     
     // the thrust are just -1 0 or +1, but I guss it's for keyboard, and joypad will have a continuum of values
     uint16_t clk = counting_calls; // enough for ~20min
     inputs_rec_to.write((const char *)&clk, 2);
     //log_shrunk << timer_GetTime() << "\t"; // Control_current_time seems to be constant , around 2s
     // timer_GetTime does what it says - but it's persistent accross levels and reloading
     inputs_rec_to.write((const char *)&(sgc.xyz), 1);
     inputs_rec_to.write((const char *)&(sgc.xyz_rot), 1);
     inputs_rec_to.write((const char *)&(sgc.ab), 1);
     inputs_rec_to.write((const char *)&(sgc.atk), 1);
     inputs_rec_to.write((const char *)&(sgc.atk1f), 1);
     inputs_rec_to.write((const char *)&(sgc.atk2f), 1);
     inputs_rec_to.write((const char *)&(sgc.misc), 1);
     
     
     //log_shrunk.close(); // i dont like to open/close on each frame, TODO only 1 open/close
   }

    if (b_record_inputs_old && !b_record_inputs) {

     // close file
     inputs_rec_to.close();
     AddHUDMessage("record of inputs done.");
   }

    b_feed_inputs_old = b_feed_inputs;
    b_record_inputs_old = b_record_inputs;
   counting_calls++;
   

  


  //	only read at the specified rate to keep things consistant. manager control system timer
  // Control_current_time += Frametime;
  // Control_frametime = Control_current_time - Control_interval_time;
  // if (Control_frametime >= CONTROL_POLL_RATE) {
  //	Control_interval_time = Control_current_time;
  //	DoMovement(controls);						// controls for moving the object
  //	return 1;
  //}
  // else
  //	return 0;
}

//	---------------------------------------------------------------------------
//	CONTROL FUNCTIONS
//		MOVEMENT
//	---------------------------------------------------------------------------

void DoMovement(game_controls *controls) {
  controls->sideways_thrust = 0.0f;
  controls->vertical_thrust = 0.0f;
  controls->forward_thrust = 0.0f;
  controls->pitch_thrust = 0.0f;
  controls->bank_thrust = 0.0f;
  controls->heading_thrust = 0.0f;
  controls->afterburn_thrust = 0.0f;

  //	only read controls in game interface mode.
  if (Game_interface_mode != GAME_INTERFACE)
    return;

  // keyboard (always do this first.)
  if (!Doing_input_message)
    DoKeyboardMovement(controls);

  // controller
  DoControllerMovement(controls);

  //	clip controller values
  if (controls->pitch_thrust > LIMIT_PITCH)
    controls->pitch_thrust = LIMIT_PITCH;
  if (controls->pitch_thrust < -LIMIT_PITCH)
    controls->pitch_thrust = -LIMIT_PITCH;
  if (controls->heading_thrust > LIMIT_HEADING)
    controls->heading_thrust = LIMIT_HEADING;
  if (controls->heading_thrust < -LIMIT_HEADING)
    controls->heading_thrust = -LIMIT_HEADING;
  if (controls->bank_thrust > LIMIT_BANK)
    controls->bank_thrust = LIMIT_BANK;
  if (controls->bank_thrust < -LIMIT_BANK)
    controls->bank_thrust = -LIMIT_BANK;
  if (controls->sideways_thrust > LIMIT_HORIZ)
    controls->sideways_thrust = LIMIT_HORIZ;
  if (controls->sideways_thrust < -LIMIT_HORIZ)
    controls->sideways_thrust = -LIMIT_HORIZ;
  if (controls->vertical_thrust > LIMIT_VERT)
    controls->vertical_thrust = LIMIT_VERT;
  if (controls->vertical_thrust < -LIMIT_VERT)
    controls->vertical_thrust = -LIMIT_VERT;

  if (controls->forward_thrust > LIMIT_FORWARD)
    controls->forward_thrust = LIMIT_FORWARD;
  if (controls->forward_thrust < -LIMIT_FORWARD)
    controls->forward_thrust = -LIMIT_FORWARD;

  if (controls->afterburn_thrust > LIMIT_FORWARD)
    controls->afterburn_thrust = LIMIT_FORWARD;
  if (controls->afterburn_thrust < -LIMIT_FORWARD)
    controls->afterburn_thrust = -LIMIT_FORWARD;
}

void DoKeyboardMovement(game_controls *controls) {
  float dx, dy, dz, dp, dh, db, d_afterburn;
  ct_packet key_x1, key_x0, key_y1, key_y0, key_z1, key_z0;
  ct_packet key_p1, key_p0, key_h1, key_h0, key_b1, key_b0;
  ct_packet key_afterburn;

  //	read controls
  Controller->get_packet(ctfFORWARD_THRUSTKEY, &key_z1);
  Controller->get_packet(ctfREVERSE_THRUSTKEY, &key_z0);
  Controller->get_packet(ctfUP_THRUSTKEY, &key_y1);
  Controller->get_packet(ctfDOWN_THRUSTKEY, &key_y0);
  Controller->get_packet(ctfRIGHT_THRUSTKEY, &key_x1);
  Controller->get_packet(ctfLEFT_THRUSTKEY, &key_x0);
  Controller->get_packet(ctfPITCH_DOWNKEY, &key_p1);
  Controller->get_packet(ctfPITCH_UPKEY, &key_p0);
  Controller->get_packet(ctfBANK_RIGHTKEY, &key_b1);
  Controller->get_packet(ctfBANK_LEFTKEY, &key_b0);
  Controller->get_packet(ctfHEADING_RIGHTKEY, &key_h1);
  Controller->get_packet(ctfHEADING_LEFTKEY, &key_h0);

  Controller->get_packet(ctfAFTERBURN_KEY, &key_afterburn);

  // check keyboard controls first.

  //	do thrust and orientation controls.  since packet contains time since last call, frametime is taken into
  // account. 	note that the ctDigital packets are for those rare cases where a key is down, but there is no key down
  // time 	registered as of yet, which happens on some systems.
  dx = (key_x1.value - key_x0.value);
  dy = (key_y1.value - key_y0.value);
  dz = (key_z1.value - key_z0.value);
  dp = (key_p1.value - key_p0.value);
  db = (key_b0.value - key_b1.value);
  dh = (key_h1.value - key_h0.value);

  d_afterburn = (key_afterburn.value);

  controls->sideways_thrust +=
      (KEY_RAMPUP_TIME) ? (ramp_control_value(dx, KEY_RAMPUP_TIME, Key_ramp.x, Key_ramp.ox) / KEY_RAMPUP_TIME) : dx;
  controls->vertical_thrust +=
      (KEY_RAMPUP_TIME) ? (ramp_control_value(dy, KEY_RAMPUP_TIME, Key_ramp.y, Key_ramp.oy) / KEY_RAMPUP_TIME) : dy;
  controls->forward_thrust +=
      (KEY_RAMPUP_TIME) ? (ramp_control_value(dz, KEY_RAMPUP_TIME, Key_ramp.z, Key_ramp.oz) / KEY_RAMPUP_TIME) : dz;

  controls->afterburn_thrust += d_afterburn / Frametime;

  if (!controls->toggle_slide && !controls->toggle_bank) {
    // clamp pitch ramp time to limits.
    controls->pitch_thrust +=
        (KEY_RAMPUP_TIME) ? (ramp_control_value(dp, KEY_RAMPUP_TIME, Key_ramp.p, Key_ramp.op) / KEY_RAMPUP_TIME) : dp;
    controls->heading_thrust +=
        (KEY_RAMPUP_TIME) ? (ramp_control_value(dh, KEY_RAMPUP_TIME, Key_ramp.h, Key_ramp.oh) / KEY_RAMPUP_TIME) : dh;
  }

  if (controls->toggle_slide) {
    controls->sideways_thrust +=
        (KEY_RAMPUP_TIME) ? (ramp_control_value(dh, KEY_RAMPUP_TIME, Key_ramp.h, Key_ramp.oh) / KEY_RAMPUP_TIME) : dh;
    controls->vertical_thrust +=
        (KEY_RAMPUP_TIME) ? (ramp_control_value(dp, KEY_RAMPUP_TIME, Key_ramp.p, Key_ramp.op) / KEY_RAMPUP_TIME) : dp;
  }
  if (controls->toggle_bank) {
    controls->bank_thrust +=
        (KEY_RAMPUP_TIME) ? (ramp_control_value(dh, KEY_RAMPUP_TIME, Key_ramp.h, Key_ramp.oh) / KEY_RAMPUP_TIME) : dh;
  } else {
    controls->bank_thrust +=
        (KEY_RAMPUP_TIME) ? (ramp_control_value(db, KEY_RAMPUP_TIME, Key_ramp.b, Key_ramp.ob) / KEY_RAMPUP_TIME) : db;
  }
}

//	VERY IMPORTANT:  All the movement thrust values are set in the keyboard movement
//	handler.  So we adjust those values in this function based off of the remaining
//	controller element stataes.

void DoControllerMovement(game_controls *controls) {
  ct_packet ctl_x, ctl_y, ctl_z, ctl_p, ctl_b, ctl_h;
  ct_packet ctl_povl, ctl_povr, ctl_povu, ctl_povd, ctl_fb, ctl_rb;
  ct_packet ctl_afterburn;
  ct_packet ctl_pub, ctl_pdb, ctl_hlb, ctl_hrb, ctl_blb, ctl_brb;

  //	read controls
  Controller->get_packet(ctfFORWARD_THRUSTAXIS, &ctl_z);
  Controller->get_packet(ctfUP_THRUSTAXIS, &ctl_y);
  Controller->get_packet(ctfRIGHT_THRUSTAXIS, &ctl_x);
  Controller->get_packet(ctfPITCH_DOWNAXIS, &ctl_p);
  Controller->get_packet(ctfBANK_RIGHTAXIS, &ctl_b);
  Controller->get_packet(ctfHEADING_RIGHTAXIS, &ctl_h);
  Controller->get_packet(ctfUP_BUTTON, &ctl_povu);
  Controller->get_packet(ctfDOWN_BUTTON, &ctl_povd);
  Controller->get_packet(ctfRIGHT_BUTTON, &ctl_povr);
  Controller->get_packet(ctfLEFT_BUTTON, &ctl_povl);
  Controller->get_packet(ctfFORWARD_BUTTON, &ctl_fb);
  Controller->get_packet(ctfREVERSE_BUTTON, &ctl_rb);
  Controller->get_packet(ctfAFTERBURN_BUTTON, &ctl_afterburn);
  Controller->get_packet(ctfHEADING_LEFTBUTTON, &ctl_hlb);
  Controller->get_packet(ctfHEADING_RIGHTBUTTON, &ctl_hrb);
  Controller->get_packet(ctfPITCH_UPBUTTON, &ctl_pub);
  Controller->get_packet(ctfPITCH_DOWNBUTTON, &ctl_pdb);
  Controller->get_packet(ctfBANK_LEFTBUTTON, &ctl_blb);
  Controller->get_packet(ctfBANK_RIGHTBUTTON, &ctl_brb);

  //	do x and y thrust
  controls->sideways_thrust += ctl_x.value;
  controls->vertical_thrust += -ctl_y.value;

  //	invert throttle alue for real flight model controls
  controls->forward_thrust += -ctl_z.value;

  //	do banking
  if (controls->toggle_bank) {
    controls->bank_thrust += -ctl_h.value;
  } else {
    controls->bank_thrust += -ctl_b.value;
  }

  // do slide if toggled
  if (controls->toggle_slide) {
    controls->sideways_thrust += ctl_h.value;
    if ((ctl_p.flags & CTPK_MOUSE) && !FindArg("-invertmouseslide")) {
      controls->vertical_thrust += (-ctl_p.value);
    } else {
      controls->vertical_thrust += ctl_p.value;
    }
  }

  // do standard pitch and heading.
  if (!controls->toggle_slide && !controls->toggle_bank) {
    controls->pitch_thrust += -ctl_p.value;
    controls->heading_thrust += ctl_h.value;
  }

  //	do afterburn button control
  if (!controls->afterburn_thrust) {
    controls->afterburn_thrust = ((ctl_afterburn.value) / Frametime);
  }

  //	do button heading
  if (ctl_hlb.value)
    controls->heading_thrust += (-1.0f);
  if (ctl_hrb.value)
    controls->heading_thrust += (1.0f);

  //	do button pitch
  if (ctl_pub.value)
    controls->pitch_thrust += (-1.0f);
  if (ctl_pdb.value)
    controls->pitch_thrust += (1.0f);

  //	do forward thrust based off of button values.
  controls->forward_thrust += ((ctl_fb.value - ctl_rb.value) / Frametime);

  //	do button banking
  if (ctl_blb.value)
    controls->bank_thrust += (1.0f);
  if (ctl_brb.value)
    controls->bank_thrust += (-1.0f);

  // do button sliding.  use control frametime to set sliding times per frame.
  //	note that vertical and sideways thrusts are dependent on what the keyboard controller
  //	set these values to.  so we save our own slidetimes.
  if (ctl_povu.value) {
    controls->vertical_thrust += (1.0f);
  }
  if (ctl_povd.value) {
    controls->vertical_thrust -= (1.0f);
  }
  if (ctl_povr.value) {
    controls->sideways_thrust += (1.0f);
  }
  if (ctl_povl.value) {
    controls->sideways_thrust -= (1.0f);
  }
}

//	---------------------------------------------------------------------------
//	CONTROL FUNCTIONS
//		WEAPONS
//	---------------------------------------------------------------------------

void DoWeapons(game_controls *controls) {
  //	reset some values
  controls->fire_primary_down_count = 0;
  controls->fire_primary_down_time = 0;
  controls->fire_primary_down_state = false;
  controls->fire_secondary_down_count = 0;
  controls->fire_secondary_down_time = 0;
  controls->fire_flare_down_count = 0;

  //	only read controls in game interface mode.
  if (Game_interface_mode != GAME_INTERFACE)
    return;

  //	Reads in values to Controls structure
  if (!Doing_input_message)
    DoKeyboardWeapons(controls);

  DoControllerWeapons(controls);
}

void DoKeyboardWeapons(game_controls *controls) {
  ct_packet fire_primary_key_time;
  ct_packet fire_secondary_key_time;
  ct_packet fire_flare_key_count;
  ct_packet automap_key;
  ct_packet cycle_prim, cycle_sec;
  int i;

  //	read controls
  Controller->get_packet(ctfFIREPRIMARY_KEY, &fire_primary_key_time);
  Controller->get_packet(ctfFIRESECONDARY_KEY, &fire_secondary_key_time);
  Controller->get_packet(ctfFIREFLARE_KEY, &fire_flare_key_count);
  Controller->get_packet(ctfAUTOMAP_KEY, &automap_key);
  Controller->get_packet(ctfWPNSEL_PCYCLEKEY, &cycle_prim);
  Controller->get_packet(ctfWPNSEL_SCYCLEKEY, &cycle_sec);

  //	weapon fire
  if (fire_primary_key_time.value > 0) {
    controls->fire_primary_down_state = true;
    controls->fire_primary_down_count = 1;
    controls->fire_primary_down_time = fire_primary_key_time.value;
  }

  if (fire_secondary_key_time.value > 0) {
    controls->fire_secondary_down_count = 1;
    controls->fire_secondary_down_time = fire_secondary_key_time.value;
  }

  // flare
  controls->fire_flare_down_count = fire_flare_key_count.value;

  // automap
  if (automap_key.value) {
    Game_interface_mode = GAME_TELCOM_AUTOMAP;
  }

  // do cycling weapons
  for (i = 0; i < (int)cycle_prim.value; i++)
    SwitchPlayerWeapon(PW_PRIMARY);

  for (i = 0; i < (int)cycle_sec.value; i++)
    SwitchPlayerWeapon(PW_SECONDARY);
}

void DoControllerWeapons(game_controls *controls) {
  ct_packet fire_primary_count, fire_primary_time;
  ct_packet fire_secondary_count, fire_secondary_time;
  ct_packet fire_flare_count;
  ct_packet cycle_prim, cycle_sec;
  ct_packet automap_key;
  int i;

  //	read controls
  Controller->get_packet(ctfFIREPRIMARY_BUTTON, &fire_primary_time);
  Controller->get_packet(ctfFIREPRIMARY_BUTTON, &fire_primary_count, ctDownCount);
  Controller->get_packet(ctfFIRESECONDARY_BUTTON, &fire_secondary_time);
  Controller->get_packet(ctfFIRESECONDARY_BUTTON, &fire_secondary_count, ctDownCount);
  Controller->get_packet(ctfFIREFLARE_BUTTON, &fire_flare_count, ctDownCount);
  Controller->get_packet(ctfWPNSEL_PCYCLEBTN, &cycle_prim);
  Controller->get_packet(ctfWPNSEL_SCYCLEBTN, &cycle_sec);
  Controller->get_packet(ctfAUTOMAP_BUTTON, &automap_key);

  //	weapon fire
  if (fire_primary_count.value > 0 || fire_primary_time.value) {
    controls->fire_primary_down_state = true;
    controls->fire_primary_down_count = (int)fire_primary_count.value;
    controls->fire_primary_down_time = fire_primary_time.value;
  }
  if (fire_secondary_count.value > 0 || fire_secondary_time.value) {
    controls->fire_secondary_down_count = (int)fire_secondary_count.value;
    controls->fire_secondary_down_time = fire_secondary_time.value;
  }

  // Flare
  if (fire_flare_count.value > 0)
    controls->fire_flare_down_count = (int)fire_flare_count.value;

  // automap
  if (automap_key.value) {
    Game_interface_mode = GAME_TELCOM_AUTOMAP;
  }

  // do cycling weapons
  for (i = 0; i < (int)cycle_prim.value; i++)
    SwitchPlayerWeapon(PW_PRIMARY);

  for (i = 0; i < (int)cycle_sec.value; i++)
    SwitchPlayerWeapon(PW_SECONDARY);
}

void DoMisc(game_controls *controls) {
  controls->toggle_slide = false;
  controls->toggle_bank = false;
  controls->rearview_down_count = 0;
  controls->rearview_down_state = false;

  if (!Doing_input_message)
    DoKeyboardMisc(controls);
  DoControllerMisc(controls);

  //@@	if (!toggle_rearview_switch.value && Rearview_key_down) {
  //@@		Rearview_key_down = false;
  //@@		ToggleRearView(0);
  //@@	}
  //@@	else if (toggle_rearview_switch.value && !Rearview_key_down) {
  //@@		Rearview_key_down = true;
  //@@		ToggleRearView(1);
  //@@	}
  //@@	else if (!Rearview_key_down) 	{
  //@@		for (i = 0; i < (int)toggle_rearview.value; i++)
  //@@			ToggleRearView();
  //@@	}
}

// use the currently selected inventory item
extern bool UseInventoryItem();
// use the currently selected countermeasure
extern bool UseCountermeasure();

// Inventory/CounterMeasure states
void DoKeyboardMisc(game_controls *controls) {
  static int energy_to_shields_id = -1;
  int type, id, i;

  ct_packet prev_inv_key, next_inv_key;
  ct_packet prev_cntm_key, next_cntm_key;
  ct_packet use_inv_key, use_inv_key_digital, use_cntm_key, use_taunt[4];
  ct_packet toggle_headlight;
  ct_packet toggle_rearview, toggle_rearview_switch;
  ct_packet key_slide1, key_bank;

  //	read controls
  Controller->get_packet(ctfPREV_INVKEY, &prev_inv_key);
  Controller->get_packet(ctfNEXT_INVKEY, &next_inv_key);
  Controller->get_packet(ctfPREV_CNTMSKEY, &prev_cntm_key);
  Controller->get_packet(ctfNEXT_CNTMSKEY, &next_cntm_key);
  Controller->get_packet(ctfINV_USEKEY, &use_inv_key);
  Controller->get_packet(ctfINV_USEKEY, &use_inv_key_digital, ctDigital);
  Controller->get_packet(ctfCNTMS_USEKEY, &use_cntm_key);
  Controller->get_packet(ctfHEADLIGHT_KEY, &toggle_headlight);
  Controller->get_packet(ctfREARVIEW_KEY, &toggle_rearview);
  Controller->get_packet(ctfREARVIEW_KEY, &toggle_rearview_switch, ctDigital);
  Controller->get_packet(ctfAUDIOTAUNT1_KEY, &use_taunt[0]);
  Controller->get_packet(ctfAUDIOTAUNT2_KEY, &use_taunt[1]);
  Controller->get_packet(ctfAUDIOTAUNT3_KEY, &use_taunt[2]);
  Controller->get_packet(ctfAUDIOTAUNT4_KEY, &use_taunt[3]);

  Controller->get_packet(ctfTOGGLE_SLIDEKEY, &key_slide1);
  Controller->get_packet(ctfTOGGLE_BANKKEY, &key_bank);

  //	check modifiers like toggles
  if (key_slide1.value) {
    controls->toggle_slide = true;
  }
  if (key_bank.value) {
    controls->toggle_bank = true;
  }

  // downcount, only once for audiotaunts
  if (use_taunt[0].value != 0.0f) {
    MultiSendRequestPlayTaunt(0);
  }
  if (use_taunt[1].value != 0.0f) {
    MultiSendRequestPlayTaunt(1);
  }
  if (use_taunt[2].value != 0.0f) {
    MultiSendRequestPlayTaunt(2);
  }
  if (use_taunt[3].value != 0.0f) {
    MultiSendRequestPlayTaunt(3);
  }

  // these are all down count values (so do operation X times)
  for (i = 0; i < (int)prev_cntm_key.value; i++)
    CounterMeasuresSwitch(false);

  for (i = 0; i < (int)next_cntm_key.value; i++)
    CounterMeasuresSwitch(true);

  for (i = 0; i < (int)use_cntm_key.value; i++)
    UseCountermeasure();

  for (i = 0; i < (int)prev_inv_key.value; i++) {
    if (Players[Player_num].inventory.Size() == 1) {
      if (Players[Player_num].inventory.GetPosName())
        AddHUDMessage(TXT_WPNSELECT, Players[Player_num].inventory.GetPosName());
    }
    InventorySwitch(false);
  }

  for (i = 0; i < (int)next_inv_key.value; i++) {
    if (Players[Player_num].inventory.Size() == 1) {
      if (Players[Player_num].inventory.GetPosName())
        AddHUDMessage(TXT_WPNSELECT, Players[Player_num].inventory.GetPosName());
    }
    InventorySwitch(true);
  }

  // do energy to shield hack
  if (energy_to_shields_id == -1) {
    energy_to_shields_id = FindObjectIDName("Converter");
  }
  Players[Player_num].inventory.GetPosTypeID(type, id);
  if (use_inv_key_digital.value) {
    if (type == OBJ_POWERUP && id == energy_to_shields_id) {
      // the player has an energy->shields converter
      DoEnergyToShields(Player_num);
    }
  }

  // do standard inventory use.
  for (i = 0; i < (int)use_inv_key.value; i++) {
    // Inventory use is special cased for Energy->Shields converter
    if (type == OBJ_POWERUP && id == energy_to_shields_id) {
      continue;
    } else {
      // handle use inventory keypress
      UseInventoryItem();
    }
  }

  for (i = 0; i < (int)toggle_headlight.value; i++)
    ToggleHeadlightControlState();

  // rear view toggling.
  controls->rearview_down_count += toggle_rearview.value;
  controls->rearview_down_state = toggle_rearview_switch.value ? true : false;
}

void DoControllerMisc(game_controls *controls) {
  static int energy_to_shields_id = -1;
  int i;

  ct_packet prev_inv, next_inv;
  ct_packet prev_cntm, next_cntm;
  ct_packet use_inv, use_cntm;
  ct_packet toggle_headlight;
  ct_packet toggle_rearview, toggle_rearview_switch;
  ct_packet ctl_bank, ctl_slide, use_taunt[4];

  //	read controls
  Controller->get_packet(ctfPREV_INVBTN, &prev_inv);
  Controller->get_packet(ctfNEXT_INVBTN, &next_inv);
  Controller->get_packet(ctfPREV_CNTMSBTN, &prev_cntm);
  Controller->get_packet(ctfNEXT_CNTMSBTN, &next_cntm);
  Controller->get_packet(ctfINV_USEBTN, &use_inv);
  Controller->get_packet(ctfCNTMS_USEBTN, &use_cntm);
  Controller->get_packet(ctfHEADLIGHT_BUTTON, &toggle_headlight);
  Controller->get_packet(ctfREARVIEW_BTN, &toggle_rearview);
  Controller->get_packet(ctfREARVIEW_BTN, &toggle_rearview_switch, ctDigital);
  Controller->get_packet(ctfAUDIOTAUNT1_BTN, &use_taunt[0]);
  Controller->get_packet(ctfAUDIOTAUNT2_BTN, &use_taunt[1]);
  Controller->get_packet(ctfAUDIOTAUNT3_BTN, &use_taunt[2]);
  Controller->get_packet(ctfAUDIOTAUNT4_BTN, &use_taunt[3]);

  Controller->get_packet(ctfTOGGLE_SLIDEBUTTON, &ctl_slide);
  Controller->get_packet(ctfTOGGLE_BANKBUTTON, &ctl_bank);

  //	check modifiers like toggles
  if (ctl_slide.value) {
    controls->toggle_slide = true;
  }
  if (ctl_bank.value) {
    controls->toggle_bank = true;
  }

  // downcount, only once for audiotaunts
  if (use_taunt[0].value != 0.0f) {
    MultiSendRequestPlayTaunt(0);
  }
  if (use_taunt[1].value != 0.0f) {
    MultiSendRequestPlayTaunt(1);
  }
  if (use_taunt[2].value != 0.0f) {
    MultiSendRequestPlayTaunt(2);
  }
  if (use_taunt[3].value != 0.0f) {
    MultiSendRequestPlayTaunt(3);
  }

  // these are all down count values (so do operation X times)
  for (i = 0; i < (int)prev_cntm.value; i++)
    CounterMeasuresSwitch(false);

  for (i = 0; i < (int)next_cntm.value; i++)
    CounterMeasuresSwitch(true);

  for (i = 0; i < (int)use_cntm.value; i++)
    UseCountermeasure();

  for (i = 0; i < (int)prev_inv.value; i++) {
    if (Players[Player_num].inventory.Size() == 1) {
      if (Players[Player_num].inventory.GetPosName())
        AddHUDMessage(TXT_WPNSELECT, Players[Player_num].inventory.GetPosName());
    }
    InventorySwitch(false);
  }

  for (i = 0; i < (int)next_inv.value; i++) {
    if (Players[Player_num].inventory.Size() == 1) {
      if (Players[Player_num].inventory.GetPosName())
        AddHUDMessage(TXT_WPNSELECT, Players[Player_num].inventory.GetPosName());
    }
    InventorySwitch(true);
  }

  for (i = 0; i < (int)use_inv.value; i++) {
    int type, id;

    if (energy_to_shields_id == -1)
      energy_to_shields_id = FindObjectIDName("Converter");

    // Inventory use is special cased for Energy->Shields converter
    Players[Player_num].inventory.GetPosTypeID(type, id);
    if (type == OBJ_POWERUP && id == energy_to_shields_id) {
      // the player has an energy->shields converter
      DoEnergyToShields(Player_num);
    } else {
      // handle use inventory keypress
      UseInventoryItem();
    }
  }

  for (i = 0; i < (int)toggle_headlight.value; i++)
    ToggleHeadlightControlState();

  // rear view toggling.
  controls->rearview_down_count += toggle_rearview.value;
  if (!controls->rearview_down_state)
    controls->rearview_down_state = toggle_rearview_switch.value ? true : false;
}

//	sets the internal controller config to the current pilot's configuration.
void LoadControlConfig(pilot *plt) {
  int j;
  if (!plt)
    plt = &Current_pilot;

  for (int i = 0; i < NUM_CONTROLLER_FUNCTIONS; i++) {
    int id = Current_pilot.controls[i].id;
    ct_type type[2];
    ct_config_data ccfgdata;
    uint8_t flags[2];

    type[0] = plt->controls[i].type[0];
    type[1] = plt->controls[i].type[1];
    ccfgdata = plt->controls[i].value;
    flags[0] = plt->controls[i].flags[0];
    flags[1] = plt->controls[i].flags[1];

    Controller->set_controller_function(id, type, ccfgdata, flags);
  }
  for (j = 0; j < N_MOUSE_AXIS; j++) {
    Controller->set_axis_sensitivity(ctMouseAxis, j + 1, plt->mouse_sensitivity[j]);
  }
  for (j = 0; j < N_JOY_AXIS; j++) {
    Controller->set_axis_sensitivity(ctAxis, j + 1, plt->joy_sensitivity[j]);
  }

  Key_ramp_speed = plt->key_ramping;
}

//	saves the internal controller config of current pilot. if the controller changes, then calling
//	LoadControlConfig will restore ONLY VALID configurations.
void SaveControlConfig(pilot *plt) {
  int j;
  if (!plt)
    plt = &Current_pilot;

  for (int i = 0; i < NUM_CONTROLLER_FUNCTIONS; i++) {
    ct_type ctype[2];
    ct_config_data ccfgdata;
    uint8_t flags[2];
    Controller->get_controller_function(Controller_needs[i].id, ctype, &ccfgdata, flags);

    plt->controls[i].id = Controller_needs[i].id;
    plt->controls[i].type[0] = ctype[0];
    plt->controls[i].type[1] = ctype[1];
    plt->controls[i].value = ccfgdata;
    plt->controls[i].flags[0] = flags[0];
    plt->controls[i].flags[1] = flags[1];
  }

  for (j = 0; j < N_MOUSE_AXIS; j++) {
    float sens = Controller->get_axis_sensitivity(ctMouseAxis, j + 1);
    plt->mouse_sensitivity[j] = sens;
  }
  for (j = 0; j < N_JOY_AXIS; j++) {
    float sens = Controller->get_axis_sensitivity(ctAxis, j + 1);
    plt->joy_sensitivity[j] = sens;
  }

  plt->key_ramping = Key_ramp_speed;
}

void ToggleHeadlightControlState() {
  if (Players[Player_num].flags & PLAYER_FLAGS_HEADLIGHT_STOLEN) {
    // player has no headlight right now
    AddHUDMessage(TXT_DONTHAVEHEADLIGHT);
    return;
  }

  if (Players[Player_num].flags & PLAYER_FLAGS_HEADLIGHT)
    Players[Player_num].flags &= ~PLAYER_FLAGS_HEADLIGHT;
  else
    Players[Player_num].flags |= PLAYER_FLAGS_HEADLIGHT;

  Sound_system.Play2dSound(SOUND_HEADLIGHT);
  AddHUDMessage(TXT_HEADLIGHTTURNED,
                Players[Player_num].flags & PLAYER_FLAGS_HEADLIGHT ? TXT_STRING_ON : TXT_STRING_OFF);
}
