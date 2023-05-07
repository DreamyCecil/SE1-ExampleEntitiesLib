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

#ifndef CECIL_INCL_IMPORTEDEVENTS_H
#define CECIL_INCL_IMPORTEDEVENTS_H

#ifdef PRAGMA_ONCE
  #pragma once
#endif

#include <Engine/Entities/EntityEvent.h>

// [Cecil] NOTE: Define 'VANILLA_EVENTS_ENTITY_ID' before including this file to use entity IDs instead of pointers
#ifdef VANILLA_EVENTS_ENTITY_ID
  typedef ULONG CVanillaEventEntity;
#else
  typedef CEntityPointer CVanillaEventEntity;
#endif

#define CLEAR_TO_DEFAULT(_EventClass) inline void ClearToDefault(_EventClass &e) { e = _EventClass(); }
#define DEFINE_MAKE_COPY(_EventClass) CEntityEvent *MakeCopy(void) { return new _EventClass(*this); }

// Global events

// Stop event
static const SLONG EVENTCODE_EStop = 0x00000000;
class EStop : public CEntityEvent {
  public:
    EStop() : CEntityEvent(EVENTCODE_EStop) {};
    DEFINE_MAKE_COPY(EStop);
};
CLEAR_TO_DEFAULT(EStop);

// Start event
static const SLONG EVENTCODE_EStart = 0x00000001;
class EStart : public CEntityEvent {
  public:
    CVanillaEventEntity penCaused;

    EStart() : CEntityEvent(EVENTCODE_EStart) {
      ClearToDefault(penCaused);
    };

    DEFINE_MAKE_COPY(EStart);
};
CLEAR_TO_DEFAULT(EStart);

// Activate event
static const SLONG EVENTCODE_EActivate = 0x00000002;
class EActivate : public CEntityEvent {
  public:
    EActivate() : CEntityEvent(EVENTCODE_EActivate) {};
    DEFINE_MAKE_COPY(EActivate);
};
CLEAR_TO_DEFAULT(EActivate);

// Deactivate event
static const SLONG EVENTCODE_EDeactivate = 0x00000003;
class EDeactivate : public CEntityEvent {
  public:
    EDeactivate() : CEntityEvent(EVENTCODE_EDeactivate) {};
    DEFINE_MAKE_COPY(EDeactivate);
};
CLEAR_TO_DEFAULT(EDeactivate);

// Environment Start event
static const SLONG EVENTCODE_EEnvironmentStart = 0x00000004;
class EEnvironmentStart : public CEntityEvent {
  public:
    EEnvironmentStart() : CEntityEvent(EVENTCODE_EEnvironmentStart) {};
    DEFINE_MAKE_COPY(EEnvironmentStart);
};
CLEAR_TO_DEFAULT(EEnvironmentStart);

// Environment Stop event
static const SLONG EVENTCODE_EEnvironmentStop = 0x00000005;
class EEnvironmentStop : public CEntityEvent {
  public:
    EEnvironmentStop() : CEntityEvent(EVENTCODE_EEnvironmentStop) {};
    DEFINE_MAKE_COPY(EEnvironmentStop);
};
CLEAR_TO_DEFAULT(EEnvironmentStop);

// End event
static const SLONG EVENTCODE_EEnd = 0x00000006;
class EEnd : public CEntityEvent {
  public:
    EEnd() : CEntityEvent(EVENTCODE_EEnd) {};
    DEFINE_MAKE_COPY(EEnd);
};
CLEAR_TO_DEFAULT(EEnd);

// Trigger event
static const SLONG EVENTCODE_ETrigger = 0x00000007;
class ETrigger : public CEntityEvent {
  public:
    CVanillaEventEntity penCaused;

    ETrigger() : CEntityEvent(EVENTCODE_ETrigger) {
      ClearToDefault(penCaused);
    };

    DEFINE_MAKE_COPY(ETrigger);
};
CLEAR_TO_DEFAULT(ETrigger);

