// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/WarriorBaseAniminstance.h"
#include "WarriorFunctionLibrary.h"

bool UWarriorBaseAniminstance::DoesOwnerHaveTag(FGameplayTag TagToCheck)
{
	if (APawn* OwnerPawn = TryGetPawnOwner())
	{
		return UWarriorFunctionLibrary::NativeDoesActorHaveTag(OwnerPawn, TagToCheck);

	}
	return false;
}
