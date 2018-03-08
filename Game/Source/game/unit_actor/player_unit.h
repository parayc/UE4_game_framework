// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "gamecore_minimal.h"
#include "unit/base_unit.h"
#include "player_unit.generated.h"

REGIIST_OBJECTPOOLTYPE(A_player_unit, OBJECT_POOL_DEFAULT_SIZE)

UCLASS()
class GAME_API A_player_unit : public A_base_unit
{
	GENERATED_BODY()
	
public:	
	A_player_unit(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(Category = base_unit, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* Mesh;

public:
	virtual void _initialize(uint32 _ui_uniq_index);
	virtual void _reset();

private:
	void load_complite(const FStringAssetReference& _AssetRef, UClass* _p_class);
	void load_fail(const FStringAssetReference& _AssetRef, UClass* _p_class);
	//////////////////////////////////////////////////////////////////////////

	//~ Begin UObject Interface
	// virtual void PostInitProperties() override;	�ν��Ͻ��� �����̳� ���� ������Ƽ�� �����ϱ� ����, �־��� ������Ʈ�� ���� �ν��Ͻ� �����Ϳ��� ���� �ε��ϱ⵵ �մϴ�
	// virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override; �����Ϳ��� ������Ƽ ����� ȣ��
};