// Teleport Moving Brush event
static const SLONG EVENTCODE_ETeleportMovingBrush = 0x00000008;
class ETeleportMovingBrush : public CEntityEvent {
  public:
    ETeleportMovingBrush() : CEntityEvent(EVENTCODE_ETeleportMovingBrush) {};
    DEFINE_MAKE_COPY(ETeleportMovingBrush);
};
CLEAR_TO_DEFAULT(ETeleportMovingBrush);

// Reminder event
static const SLONG EVENTCODE_EReminder = 0x00000009;
class EReminder : public CEntityEvent {
  public:
    INDEX iValue;

    EReminder() : CEntityEvent(EVENTCODE_EReminder) {
      ClearToDefault(iValue);
    };

    DEFINE_MAKE_COPY(EReminder);
};
CLEAR_TO_DEFAULT(EReminder);

// Start Attack event
static const SLONG EVENTCODE_EStartAttack = 0x0000000a;
class EStartAttack : public CEntityEvent {
  public:
    EStartAttack() : CEntityEvent(EVENTCODE_EStartAttack) {};
    DEFINE_MAKE_COPY(EStartAttack);
};
CLEAR_TO_DEFAULT(EStartAttack);

// Stop Attack event
static const SLONG EVENTCODE_EStopAttack = 0x0000000b;
class EStopAttack : public CEntityEvent {
  public:
    EStopAttack() : CEntityEvent(EVENTCODE_EStopAttack) {};
    DEFINE_MAKE_COPY(EStopAttack);
};
CLEAR_TO_DEFAULT(EStopAttack);

// Stop Blindness event
static const SLONG EVENTCODE_EStopBlindness = 0x0000000c;
class EStopBlindness : public CEntityEvent {
  public:
    EStopBlindness() : CEntityEvent(EVENTCODE_EStopBlindness) {};
    DEFINE_MAKE_COPY(EStopBlindness);
};
CLEAR_TO_DEFAULT(EStopBlindness);

// Stop Deafness event
static const SLONG EVENTCODE_EStopDeafness = 0x0000000d;
class EStopDeafness : public CEntityEvent {
  public:
    EStopDeafness() : CEntityEvent(EVENTCODE_EStopDeafness) {};
    DEFINE_MAKE_COPY(EStopDeafness);
};
CLEAR_TO_DEFAULT(EStopDeafness);

// Receive Score event
static const SLONG EVENTCODE_EReceiveScore = 0x0000000e;
class EReceiveScore : public CEntityEvent {
  public:
    INDEX iPoints;

    EReceiveScore() : CEntityEvent(EVENTCODE_EReceiveScore) {
      ClearToDefault(iPoints);
    };

    DEFINE_MAKE_COPY(EReceiveScore);
};
CLEAR_TO_DEFAULT(EReceiveScore);

// Killed Enemy event
static const SLONG EVENTCODE_EKilledEnemy = 0x0000000f;
class EKilledEnemy : public CEntityEvent {
  public:
    EKilledEnemy() : CEntityEvent(EVENTCODE_EKilledEnemy) {};
    DEFINE_MAKE_COPY(EKilledEnemy);
};
CLEAR_TO_DEFAULT(EKilledEnemy);

// Secret Found event
static const SLONG EVENTCODE_ESecretFound = 0x00000010;
class ESecretFound : public CEntityEvent {
  public:
    ESecretFound() : CEntityEvent(EVENTCODE_ESecretFound) {};
    DEFINE_MAKE_COPY(ESecretFound);
};
CLEAR_TO_DEFAULT(ESecretFound);

// Specific entity events

// EnemyBase: Restart attack
static const SLONG EVENTCODE_ERestartAttack = 0x01360000;
class ERestartAttack : public CEntityEvent {
  public:
    ERestartAttack() : CEntityEvent(EVENTCODE_ERestartAttack) {};
    DEFINE_MAKE_COPY(ERestartAttack);
};
CLEAR_TO_DEFAULT(ERestartAttack);

