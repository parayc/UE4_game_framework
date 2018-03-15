/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
///			Copyright 2017 (C) Bruno Xavier B. Leite
//////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "UFSM.h"
#include "UFSMGraphNode.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class UFSMGraph;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UCLASS()
class UFSMGraphNode : public UEdGraphNode {
	GENERATED_UCLASS_BODY()
	friend class UFSMGraph;
private:
	virtual void AllocateDefaultPins() override;
	//
	virtual FLinearColor GetNodeTitleColor() const override;
	virtual bool CanDuplicateNode() const override {return false;}
	virtual bool CanUserDeleteNode() const override {return false;}
	virtual bool ShowPaletteIconOnNode() const override {return true;}
	virtual FSlateIcon GetIconAndTint(FLinearColor& OutColor) const override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	//
	UEdGraphPin* ParentPin;
	UEdGraphPin* ChildPin;
	//
	UPROPERTY()
	const UStateMachineComponent* FSM;
	//
	UPROPERTY()
	float Time = 0;
public :
	void SetupNode(const FIntPoint &NodePosition, const FIntPoint &NodeSize, const FString &Title, const UStateMachineComponent* FSMC);
	void AddChild(UFSMGraphNode* ChildNode);
	void UpdateNode();
	void ClearStats();
	//
	virtual UEdGraphPin* GetParentPin() const;
	virtual UEdGraphPin* GetChildPin() const;
	//
	//
	UPROPERTY()
	FString NodeTitle;
	//
	UPROPERTY()
	FString ReplicateStateID = FString(TEXT("Replicate State ID: "));
	//
	UPROPERTY()
	FString ReplicatePreviousStateID = FString(TEXT("Replicate Previous ID: "));
	//
	UPROPERTY()
	FString ReplicateStateTime = FString(TEXT("Replicate State Time: "));
	//
	UPROPERTY()
	FString Debug = FString(TEXT("Debug: "));
	//
	UPROPERTY()
	FString StateID = FString(TEXT("State ID: "));
	//
	UPROPERTY()
	FString StateTime = FString(TEXT("State Time: "));
	//
	UPROPERTY()
	FString IsCurrentState = FString(TEXT("Is Current State: "));
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////