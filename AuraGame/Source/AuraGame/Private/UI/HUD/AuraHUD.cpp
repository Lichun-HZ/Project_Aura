// Copyright lichun


#include "UI/HUD/AuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		// 创建WidgetController，设置PlayerController，PlayerState，AbilitySystemComponent和AttributeSet
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);

		// 绑定AttributeValue改变的回调。
		OverlayWidgetController->BindCallbacksToDependencies();
	}

	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget class uninitialized, please fill out BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller class uninitialized, please fill out BP_AuraHUD"));

	// 创建OverlayWidget
	OverlayWidget = CreateWidget<UAuraUserWidget>(GetWorld(), OverlayWidgetClass);

	// 创建OverlayWidgetController，设置给OverlayWidget
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(FWidgetControllerParams(PC, PS, ASC, AS));
	OverlayWidget->SetWidgetController(WidgetController);

	// 通知界面Controller的初始值，界面用于刷新显示。
	WidgetController->BroadcastInitialValues();
	
	OverlayWidget->AddToViewport();
}

void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();
}
