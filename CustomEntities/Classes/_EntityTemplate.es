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

// --- Unique entity ID (increase by one for each new entity)
2001
%{
#include "StdH.h"

// --- C++ code goes before the class definition enclosed in "%{ %}"
%}

// --- Class-specific events and enums go outside of any "%{ %}"

// --- Replace all occurrences of 'ClassName' with your class name (no spaces)
class export CClassName : CRationalEntity {
name      "ClassName";
thumbnail "Placeholder.tbn";
features  "HasName", "HasTarget", "IsTargetable", "IsImportant";

properties:
 // --- Main logical properties
  1 BOOL m_bActive "Active" 'A' = TRUE,
  2 CEntityPointer m_penTarget "Target" 'T',

 // --- Entity identity properties
 10 CTString m_strName "Name" 'N' = "ClassName",
 11 CTString m_strDescription = "",
 12 COLOR m_colEntity "Entity Color" = COLOR(0xFFFFFF00),

components:
  1 model   MODEL_MARKER   "Models\\Editor\\Axis.mdl",
  2 texture TEXTURE_MARKER "Models\\Editor\\Vector.tex",

functions:
  // Entity description
  const CTString &GetDescription(void) const {
    ((CTString&)m_strDescription).PrintF("->%s", (m_penTarget == NULL ? "<none>" : m_penTarget->GetName()));
    return m_strDescription;
  };

// --- Methods not supported by 1.05 engine version can be enclosed in these blocks
#if SE1_VER >= 107
  // Count memory used by this object
  SLONG GetUsedMemory(void) {
    SLONG slUsedMemory = sizeof(CClassName) - sizeof(CRationalEntity) + CRationalEntity::GetUsedMemory();

    slUsedMemory += m_strName.Length();
    slUsedMemory += m_strDescription.Length();
    return slUsedMemory;
  };
#endif

procedures:
  // --- Entity entry procedure (usually in the very bottom of procedures)
  Main() {
    InitAsEditorModel();
    SetPhysicsFlags(EPF_MODEL_IMMATERIAL);
    SetCollisionFlags(ECF_IMMATERIAL);

    SetModel(MODEL_MARKER);
    SetMainModelTexture(TEXTURE_MARKER);

    // Color the entity
    GetModelObject()->mo_colBlendColor = m_colEntity|0xFF;

    return;
  };
};
