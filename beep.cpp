/*
 *  beep.ino - beep example application
 *  Copyright 2018 Sony Semiconductor Solutions Corporation
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "beep.hpp"

void Beep::setup()
{
  theAudio = AudioClass::getInstance();
  theAudio->begin();
  theAudio->setPlayerMode(AS_SETPLAYER_OUTPUTDEVICE_SPHP, 0, 0);
}

void Beep::beep(short freq)
{
  theAudio->setBeep(1, -40, freq);
}

void Beep::panic()
{
  theAudio->setBeep(0, 0, 0);
}

short Beep::determine_freq(uint8_t scale, bool sharp)
{
  short freq = 440;

  switch (scale) {
    case 0:
      freq = sharp ? 277 : 262; //C4
      break;
    case 1:
      freq = sharp ? 311 : 293; //D4
      break;
    case 2:
      freq = sharp ? 349 : 330; //E4
      break;
    case 3:
      freq = sharp ? 370 : 349; //F4
      break;
    case 4:
      freq = sharp ? 415 : 392; //G4
      break;
    case 5:
      freq = sharp ? 466 : 440; //A4
      break;
    case 6:
      freq = sharp ? 523 : 494; //B4
      break;
    case 7:
      freq = sharp ? 554 : 523; //C5
      break;
    case 8:
      freq = sharp ? 622 : 587; //D5
      break;
    case 9:
      freq = sharp ? 698 : 659; //E5
      break;
    default:
      freq = sharp ? 740 : 698; //F5
      break;
  }

  return freq;
}
