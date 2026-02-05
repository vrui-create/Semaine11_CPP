// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Porte.h"

// Sets default values
ACPP_Porte::ACPP_Porte()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TurnDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Porte"));
	RootComponent = TurnDoor;
	Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Porte"));
	Cube->SetupAttachment(TurnDoor);
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Meshes/MyMesh.MyMesh")
	Rotate_Z = 0;
	Activaction = false;
}

// Called when the game starts or when spawned
void ACPP_Porte::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Porte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ACPP_Porte::TurnDoorRR();
	

}

void ACPP_Porte::TurnDoorRR()
{
	if(Activaction && Rotate_Z<=90)TurnDoor->SetRelativeRotation(FRotator(0.0f, 0.0f, Rotate_Z));
	if(!Activaction && Rotate_Z>=0)TurnDoor->SetRelativeRotation(FRotator(0.0f, 0.0f, Rotate_Z));	
}

void ACPP_Porte::ChangeBool_TurnRound()
{
	if (Activaction)Activaction = false;
	else Activaction = true;
}
