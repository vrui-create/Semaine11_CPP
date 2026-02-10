// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "CPP_Porte.h"
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

	UPROPERTY(EditAnywhere, Category = "IA_Player_Input")
	class UInputMappingContext* MI_Player;

	UPROPERTY(EditAnywhere, Category = "IA_Player_Input")
	class UInputAction* IA_Interaction;

	UPROPERTY(EditAnywhere, Category = "IA_Player_Input")
	class UInputAction* IA_Move_player;

	UPROPERTY(EditAnywhere, Category = "IA_Player_Input")
	class UInputAction* IA_Look_player;

	UPROPERTY(EditAnywhere, Category = "IA_Player_Input")
	class UInputAction* IA_Jump_player;
	
	UPROPERTY(EditAnywhere, Category = "VARIABLE_VATS")
	float ForceJumping;


	UFUNCTION(BlueprintCallable)
	void Set_CPP_Variable(bool Activer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ACPP_Porte* CPP_PORTE_REF;

	bool ActionJoueur;
	 
	void InteractEvent_RAG();

	UFUNCTION(BlueprintCallable)
	void OuvrePorte();

	void jumping();

	void MovePlayer(const FInputActionValue& value);

	void Look_RT(const FInputActionValue& Value);
};
