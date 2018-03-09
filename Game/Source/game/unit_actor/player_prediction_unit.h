// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "game_minimal.h"
#include "unit/base_unit.h"
#include "unit_actor/game_unit_define.h"
#include "player_prediction_unit.generated.h"

REGIIST_OBJECTPOOLTYPE(A_player_prediction_unit, OBJECT_POOL_DEFAULT_SIZE)

UCLASS()
class GAME_API A_player_prediction_unit : public A_base_unit
{
	GENERATED_BODY()
	
public:	
	A_player_prediction_unit(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	virtual void _initialize(uint32 _ui_uniq_index);
	virtual void _reset();

private:

	//~ Begin UObject Interface
	// virtual void PostInitProperties() override;	�ν��Ͻ��� �����̳� ���� ������Ƽ�� �����ϱ� ����, �־��� ������Ʈ�� ���� �ν��Ͻ� �����Ϳ��� ���� �ε��ϱ⵵ �մϴ�
	// virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override; �����Ϳ��� ������Ƽ ����� ȣ��
};