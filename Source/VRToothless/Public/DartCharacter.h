// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DartCharacter.generated.h"


class UPawnSensingComponent;
class UAIPerceptionComponent;

UENUM(BlueprintType)
enum class EDragonState : uint8
{
	IDLE		UMETA(DisplayName = "Base State"),
	MOVE		UMETA(DisplayName = "Walk State"),
	EAT			UMETA(DisplayName = "EAT State"),
	EES_Patrolling UMETA(DisplayName = "Patrolling"),
	STATENICE	UMETA(DisplayName = "Nice State"),
	RETURN		UMETA(DisplayName = "Return State"),
	AGGRESSIVE	UMETA(DisplayName = "Aggressive State"),
	DIE			UMETA(DisplayName = "Die State")

};

UCLASS()
class VRTOOTHLESS_API ADartCharacter : public ACharacter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADartCharacter();

	int32 currentState = 4;



	/*
		Navigation
	*/

	UPROPERTY()
	class AAIController* PetController;

	// 순찰 대상
	UPROPERTY(EditAnywhere, Category = "Mysettings" , BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	AActor* PatrolTarget;

	UPROPERTY(EditAnywhere, Category = "Mysettings")
	TArray<AActor*> PatrolTargets;

	UPROPERTY(EditAnywhere, Category= "VR")
	class UAnimMontage* Bang_Montage;

	UPROPERTY(EditAnywhere, Category = "VR")
	class UAnimMontage* Wait_Montage;

	UPROPERTY(EditAnywhere, Category = "VR")
	class UAnimMontage* Fly_Montage;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "VR")
	FVector foodeat;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 센서를 통해 액터 주시
	UFUNCTION()
	void PawnSeen(APawn* SeenActor);



	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 충돌체 컴포넌트 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mysettings")
	class UBoxComponent* boxComp;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mysettings")
	class USkeletalMeshComponent* mesh1;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mysettings")
	EDragonState dragonState = EDragonState::EES_Patrolling;

	void BangAnim();
	void SitAnim();
	void FlyAnim();
	

private:

	UPROPERTY()
	class AActor* target;

	// components
	
	UPROPERTY(VisibleAnywhere)
	UPawnSensingComponent* PawnSensing;

	UPROPERTY(VisibleAnywhere)
	UAIPerceptionComponent* ActorSensing;

	//class AVRPlayer* player;

	float currentTime = 3;

	UFUNCTION(BlueprintCallable)
	void Idle(float deltaseconds);
	void Move(float deltaseconds);
	void Patrolling();
	UFUNCTION(BlueprintCallable)
	void Eat();
	void StateNice();
	void Return();
	void Aggressive();
	void RandomPatrol();
	void Die();

	float randomPatrolDelay = 3;

	UPROPERTY()
	class AAIController* EnemyController;

	class UNavigationSystemV1* NavArea;

	FVector RandomLocation;



	
};