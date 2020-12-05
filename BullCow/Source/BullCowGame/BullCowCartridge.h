// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	
	// Your declarations go below!
	virtual void StartGame(int);
	virtual void SetHiddenWord(const FString& HiddenWord);
	virtual bool CheckInput(const FString& Input);
	virtual bool CheckHP();
	virtual FString GetHiddenWord();
private:
	FString HiddenWord;
	int vidas;
	
};
