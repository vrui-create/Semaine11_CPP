// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Ball.h"

// Sets default values
ACPP_Ball::ACPP_Ball()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh_Sphere_Component"));
	RootComponent = USphere;

}

// Called when the game starts or when spawned
void ACPP_Ball::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Ball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

