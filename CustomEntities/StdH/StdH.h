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

#include <Engine/Engine.h>

#define DECL_DLL _declspec(dllexport)

// -- EntitiesMP compatibility (if not dependent directly)

// Define player class
typedef CPlayerEntity CPlayer;

// Imported events (exclude if using "Global.h" from EntitiesMP)
#include "../Common/ImportedEvents.h"
// Imported flags (exclude if using "Common/Flags.h" from EntitiesMP)
#include "../Common/ImportedFlags.h"

// Define a string class
#include <string>
typedef std::string String;

// Global headers
#include "../_Global.h"
#include "../Common/Common.h"
#include "../Common/EntityExt.h"
