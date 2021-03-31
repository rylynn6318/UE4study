// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "ABGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FABCharacterData : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	FABCharacterData() : Level(1), MaxHP(100.0f), Attack(10.0f), DropExp(10), NextExp(30) {}

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	int32 Level;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	float MaxHP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	float Attack;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	int32 DropExp;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	int32 NextExp;
};

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UABGameInstance();

	virtual void Init() override;
	FABCharacterData* GetABCharacterData(int32 Level);

private:
	UPROPERTY()
	class UDataTable* ABCharacterTable;
};
