// Shoot Them Up Game. All rights reserved.

#include "UI/STUSpectatorWidget.h"
#include "STUUtils.h"
#include "Components/STURespawnComponent.h"

bool USTUSpectatorWidget::GetRespawnTime(int32& CountDownTime)
{
	const auto RespawComponent = STUUtils::GetSTUPlayerComponent<USTURespawnComponent>(GetOwningPlayer());

	if (!RespawComponent || !RespawComponent->IsRespawnInProgress()) return false;

	CountDownTime = RespawComponent->GetRespawnCountDown();
	return true;
}
