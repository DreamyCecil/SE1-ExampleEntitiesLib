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

2001
%{
#include "StdH.h"

#if VANILLA_ENTITIES
  #include <EntitiesV/PlayerWeapons.h>
#endif

// Print player info
void PrintPlayerInfo(CEntity *penPlayer, BOOL bAlive) {
  // Not alive
  if (bAlive && !(penPlayer->GetFlags() & ENF_ALIVE)) {
    return;
  }

  // Player name
  CPrintF("%s^r:\n", penPlayer->GetName());

  // Display health
  FLOAT fHealth = ((CLiveEntity *)penPlayer)->GetHealth();
  CPrintF("  Health: %d\n", (INDEX)fHealth);

  // Display available weapons
  #if VANILLA_ENTITIES
    INDEX iWeapons = ((CPlayer *)penPlayer)->GetPlayerWeapons()->m_iAvailableWeapons;
    CPrintF("  Weapons: 0x%X\n", iWeapons);
  #endif
};
%}

class export CExampleEntity : CRationalEntity {
name      "ExampleEntity";
thumbnail "Thumbnails\\Marker.tbn";
features  "HasName", "IsTargetable", "IsImportant";

properties:
  1 BOOL m_bActive "Active" 'A' = TRUE,

 10 CTString m_strName "Name" 'N' = "ExampleEntity",
 11 CTString m_strDescription = "",
 12 COLOR m_colEntity "Entity Color" = COLOR(0xFFFFFF00),

 // Only report on alive players
 20 BOOL m_bOnlyAlive "Only Alive Players" = FALSE,

components:
  // White texture for coloring
  1 model   MODEL_MARKER   "Models\\Editor\\Axis.mdl",
  2 texture TEXTURE_MARKER "TexturesMP\\Detail\\White.tex",

functions:
  // Entity description
  const CTString &GetDescription(void) const {
    ((CTString &)m_strDescription).PrintF("<%s>", (m_bActive ? "active" : "inactive"));
    return m_strDescription;
  };

// Only valid for TSE 1.07 and newer
#if SE1_VER >= 107
  // Count memory used by this object
  SLONG GetUsedMemory(void) {
    SLONG slUsedMemory = sizeof(CExampleEntity) - sizeof(CRationalEntity) + CRationalEntity::GetUsedMemory();

    slUsedMemory += m_strName.Length();
    slUsedMemory += m_strDescription.Length();
    return slUsedMemory;
  };
#endif

procedures:
  // Logic loop
  MainLoop() {
    // Wait for events
    wait() {
      // Tell if active
      on (EBegin) : {
        CPrintF("%s is %s\n", m_strName, (m_bActive ? "active" : "inactive"));
        resume;
      };

      // Activate the entity
      on (EActivate) : {
        m_bActive = TRUE;

        // Tell that became active
        SendEvent(EBegin());
        resume;
      };

      // Deactivate the entity
      on (EDeactivate) : {
        m_bActive = FALSE;

        // Tell that became inactive
        SendEvent(EBegin());
        resume;
      };

      // Print all players' health on trigger event
      on (ETrigger) : {
        // Not active
        if (!m_bActive) {
          resume;
        }

        CPrintF(" --- Player info:\n");

        // Go through existing players
        for (INDEX i = 0; i < GetMaxPlayers(); i++) {
          CEntity *penPlayer = GetPlayerEntity(i);

          if (penPlayer == NULL || penPlayer->GetFlags() & ENF_DELETED) {
            continue;
          }

          // Print out their info
          PrintPlayerInfo(penPlayer, m_bOnlyAlive);
        }

        resume;
      };

      // Ignore other events
      otherwise() : {
        resume;
      };
    }

    return;
  };

  // Entry point
  Main() {
    InitAsEditorModel();
    SetPhysicsFlags(EPF_MODEL_IMMATERIAL);
    SetCollisionFlags(ECF_IMMATERIAL);

    SetModel(MODEL_MARKER);
    SetModelMainTexture(TEXTURE_MARKER);

    // Color the entity
    GetModelObject()->mo_colBlendColor = m_colEntity | 0xFF;

    // Wait one game tick before jumping to the logic procedure
    autowait(_pTimer->TickQuantum);
    jump MainLoop();

    return;
  };
};
