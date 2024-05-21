// Fill out your copyright notice in the Description page of Project Settings.


#include "CommandWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "DartCharacter.h"
#include "EngineUtils.h"





void UCommandWidget::NativeConstruct()
{
	for (TActorIterator<ADartCharacter> it(GetWorld()); it; ++it)
	{
		dragon = *it;
	}

	btn_sit->OnClicked.AddDynamic(this, &UCommandWidget::Sit);
	btn_bang->OnClicked.AddDynamic(this, &UCommandWidget::Bang);
	btn_fly->OnClicked.AddDynamic(this, &UCommandWidget::Fly);
	btn_return->OnClicked.AddDynamic(this, &UCommandWidget::ReturnMenu);

}

void UCommandWidget::Sit()
{
	dragon->SitAnim();
	UE_LOG(LogTemp, Warning, TEXT("1"));
}

void UCommandWidget::Fly()
{
	dragon->FlyAnim();
	UE_LOG(LogTemp, Warning, TEXT("2"));
}

void UCommandWidget::Bang()
{
	dragon->BangAnim();
	UE_LOG(LogTemp, Warning, TEXT("3"));
}

void UCommandWidget::ReturnMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("4"));
}
