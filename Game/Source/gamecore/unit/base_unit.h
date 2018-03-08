// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "gamecore_minimal.h"

#include "GameFramework/Pawn.h"
#include "Components/SkeletalMeshComponent.h"

#include "base_unit.generated.h"

REGIIST_OBJECTPOOLTYPE(A_base_unit, OBJECT_POOL_DEFAULT_SIZE)

UCLASS()
class GAMECORE_API A_base_unit : public APawn
{
	GENERATED_BODY()
	
public:	
	A_base_unit(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(Category = base_unit, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	uint32 m_ui_uniq_index = 0;

protected:
	UPROPERTY(Category = base_unit, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* m_p_root_scene_componenet = nullptr;

	UPROPERTY(Category = base_unit, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* m_p_capsule_componenet = nullptr;

	UPROPERTY(Category = base_unit, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* m_p_root_mesh_componenet = nullptr;

	UPROPERTY(Category = base_unit, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class U_unit_movement_component* m_p_movement_component = nullptr;

	UPROPERTY(Category = base_unit, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class U_unit_anim_instance* m_p_anim_instance = nullptr;

private:
	TMap<int32, class USkeletalMeshComponent*> m_map_child_mesh;

public:
	virtual void _initialize(uint32 _ui_uniq_index);
	virtual void _reset();

	//--------------------------------------------------------------------------------------------------------------------------------
	// anim_instance
public:
	void set_anim_instance(const FString& _str_path);

private:
	void load_complite_anim_instance(const FStringAssetReference& _AssetRef, UClass* _p_class, int32 _i_custom_index);
	void load_fail_anim_instance(const FStringAssetReference& _AssetRef, UClass* _p_class, int32 _i_custom_index);

	//--------------------------------------------------------------------------------------------------------------------------------
	// mesh
public:
	//void regist_cdo_mesh_componenet(int32 _ui_index, USkeletalMeshComponent* _p_mesh_componenet);
	void change_mesh(int32 _ui_index, const FString& _str_path);
	
private:
	void load_complite_mesh(const FStringAssetReference& _AssetRef, UClass* _p_class, int32 _i_custom_index);
	void load_fail_mesh(const FStringAssetReference& _AssetRef, UClass* _p_class, int32 _i_custom_index);
	//--------------------------------------------------------------------------------------------------------------------------------
	//~ Begin UObject Interface
	// virtual void PostInitProperties() override;	�ν��Ͻ��� �����̳� ���� ������Ƽ�� �����ϱ� ����, �־��� ������Ʈ�� ���� �ν��Ͻ� �����Ϳ��� ���� �ε��ϱ⵵ �մϴ�
	// virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override; �����Ϳ��� ������Ƽ ����� ȣ��
};
