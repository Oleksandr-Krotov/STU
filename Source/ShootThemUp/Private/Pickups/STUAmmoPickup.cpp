// Shoot Them Up Game. All rights reserved.

#include "Pickups/STUAmmoPickup.h"
#include "Components/STUHealthComponent.h"
#include "Components/STUWeaponComponent.h"
#include "STUUtils.h"


DEFINE_LOG_CATEGORY_STATIC(LogAmmoPickup, All, All);

bool ASTUAmmoPickup::GivePickupTo(APawn* PlayerPawn)
{
	const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(PlayerPawn);
	if (!HealthComponent || HealthComponent->IsDead()) return false;

	const auto WeapontComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(PlayerPawn);

	return WeapontComponent->TryToAddAmmo(WeaponType, ClipsAmount);
}
