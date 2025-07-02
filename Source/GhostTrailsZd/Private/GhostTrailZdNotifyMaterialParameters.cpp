// Copyright 2025 JinraiMac. All Rights Reserved.

#include "GhostTrailZdNotifyMaterialParameters.h"
#include "GhostTrail2dMaterialParameters.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Notifies/PaperZDAnimNotify.h"
#include "PaperZDCharacter.h"
#include "PaperZDAnimInstance.h"
#include "PaperZDAnimBPGeneratedClass.h"


void UGhostTrailZdNotifyMaterialParameters::OnReceiveNotify_Implementation(UPaperZDAnimInstance* OwningInstance /* = nullptr */) const
{
	Super::OnReceiveNotify_Implementation(OwningInstance);

	if (OwningInstance)
	{
		APaperZDCharacter* SpriteComponentOwner = OwningInstance->GetPaperCharacter();

		FTransform Transform = SpriteComponentOwner->GetTransform();

		AGhostTrail2dMaterialParameters* trailActor = SpriteComponentOwner->GetWorld()->SpawnActorDeferred<AGhostTrail2dMaterialParameters>(TrailClass, Transform, SpriteComponentOwner, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

		trailActor->TrailMaterials = TrailMaterials;
		trailActor->TrailFlipbookComponent = SpriteComponentOwner->GetSprite();
		trailActor->TimeLineCurve = TimeLineCurve;
		trailActor->MaterialParameter = MaterialParameter;
		trailActor->bShouldRenderCustomDepth = bShouldRenderCustomDepth;

		trailActor->GetRootComponent()->AddLocalTransform(TransformOffset);

		UGameplayStatics::FinishSpawningActor(trailActor, Transform);
	}
}

FName UGhostTrailZdNotifyMaterialParameters::GetDisplayName_Implementation() const
{
	return FName("GhostTrail MaterialParameters");
}