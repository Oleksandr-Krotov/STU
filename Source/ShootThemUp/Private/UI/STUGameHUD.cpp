// Shoot Them Up Game. All rights reserved.

#include "UI/STUGameHUD.h"
#include "Blueprint/UserWidget.h"
#include "Engine/Canvas.h"

void ASTUGameHUD::DrawHUD()
{
	Super::DrawHUD();
	//DrawCrossHair();
}

void ASTUGameHUD::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerHudWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHudWidgetClass);
	if (PlayerHudWidget)
	{
		PlayerHudWidget->AddToViewport();
	}
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
