// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGameMode.generated.h"

/**
 * 
 */
UCLASS()
class COOPGAME_API ASGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	
	FTimerHandle TimerHandle_BotSpawner;

	FTimerHandle TimerHandle_NextWaveStart;

	// Bots to spawn in a current wave
	int32 NroOfBotsToSpawn;

	int32 WaveCount;

	UPROPERTY(EditDefaultsOnly, Category= "GameMode")
	float TimeBetweenWaves;

	// Hook for BP to spawn a single bot
	UFUNCTION(BlueprintImplementableEvent, Category= "GameMode")
	void SpawnNewBot();

	void SpawnBotTimerElapsed();

	// Start spawning bots
	void StartWave();

	// Stop spawning bots
	void EndWave();

	// Set timer for next startwave
	void PrepareForNextWave();

	void CheckWaveState();

	void CheckAnyPlayerAlive();

	void GameOver();

public:

	ASGameMode();

	virtual void StartPlay() override;

	virtual void Tick(float DeltaSeconds) override;	
};
