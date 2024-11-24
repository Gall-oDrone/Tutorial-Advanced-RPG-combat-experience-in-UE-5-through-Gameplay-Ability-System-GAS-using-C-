// Diego Gallo All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_RotateToFaceTarget.generated.h"

struct FRotateToFaceTargetTaskMemory
{
	TWeakObjectPtr<APawn> OwningPawn;
	TWeakObjectPtr<AActor> TargetActor;

	bool IdValid() const
	{
		return OwningPawn.IsValid() && TargetActor.IsValid();
	}

	void Reset()
	{
		OwningPawn.Reset();
		TargetActor.Reset();
	}
};

/**
 * 
 */
UCLASS()
class WARRIOR_API UBTTask_RotateToFaceTarget : public UBTTaskNode
{
	GENERATED_BODY()
	
	UBTTask_RotateToFaceTarget();

	//~ Begin UBTNode Interface
	virtual void InitializeFromAsset(UBehaviorTree& Asset) override;
	virtual uint16 GetInstanceMemorySize() const override;
	virtual FString GetStaticDescription() const override ;
	//~ End UBTNode Interface

	UPROPERTY(EditAnywhere, Category = "Face Target")
	float AnglePrecision;

	UPROPERTY(EditAnywhere, Category = "Face Target")
	float RotationInterSpeed;

	UPROPERTY(EditAnywhere, Category = "Face Target")
	FBlackboardKeySelector InTargetToFaceKey;

};
