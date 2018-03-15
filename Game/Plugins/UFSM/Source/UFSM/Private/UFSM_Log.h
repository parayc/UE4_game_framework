/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
///			Copyright 2017 (C) Bruno Xavier B. Leite
//////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/WeakObjectPtr.h" 
#include "UFSM_Log.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DECLARE_LOG_CATEGORY_EXTERN(UFSM,Log,All);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define FFIND(Name) FindFunction(Name)

#define PIE_Warning(Message,Token) FMessageLog("PIE").Warning(FText::FromString(FString::Printf(TEXT("{FSM}:: %s --> "),*Message)))->AddToken(Token)
#define PIE_Error(Message,Token) FMessageLog("PIE").Error(FText::FromString(FString::Printf(TEXT("{FSM}:: %s --> "),*Message)))->AddToken(Token)
#define PIE_Critical(Token) FMessageLog("PIE").Message(EMessageSeverity::CriticalError)->AddToken(Token)
#define PIE_Message(Token) FMessageLog("PIE").Message(EMessageSeverity::Info)->AddToken(Token);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UENUM()
enum class ESeverity : uint8 {
	CriticalError		= 0,
	Error				= 1,
	Warning				= 2,
	Info				= 3
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UFSM_API void LOG_FSM(const bool Debug, const bool Logs, const float Duration, const FColor Color, const FString Message);
UFSM_API void LOG_PIE(const bool Debug, const ESeverity Severity, const UObject* Owner, const UFunction* Function, const FString Message = TEXT(""));
UFSM_API void LOG_PIE(const ESeverity Severity, const UObject* Owner, const UFunction* Function, const FString Message = TEXT(""));
UFSM_API void LOG_PIE(const UObject* Owner, const UFunction* Function, const FString Message = TEXT(""));
UFSM_API void LOG_PIE(const UFunction* Function, const UObject* Owner);
UFSM_API void LOG_PIE(const UFunction* Function);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////