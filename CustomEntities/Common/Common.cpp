/* Copyright (c) 2020-2023 Dreamy Cecil
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

#include "Classes/Global.h"

// Send event to target
void SendToTarget(CEntity *penSendEvent, EVanillaEventType eEventType, CEntity *penCaused) {
  // Invalid target
  if (penSendEvent == NULL) {
    return;
  }
  
  switch (eEventType) {
    // Send causer with the Trigger event
    case VET_TRIGGER: {
      ETrigger eTrigger;
      eTrigger.penCaused = penCaused;
      penSendEvent->SendEvent(eTrigger);
    } break;
    
    // Send causer with the Start event
    case VET_START: {
      EStart eStart;
      eStart.penCaused = penCaused;
      penSendEvent->SendEvent(eStart);
    } break;
    
    case VET_STOP:             penSendEvent->SendEvent(EStop()); break;
    case VET_ACTIVATE:         penSendEvent->SendEvent(EActivate()); break;
    case VET_DEACTIVATE:       penSendEvent->SendEvent(EDeactivate()); break;
    case VET_ENVIRONMENTSTART: penSendEvent->SendEvent(EEnvironmentStart()); break;
    case VET_ENVIRONMENTSTOP:  penSendEvent->SendEvent(EEnvironmentStop()); break;
    case VET_STARTATTACK:      penSendEvent->SendEvent(EStartAttack()); break;
    case VET_STOPATTACK:       penSendEvent->SendEvent(EStopAttack()); break;
    case VET_STOPBLINDNESS:    penSendEvent->SendEvent(EStopBlindness()); break;
    case VET_STOPDEAFNESS:     penSendEvent->SendEvent(EStopDeafness()); break;
    case VET_TELEPORTMB:       penSendEvent->SendEvent(ETeleportMovingBrush()); break;
    
    // Ignore other events (including VET_IGNORE)
    default: break;
  }
};

// Send event in range
void SendInRange(CEntity *penSource, EVanillaEventType eEventType, const FLOATaabbox3D &boxRange) {
  switch (eEventType) {
    case VET_START:            penSource->SendEventInRange(EStart(), boxRange); break;
    case VET_STOP:             penSource->SendEventInRange(EStop(), boxRange); break;
    case VET_TRIGGER:          penSource->SendEventInRange(ETrigger(), boxRange); break;
    case VET_ACTIVATE:         penSource->SendEventInRange(EActivate(), boxRange); break;
    case VET_DEACTIVATE:       penSource->SendEventInRange(EDeactivate(), boxRange); break;
    case VET_ENVIRONMENTSTART: penSource->SendEventInRange(EEnvironmentStart(), boxRange); break;
    case VET_ENVIRONMENTSTOP:  penSource->SendEventInRange(EEnvironmentStop(), boxRange); break;
    case VET_STARTATTACK:      penSource->SendEventInRange(EStartAttack(), boxRange); break;
    case VET_STOPATTACK:       penSource->SendEventInRange(EStopAttack(), boxRange); break;
    case VET_STOPBLINDNESS:    penSource->SendEventInRange(EStopBlindness(), boxRange); break;
    case VET_STOPDEAFNESS:     penSource->SendEventInRange(EStopDeafness(), boxRange); break;
    
    // Ignore other events (including VET_IGNORE)
    default: break;
  }
};
