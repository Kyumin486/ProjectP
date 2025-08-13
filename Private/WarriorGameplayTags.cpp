// Fill out your copyright notice in the Description page of Project Settings.

#include "WarriorGameplayTags.h"

namespace WarriorGameplayTags
{
	/** Input Tags **/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipKatana, "InputTag.EquipKatana");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnEquipKatana, "InputTag.UnEquipKatana");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipBow, "InputTag.EquipBow");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnEquipBow, "InputTag.UnEquipBow");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipScabbard, "InputTag.EquipScabbard");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnEquipScabbard, "InputTag.UnEquipScabbard");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_LightAttack_Katana, "InputTag.LightAttack.Katana");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_HeavyAttack_Katana, "InputTag.HeavyAttack.Katana");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Roll, "InputTag.Roll");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_SwitchTarget, "InputTag.SwitchTarget");

	UE_DEFINE_GAMEPLAY_TAG(InputTag_MustBeHeld, "InputTag.MustBeHeld");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_MustBeHeld_Block, "InputTag.MustBeHeld.Block");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_MustBeHeld_Aiming, "InputTag.MustBeHeld.Aiming");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_MustBeHeld_ArrowFire, "InputTag.MustBeHeld.ArrowFire");

	UE_DEFINE_GAMEPLAY_TAG(InputTag_Toggleable, "InputTag.Toggleable");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Toggleable_TargetLock, "InputTag.Toggleable.TargetLock");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Toggleable_Rage, "InputTag.Toggleable.Rage");
	
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Skill_Katana_Light, "InputTag.Skill.Katana.Light");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Skill_Katana_Heavy, "InputTag.Skill.Katana.Heavy");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Skill_Katana_Third, "InputTag.Skill.Katana.Third");	
								
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Skill_Bow_Light, "InputTag.Skill.Bow.Light");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Skill_Bow_Heavy, "InputTag.Skill.Bow.Heavy");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Skill_Bow_Third, "InputTag.Skill.Bow.Third");

	UE_DEFINE_GAMEPLAY_TAG(InputTag_PickUp_Heal, "InputTag.PickUp.Heal");

	UE_DEFINE_GAMEPLAY_TAG(InputTag_InterAction_Grace, "InputTag.InterAction.Grace");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_InterAction_BossRoom, "InputTag.InterAction.BossRoom");

	/** Player Tags **/
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Katana, "Player.Weapon.Katana");
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Scabbard, "Player.Weapon.Scabbard");
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Bow, "Player.Weapon.Bow");
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Quiver, "Player.Weapon.Quiver");

	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Katana, "Player.Ability.Equip.Katana");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_UnEquip_Katana, "Player.Ability.UnEquip.Katana");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Bow, "Player.Ability.Equip.Bow");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_UnEquip_Bow, "Player.Ability.UnEquip.Bow");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_HitPause, "Player.Ability.HitPause");

	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light_Katana, "Player.Ability.Attack.Light.Katana");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Heavy_Katana, "Player.Ability.Attack.Heavy.Katana");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Third_Katana, "Player.Ability.Attack.Third.Katana");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light_Bow, "Player.Ability.Attack.Light.Bow");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Heavy_Bow, "Player.Ability.Attack.Heavy.Bow");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Third_Bow, "Player.Ability.Attack.Third.Bow");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Roll, "Player.Ability.Roll");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Block, "Player.Ability.Block");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_TargetLock, "Player.Ability.TargetLock");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_PickUp_Heal, "Player.Ability.PickUp.Heal");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Aiming, "Player.Ability.Aiming");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_ArrowFire, "Player.Ability.ArrowFire");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Execute, "Player.Ability.Execute");

	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Buff_Rage, "Player_Ability_Buff_Rage");

	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Skill_Attack_Light_Katana, "Player.Ability.Skill.Attack.Light.Katana");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Skill_Attack_Heavy_Katana, "Player.Ability.Skill.Attack.Heavy.Katana");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Skill_Attack_Third_Katana, "Player.Ability.Skill.Attack.Third.Katana");

	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Skill_Attack_Light_Bow, "Player.Ability.Skill.Attack.Light.Bow");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Skill_Attack_Heavy_Bow, "Player.Ability.Skill.Attack.Heavy.Bow");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Skill_Attack_Third_Bow, "Player.Ability.Skill.Attack.Third.Bow");

	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_InterAction_Grace, "Player.Ability.InterAction.Grace");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_InterAction_BossRoom, "Player.Ability.InterAction.BossRoom");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_EquipBow, "Player.Event.EquipBow");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_UnEquipBow, "Player.Event.UnEquipBow");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_EquipKatana, "Player.Event.EquipKatana");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_UnEquipKatana, "Player.Event.UnEquipKatana");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_HitPause, "Player.Event.HitPause");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_SuccessfulBlock, "Player.Event.SuccessfulBlock");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_SwitchTarget_Left, "Player.Event.SwitchTarget.Left");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_SwitchTarget_Right, "Player.Event.SwitchTarget.Right");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ActivateRage, "Player.Event.ActivateRage");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_AOE, "Player.Event.AOE");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ConsumeHeal, "Player.Event.ConsumeHeal");
	
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_InterAction_Grace, "Player.Event.InterAction.Grace");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_InterAction_BossRoom, "Player.Event.InterAction.BossRoom");

	UE_DEFINE_GAMEPLAY_TAG(Player_Status_JumpToFinisher, "Player.Status.JumpToFinisher");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_CounterAttack, "Player.Status.CounterAttack");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Rolling, "Player.Status.Rolling");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Blocking, "Player.Status.Blocking");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_TargetLock, "Player.Status.TargetLock");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Rage_Activating, "Player.Status.Rage.Activating");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Rage_Active, "Player.Status.Rage.Active");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Rage_Full, "Player.Status.Rage.Full");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Rage_None, "Player.Status.Rage.None");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Aiming, "Player.Status.Aiming");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Charging, "Player.Status.Charging");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_ArrowReady, "Player.Status.ArrowReady");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Equipped_Katana, "Player.Status.Equipped.Katana");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Equipped_Bow, "Player.Status.Equipped.Bow");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_ArrowFire, "Player.Status.ArrowFire");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_SuperArmor, "Player.Status.SuperArmor");

	UE_DEFINE_GAMEPLAY_TAG(Player_SetByCaller_AttackType_Light, "Player.SetByCaller.AttackType.Light");
	UE_DEFINE_GAMEPLAY_TAG(Player_SetByCaller_AttackType_Heavy, "Player.SetByCaller.AttackType.Heavy");
	UE_DEFINE_GAMEPLAY_TAG(Player_SetByCaller_AttackType_Arrow, "Player.SetByCaller.AttackType.Arrow");
	
	UE_DEFINE_GAMEPLAY_TAG(Player_Cooldown_Skill_Katana_Light, "Player.Cooldown.Skill.Katana.Light");
	UE_DEFINE_GAMEPLAY_TAG(Player_Cooldown_Skill_Katana_Heavy, "Player.Cooldown.Skill.Katana.Heavy");
	UE_DEFINE_GAMEPLAY_TAG(Player_Cooldown_Skill_Katana_Third, "Player.Cooldown.Skill.Katana.Third");
										  
	UE_DEFINE_GAMEPLAY_TAG(Player_Cooldown_Skill_Bow_Light, "Player.Cooldown.Skill.Bow.Light");
	UE_DEFINE_GAMEPLAY_TAG(Player_Cooldown_Skill_Bow_Heavy, "Player.Cooldown.Skill.Bow.Heavy");
	UE_DEFINE_GAMEPLAY_TAG(Player_Cooldown_Skill_Bow_Third, "Player.Cooldown.Skill.Bow.Third");

	UE_DEFINE_GAMEPLAY_TAG(Player_Cooldown_Roll, "Player.Cooldown.Roll");
	UE_DEFINE_GAMEPLAY_TAG(Player_Cooldown_Guard, "Player.Cooldown.Guard");
	UE_DEFINE_GAMEPLAY_TAG(Player_Cooldown_Execute, "Player.Cooldown.Execute");

	/** Enemy Tags **/
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Weapon, "Enemy.Weapon");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Melee, "Enemy.Ability.Melee");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Ranged, "Enemy.Ability.Ranged");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_SummonEnemies, "Enemy.Ability.SummonEnemies");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_SummonEnemiesEverySecond, "Enemy.Ability.SummonEnemiesEverySecond");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_SpawnHealingItem, "Enemy.Ability.SpawnHealingItem");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Meteor, "Enemy.Ability.Meteor");


	UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_Strafing, "Enemy.Status.Strafing");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_UnderAttack, "Enemy.Status.UnderAttack");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_Unblockable, "Enemy.Status.Unblockable");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_Boss, "Enemy.Status.Boss");

	UE_DEFINE_GAMEPLAY_TAG(Enemy_Size_Small, "Enemy.Size.Small");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Size_Medium, "Enemy.Size.Medium");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Size_Large, "Enemy.Size.Large");

	UE_DEFINE_GAMEPLAY_TAG(Enemy_UI_Rampage_BossBar, "Enemy.UI.Rampage.BossBar");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_UI_Sevarog_BossBar, "Enemy.UI.Sevarog.BossBar");

	/** Shared Tags **/
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_MeleeHit, "Shared.Event.MeleeHit");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_HitReact, "Shared.Event.HitReact");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_SpawnProjectile, "Shared.Event.SpawnProjectile");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_Executed, "Shared.Event.Executed");

	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_HitReact, "Shared.Ability.HitReact");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_JustGuardHitReact, "Shared.Ability.JustGuardHitReact");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_Death, "Shared.Ability.Death");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_Executed, "Shared.Ability.Executed");

	UE_DEFINE_GAMEPLAY_TAG(Shared_SetByCaller_BaseDamage, "Shared.SetByCaller.BaseDamage");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Dead, "Shared.Status.Dead");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Front, "Shared.Status.HitReact.Front");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Left, "Shared.Status.HitReact.Left");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Right, "Shared.Status.HitReact.Right");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Back, "Shared.Status.HitReact.Back");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Invincible, "Shared.Status.Invincible");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Slow, "Shared.Status.Slow");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Executed, "Shared.Status.Executed");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Executable, "Shared.Status.Executable");
	

	/** Game Data tags **/
	UE_DEFINE_GAMEPLAY_TAG(GameData_Level_MainMenuMap, "GameData.Level.MainMenuMap");
	UE_DEFINE_GAMEPLAY_TAG(GameData_Level_GameplayMap, "GameData.Level.GameplayMap");

}