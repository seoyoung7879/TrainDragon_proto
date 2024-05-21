// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CommandWidget.generated.h"

/**
 * 
 */
UCLASS()
class VRTOOTHLESS_API UCommandWidget : public UUserWidget
{
	GENERATED_BODY()
	

protected:
virtual void NativeConstruct() override;

public:

	UPROPERTY(EditDefaultsOnly, Category = "VR", meta = (BindWidget))
	class UButton* btn_sit;

	UPROPERTY(EditDefaultsOnly, Category = "VR", meta = (BindWidget))
	class UButton* btn_bang;

	UPROPERTY(EditDefaultsOnly, Category = "VR", meta = (BindWidget))
	class UButton* btn_fly;

	UPROPERTY(EditDefaultsOnly, Category = "VR", meta =(BindWidget))
	class UButton* btn_return;


	class ADartCharacter* dragon;



private:
	UFUNCTION(BlueprintCallable)
	void Sit();

	UFUNCTION(BlueprintCallable)
	void Fly();

	UFUNCTION(BlueprintCallable)
	void Bang();

	UFUNCTION(BlueprintCallable)
	void ReturnMenu();
};
