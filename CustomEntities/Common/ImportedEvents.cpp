/* Copyright (c) 2002-2012 Croteam Ltd. 
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
#include "ImportedEvents.h"

// Copy functions for imported events

CEntityEvent *EStop::MakeCopy(void) {
  CEntityEvent *peeCopy = new EStop(*this);
  return peeCopy;
};

CEntityEvent *EStart::MakeCopy(void) {
  CEntityEvent *peeCopy = new EStart(*this);
  return peeCopy;
};

CEntityEvent *EActivate::MakeCopy(void) {
  CEntityEvent *peeCopy = new EActivate(*this);
  return peeCopy;
};

CEntityEvent *EDeactivate::MakeCopy(void) {
  CEntityEvent *peeCopy = new EDeactivate(*this);
  return peeCopy;
};

CEntityEvent *EEnvironmentStart::MakeCopy(void) {
  CEntityEvent *peeCopy = new EEnvironmentStart(*this);
  return peeCopy;
};

CEntityEvent *EEnvironmentStop::MakeCopy(void) {
  CEntityEvent *peeCopy = new EEnvironmentStop(*this);
  return peeCopy;
};

CEntityEvent *EEnd::MakeCopy(void) {
  CEntityEvent *peeCopy = new EEnd(*this);
  return peeCopy;
};

CEntityEvent *ETrigger::MakeCopy(void) {
  CEntityEvent *peeCopy = new ETrigger(*this);
  return peeCopy;
};

CEntityEvent *ETeleportMovingBrush::MakeCopy(void) {
  CEntityEvent *peeCopy = new ETeleportMovingBrush(*this);
  return peeCopy;
};

CEntityEvent *EReminder::MakeCopy(void) {
  CEntityEvent *peeCopy = new EReminder(*this);
  return peeCopy;
};

CEntityEvent *EStartAttack::MakeCopy(void) {
  CEntityEvent *peeCopy = new EStartAttack(*this);
  return peeCopy;
};

CEntityEvent *EStopAttack::MakeCopy(void) {
  CEntityEvent *peeCopy = new EStopAttack(*this);
  return peeCopy;
};

CEntityEvent *EStopBlindness::MakeCopy(void) {
  CEntityEvent *peeCopy = new EStopBlindness(*this);
  return peeCopy;
};

CEntityEvent *EStopDeafness::MakeCopy(void) {
  CEntityEvent *peeCopy = new EStopDeafness(*this);
  return peeCopy;
};

CEntityEvent *EReceiveScore::MakeCopy(void) {
  CEntityEvent *peeCopy = new EReceiveScore(*this);
  return peeCopy;
};

CEntityEvent *EKilledEnemy::MakeCopy(void) {
  CEntityEvent *peeCopy = new EKilledEnemy(*this);
  return peeCopy;
};

CEntityEvent *ESecretFound::MakeCopy(void) {
  CEntityEvent *peeCopy = new ESecretFound(*this);
  return peeCopy;
};