// EnemyBase: Reconsider behavior
static const SLONG EVENTCODE_EReconsiderBehavior = 0x01360001;
class EReconsiderBehavior : public CEntityEvent {
  public:
    EReconsiderBehavior() : CEntityEvent(EVENTCODE_EReconsiderBehavior) {};
    DEFINE_MAKE_COPY(EReconsiderBehavior);
};
CLEAR_TO_DEFAULT(EReconsiderBehavior);

// EnemyBase: Force wound animation
static const SLONG EVENTCODE_EForceWound = 0x01360002;
class EForceWound : public CEntityEvent {
  public:
    EForceWound() : CEntityEvent(EVENTCODE_EForceWound) {};
    DEFINE_MAKE_COPY(EForceWound);
};
CLEAR_TO_DEFAULT(EForceWound);

// PlayerWeapons: Select new weapon
static const SLONG EVENTCODE_ESelectWeapon = 0x01920001;
class ESelectWeapon : public CEntityEvent {
  public:
    INDEX iWeapon;

    ESelectWeapon() : CEntityEvent(EVENTCODE_ESelectWeapon) {
      ClearToDefault(iWeapon);
    };

    DEFINE_MAKE_COPY(ESelectWeapon);
};
CLEAR_TO_DEFAULT(ESelectWeapon);

// PlayerWeapons: Play boring animation
static const SLONG EVENTCODE_EBoringWeapon = 0x01920002;
class EBoringWeapon : public CEntityEvent {
  public:
    EBoringWeapon() : CEntityEvent(EVENTCODE_EBoringWeapon) {};
    DEFINE_MAKE_COPY(EBoringWeapon);
};
CLEAR_TO_DEFAULT(EBoringWeapon);

// PlayerWeapons: Start firing current weapon
static const SLONG EVENTCODE_EFireWeapon = 0x01920003;
class EFireWeapon : public CEntityEvent {
  public:
    EFireWeapon() : CEntityEvent(EVENTCODE_EFireWeapon) {};
    DEFINE_MAKE_COPY(EFireWeapon);
};
CLEAR_TO_DEFAULT(EFireWeapon);

// PlayerWeapons: Stop firing current weapon
static const SLONG EVENTCODE_EReleaseWeapon = 0x01920004;
class EReleaseWeapon : public CEntityEvent {
  public:
    EReleaseWeapon() : CEntityEvent(EVENTCODE_EReleaseWeapon) {};
    DEFINE_MAKE_COPY(EReleaseWeapon);
};
CLEAR_TO_DEFAULT(EReleaseWeapon);

// PlayerWeapons: Reload current weapon
static const SLONG EVENTCODE_EReloadWeapon = 0x01920005;
class EReloadWeapon : public CEntityEvent {
  public:
    EReloadWeapon() : CEntityEvent(EVENTCODE_EReloadWeapon) {};
    DEFINE_MAKE_COPY(EReloadWeapon);
};
CLEAR_TO_DEFAULT(EReloadWeapon);

// PlayerWeapons: When the weapon has been changed
static const SLONG EVENTCODE_EWeaponChanged = 0x01920006;
class EWeaponChanged : public CEntityEvent {
  public:
    EWeaponChanged() : CEntityEvent(EVENTCODE_EWeaponChanged) {};
    DEFINE_MAKE_COPY(EWeaponChanged);
};
CLEAR_TO_DEFAULT(EWeaponChanged);

// Specific initialization events

// AirShockwave
static const SLONG EVENTCODE_EAirShockwave = 0x015d0000;
class EAirShockwave : public CEntityEvent {
  public:
    CVanillaEventEntity penLauncher;
    FLOAT fHeight;
    FLOAT fEndWidth;
    FLOAT fDuration;

    EAirShockwave() : CEntityEvent(EVENTCODE_EAirShockwave) {
      ClearToDefault(penLauncher);
      ClearToDefault(fHeight);
      ClearToDefault(fEndWidth);
      ClearToDefault(fDuration);
    };

    DEFINE_MAKE_COPY(EAirShockwave);
};
CLEAR_TO_DEFAULT(EAirShockwave);

