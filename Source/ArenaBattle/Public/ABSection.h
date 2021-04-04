// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Actor.h"
#include "ABSection.generated.h"

UCLASS()
class ARENABATTLE_API AABSection : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AABSection();
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	enum class ESectionState : uint8
	{
		READY=0,
		BATTLE,
		COMPLETE
	};

	void SetState(ESectionState NewState);
	ESectionState CurrentState = ESectionState::READY;

	void OperateGates(bool bOpen = true);

	UFUNCTION()
	void OnTriggerBeginOvelap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnGateTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void OnNPCSpawn();

	UFUNCTION()
	void OnKeyNPCDestroyed(AActor* DestroyedActor);

private:
	UPROPERTY(VisibleAnywhere, Category = "Mesh", meta = (AllowPrivateAccess = true))
	TArray<UStaticMeshComponent*> GateMeshes;

	UPROPERTY(VisibleAnywhere, Category = "Trigger", meta = (AllowPrivateAccess = true))
	TArray<UBoxComponent*> GateTriggers;
	
	UPROPERTY(VisibleAnywhere, Category = "Mesh", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = "Trigger", meta = (AllowPrivateAccess = true))
	UBoxComponent* Trigger;

	UPROPERTY(EditAnywhere, Category = "State", meta = (AllowPrivateAccess = true))
	bool bNoBattle;

	UPROPERTY(EditAnywhere, Category = "Spawn", meta = (AllowPrivateAccess = true))
	float EnemySpawnTime;
	
	UPROPERTY(EditAnywhere, Category = "Spawn", meta = (AllowPrivateAccess = true))
	float ItemBoxSpawnTime;
	
	FTimerHandle SpawnNPCTimerHandle = {};
	FTimerHandle SpawnItemBoxTimerHandle = {};

};
