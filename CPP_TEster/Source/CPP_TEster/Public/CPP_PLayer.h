#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "CPP_PLayer.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class UStaticMeshComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class CPP_TESTER_API ACPP_PLayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_PLayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	USceneComponent* Root;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraFPS;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Viseur;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputMappingContext* MI_Player;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* IA_Interaction;

	//void InteractEvent(const FInputActionValue& Value);
	UFUNCTION()
	void interact_objet(const FInputActionValue& Value);
};
