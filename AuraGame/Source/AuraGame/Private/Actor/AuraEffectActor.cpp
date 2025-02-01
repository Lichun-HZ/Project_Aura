// Copyright lichun


#include "Actor/AuraEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Components/SphereComponent.h"

// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

// Called when the game starts or when spawned
void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();

}

void AAuraEffectActor::ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	check(GameplayEffectClass);
	
	UAbilitySystemComponent* ASCTarget = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
	if (ASCTarget)
	{
		FGameplayEffectContextHandle EffectContextHandle = ASCTarget->MakeEffectContext();
		EffectContextHandle.AddSourceObject(this);
		
		const FGameplayEffectSpecHandle EffectSpecHandle = ASCTarget->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContextHandle);
		ASCTarget->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data);
	}
}