// AirWave
static const SLONG EVENTCODE_EAirWave = 0x01fe0000;
class EAirWave : public CEntityEvent {
  public:
    CVanillaEventEntity penLauncher;

    EAirWave() : CEntityEvent(EVENTCODE_EAirWave) {
      ClearToDefault(penLauncher);
    };

    DEFINE_MAKE_COPY(EAirWave);
};
CLEAR_TO_DEFAULT(EAirWave);

// BasicEffect
static const SLONG EVENTCODE_ESpawnEffect = 0x02590000;
class ESpawnEffect : public CEntityEvent {
  public:
    INDEX betType; // BasicEffectType enum
    FLOAT3D vNormal;
    FLOAT3D vDirection;
    FLOAT3D vStretch;
    COLOR colMuliplier;

    ESpawnEffect() : CEntityEvent(EVENTCODE_ESpawnEffect) {
      ClearToDefault(betType);
      ClearToDefault(vNormal);
      ClearToDefault(vDirection);
      ClearToDefault(vStretch);
      ClearToDefault(colMuliplier);
    };

    DEFINE_MAKE_COPY(ESpawnEffect);
};
CLEAR_TO_DEFAULT(ESpawnEffect);

// BloodSpray
static const SLONG EVENTCODE_ESpawnSpray = 0x025b0000;
class ESpawnSpray : public CEntityEvent {
  public:
    INDEX sptType; // SprayParticlesType enum
    FLOAT fDamagePower;
    FLOAT fSizeMultiplier;
    FLOAT3D vDirection;
    CVanillaEventEntity penOwner;
    COLOR colCentralColor;
    FLOAT fLaunchPower;
    COLOR colBurnColor;

    ESpawnSpray() : CEntityEvent(EVENTCODE_ESpawnSpray) {
      ClearToDefault(sptType);
      ClearToDefault(fDamagePower);
      ClearToDefault(fSizeMultiplier);
      ClearToDefault(vDirection);
      ClearToDefault(penOwner);
      ClearToDefault(colCentralColor);
      ClearToDefault(fLaunchPower);
      ClearToDefault(colBurnColor);
    };

    DEFINE_MAKE_COPY(ESpawnSpray);
};
CLEAR_TO_DEFAULT(ESpawnSpray);

// Bullet
static const SLONG EVENTCODE_EBulletInit = 0x01f60000;
class EBulletInit : public CEntityEvent {
  public:
    CVanillaEventEntity penOwner;
    FLOAT fDamage;

    EBulletInit() : CEntityEvent(EVENTCODE_EBulletInit) {
      ClearToDefault(penOwner);
      ClearToDefault(fDamage);
    };

    DEFINE_MAKE_COPY(EBulletInit);
};
CLEAR_TO_DEFAULT(EBulletInit);

// CannonBall
static const SLONG EVENTCODE_ELaunchCannonBall = 0x01fa0000;
class ELaunchCannonBall : public CEntityEvent {
  public:
    CVanillaEventEntity penLauncher;
    INDEX cbtType; // CannonBallType enum
    FLOAT fLaunchPower;
    FLOAT fSize;

    ELaunchCannonBall() : CEntityEvent(EVENTCODE_ELaunchCannonBall) {
      ClearToDefault(penLauncher);
      ClearToDefault(cbtType);
      ClearToDefault(fLaunchPower);
      ClearToDefault(fSize);
    };

    DEFINE_MAKE_COPY(ELaunchCannonBall);
};
CLEAR_TO_DEFAULT(ELaunchCannonBall);

// CyborgBike
static const SLONG EVENTCODE_ECyborgBike = 0x014b0000;
class ECyborgBike : public CEntityEvent {
  public:
    FLOAT fSpeed;

    ECyborgBike() : CEntityEvent(EVENTCODE_ECyborgBike) {
      ClearToDefault(fSpeed);
    };

    DEFINE_MAKE_COPY(ECyborgBike);
};
CLEAR_TO_DEFAULT(ECyborgBike);

