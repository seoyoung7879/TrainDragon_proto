#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "VRPlayer.generated.h"

UCLASS()
class VRTOOTHLESS_API AVRPlayer : public APawn
{
	GENERATED_BODY()

public:

	AVRPlayer();

protected:

	virtual void BeginPlay() override;


public:	


	virtual void Tick(float DeltaTime) override;



	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
