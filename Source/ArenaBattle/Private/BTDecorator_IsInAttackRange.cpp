// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_IsInAttackRange.h"
#include "ABCharacter.h"
#include "ABAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_IsInAttackRange::UBTDecorator_IsInAttackRange()
{
	NodeName = TEXT("CanAttck");
}

bool UBTDecorator_IsInAttackRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	//auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto ControllingPawn = Cast<AABCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (ControllingPawn == nullptr)
		return false;

	auto Target = Cast<AABCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AABAIController::TargetKey));
	if (Target == nullptr)
		return false;

	//bResult = (Target->GetDistanceTo(ControllingPawn) <= 200.0f);
	bResult = (Target->GetDistanceTo(ControllingPawn) <= ControllingPawn->GetFinalAttackRange());
	return bResult;
}
