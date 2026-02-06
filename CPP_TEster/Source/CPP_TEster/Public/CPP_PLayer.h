// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "CPP_PLayer.generated.h"


class UCapsuleComponent;
class USkeletMeshComponent;
class UCameraComponent;

UCLASS()
class CPP_TESTER_API ACPP_PLayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_PLayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	USceneComponent* Root;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraFPS;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Viseur;

	UPROPERTY(EditAnywhere, Category = "UEnhancedInput")
	class UInputMappingContext* MI_Player;

	UPROPERTY(EditAnywhere, Category = "UEnhancedInput")
	class UInputAction* IA_Interaction;

	UPROPERTY(EditAnywhere, Category = "UEnhancedInput")
	class UInputAction* IA_Move_player;

	UPROPERTY(EditAnywhere, Category = "UEnhancedInput")
	class UInputAction* IA_Look_player;
	
	// Variable float exposée à Blueprint
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MyFloatValue;

	UFUNCTION(BlueprintCallable)
	void Set_CPP_Variable(float code_01, float code_02, float code_03, float code_04);

	 
	void InteractEvent_RAG();

	void MovePlayer(const FInputActionValue& value);

	void Look_RT(const FInputActionValue& Value);
};
