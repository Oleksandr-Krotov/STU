// Shoot Them Up Game. All rights reserved.

#include "STUGoToMenuWidget.h"
#include "STUGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

DEFINE_LOG_CATEGORY_STATIC(LogSTUGoToMenuWidget, All, All);

void USTUGoToMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (GoToMenuButton)
	{
		GoToMenuButton->OnClicked.AddDynamic(this, &USTUGoToMenuWidget::OnGoToMenu);
	}

}

void USTUGoToMenuWidget::OnGoToMenu()
{
	if (!GetWorld()) return;

	const auto STUGameInstance = GetWorld()->GetGameInstance<USTUGameInstance>();

	if (STUGameInstance)
	{
		if (STUGameInstance->GetMenuLevelName().IsNone())
		{
			UE_LOG(LogSTUGoToMenuWidget, Error, TEXT("Menu Level name is NONE"));
			return;
		}

		UGameplayStatics::OpenLevel(this, STUGameInstance->GetMenuLevelName());
	}
}

