// Shoot Them Up Game. All rights reserved.

#include "STUGameInstance.h"
#include "Sound/STUSoundFuncLibrary.h"

void USTUGameInstance::ToggleVolume()
{
	USTUSoundFuncLibrary::ToggleSetSoundClassVolume(MasterSoundClass);
}
