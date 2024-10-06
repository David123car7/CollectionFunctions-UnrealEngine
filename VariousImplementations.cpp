
/*
This function implements a simple raycast

Explanation: 
Start trace is where the ray will start 
DirectionVector is the direction the ray will be casted, in this example will be casted upwards
End trace is where the ray will end, the directionVector is multiplied by the distance the ray will cast, if you are not sure about the distance (for example implementing this in a gun) put a high value 
*/
int AFirstPersonController::Raycast() {
	FHitResult* hitResult = new FHitResult();
	FVector startTrace = GetCapsuleComponent()->GetComponentLocation();
	FVector directionVector = GetCapsuleComponent()->GetUpVector(); 
	FVector endTrace = (directionVector * 5000.f) + startTrace; 
	FCollisionQueryParams* CQP = new FCollisionQueryParams();

	if (GetWorld()->LineTraceSingleByChannel(*hitResult, startTrace, endTrace, ECC_Visibility, *CQP)) { //(its used to check if the ray was casted)
		DrawDebugLine(GetWorld(), startTrace, endTrace, FColor(255, 0, 0), true); 
		if (hitResult->GetActor() != NULL) { //if the ray hit something 
			return 1;
		}
		else
			return 0;
	}

	return -1; //If returns -1 means the raycast was not casted (it will probably never happen if things are working well)
}

/*
This function returns the surface which player currently stands

Can be used for example to create footsteps sounds, changing the sounds when the player changes surface (from dirt to sand for example).
Docs to the creation of the UPhysicalMaterial: https://dev.epicgames.com/documentation/en-us/unreal-engine/physical-materials-user-guide-for-unreal-engine?application_version=5.4
*/
EPhysicalSurface AFirstPersonController::GetPlayerSurface() {
	FHitResult hitResult;
	FVector startTrace = GetCapsuleComponent()->GetComponentLocation();
	FVector downVector = GetCapsuleComponent()->GetUpVector();
	FVector endTrace = (downVector * -1000.f) + startTrace; //5000 is range of the ray
	FCollisionQueryParams* CQP = new FCollisionQueryParams();
	CQP->bReturnPhysicalMaterial = true;

	if (GetWorld()->LineTraceSingleByChannel(hitResult, startTrace, endTrace, ECC_Visibility, *CQP)) { 
		DrawDebugLine(GetWorld(), startTrace, endTrace, FColor(255, 0, 0), true);
		auto physMat = hitResult.PhysMaterial;
		if (physMat != NULL)
			return UGameplayStatics::GetSurfaceType(hitResult);
	}

	return SurfaceType_Default; 
}
