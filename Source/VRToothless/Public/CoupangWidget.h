#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CoupangWidget.generated.h"

/**
 * 
 */
UCLASS()
class VRTOOTHLESS_API UCoupangWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	/*UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	class UButton* btn_Food1;
	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	class UButton* btn_Food2;
	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	class UButton* btn_Food3;
	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	class UButton* btn_Water1;
	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	class UButton* btn_Water2;
	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	class UButton* btn_Water3;
	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	class UButton* btn_Brush1;
	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	class UButton* btn_Brush2;
	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	class UButton* btn_Brush3;
	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	class UButton* btn_Shampoo1;
	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	class UButton* btn_Shampoo2;
	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	class UButton* btn_Shampoo3;
	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	class UButton* btn_Bowl1;
	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	class UButton* btn_Bowl2;
	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	class UButton* btn_Bowl3;
	
	class UWidgetComponent* widgetComp;

	class UMainWidget* wallet;

	UFUNCTION()
	void BuyC();
	UFUNCTION()
	void BuyB();
	UFUNCTION()
	void BuyA();*/
	
};
