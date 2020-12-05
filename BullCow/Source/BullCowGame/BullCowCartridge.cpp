// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

#include <string>

#include "SurfaceIterators.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    StartGame(0);
}

//2 morte
//0 Neutro
//1 vitoria
void UBullCowCartridge::StartGame(int enumVitoria) 
{
    if(enumVitoria == 0)
    {
        const FString HiddenWord = TEXT("Goku");
        SetHiddenWord(HiddenWord);
        vidas = 5;
        
        PrintLine(TEXT("Oi, eu sou goku!"));
        FString frase = "Tente advinhar a palavra de ";
        frase.Append(std::to_string(HiddenWord.Len()).c_str());
        frase.Append(" letras!");
        PrintLine(frase);
    }
    else if(enumVitoria == 1)
    {
        ClearScreen();
        PrintLine(TEXT("VITÓRIA!"));
        PrintLine(TEXT("Parabéns, você ganhou! Quer tentar de novo?"));   
    }
    else if(enumVitoria == 2)
    {
        ClearScreen();
        PrintLine(TEXT("E tu morreu."));
        PrintLine(TEXT("Vamos outra vez?"));
    }
}


void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    //Checa se ele está morto e tentando reiniciar o jogo.
    if(Input.Compare("Sim", ESearchCase::IgnoreCase) && vidas == 0)
        StartGame(0);
    else if(Input.Compare("Nao", ESearchCase::IgnoreCase) && vidas == 0)
        PrintLine(TEXT("ok, flwvlw"));

    //Checa se está vivo e respondeu certo
    //Respondeu certo
    if(CheckInput(Input))
    {
        StartGame(1);
    }
    //Respondeu errado e morreu
    else if(vidas == 0)
    {
        StartGame(2);
    }
    //Respondeu errado
    else
        PrintLine(TEXT("Tente outra vez, você é brasileiro"));
}

void UBullCowCartridge::SetHiddenWord(const FString& HiddenWord)
{
    this->HiddenWord = HiddenWord;
}

FString UBullCowCartridge::GetHiddenWord()
{
    return HiddenWord;
}

bool UBullCowCartridge::CheckInput(const FString& Input)
{
    if(Input.Compare(GetHiddenWord()) == 0)
    {
        PrintLine(TEXT("TU ACERTOU!"));
        return true;
    }

    if(!CheckHP())
    {
        return false;
    }
    PrintLine(TEXT("Nem é, errou feio, errou rude."));
    PrintLine(TEXT("E perdeu uma vida, btw"));
    return false;
}

bool UBullCowCartridge::CheckHP()
{
    vidas--;
    if(vidas == 0)
        return false;
    return true;
}
