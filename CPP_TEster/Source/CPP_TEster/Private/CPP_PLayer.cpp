// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PLayer.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ACPP_PLayer::ACPP_PLayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UCapsuleComponent* Capsule = GetCapsuleComponent();
	GetMesh()->SetupAttachment(Capsule);
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	Viseur = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Viseur"));
	Viseur->SetupAttachment(Capsule);

	CameraFPS = CreateDefaultSubobject<UCameraComponent>(TEXT("NAME_CAMERA_LOL"));
	CameraFPS->SetupAttachment(Capsule);

	//unreal engine c++ setup new input system ohttps://www.youtube.com/watch?v=I-VBDt6O2gM
	if(UEnhancedInputComponent* input = CastChecked< UEnhancedInputComponent>(PlayerInputComponent))

}

// Called when the game starts or when spawned
void ACPP_PLayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_PLayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_PLayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ACPP_PLayer::InteractEvent(const FInputActionValue& Value)
{

}