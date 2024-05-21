// Fill out your copyright notice in the Description page of Project Settings.


#include "DartCharacter.h"
#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "VRPlayer.h"
#include "AIController.h"
#include "PetAnimInstance.h"
#include "NavigationSystem.h"
#include "Perception/PawnSensingComponent.h"
#include <../../../../../../../Source/Runtime/Core/Public/Delegates/Delegate.h>
#include <../../../../../../../Source/Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h>


// Sets default values
ADartCharacter::ADartCharacter()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	/*SetRootComponent(boxComp);

	mesh1 = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh Components"));
	mesh1->SetupAttachment(boxComp);*/

	EnemyController = Cast<AAIController>(GetController());

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	PawnSensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawnsensing"));
	PawnSensing->SightRadius = 250.f;
	PawnSensing->HearingThreshold = 200.f;
	PawnSensing->LOSHearingThreshold = 200.f;
	PawnSensing->SetPeripheralVisionAngle(27.f);

	ActorSensing = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("ActorSensing"));
}

// Called when the game starts or when spawned
void ADartCharacter::BeginPlay()
{
	Super::BeginPlay();

	//// 랜덤 패트롤
	//NavArea = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
	//RandomPatrol();

	// 기본 상태를 idle 상태로 설정 초기화 한다.
	dragonState = EDragonState::EES_Patrolling;

	/*for (TActorIterator<AVRPlayer> player(GetWorld()); player; ++player)
	{
		target = *player;
	}*/

	PetController = Cast<AAIController>(GetController());
	if (PetController && PatrolTarget)
	{
		FAIMoveRequest MoveRequest;
		MoveRequest.SetGoalActor(PatrolTarget);
		MoveRequest.SetAcceptanceRadius(15.f);
		FNavPathSharedPtr navPath;
		PetController->MoveTo(MoveRequest, &navPath);
		TArray<FNavPathPoint>& Pathpoints = navPath->GetPathPoints();
		for (auto& Point : Pathpoints)
		{
			const FVector& Location = Point.Location;
			DrawDebugSphere(GetWorld(), Location, 12.f, 12, FColor::Green, false, 10.f);
		}
	}

	if (PawnSensing)
	{
		PawnSensing->OnSeePawn.AddDynamic(this, &ADartCharacter::PawnSeen);
	}


	randomPatrolDelay = FMath::RandRange(1.5f, 4.5f);

}

void ADartCharacter::PawnSeen(APawn* SeenActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Pawn seen!!!"));

}

// Called every frame
void ADartCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	switch (dragonState)
	{
	case EDragonState::IDLE:
		Idle(DeltaTime);
		break;
	case EDragonState::MOVE:
		Move(DeltaTime);
		break;
	case EDragonState::EES_Patrolling:
		Patrolling();
		break;
	case EDragonState::EAT:
		Eat();
		break;
	case EDragonState::STATENICE:
		StateNice();
		break;
	case EDragonState::RETURN:
		Return();
		break;
	case EDragonState::AGGRESSIVE:
		Aggressive();
		break;
	case EDragonState::DIE:
		Die();
		break;
	default:
		break;
	}

}

void ADartCharacter::BangAnim()
{
	PlayAnimMontage(Bang_Montage, 1);
}

void ADartCharacter::SitAnim()
{
	PlayAnimMontage(Wait_Montage, 1);
}

void ADartCharacter::FlyAnim()
{
	PlayAnimMontage(Fly_Montage, 1);
}

void ADartCharacter::Idle(float deltaseconds)
{

	UE_LOG(LogTemp, Warning, TEXT("IDLE State"));

	//5초가 지나면 상태를 move 상태로 변경
	currentTime += deltaseconds;
	if (currentTime > 5.0f)
	{

		currentTime = 0;
		dragonState = EDragonState::MOVE;
	}
}

void ADartCharacter::Move(float deltaseconds)
{
	currentTime += deltaseconds;
	if (currentTime > 10.0f)
	{

		currentTime = 0;
		dragonState = EDragonState::IDLE;
	}

}

void ADartCharacter::Patrolling()
{
	//dragonState = EDragonState::EES_Patrolling;
	//GetCharacterMovement()->MaxWalkSpeed = 
}

void ADartCharacter::Eat()
{

}

void ADartCharacter::StateNice()
{

}

void ADartCharacter::Return()
{

}

void ADartCharacter::Aggressive()
{

}

void ADartCharacter::Die()
{

}

void ADartCharacter::RandomPatrol()
{
	if (NavArea)
	{
		NavArea->K2_GetRandomReachablePointInRadius(GetWorld(), GetActorLocation(),
			RandomLocation, 15000.0f);

		//movetolocation(RandomLocation);

	}

}