// Debris
static const SLONG EVENTCODE_ESpawnDebris = 0x025a0000;
class ESpawnDebris : public CEntityEvent {
  public:
    INDEX Eeibt; // EntityInfoBodyType enum
    CModelData *pmd;
    FLOAT fSize;
    CTextureData *ptd;
    CTextureData *ptdRefl;
    CTextureData *ptdSpec;
    CTextureData *ptdBump;
    INDEX iModelAnim;
    INDEX dptParticles; // DebrisParticlesType enum
    INDEX betStain; // BasicEffectType enum
    COLOR colDebris;
    BOOL bCustomShading;
    ANGLE3D aShadingDirection;
    COLOR colCustomAmbient;
    COLOR colCustomDiffuse;
    BOOL bImmaterialASAP;
    FLOAT fDustStretch;
    FLOAT3D vStretch;
    CVanillaEventEntity penFallFXPapa;

    ESpawnDebris() : CEntityEvent(EVENTCODE_ESpawnDebris) {
      ClearToDefault(Eeibt);
      ClearToDefault(pmd);
      ClearToDefault(fSize);
      ClearToDefault(ptd);
      ClearToDefault(ptdRefl);
      ClearToDefault(ptdSpec);
      ClearToDefault(ptdBump);
      ClearToDefault(iModelAnim);
      ClearToDefault(dptParticles);
      ClearToDefault(betStain);
      ClearToDefault(colDebris);
      ClearToDefault(bCustomShading);
      ClearToDefault(aShadingDirection);
      ClearToDefault(colCustomAmbient);
      ClearToDefault(colCustomDiffuse);
      ClearToDefault(bImmaterialASAP);
      ClearToDefault(fDustStretch);
      ClearToDefault(vStretch);
      ClearToDefault(penFallFXPapa);
    };

    DEFINE_MAKE_COPY(ESpawnDebris);
};
CLEAR_TO_DEFAULT(ESpawnDebris);

// DevilProjectile
static const SLONG EVENTCODE_EDevilProjectile = 0x01ff0000;
class EDevilProjectile : public CEntityEvent {
  public:
    CVanillaEventEntity penLauncher;
    CVanillaEventEntity penTarget;

    EDevilProjectile() : CEntityEvent(EVENTCODE_EDevilProjectile) {
      ClearToDefault(penLauncher);
      ClearToDefault(penTarget);
    };

    DEFINE_MAKE_COPY(EDevilProjectile);
};
CLEAR_TO_DEFAULT(EDevilProjectile);

// Effector
static const SLONG EVENTCODE_ESpawnEffector = 0x02600000;
class ESpawnEffector : public CEntityEvent {
  public:
    INDEX eetType; // EffectorEffectType enum
    FLOAT3D vDamageDir;
    FLOAT3D vDestination;
    FLOAT tmLifeTime;
    FLOAT fSize;
    INDEX ctCount;
    CVanillaEventEntity penModel;
    CVanillaEventEntity penModel2;

    ESpawnEffector() : CEntityEvent(EVENTCODE_ESpawnEffector) {
      ClearToDefault(eetType);
      ClearToDefault(vDamageDir);
      ClearToDefault(vDestination);
      ClearToDefault(tmLifeTime);
      ClearToDefault(fSize);
      ClearToDefault(ctCount);
      ClearToDefault(penModel);
      ClearToDefault(penModel2);
    };

    DEFINE_MAKE_COPY(ESpawnEffector);
};
CLEAR_TO_DEFAULT(ESpawnEffector);

// Flame
static const SLONG EVENTCODE_EFlame = 0x01f80000;
class EFlame : public CEntityEvent {
  public:
    CVanillaEventEntity penOwner;
    CVanillaEventEntity penAttach;

    EFlame() : CEntityEvent(EVENTCODE_EFlame) {
      ClearToDefault(penOwner);
      ClearToDefault(penAttach);
    };

    DEFINE_MAKE_COPY(EFlame);
};
CLEAR_TO_DEFAULT(EFlame);

