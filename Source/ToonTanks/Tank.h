// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
	
public:

	ATank();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Tick(float DeltaTime) override;
	void HandleDestruction();

	APlayerController* GetTankPlayerController() const  { return TankPlayerController; }

	bool bAlive = true;

protected:

	virtual void BeginPlay() override;


private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float speed = 200.0f;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurnRate = 50.0f;
	
	void Move(float value);
	void Turn(float value);

	APlayerController* TankPlayerController;

};