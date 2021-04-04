// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Actor.h"
#include "ABWeapon.generated.h"

UCLASS()
class ARENABATTLE_API AABWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AABWeapon();

	float GetAttackRange() const;
	float GetAttackDamage() const;
	float GetAttackModifier() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	USkeletalMeshComponent* Weapon;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attack")
	float AttackRange;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attack")
	float AttackDamageMin;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attack")
	float AttackDamageMax;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attack")
	float AttackModifierMin;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attack")
	float AttackModifierMax;

	UPROPERTY(BlueprintReadOnly, Transient, VisibleInstanceOnly, Category = "Attack")
	float AttackDamage;

	UPROPERTY(BlueprintReadOnly, Transient, VisibleInstanceOnly, Category = "Attack")
	float AttackModifier;
};
