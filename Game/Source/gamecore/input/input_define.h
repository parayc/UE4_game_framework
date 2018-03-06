// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "gamecore_minimal.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define CONTROLLER_PAWN_AXIS_HISTORY_SIZE 120
#define CONTROLLER_PAWN_AXIS_SAMPLING_INTERVAL 0.15f
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DECLARE_MULTICAST_DELEGATE_OneParam(delegate_axis_event, float);
DECLARE_MULTICAST_DELEGATE(delegate_action_event);

//////////////////////////////////////////////////////////////////////////
//-->ytb Temporary : Axis�̺�Ʈ�� ���� ����� ANxnExt_ControllerPawn::SetupPlayerInputComponent�� ���� Binding ������(�ڵ�ȭ �ؾ��� ��� ���� �����ؾ� �� ��)
//                   Action �̺�Ʈ�� ��� Enum�� �߰����ָ� �ڵ����� �̺�Ʈ�� Binding �ȴ�. ActionName�� Enum Value(ex:skill_0) ����
#define DEFAULT_AXIS_EVENT_MOVEFORWARDBACK		TEXT("move_forward_back")
#define DEFAULT_AXIS_EVENT_MOVERIGHTLEFT 		TEXT("move_right_left")

#define DEFAULT_AXIS_EVENT_TOUCH		 		TEXT("touch")
#define DEFAULT_AXIS_EVENT_PINCH			 	TEXT("pinch")

UENUM(BlueprintType)
enum class E_action_event_type : uint8
{
	skill_0 = 0 			UMETA(DisplayName = "skill_0"),
	skill_1					UMETA(DisplayName = "skill_1"),
	skill_2 				UMETA(DisplayName = "skill_2"),
	skill_3 				UMETA(DisplayName = "skill_3"),
	skill_4 				UMETA(DisplayName = "skill_4"),

	test_event_0			UMETA(DisplayName = "test_btn"), // Test Event
	Max
};
