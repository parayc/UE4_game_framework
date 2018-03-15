/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
///			Copyright 2017 (C) Bruno Xavier B. Leite
//////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "UFSM_Log.h"
#include "UFSMShared.h"

#if WITH_EDITOR
	#include "MessageLog.h"
	#include "TokenizedMessage.h"
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DEFINE_LOG_CATEGORY(UFSM);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UFSM_API void LOG_FSM(const bool Debug, const bool Logs, const float Duration, const FColor Color, const FString Message) {
	if (!Debug)  {return;} if (Logs) {UE_LOG(UFSM,Warning,TEXT("{FSM}:: %s"),*Message);}
	if (GEngine) {GEngine->AddOnScreenDebugMessage(-1,Duration,Color,FString::Printf(TEXT("{FSM}:: %s"),*Message));}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define LOCTEXT_NAMESPACE "Synaptech"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UFSM_API void LOG_PIE(const bool Debug, const ESeverity Severity, const UObject* Owner, const UFunction* Function, const FString Message) {
	if (!Debug)  {return;}
	if (!Function)  {return;}
	if (!Owner)  {return;}
	//
#if WITH_EDITOR
	FFormatNamedArguments ARG;
	FFormatArgumentValue AMessage = FText::FromString(Message);
	FFormatArgumentValue AFunction = Function->GetDisplayNameText();
	FFormatArgumentValue AInfo = FText::FromString(Function->GetFullName());
	FFormatArgumentValue APackage = FText::FromString(Owner->GetFullName());
	//
	ARG.Add(TEXT("Message"),AMessage);
	ARG.Add(TEXT("Function"),AFunction);
	ARG.Add(TEXT("Package"),APackage);
	ARG.Add(TEXT("Details"),AInfo);
	//
	const auto Token = FTextToken::Create(FText::Format(LOCTEXT("LOG_PIE","{Function}: [{Details} at ({Package})]"),ARG));
	const auto Silent = FTextToken::Create(FText::Format(LOCTEXT("LOG_PIE","{Function}: {Message} at ({Package})"),ARG));
	//
	switch (Severity) {
		case ESeverity::Info:
			PIE_Message(Silent); break;
		case ESeverity::Warning:
			PIE_Warning(Message,Token); break;
		case ESeverity::Error:
			PIE_Error(Message,Token); break;
		case ESeverity::CriticalError:
			PIE_Critical(Silent); break;
	default: break;}
#endif
}

UFSM_API void LOG_PIE(const ESeverity Severity, const UObject* Owner, const UFunction* Function, const FString Message) {
	LOG_PIE(true,Severity,Owner,Function,Message);
}

UFSM_API void LOG_PIE(const UObject* Owner, const UFunction* Function, const FString Message) {
	LOG_PIE(ESeverity::Warning,Owner,Function,Message);
}

UFSM_API void LOG_PIE(const UFunction* Function, const UObject* Owner) {
	LOG_PIE(Owner,Function,FString(TEXT("Something went wrong!")));
}

UFSM_API void LOG_PIE(const UFunction* Function) {
	LOG_PIE(ESeverity::Info,Function,Function,TEXT(""));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////