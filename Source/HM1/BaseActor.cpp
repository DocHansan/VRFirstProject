// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseActor.h"

// Sets default values
ABaseActor::ABaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	//RootComponent = StaticMeshComponent;
	StaticMeshComponent->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void ABaseActor::BeginPlay()
{
	Super::BeginPlay();
	
}

FVector ABaseActor::ChangeColor(FVector Color)
{
	return FVector(1.0f, 1.0f, 1.0f);
}

// Called every frame
void ABaseActor::Tick(float DeltaTime)
{
	

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
	Super::Tick(DeltaTime);

}

