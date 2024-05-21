#include "CoupangWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "MainWidget.h"

void UCoupangWidget::NativeConstruct()
{
	Super::NativeConstruct();

	/*btn_Food1->OnClicked.AddDynamic(this, &UCoupangWidget::BuyC);
	btn_Water1->OnClicked.AddDynamic(this, &UCoupangWidget::BuyC);
	btn_Brush1->OnClicked.AddDynamic(this, &UCoupangWidget::BuyC);
	btn_Shampoo1->OnClicked.AddDynamic(this, &UCoupangWidget::BuyC);
	btn_Bowl1->OnClicked.AddDynamic(this, &UCoupangWidget::BuyC);

	btn_Food2->OnClicked.AddDynamic(this, &UCoupangWidget::BuyB);
	btn_Water2->OnClicked.AddDynamic(this, &UCoupangWidget::BuyB);
	btn_Brush2->OnClicked.AddDynamic(this, &UCoupangWidget::BuyB);
	btn_Shampoo2->OnClicked.AddDynamic(this, &UCoupangWidget::BuyB);
	btn_Bowl2->OnClicked.AddDynamic(this, &UCoupangWidget::BuyB);

	btn_Food3->OnClicked.AddDynamic(this, &UCoupangWidget::BuyA);
	btn_Water3->OnClicked.AddDynamic(this, &UCoupangWidget::BuyA);
	btn_Brush3->OnClicked.AddDynamic(this, &UCoupangWidget::BuyA);
	btn_Shampoo3->OnClicked.AddDynamic(this, &UCoupangWidget::BuyA);
	btn_Bowl3->OnClicked.AddDynamic(this, &UCoupangWidget::BuyA);*/


}
//
//void UCoupangWidget::BuyC()
//{
//	wallet->DownMoney(1000);
//}
//
//void UCoupangWidget::BuyB()
//{
//	wallet->DownMoney(3000);
//}
//
//void UCoupangWidget::BuyA()
//{
//	wallet->DownMoney(5000);
//}
//
