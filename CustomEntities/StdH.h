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

// Vanilla entities dependency switch
#define VANILLA_ENTITIES 0

#if VANILLA_ENTITIES

// Link the vanilla library
#pragma comment(lib, "EntitiesV.lib")

// Include common headers from vanilla entities
#include <EntitiesV/StdH/StdH.h>
#include <EntitiesV/Player.h>

#else

// Engine components
#include <Engine/Engine.h>

#define DECL_DLL _declspec(dllexport)

// Dummy player class
typedef CPlayerEntity CPlayer;

// Imported events & flags (replacing "EntitiesV/Global.h" and "EntitiesV/Common/Flags.h")
#include "Common/ImportedEvents.h"
#include "Common/ImportedFlags.h"

// Common headers
#include "Classes/Global.h"
#include "Common/Common.h"

#endif
