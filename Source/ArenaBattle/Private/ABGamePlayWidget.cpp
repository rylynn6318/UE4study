// Fill out your copyright notice in the Description page of Project Settings.


#include "ABGamePlayWidget.h"
#include "Components/Button.h"
#include "ABPlayerController.h"

void UABGamePlayWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ResumeButton = Cast<UButton>(GetWidgetFromName(TEXT("btnResume")));
	if (ResumeButton != nullptr)
	{
		ResumeButton->OnClicked.AddDynamic(this, &UABGamePlayWidget::OnResumeClicked);
	}

	ReturnToTitleButton = Cast<UButton>(GetWidgetFromName(TEXT("btnReturnToTitle")));
	if (ReturnToTitleButton != nullptr)
	{
		ReturnToTitleButton->OnClicked.AddDynamic(this, &UABGamePlayWidget::OnReturnToTitleClicked);
	}

	RetryGameButton = Cast<UButton>(GetWidgetFromName(TEXT("btnRetryGame")));
	if (RetryGameButton != nullptr)
	{
		RetryGameButton->OnClicked.AddDynamic(this, &UABGamePlayWidget::OnRetryGameClicked);
	}
}

void UABGamePlayWidget::OnResumeClicked()
{
	auto ABPlayerController = Cast<AABPlayerController>(GetOwningPlayer());
	ABCHECK(ABPlayerController != nullptr);

	RemoveFromParent();

	ABPlayerController->ChangeInputMode(true);
	ABPlayerController->SetPause(false);
}

void UABGamePlayWidget::OnReturnToTitleClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("Title"));
}

void UABGamePlayWidget::OnRetryGameClicked()
{
	auto ABPlayerController = Cast<AABPlayerController>(GetOwningPlayer());
	ABCHECK(ABPlayerController != nullptr);
	ABPlayerController->RestartLevel();
}