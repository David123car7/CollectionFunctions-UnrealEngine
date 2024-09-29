/*
Returns the player velocity
*/
float AFirstPersonController::GetPlayerVelocity() {
	FVector velocity = GetVelocity();
	return velocity.Length();
}

/*
Returns the height of the capsuleComponent 
 */
float AFirstPersonController::GetPlayerHeight() {
	return GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
}

/*
Returns the APlayerController of the player
*/
APlayerController* AFirstPersonController::GetPlayerController() {
	return Cast<APlayerController>(GetController());
}

/*
Sets the player speed 
*/
void AFirstPersonController::SetPlayerSpeed(float speed) {
	GetCharacterMovement()->MaxWalkSpeed = speed;
}
