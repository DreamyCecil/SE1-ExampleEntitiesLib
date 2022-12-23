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

#include "StdH.h"

// Get DLL class of an entity
inline CDLLEntityClass *GetDLLEntityClass(CEntity *pen) {
  return pen->en_pecClass->ec_pdecDLLClass;
};

// Get number of entities of a specific class
INDEX GetNumberOfClasses(const CTString &strClass) {
  INDEX ctEntities = 0;

  FOREACHINDYNAMICCONTAINER(_pNetwork->ga_World.wo_cenEntities, CEntity, iten) {
    if (IsDerivedFromClass(iten, strClass)) {
      ctEntities++;
    }
  }

  return ctEntities;
};

// Get a specific entity of a specific class
CEntity *GetEntityOfClass(const CTString &strClass, INDEX iEntity) {
  INDEX ctEntities = 0;
  CEntity *pen = NULL;

  FOREACHINDYNAMICCONTAINER(_pNetwork->ga_World.wo_cenEntities, CEntity, iten) {
    if (IsDerivedFromClass(iten, strClass)) {
      pen = iten;

      if (ctEntities == iEntity) {
        break;
      }
      ctEntities++;
    }
  }

  return pen;
};

// Get player entity inside of the loop
CPlayer *GetNextPlayerEntity(INDEX &iPlayer) {
  // Too many players
  if (iPlayer >= CEntity::GetMaxPlayers()) {
    // Couldn't find anyone
    return NULL;
  }

  // Get player entity
  CEntity *pen = CEntity::GetPlayerEntity(iPlayer);

  // If it doesn't exist
  if ASSERT_ENTITY(pen) {
    // Check the next one
    iPlayer++;
    return GetNextPlayerEntity(iPlayer);
  }

  // Return pointer to a player
  CPlayer *penPlayer = (CPlayer*)pen;
  return penPlayer;
};
