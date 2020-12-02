/* Copyright (c) 2020 Dreamy Cecil
This program is free software; you can redistribute it and/or modify
it under the terms of version 2 of the GNU General Public License as published by
the Free Software Foundation


This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */

2000
%{
#include "StdH.h"
%}

// Imported events
enum EEventType {
  0 EET_START            "Start Event",
  1 EET_STOP             "Stop Event",
  2 EET_TRIGGER          "Trigger Event",
  3 EET_IGNORE           "Ignore / Don't send",
  4 EET_ACTIVATE         "Activate Event",
  5 EET_DEACTIVATE       "Deactivate Event",
  6 EET_ENVIRONMENTSTART "Start Environment Event",
  7 EET_ENVIRONMENTSTOP  "Stop Environment Event",
  8 EET_STARTATTACK      "Start Attack Event",
  9 EET_STOPATTACK       "Stop Attack Event",
 10 EET_STOPBLINDNESS    "Stop Blindness Event",
 11 EET_STOPDEAFNESS     "Stop Deafness Event",
 12 EET_TELEPORTMB       "Teleport Moving Brush",
};

// Target type
enum EEntityTargetType {
  0 ETT_NONE    "Nothing",
  1 ETT_TRIGGER "Triggerer",
  2 ETT_TARGET  "Target",
};

// Entity group type
enum EGroupType {
  0 EGT_TARGET "None / Target",
  1 EGT_CLASS  "Class Name",
  2 EGT_NAME   "Entity Name",
};