// Shoot Them Up Game. All rights reserved.


#include "STUHealthBarWidget.h"
#include "Components/ProgressBar.h"

void USTUHealthBarWidget::SetHealthPercent(float Percent)
{
	if (!HealthProgressBar) return;

	const auto HeathBarVisibility = (Percent > PercentVisibilityThreshold || FMath::IsNearlyZero(Percent)
		? ESlateVisibility::Hidden : ESlateVisibility::Visible);

	HealthProgressBar->SetVisibility(HeathBarVisibility);
	
	const auto HealthBarColor = Percent > PercentColorThreshold ? GoodColor : BadColor;

	HealthProgressBar->SetFillColorAndOpacity(HealthBarColor);
	HealthProgressBar->SetPercent(Percent);
}
