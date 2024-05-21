#include "VRPlayer.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"


AVRPlayer::AVRPlayer()
{

	PrimaryActorTick.bCanEverTick = true;

}


void AVRPlayer::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* pc = GetController<APlayerController>();
}


void AVRPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AVRPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


