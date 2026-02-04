// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PLayer.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"

#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

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

}

// Called when the game starts or when spawned
void ACPP_PLayer::BeginPlay()
{
	Super::BeginPlay();
	if (APlayerController* PC = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MI_Player, 0);
		}
	}
}

// Called every frame
void ACPP_PLayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_PLayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent); //unreal engine c++ setup new input system ohttps://www.youtube.com/watch?v=I-VBDt6O2gM

	if (UEnhancedInputComponent* input_player = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		input_player->BindAction(IA_Interaction, ETriggerEvent::Started, this, &ACPP_PLayer::interact_objet);
	}
	

}
void ACPP_PLayer::interact_objet(const FInputActionValue& Value)
{
	printf("Action effectuer");
	UE_LOG(LogTemp, Warning, TEXT("Interaction !"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green,TEXT("Action effectuee !"));
	}
}

