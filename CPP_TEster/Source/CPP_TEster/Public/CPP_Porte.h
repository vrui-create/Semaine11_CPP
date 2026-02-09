// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
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

	UFUNCTION(BlueprintCallable, Category = "Code")
	void MotsPasse(int Premier, int Deuxieme, int Troisieme, int Quatrieme);

	UFUNCTION(BlueprintCallable, Category = "Code")
	void Clear_Code();

	UFUNCTION(BlueprintCallable, Category = "Code")
	void Sortir_Code();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* TurnDoor;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Cube;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> widgetRef;

	UPROPERTY()
	class UUserWidget* UI_Coding;




	UPROPERTY(EditAnywhere)
	int C1 = 0; int C2 = 0; int C3 = 0; int C4 = 0;
	UPROPERTY(EditAnywhere)
	bool Porte_Fermer;


	bool Activaction;
	float Rotate_Z;

	void TurnDoorRR();

	void ChangeBool_TurnRound();


};
