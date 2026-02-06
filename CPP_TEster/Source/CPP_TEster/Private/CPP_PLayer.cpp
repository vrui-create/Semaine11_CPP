// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PLayer.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"

#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

#include "DrawDebugHelpers.h"

#include "CPP_Porte.h"

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
	CameraFPS->bUsePawnControlRotation = true;

	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = true;
	bUseControllerRotationRoll = false;

	//unreal engine c++ setup new input system ohttps://www.youtube.com/watch?v=I-VBDt6O2gM
	
}

// Called when the game starts or when spawned
void ACPP_PLayer::BeginPlay()
{
	Super::BeginPlay();
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Salut joueur !"));
	if (APlayerController* PC = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("MI_Mapping, Fonctionne"));
			Subsystem->AddMappingContext(MI_Player, 0);
		}

		bUseControllerRotationYaw = true;
		bUseControllerRotationPitch = true;
		bUseControllerRotationRoll = false;
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
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Green, TEXT("SetupPlayerInputComponent fonctionne"));
	if (UEnhancedInputComponent* Input_Player = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Green, TEXT("UEnhancedInputComponent, Fonctionne"));

		Input_Player->BindAction(IA_Interaction, ETriggerEvent::Started, this, &ACPP_PLayer::InteractEvent_RAG);
		Input_Player->BindAction(IA_Move_player, ETriggerEvent::Triggered, this, &ACPP_PLayer::MovePlayer);
		Input_Player->BindAction(IA_Look_player, ETriggerEvent::Triggered, this, &ACPP_PLayer::Look_RT);
	}
}


void ACPP_PLayer::Set_CPP_Variable(float code_01, float code_02, float code_03, float code_04)
{
	GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Blue, FString::Printf(TEXT("code_01 : %f| code_02 : %f | code_03 : %f| code_04 : %f"), code_01, code_02,code_03, code_04));
}

//void ACPP_PLayer::InteractEvent(const FInputActionValue & Value)
void ACPP_PLayer::InteractEvent_RAG()
{
	FVector loc;
	FRotator rot;
	FHitResult OutHit;

	GetController()->GetPlayerViewPoint(loc, rot);

	FVector Start = loc;
	FVector End = Start + (rot.Vector() * 250);

	FCollisionQueryParams TraceParams;
	GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, TraceParams);
	DrawDebugLine(GetWorld(), Start, End, FColor::Orange, true, 10.0f);

	bool bHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, TraceParams);
	if (bHit)
	{
		ACPP_Porte* Porte = Cast<ACPP_Porte>(OutHit.GetActor());
		if (Porte)
		{
			
			Porte->ChangeBool_TurnRound();
		}
	}
}

void ACPP_PLayer::MovePlayer(const FInputActionValue& value)
{
	FVector2D MoveValue = value.Get<FVector2D>();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Blue, FString::Printf(TEXT("RRX : %f| RRY : %f"), MoveValue.X, MoveValue.Y));
	}
	const FVector Forward = GetActorForwardVector();
	const FVector Right = GetActorRightVector();
	AddMovementInput(Forward, MoveValue.X);
	AddMovementInput(Right, MoveValue.Y);
}

void ACPP_PLayer::Look_RT(const FInputActionValue& Value)
{
	const FVector2D LookAxis = Value.Get<FVector2D>();

	GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Blue, FString::Printf(TEXT("RRX : %f| RRY : %f"), LookAxis.X, LookAxis.Y));

	AddControllerYawInput(LookAxis.X);
	AddControllerPitchInput(-LookAxis.Y);
}