// LarvaOffspring
static const SLONG EVENTCODE_ELaunchLarvaOffspring = 0x01610000;
class ELaunchLarvaOffspring : public CEntityEvent {
  public:
    CVanillaEventEntity penLauncher;

    ELaunchLarvaOffspring() : CEntityEvent(EVENTCODE_ELaunchLarvaOffspring) {
      ClearToDefault(penLauncher);
    };

    DEFINE_MAKE_COPY(ELaunchLarvaOffspring);
};
CLEAR_TO_DEFAULT(ELaunchLarvaOffspring);

// PlayerAnimator
static const SLONG EVENTCODE_EAnimatorInit = 0x01960000;
class EAnimatorInit : public CEntityEvent {
  public:
    CVanillaEventEntity penPlayer;

    EAnimatorInit() : CEntityEvent(EVENTCODE_EAnimatorInit) {
      ClearToDefault(penPlayer);
    };

    DEFINE_MAKE_COPY(EAnimatorInit);
};
CLEAR_TO_DEFAULT(EAnimatorInit);

// PlayerView
static const SLONG EVENTCODE_EViewInit = 0x01930000;
class EViewInit : public CEntityEvent {
  public:
    CVanillaEventEntity penOwner;
    CVanillaEventEntity penCamera;
    INDEX vtView; // ViewType enum
    BOOL bDeathFixed;

    EViewInit() : CEntityEvent(EVENTCODE_EViewInit) {
      ClearToDefault(penOwner);
      ClearToDefault(penCamera);
      ClearToDefault(vtView);
      ClearToDefault(bDeathFixed);
    };

    DEFINE_MAKE_COPY(EViewInit);
};
CLEAR_TO_DEFAULT(EViewInit);

// PlayerWeapons
static const SLONG EVENTCODE_EWeaponsInit = 0x01920000;
class EWeaponsInit : public CEntityEvent {
  public:
    CVanillaEventEntity penOwner;

    EWeaponsInit() : CEntityEvent(EVENTCODE_EWeaponsInit) {
      ClearToDefault(penOwner);
    };

    DEFINE_MAKE_COPY(EWeaponsInit);
};
CLEAR_TO_DEFAULT(EWeaponsInit);

// PlayerWeaponsEffects
static const SLONG EVENTCODE_EWeaponEffectInit = 0x01950000;
class EWeaponEffectInit : public CEntityEvent {
  public:
    CVanillaEventEntity penOwner;
    INDEX EwetEffect; // WeaponEffectType enum

    EWeaponEffectInit() : CEntityEvent(EVENTCODE_EWeaponEffectInit) {
      ClearToDefault(penOwner);
      ClearToDefault(EwetEffect);
    };

    DEFINE_MAKE_COPY(EWeaponEffectInit);
};
CLEAR_TO_DEFAULT(EWeaponEffectInit);

// Projectile
static const SLONG EVENTCODE_ELaunchProjectile = 0x01f50000;
class ELaunchProjectile : public CEntityEvent {
  public:
    CVanillaEventEntity penLauncher;
    INDEX prtType; // ProjectileType enum
    FLOAT fSpeed;
    FLOAT fStretch;

    ELaunchProjectile() : CEntityEvent(EVENTCODE_ELaunchProjectile) {
      ClearToDefault(penLauncher);
      ClearToDefault(prtType);
      ClearToDefault(fSpeed);
      ClearToDefault(fStretch);
    };

    DEFINE_MAKE_COPY(ELaunchProjectile);
};
CLEAR_TO_DEFAULT(ELaunchProjectile);

// Reminder
static const SLONG EVENTCODE_EReminderInit = 0x02bf0000;
class EReminderInit : public CEntityEvent {
  public:
    CVanillaEventEntity penOwner;
    FLOAT fWaitTime;
    INDEX iValue;

    EReminderInit() : CEntityEvent(EVENTCODE_EReminderInit) {
      ClearToDefault(penOwner);
      ClearToDefault(fWaitTime);
      ClearToDefault(iValue);
    };

