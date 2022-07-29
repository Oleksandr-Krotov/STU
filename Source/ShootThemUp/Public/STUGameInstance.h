// Shoot Them Up Game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "STUGameInstance.generated.h"

UCLASS()
class SHOOTTHEMUP_API USTUGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	FName GetStartupLevelName() const { return StartupLevelName; }
	FName GetMenuLevelName() const {return GameMenuName;}
protected:
	UPROPERTY(EditDefaultsOnly, Category= "Game")
	FName StartupLevelName = NAME_None;

	UPROPERTY(EditDefaultsOnly, Category= "Game")
	FName GameMenuName = NAME_None;
};
