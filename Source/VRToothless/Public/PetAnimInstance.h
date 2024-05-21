// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "DartCharacter.h"
#include "PetAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class VRTOOTHLESS_API UPetAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "mysettings")
	class ADartCharacter* Dragon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "mysettings")
	EDragonState currentState;



	virtual void NativeUninitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
};
