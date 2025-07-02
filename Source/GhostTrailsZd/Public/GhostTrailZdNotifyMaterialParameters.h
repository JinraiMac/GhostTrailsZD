// Copyright 2025 JinraiMac. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Notifies/PaperZDAnimNotify.h"
#include "Curves/CurveFloat.h"
#include "GhostTrail2dMaterialParameters.h"
#include "GhostTrailZdNotifyMaterialParameters.generated.h"

/**
 * UPaperZDAnimNotify class to spawn an AGhostTrail2dMaterialParameters and set values appropriately.
 */
UCLASS()
class GHOSTTRAILSZD_API UGhostTrailZdNotifyMaterialParameters : public UPaperZDAnimNotify
{
	GENERATED_BODY()

protected:
	//Override the native notify implementation
	void OnReceiveNotify_Implementation(UPaperZDAnimInstance* OwningInstance = nullptr) const override;
	FName GetDisplayName_Implementation() const override;

public:
	// Float curve used in timeline to update dynamic materials.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", Meta = (ExposeOnSpawn = true, DisplayName = "Effect Timeline"))
		UCurveFloat* TimeLineCurve = nullptr;

	// Materials to be dynamically updated on sprite.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", Meta = (ExposeOnSpawn = true, DisplayName = "Materials"))
		TArray<UMaterialInterface*> TrailMaterials;

	// Material parameter that is updated.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", Meta = (ExposeOnSpawn = true, DisplayName = "Material Parameter"))
		FName MaterialParameter = TEXT("Opacity");

	// AGhostTrail2dMaterialParameters class to be used in effect.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", Meta = (ExposeOnSpawn = true, DisplayName = "Ghost Trail"))
		TSubclassOf<AGhostTrail2dMaterialParameters> TrailClass = AGhostTrail2dMaterialParameters::StaticClass();

	// Offset transform for the effect
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", Meta = (ExposeOnSpawn = true, DisplayName = "Offset"))
		FTransform TransformOffset = FTransform();

	// Whether meshes should have render custom depth set.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", Meta = (ExposeOnSpawn = true, DisplayName = "Set Custom Depth"))
		bool bShouldRenderCustomDepth = true;
};