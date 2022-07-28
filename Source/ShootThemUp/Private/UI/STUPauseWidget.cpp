// Shoot Them Up Game. All rights reserved.


#include "UI/STUPauseWidget.h"
#include "GameFramework/GameModeBase.h"
#include "Components/Button.h"

void USTUPauseWidget::NativeOnInitialized()
{
	Super::Initialize();

	if (ClearPauseButton)
	{
		ClearPauseButton->OnClicked.AddDynamic(this, &USTUPauseWidget::OnClearPause);
	}
}

void USTUPauseWidget::OnClearPause()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;

	GetWorld()->GetAuthGameMode()->ClearPause();
}
