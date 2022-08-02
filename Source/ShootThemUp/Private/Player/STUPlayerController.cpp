// Shoot Them Up Game. All rights reserved.

#include "Player/STUPlayerController.h"
#include "Components/STURespawnComponent.h"
#include "STUCoreTypes.h"
#include "STUGameInstance.h"
#include "STUGameModeBase.h"
#include "GameFramework/GameModeBase.h"

ASTUPlayerController::ASTUPlayerController()
{
	RespawnComponent = CreateDefaultSubobject<USTURespawnComponent>("RespawnComponent");
}

void ASTUPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld())
	{
		const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());

		if (GameMode)
		{
			GameMode->OnMathStateChanged.AddUObject(this, &ASTUPlayerController::OnMatchStateChanged);
		}
	}
}

void ASTUPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	OnNewPawn.Broadcast(InPawn);
}

void ASTUPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (!InputComponent) return;

	InputComponent->BindAction("PauseGame", IE_Pressed, this, &ASTUPlayerController::OnPauseGame);
	InputComponent->BindAction("Mute", IE_Pressed, this, &ASTUPlayerController::OnMuteSound);
}

void ASTUPlayerController::OnPauseGame()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;

	GetWorld()->GetAuthGameMode()->SetPause(this);
}

void ASTUPlayerController::OnMatchStateChanged(ESTUMatchState State)
{
	bShowMouseCursor = State != ESTUMatchState::InProgress;

	if (bShowMouseCursor)
	{
		SetInputMode(FInputModeUIOnly());
	}
	else
	{
		SetInputMode(FInputModeGameOnly());
	}
}

void ASTUPlayerController::OnMuteSound()
{
	if (!GetWorld()) return;
	
	const auto STUGameInstance = GetWorld()->GetGameInstance<USTUGameInstance>();
	if (!STUGameInstance) return;
	
	STUGameInstance->ToggleVolume();
}
