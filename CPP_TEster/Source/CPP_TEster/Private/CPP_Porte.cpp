// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Porte.h"
#include "Blueprint/UserWidget.h"

// Sets default values
ACPP_Porte::ACPP_Porte()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TurnDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurneRound"));
	RootComponent = TurnDoor;
	Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Porte"));
	Cube->SetupAttachment(TurnDoor);
		
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/FBX/FBX_CUBE.FBX_CUBE")); // permet de setup la porte

	Cube->SetRelativeLocation(FVector(0.0f, 100.0f, 100.0f));
	Cube->SetRelativeScale3D(FVector(0.1f, 1.0f, 1.0f));

	if (MeshAsset.Succeeded())
	{
		Cube->SetStaticMesh(MeshAsset.Object);
	}
	
	Rotate_Z = 0;
	Activaction = false;

}

// Called when the game starts or when spawned
void ACPP_Porte::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(widgetRef))
	{
		UI_Coding = CreateWidget<UUserWidget>(GetWorld(), widgetRef);
	}
}

// Called every frame
void ACPP_Porte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ACPP_Porte::TurnDoorRR();
	

}

void ACPP_Porte::MotsPasse(int Premier, int Deuxieme, int Troisieme, int Quatrieme)
{
	if (C1 == Premier && C2 == Deuxieme && C3 == Troisieme && C4== Quatrieme)
	{

	}
}

void ACPP_Porte::Clear_Code()
{
	C1 = C2 = C3 = C4 = 0;
}

void ACPP_Porte::Sortir_Code()
{
	if (IsValid(UI_Coding))
	{
		UI_Coding->RemoveFromParent();
	}
}

void ACPP_Porte::TurnDoorRR()
{
	
	if (Activaction && Rotate_Z <= 89) 
	{
		Rotate_Z += 1;
		TurnDoor->SetRelativeRotation(FRotator(0.0f, Rotate_Z, 0.0f));
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Blue, FString::Printf(TEXT("RR : %f"), Rotate_Z));
		}
	}
	if (!Activaction && Rotate_Z >= 1) 
	{
		Rotate_Z -= 1;
		TurnDoor->SetRelativeRotation(FRotator(0.0f, Rotate_Z, 0.0f));
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Blue, FString::Printf(TEXT("RR : %f"), Rotate_Z));
		}
	}
	
}

void ACPP_Porte::ChangeBool_TurnRound()
{
	if (!Porte_Fermer)
	{
		if (Activaction)Activaction = false;
		else Activaction = true;
	}
	else if(IsValid(UI_Coding))
	{
		UI_Coding->AddToViewport();
	}
}


