// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "CPP_Porte.generated.h"

UCLASS()
class CPP_TESTER_API ACPP_Porte : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Porte();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* TurnDoor;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Cube;

	bool Activaction;
	float Rotate_Z;

	void TurnDoorRR();

	void ChangeBool_TurnRound();


};
