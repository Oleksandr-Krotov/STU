// Shoot Them Up Game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUBaseWidget.generated.h"

class UWidgetAnimation;
class USoundCue;

UCLASS()
class SHOOTTHEMUP_API USTUBaseWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void Show();

protected:
	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* ShowAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Sound")
	USoundCue* OpenSound;
};