    DEFINE_MAKE_COPY(EReminderInit);
};
CLEAR_TO_DEFAULT(EReminderInit);

// SeriousBomb
static const SLONG EVENTCODE_ESeriousBomb = 0x01620000;
class ESeriousBomb : public CEntityEvent {
  public:
    CVanillaEventEntity penOwner;

    ESeriousBomb() : CEntityEvent(EVENTCODE_ESeriousBomb) {
      ClearToDefault(penOwner);
    };

    DEFINE_MAKE_COPY(ESeriousBomb);
};
CLEAR_TO_DEFAULT(ESeriousBomb);

// SpawnerProjectile
static const SLONG EVENTCODE_ESpawnerProjectile = 0x01fb0000;
class ESpawnerProjectile : public CEntityEvent {
  public:
    CVanillaEventEntity penOwner;
    CVanillaEventEntity penTemplate;

    ESpawnerProjectile() : CEntityEvent(EVENTCODE_ESpawnerProjectile) {
      ClearToDefault(penOwner);
      ClearToDefault(penTemplate);
    };

    DEFINE_MAKE_COPY(ESpawnerProjectile);
};
CLEAR_TO_DEFAULT(ESpawnerProjectile);

// Spinner
static const SLONG EVENTCODE_ESpinnerInit = 0x015c0000;
class ESpinnerInit : public CEntityEvent {
  public:
    CVanillaEventEntity penParent;
    CVanillaEventEntity penTwister;
    FLOAT3D vRotationAngle;
    FLOAT tmSpinTime;
    FLOAT fUpSpeed;
    BOOL bImpulse;
    FLOAT tmImpulseDuration;

    ESpinnerInit() : CEntityEvent(EVENTCODE_ESpinnerInit) {
      ClearToDefault(penParent);
      ClearToDefault(penTwister);
      ClearToDefault(vRotationAngle);
      ClearToDefault(tmSpinTime);
      ClearToDefault(fUpSpeed);
      ClearToDefault(bImpulse);
      ClearToDefault(tmImpulseDuration);
    };

    DEFINE_MAKE_COPY(ESpinnerInit);
};
CLEAR_TO_DEFAULT(ESpinnerInit);

// Twister
static const SLONG EVENTCODE_ETwister = 0x01fb0000;
class ETwister : public CEntityEvent {
  public:
    CVanillaEventEntity penOwner;
    FLOAT fSize;
    FLOAT fDuration;
    INDEX sgnSpinDir;
    BOOL bGrow;
    BOOL bMovingAllowed;

    ETwister() : CEntityEvent(EVENTCODE_ETwister) {
      ClearToDefault(penOwner);
      ClearToDefault(fSize);
      ClearToDefault(fDuration);
      ClearToDefault(sgnSpinDir);
      ClearToDefault(bGrow);
      ClearToDefault(bMovingAllowed);
    };

    DEFINE_MAKE_COPY(ETwister);
};
CLEAR_TO_DEFAULT(ETwister);

// Watcher
static const SLONG EVENTCODE_EWatcherInit = 0x02bc0000;
class EWatcherInit : public CEntityEvent {
  public:
    CVanillaEventEntity penOwner;

    EWatcherInit() : CEntityEvent(EVENTCODE_EWatcherInit) {
      ClearToDefault(penOwner);
    };

    DEFINE_MAKE_COPY(EWatcherInit);
};
CLEAR_TO_DEFAULT(EWatcherInit);

// Water
static const SLONG EVENTCODE_EWater = 0x01fc0000;
class EWater : public CEntityEvent {
  public:
    CVanillaEventEntity penLauncher;
    INDEX EwsSize; // WaterSize enum

    EWater() : CEntityEvent(EVENTCODE_EWater) {
      ClearToDefault(penLauncher);
      ClearToDefault(EwsSize);
    };

    DEFINE_MAKE_COPY(EWater);
};
CLEAR_TO_DEFAULT(EWater);

#endif
