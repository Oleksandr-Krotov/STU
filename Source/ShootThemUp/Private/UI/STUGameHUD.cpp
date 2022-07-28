// Shoot Them Up Game. All rights reserved.

#include "UI/STUGameHUD.h"
#include "Blueprint/UserWidget.h"
#include "Engine/Canvas.h"
#include "STUGameModeBase.h"

DEFINE_LOG_CATEGORY_STATIC(LogSTUGameHUD, All, All)

void ASTUGameHUD::DrawHUD()
{
	Super::DrawHUD();
	//DrawCrossHair(); Replaced with texture sight.
}

void ASTUGameHUD::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerHudWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHudWidgetClass);
	if (PlayerHudWidget)
	{
		PlayerHudWidget->AddToViewport();
	}

	if (GetWorld())
	{
		const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());

		if (GameMode)
		{
			GameMode->OnMathStateChanged.AddUObject(this, &ASTUGameHUD::OnMatchStateChanged);
		}
	}
}

void ASTUGameHUD::OnMatchStateChanged(ESTUMatchState State)
{
	UE_LOG(LogSTUGameHUD, Display, TEXT("Match state changed: %s"), *UEnum::GetValueAsString(State));	
}

void ASTUGameHUD::DrawCrossHair()
{
	const TInterval<float>Center(Canvas->SizeX * 0.5f, Canvas->SizeY * 0.5f);

	const float HalfLineSize = 10.0f;
	const float LineThickness = 2.0f;
	const FLinearColor LinearColor = FLinearColor::Green;
	
	DrawLine(Center.Min -HalfLineSize, Center.Max, Center.Min + HalfLineSize, Center.Max, LinearColor, LineThickness);
	DrawLine(Center.Min, Center.Max -HalfLineSize, Center.Min, Center.Max + HalfLineSize, LinearColor, LineThickness);
}

