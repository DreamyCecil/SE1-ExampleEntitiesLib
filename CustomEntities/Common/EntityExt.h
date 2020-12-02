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

// -- Entity classes

// Get library class of an entity
DECL_DLL CDLLEntityClass *GetDLLEntityClass(CEntity *pen);

// Get classes by their class name
DECL_DLL INDEX GetNumberOfClasses(const CTString &strClass);
DECL_DLL CEntity *GetEntityOfClass(const CTString &strClass, INDEX iEntity);

// -- Loops

// Get player entity inside of the loop
DECL_DLL CPlayer *GetNextPlayerEntity(INDEX &iPlayer);

// Loop through player indeces
#define FOREACH_PLAYER(_PlayerIndex) for (INDEX _PlayerIndex = 0; _PlayerIndex < CEntity::GetMaxPlayers(); _PlayerIndex++)

// Loop through existing players
#define FOREACH_CPlayer(_PlayerIndex, _Player) \
  CPlayer *_Player = NULL; \
  for (INDEX _PlayerIndex = 0; \
      (_Player = GetNextPlayerEntity(_PlayerIndex)) != NULL; \
       _PlayerIndex++)

// Assert entity's existence
#define ASSERT_ENTITY(_Entity) (_Entity == NULL || _Entity->GetFlags() & ENF_DELETED)