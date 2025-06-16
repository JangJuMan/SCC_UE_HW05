// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class SCC_UE_HW05_API AMyActor : public AActor
{
	GENERATED_BODY()
	
private:
	FVector start;
	int32 evCnt;
	float totDist;		// float 이어야 하는거 아닌가?

public:	
	// Sets default values for this actor's properties
	AMyActor() : start(0, 0, 0), evCnt(0), totDist(0) {};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float distance(FVector first, FVector second);
	void move();
	int32 step();
	void createEvent();

};
