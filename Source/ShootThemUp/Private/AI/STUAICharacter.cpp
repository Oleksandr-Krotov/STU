// Shoot Them Up Game. All rights reserved.


#include "AI/STUAICharacter.h"

ASTUAICharacter::ASTUAICharacter(const FObjectInitializer& ObjInit)
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	AIControllerClass = ASTUAICharacter::StaticClass();
}
