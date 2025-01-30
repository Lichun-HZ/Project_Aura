// Copyright lichun

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURAGAME_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();

	/* Being IEnemyInterface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/* End IEnemyInterface */

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;
};
