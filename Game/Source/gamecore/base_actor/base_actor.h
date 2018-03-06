// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "gamecore_minimal.h"
#include "GameFramework/Actor.h"
#include "base_actor.generated.h"

UCLASS()
class GAMECORE_API A_base_actor : public AActor
{
	GENERATED_BODY()
	
public:	
	A_base_actor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(Category = Unit, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	uint32 m_ui_uniq_index = 0;

public:
	virtual void _initialize(uint32 _ui_uniq_index);
	virtual void _reset();

	FORCEINLINE uint32 get_uniq_index() { return m_ui_uniq_index; }

	//~ Begin UObject Interface
	// virtual void PostInitProperties() override;	�ν��Ͻ��� �����̳� ���� ������Ƽ�� �����ϱ� ����, �־��� ������Ʈ�� ���� �ν��Ͻ� �����Ϳ��� ���� �ε��ϱ⵵ �մϴ�
	// virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override; �����Ϳ��� ������Ƽ ����� ȣ��
};
