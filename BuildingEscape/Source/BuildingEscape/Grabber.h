// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
	float Reach = 100.f; // how far ahead of the player can we reach in cm

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	//Ray-cast and Grab whats in reach
	void Grab();

	//Called when Grab is released
	void Release();
	
	//find (assumed) attached physics handle
	void FindPhysicsHandleComponent();

	//Setup (assumed) Input Component
	void SetupInputComponent();

	//Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	//Get the start of the ray-cast
	FVector GetReachLineStart();

	//Returns the end of the ray-cast
	FVector GetReachLineEnd();
};
