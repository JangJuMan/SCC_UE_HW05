// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	for (size_t i = 0; i < 10; ++i) {
		move();
		createEvent();
	}
	UE_LOG(LogTemp, Warning, TEXT("총 이동거리 : %.2f, 총 이벤트 발생 횟수 : %d회"), totDist, evCnt);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/* first ~ second 거리 리턴 */
float AMyActor::distance(FVector first, FVector second)
{
	return FVector(first - second).Size();
	
	// float dx = first.X - second.X;
	// float dy = first.Y - second.Y;
	// return FMath::Sqrt(dx * dx + dy * dy);

}
/* 좌표 이동 함수 */
void AMyActor::move()
{
	FVector first = start;
	FVector second = first + FVector(step(), step(), 0);
	float dist = distance(first, second);
	totDist += dist;
	start = second;
	UE_LOG(LogTemp, Warning, TEXT("좌표이동! (%.2f, %.2f, %.2f) -> (%.2f, %.2f, %.2f), 이동거리 : %.2f,  총 이동거리 : %.2f"), 
		first.X, first.Y, first.Z, second.X, second.Y, second.Z, dist, totDist);
}
/* 0 or 1 중 랜덤값을 리턴 */
int32 AMyActor::step()
{
	return FMath::RandRange(0, 1);
}

/* 50% 확률로 이벤트 발생 */
void AMyActor::createEvent()
{
	if (FMath::RandRange(0, 1))
	{
		UE_LOG(LogTemp, Warning, TEXT("Event Occured! EvCnt : %d"), ++evCnt);
	}
}

