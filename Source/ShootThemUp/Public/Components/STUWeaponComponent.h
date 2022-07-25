// Shoot Them Up Game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "STUAmmoPickup.h"
#include "STUBaseWeapon.h"
#include "STUCoreTypes.h"
#include "Components/ActorComponent.h"
#include "Decorators/STUNeedAmmoDecorator.h"
#include "STUWeaponComponent.generated.h"

class ASTUBaseWeapon;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SHOOTTHEMUP_API USTUWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USTUWeaponComponent();
	void Reload();
	void StopFire();
	virtual void StartFire();
	virtual void NextWeapon();
	bool GetCurrentWeaponUIData(FWeaponUIData& UIData) const;
	bool GetCurrentWeaponAmmoData(FAmmoData& AmmoData) const;
	bool TryToAddAmmo(TSubclassOf<ASTUBaseWeapon> WeaponType, int32 ClipAmount);
	bool NeedAmmo(TSubclassOf<ASTUBaseWeapon> WeaponType);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TArray<FWeaponData> WeaponData;
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	FName WeaponEquipSocketName = "WeaponSocket";

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	FName WeaponArmorySocketName = "ArmorySocket";

	UPROPERTY(EditDefaultsOnly, Category = "Animation");
	UAnimMontage* EquipAnimMontage;
	UPROPERTY()
	ASTUBaseWeapon* CurrentWeapon = nullptr;
	UPROPERTY()
	TArray<ASTUBaseWeapon*> Weapons;

	int32 CurrentWeaponIndex = 0;

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	bool CanFire() const;
	bool CanEquip() const;
	void EquipWeapon(int32 WeaponIndex);
private:
	UPROPERTY()
	UAnimMontage* CurrentReloadAnimMontage = nullptr;

	bool IsEquipAnimInProgress = false;
	bool IsReloadAnimInProgress = false;

	void AttachWeaponToSocket(ASTUBaseWeapon* Weapon, USceneComponent* SceneComponent, const FName& SocketName);
	void SpawnWeapons();

	void PlayAnimMontage(UAnimMontage* Animation);
	void InitAnimations();
	void OnEquipFinished(USkeletalMeshComponent* MeshComponent);
	void OnReloadFinished(USkeletalMeshComponent* MeshComponent);
	bool CanReload() const;
	void OnEmptyClip(ASTUBaseWeapon* AmmoEmptyWeapon);
	void ChangeClip();
	

};
