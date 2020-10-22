// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveActor.h"

// Sets default values
AInteractiveActor::AInteractiveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	//RootComponent = StaticMeshComponent;
	StaticMeshComponent->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void AInteractiveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractiveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//�������� 
	//StaticMeshComponent->AddRelativeRotation(FRotator(0.0f, 1.0f, 0.0f));

	//������ ���� 
	FVector Color(0.0f, 0.0f, 0.0f);

	/*���� ����� ��������
	��� �������� ����� ����� �������� 1 (��� ��� �������, 0 ������� ����� ��� None)
	����� �� ������ ��� None � �������� 0 �� �������� 1, Actor Color ��������� �������� 1

	*/
	if (ActorColor & (uint8)EActorColor::ECB_Red + 1)
	{
		Color.X = RedIntensity;
		UE_LOG(LogTemp, Warning, TEXT("red"));
	}
	if (ActorColor & (uint8)EActorColor::ECB_Green + 1)
	{
		Color.Y = GreenIntensity;
		UE_LOG(LogTemp, Warning, TEXT("green"));
	}
	if (ActorColor & (uint8)EActorColor::ECB_Blue + 2)
	{
		Color.Z = BlueIntensity;
		UE_LOG(LogTemp, Warning, TEXT("blue"));
	}
	StaticMeshComponent->SetVectorParameterValueOnMaterials(FName("Color"), Color);

}

