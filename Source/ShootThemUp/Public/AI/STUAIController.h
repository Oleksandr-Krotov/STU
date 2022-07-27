// Shoot Them Up Game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Components/STURespawnComponent.h"
#include "STUAIController.generated.h"

class USTUAIPerceptionComponent;
class USTURespawnComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ASTUAIController();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	USTUAIPerceptionComponent* STUAIPerceptionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	USTURespawnComponent* RespawnComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	FName FocusOnKeyName = "EnemyActor";
	
	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float DeltaSeconds) override;

private:
	AActor* GetFocusOnActor() const;
};
