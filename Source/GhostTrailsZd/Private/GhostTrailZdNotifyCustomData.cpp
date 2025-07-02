// Copyright 2025 JinraiMac. All Rights Reserved.

#include "GhostTrailZdNotifyCustomData.h"
#include "GhostTrail2dCustomData.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Notifies/PaperZDAnimNotify.h"
#include "PaperZDCharacter.h"
#include "PaperZDAnimInstance.h"
#include "PaperZDAnimBPGeneratedClass.h"


void UGhostTrailZdNotifyCustomData::OnReceiveNotify_Implementation(UPaperZDAnimInstance* OwningInstance /* = nullptr */) const
{
	Super::OnReceiveNotify_Implementation(OwningInstance);

	if (OwningInstance)
	{
		APaperZDCharacter* SpriteComponentOwner = OwningInstance->GetPaperCharacter();

		FTransform Transform = SpriteComponentOwner->GetTransform();

		AGhostTrail2dCustomData* trailActor = SpriteComponentOwner->GetWorld()->SpawnActorDeferred<AGhostTrail2dCustomData>(TrailClass, Transform, SpriteComponentOwner, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

		trailActor->TrailMaterials = TrailMaterials;
		trailActor->TrailFlipbookComponent = SpriteComponentOwner->GetSprite();
		trailActor->TimeLineCurve = TimeLineCurve;
		trailActor->CustomDataIndex = CustomDataIndex;
		trailActor->bShouldRenderCustomDepth = bShouldRenderCustomDepth;

		trailActor->GetRootComponent()->AddLocalTransform(TransformOffset);

		UGameplayStatics::FinishSpawningActor(trailActor, Transform);
	}
}

FName UGhostTrailZdNotifyCustomData::GetDisplayName_Implementation() const
{
	return FName("GhostTrail CustomData");
}