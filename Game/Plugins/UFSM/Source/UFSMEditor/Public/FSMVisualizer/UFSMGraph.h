/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
///			Copyright 2017 (C) Bruno Xavier B. Leite
//////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "GraphEditor.h"
#include "UFSMGraphNode.h"
#include "Runtime/Engine/Classes/EdGraph/EdGraph.h"
#include "UFSMGraph.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class FSMCustomDetails;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UCLASS()
class UFSMGraph : public UEdGraph {
	GENERATED_UCLASS_BODY()
	friend class FSMCustomDetails;
protected:
	UPROPERTY()
	const UStateMachineComponent* FSM;
	//
	UPROPERTY()
	TSet<const UEdGraphNode*> Selection;
public:
	UFSMGraphNode* const AddNode(const TCHAR* Name, const FIntPoint Position);
	void SelectNode(UEdGraphNode* const Node);
	//
	void Initialize(const UStateMachineComponent* FSMC);
	void UpdateGraph();
	void ClearGraph();
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
