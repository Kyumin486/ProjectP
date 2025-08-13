// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/PickUps/WarriorPickUpBase.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"

// Sets default values
AWarriorPickUpBase::AWarriorPickUpBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PickUpCollisionSphere = CreateDefaultSubobject<USphereComponent>("PickUpCollisionSphere");
	SetRootComponent(PickUpCollisionSphere);
	PickUpCollisionSphere->InitSphereRadius(50.f);
	PickUpCollisionSphere->OnComponentBeginOverlap.AddUniqueDynamic(this,&ThisClass::OnPickUpCollisionSphereBeginOverlap);
	PickUpCollisionSphere->OnComponentEndOverlap.AddUniqueDynamic(this, &ThisClass::OnPickUpCollisionSphereEndOverlap);
	

	FloatingItemInfoWidget = CreateDefaultSubobject<UWidgetComponent>("FloatingItemInfoWidget");
	FloatingItemInfoWidget->SetupAttachment(GetRootComponent());

}

void AWarriorPickUpBase::OnPickUpCollisionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void AWarriorPickUpBase::OnPickUpCollisionSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}







