// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BasePlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Both/PlayerHUD.h"
#include "Blueprint/UserWidget.h"
#include "../END2408.h"

ABasePlayer::ABasePlayer() {
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetRelativeLocation(FVector(0., 0., 60.));
	SpringArm->SetupAttachment(GetRootComponent() /*, Not needed unless we have to set something by it's SOCKET'*/);
	SpringArm->bUsePawnControlRotation = true;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(SpringArm);
	//PlayerCamera->SetRelativeLocation(FVector{ 0.f,80.f,90.f });

	gunClass = nullptr;
	PlayerHUD = nullptr;
}

void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	//Always call your parent
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Bind Rotation Function(s)
	PlayerInputComponent->BindAxis("TurnRight", this, &ABasePlayer::AddControllerYawInput);	
	
	// Bind Rotation Function(s)
	PlayerInputComponent->BindAxis("LookUp", this, &ABasePlayer::AddControllerPitchInput);

	// Bind Movement Function(s)
	PlayerInputComponent->BindAxis("MoveForward", this, &ABasePlayer::InputAxisMoveForward);

	PlayerInputComponent->BindAxis("Strafe", this, &ABasePlayer::Strafe);

	// Bind Shoot/Attack Function
	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &ABasePlayer::Shoot);

	// Bind Reload Function
	PlayerInputComponent->BindAction("ReloadInput",IE_Pressed, this ,&ABasePlayer::InputReload);
}

bool ABasePlayer::CanPickupHealth()
{
	return true;
}

void ABasePlayer::InputAxisMoveForward(float AxisValue) 
{
	AddMovementInput(FRotator(0.f, GetControlRotation().Yaw, 0.f).Vector(), AxisValue);
}

void ABasePlayer::Strafe(float value)
{
	FRotator MakeRotation = FRotator(0.f, GetControlRotation().Yaw, 0.f);
	AddMovementInput(FRotationMatrix(MakeRotation).GetScaledAxis(EAxis::Y), value);

	//AddMovementInput(FRotator(0.f, GetControlRotation().Yaw, 0.f).Vector().RightVector, value);
}

void ABasePlayer::InputReload()
{
	Reload();
}

void ABasePlayer::PlayerLost()
{
	UE_LOG(Game, Warning, TEXT("YOU LOSE"));
	RemoveUI();
	PlayerController->SetShowMouseCursor(true);
	OnPlayerLost.Broadcast();
}

void ABasePlayer::PlayerWin()
{
	UE_LOG(Game, Warning, TEXT("YOU WIN"));
	DisableInput(PlayerController);
	RemoveUI();
}

void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(PlayerHUD))
	{
		PlayerHUD_Widget = CreateWidget<UPlayerHUD>(GetWorld(), PlayerHUD);
		if (PlayerHUD_Widget != nullptr)
		{
			PlayerHUD_Widget->AddToViewport();
		}
	}
	
	Gun->OnAmmoChanged.AddDynamic(PlayerHUD_Widget, &UPlayerHUD::CodeSetAmmo);
	Gun->ReloadAmmo();
	HealthComponent->OnHurt.AddDynamic(PlayerHUD_Widget, &UPlayerHUD::CodeSetHealth);
	HealthComponent->OnDeath.AddDynamic(PlayerHUD_Widget, &UPlayerHUD::CodeSetHealth);
	HealthComponent->OnHeal.AddDynamic(PlayerHUD_Widget, &UPlayerHUD::CodeSetHealth);
}

void ABasePlayer::HandleDeath(float Ratio)
{
	Super::HandleDeath(Ratio);
	DisableInput(PlayerController);
}

void ABasePlayer::RemoveUI_Implementation()
{
	PlayerHUD_Widget->RemoveFromParent();
}