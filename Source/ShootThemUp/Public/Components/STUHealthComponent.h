// Shoot Them Up Game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "STUCoreTypes.h"
#include "Components/ActorComponent.h"
#include "STUHealthComponent.generated.h"

class UCameraShakeBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SHOOTTHEMUP_API USTUHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USTUHealthComponent();

	FOnDeath OnDeath;
	FOnHealthChanged OnHealthChanged;

	UFUNCTION(BlueprintCallable)
	bool IsDead() const { return FMath::IsNearlyZero(Health); }

	UFUNCTION(BlueprintCallable, Category = "Health")
	float GetHealthPercent() const { return Health / MaxHealth; }
	
	float GetHealth() const { return Health; }
	
	bool TryToAddHealth(int32 HealthAmount);
	bool IsHealthFull();;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Health", meta = (ClampMin = "0.0", ClampMax = "1000"))
	float MaxHealth = 100.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Heal");
	bool AutoHeal = true;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Heal", meta=(EditCondition = "AutoHeal"));
	float HealUpdateTime = 1.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Heal", meta=(EditCondition = "AutoHeal"));
	float HealDelay = 3.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Heal", meta = (ClampMin = "0.0", ClampMax = "1000"), meta=(EditCondition = "AutoHeal"))
	float HealModifier= 5.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "VFX");
	TSubclassOf<UCameraShakeBase> CameraShake;

	virtual void BeginPlay() override;
	
private:
	float Health = 0.0f;

	FTimerHandle HealTimerHandle;
	
	UFUNCTION()
	void OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy,
	                     AActor* DamageCauser);
	void HealUpdate();
	void SetHealth(float NewHealth);
	void PlayCameraShake();

	void Killed(AController* KillerController);
};
