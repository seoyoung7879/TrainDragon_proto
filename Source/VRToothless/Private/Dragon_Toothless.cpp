// Fill out your copyright notice in the Description page of Project Settings.


#include "Dragon_Toothless.h"
#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "VRPlayer.h"

// Sets default values
ADragon_Toothless::ADragon_Toothless()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	SetRootComponent(boxComp);

	meshComp1 = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh Component1"));
	meshComp1->SetupAttachment(boxComp);
}

// Called when the game starts or when spawned
void ADragon_Toothless::BeginPlay()
{
	Super::BeginPlay();

	// 기본 상태를 idle 상태로 설정 초기화 한다.
	
	
}

// Called every frame
void ADragon_Toothless::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	

}


