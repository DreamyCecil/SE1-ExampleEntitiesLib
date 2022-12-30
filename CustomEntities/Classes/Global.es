/* Copyright (c) 2020-2022 Dreamy Cecil
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

// Vanilla event types
enum EVanillaEventType {
  0 VET_START            "Start Event",
  1 VET_STOP             "Stop Event",
  2 VET_TRIGGER          "Trigger Event",
  3 VET_IGNORE           "Ignore / Don't send",
  4 VET_ACTIVATE         "Activate Event",
  5 VET_DEACTIVATE       "Deactivate Event",
  6 VET_ENVIRONMENTSTART "Start Environment Event",
  7 VET_ENVIRONMENTSTOP  "Stop Environment Event",
  8 VET_STARTATTACK      "Start Attack Event",
  9 VET_STOPATTACK       "Stop Attack Event",
 10 VET_STOPBLINDNESS    "Stop Blindness Event",
 11 VET_STOPDEAFNESS     "Stop Deafness Event",
 12 VET_TELEPORTMB       "Teleport Moving Brush",
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
