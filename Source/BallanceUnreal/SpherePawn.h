#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Engine/StaticMeshActor.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h" // Include for UGameplayStatics
#include "SpherePawn.generated.h"


UCLASS()
class BALLANCEUNREAL_API ASpherePawn : public APawn
{
    GENERATED_BODY()

public:
    ASpherePawn();

    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // Input handling
    void MoveLongitudinally(float Value);
    void MoveLaterally(float Value);
    void Jump();
    void Dash();
    void LookUp(float Value);
    void LookRight(float Value);

    

    void ResetJump(); // Declare the ResetJump function
    void RestartGame(); // Function to restart the game

protected:
    virtual void BeginPlay() override;


private:
    FTimerHandle JumpCooldownTimerHandle; // Timer handle for managing jump cooldown
    bool bCanJump = true; // Flag to determine if the pawn can jump

private:
    void InitializeDefaultPawnInputBindings(); // Declare the function

private:
    // Sphere Component for collision and physics simulation
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    USphereComponent* SphereComponent;

    // Static Mesh for the visual representation of the ball
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    UStaticMeshComponent* BallMesh;

    // Spring Arm and Camera for following the ball
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    USpringArmComponent* SpringArm;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    UCameraComponent* Camera;

    // Movement Component
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    UFloatingPawnMovement* FloatingPawnMovement;

    // Movement Input functions
    void MoveForward(float Value);
    void MoveRight(float Value);

    // Input variables
    float InputLongitude; // For forward/backward movement
    float InputLatitude;  // For left/right movement

    // Jumping and dashing variables
    bool bInContact;  // True if the ball is on the ground
    float JumpForce;
    float DashForce;
    float MaximumSpeed;
    float ControllerForce;
    float DashTimer;
};
