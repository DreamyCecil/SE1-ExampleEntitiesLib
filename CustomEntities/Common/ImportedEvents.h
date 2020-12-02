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

#ifndef SE_INCL_IMPORTEDEVENTS_H
#define SE_INCL_IMPORTEDEVENTS_H
#ifdef PRAGMA_ONCE
  #pragma once
#endif

// Stop event
#define EVENTCODE_EStop 0x00000000
class DECL_DLL EStop : public CEntityEvent {
public:
  EStop() : CEntityEvent(EVENTCODE_EStop) {};
  CEntityEvent *MakeCopy(void);
};

DECL_DLL inline void ClearToDefault(EStop &e) {
  e = EStop();
};

// Start event
#define EVENTCODE_EStart 0x00000001
class DECL_DLL EStart : public CEntityEvent {
public:
  CEntityPointer penCaused;
  
  EStart() : CEntityEvent(EVENTCODE_EStart) {
    ClearToDefault(penCaused);
  };
  
  CEntityEvent *MakeCopy(void);
};

DECL_DLL inline void ClearToDefault(EStart &e) {
  e = EStart();
};

// Activate event
#define EVENTCODE_EActivate 0x00000002
class DECL_DLL EActivate : public CEntityEvent {
public:
  EActivate() : CEntityEvent(EVENTCODE_EActivate) {};
  CEntityEvent *MakeCopy(void);
};

DECL_DLL inline void ClearToDefault(EActivate &e) {
  e = EActivate();
};

// Deactivate event
#define EVENTCODE_EDeactivate 0x00000003
class DECL_DLL EDeactivate : public CEntityEvent {
public:
  EDeactivate() : CEntityEvent(EVENTCODE_EDeactivate) {};
  CEntityEvent *MakeCopy(void);
};

DECL_DLL inline void ClearToDefault(EDeactivate &e) {
  e = EDeactivate();
};

// Environment Start event
#define EVENTCODE_EEnvironmentStart 0x00000004
class DECL_DLL EEnvironmentStart : public CEntityEvent {
public:
  EEnvironmentStart() : CEntityEvent(EVENTCODE_EEnvironmentStart) {};
  CEntityEvent *MakeCopy(void);
};

DECL_DLL inline void ClearToDefault(EEnvironmentStart &e) {
  e = EEnvironmentStart();
};

// Environment Stop event
#define EVENTCODE_EEnvironmentStop 0x00000005
class DECL_DLL EEnvironmentStop : public CEntityEvent {
public:
  EEnvironmentStop() : CEntityEvent(EVENTCODE_EEnvironmentStop) {};
  CEntityEvent *MakeCopy(void);
};

DECL_DLL inline void ClearToDefault(EEnvironmentStop &e) {
  e = EEnvironmentStop();
};

// End event
#define EVENTCODE_EEnd 0x00000006
class DECL_DLL EEnd : public CEntityEvent {
public:
  EEnd() : CEntityEvent(EVENTCODE_EEnd) {};
  CEntityEvent *MakeCopy(void);
};

DECL_DLL inline void ClearToDefault(EEnd &e) {
  e = EEnd();
};

// Trigger event
#define EVENTCODE_ETrigger 0x00000007
class DECL_DLL ETrigger : public CEntityEvent {
public:
  CEntityPointer penCaused;
  
  ETrigger() : CEntityEvent(EVENTCODE_ETrigger) {
    ClearToDefault(penCaused);
  };

  CEntityEvent *MakeCopy(void);
};

DECL_DLL inline void ClearToDefault(ETrigger &e) {
  e = ETrigger();
};

// Teleport Moving Brush event
#define EVENTCODE_ETeleportMovingBrush 0x00000008
class DECL_DLL ETeleportMovingBrush : public CEntityEvent {
public:
  ETeleportMovingBrush() : CEntityEvent(EVENTCODE_ETeleportMovingBrush) {};
  CEntityEvent *MakeCopy(void);
};

DECL_DLL inline void ClearToDefault(ETeleportMovingBrush &e) {
  e = ETeleportMovingBrush();
};

// Reminder event
#define EVENTCODE_EReminder 0x00000009
class DECL_DLL EReminder : public CEntityEvent {
public:
  INDEX iValue;
  
  EReminder() : CEntityEvent(EVENTCODE_EReminder) {
    ClearToDefault(iValue);
  };
  
  CEntityEvent *MakeCopy(void);
};

DECL_DLL inline void ClearToDefault(EReminder &e) {
  e = EReminder();
};

// Start Attack event
#define EVENTCODE_EStartAttack 0x0000000a
class DECL_DLL EStartAttack : public CEntityEvent {
public:
  EStartAttack() : CEntityEvent(EVENTCODE_EStartAttack) {};
  CEntityEvent *MakeCopy(void);
};

DECL_DLL inline void ClearToDefault(EStartAttack &e) {
  e = EStartAttack();
};

// Stop Attack event
#define EVENTCODE_EStopAttack 0x0000000b
class DECL_DLL EStopAttack : public CEntityEvent {
public:
  EStopAttack() : CEntityEvent(EVENTCODE_EStopAttack) {};
  CEntityEvent *MakeCopy(void);
};

DECL_DLL inline void ClearToDefault(EStopAttack &e) {
  e = EStopAttack();
};

// Stop Blindness event
#define EVENTCODE_EStopBlindness 0x0000000c
class DECL_DLL EStopBlindness : public CEntityEvent {
public:
  EStopBlindness() : CEntityEvent(EVENTCODE_EStopBlindness) {};
  CEntityEvent *MakeCopy(void);
};

DECL_DLL inline void ClearToDefault(EStopBlindness &e) {
  e = EStopBlindness();
};

// Stop Deafness event
#define EVENTCODE_EStopDeafness 0x0000000d
class DECL_DLL EStopDeafness : public CEntityEvent {
public:
  EStopDeafness() : CEntityEvent(EVENTCODE_EStopDeafness) {};
  CEntityEvent *MakeCopy(void);
};

DECL_DLL inline void ClearToDefault(EStopDeafness &e) {
  e = EStopDeafness();
};

// Receive Score event
#define EVENTCODE_EReceiveScore 0x0000000e
class DECL_DLL EReceiveScore : public CEntityEvent {
public:
  INDEX iPoints;
  
  EReceiveScore() : CEntityEvent(EVENTCODE_EReceiveScore) {
    ClearToDefault(iPoints);
  };
  
  CEntityEvent *MakeCopy(void);
};

DECL_DLL inline void ClearToDefault(EReceiveScore &e) {
  e = EReceiveScore();
};

// Killed Enemy event
#define EVENTCODE_EKilledEnemy 0x0000000f
class DECL_DLL EKilledEnemy : public CEntityEvent {
public:
  EKilledEnemy() : CEntityEvent(EVENTCODE_EKilledEnemy) {};
  CEntityEvent *MakeCopy(void);
};

DECL_DLL inline void ClearToDefault(EKilledEnemy &e) {
  e = EKilledEnemy();
};

// Secret Found event
#define EVENTCODE_ESecretFound 0x00000010
class DECL_DLL ESecretFound : public CEntityEvent {
public:
  ESecretFound() : CEntityEvent(EVENTCODE_ESecretFound) {};
  CEntityEvent *MakeCopy(void);
};

DECL_DLL inline void ClearToDefault(ESecretFound &e) {
  e = ESecretFound();
};

#endif