/* Copyright (c) 2020-2021 Dreamy Cecil
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

#include "StdH.h"

// Replace all occurrences of a substring
CTString ReplaceSubstr(CTString str, const CTString &strSub, const CTString &strReplace) {
  String strReturn = str;
  int iStart = 0;

  while ((iStart = strReturn.find(strSub, iStart)) != String::npos) {
    strReturn.replace(iStart, strSub.Length(), strReplace);
    iStart += strReplace.Length();
  }
  return strReturn.c_str();
};

// Send event to target
void SendToTarget(CEntity *penSendEvent, EEventType eEventType, CEntity *penCaused) {
  // invalid target
  if (penSendEvent == NULL) {
    return;
  }
  
  switch (eEventType) {
    // send causer with Trigger event
    case EET_TRIGGER: {
      ETrigger eTrigger;
      eTrigger.penCaused = penCaused;
      penSendEvent->SendEvent(eTrigger);
    } break;
    
    // send causer with Start event
    case EET_START: {
      EStart eStart;
      eStart.penCaused = penCaused;
      penSendEvent->SendEvent(eStart);
    } break;
    
    case EET_STOP:             penSendEvent->SendEvent(EStop()); break;
    case EET_ACTIVATE:         penSendEvent->SendEvent(EActivate()); break;
    case EET_DEACTIVATE:       penSendEvent->SendEvent(EDeactivate()); break;
    case EET_ENVIRONMENTSTART: penSendEvent->SendEvent(EEnvironmentStart()); break;
    case EET_ENVIRONMENTSTOP:  penSendEvent->SendEvent(EEnvironmentStop()); break;
    case EET_STARTATTACK:      penSendEvent->SendEvent(EStartAttack()); break;
    case EET_STOPATTACK:       penSendEvent->SendEvent(EStopAttack()); break;
    case EET_STOPBLINDNESS:    penSendEvent->SendEvent(EStopBlindness()); break;
    case EET_STOPDEAFNESS:     penSendEvent->SendEvent(EStopDeafness()); break;
    case EET_TELEPORTMB:       penSendEvent->SendEvent(ETeleportMovingBrush()); break;
    
    // ignore other events (including EET_IGNORE)
    default: break;
  }
};

// Send event in range
void SendInRange(CEntity *penSource, EEventType eEventType, const FLOATaabbox3D &boxRange) {
  switch (eEventType) {
    case EET_START:            penSource->SendEventInRange(EStart(), boxRange); break;
    case EET_STOP:             penSource->SendEventInRange(EStop(), boxRange); break;
    case EET_TRIGGER:          penSource->SendEventInRange(ETrigger(), boxRange); break;
    case EET_ACTIVATE:         penSource->SendEventInRange(EActivate(), boxRange); break;
    case EET_DEACTIVATE:       penSource->SendEventInRange(EDeactivate(), boxRange); break;
    case EET_ENVIRONMENTSTART: penSource->SendEventInRange(EEnvironmentStart(), boxRange); break;
    case EET_ENVIRONMENTSTOP:  penSource->SendEventInRange(EEnvironmentStop(), boxRange); break;
    case EET_STARTATTACK:      penSource->SendEventInRange(EStartAttack(), boxRange); break;
    case EET_STOPATTACK:       penSource->SendEventInRange(EStopAttack(), boxRange); break;
    case EET_STOPBLINDNESS:    penSource->SendEventInRange(EStopBlindness(), boxRange); break;
    case EET_STOPDEAFNESS:     penSource->SendEventInRange(EStopDeafness(), boxRange); break;
    
    // ignore other events (including EET_IGNORE)
    default: break;
  }
};