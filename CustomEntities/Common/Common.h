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

// Replace all occurrences of a substring
DECL_DLL CTString ReplaceSubstr(CTString str, const CTString &strSub, const CTString &strReplace);

// Send event to target
DECL_DLL void SendToTarget(CEntity *penSendEvent, EEventType eEventType, CEntity *penCaused = NULL);
// Send event in range
DECL_DLL void SendInRange(CEntity *penSource, EEventType eEventType, const FLOATaabbox3D &boxRange);