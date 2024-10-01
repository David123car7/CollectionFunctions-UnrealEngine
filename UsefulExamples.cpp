/*
THIS IS NOT A FILE WITH FUNCTIONS

This file contains examples of implementations in C++ that can be useful to lear & use.
 */


/*
In this example the class is a "Game Controller Class" and it acesses a "Character Controller Class" (AFirstPersonController))

To use the code just replace the "AFirstPersonController" for your class
*/
#pragma region Acessing a class from a different class

#pragma region .header file
UPROPERTY() AFirstPersonController* firstPersonController;
#pragma endregion

#pragma region .cpp file
void AGameController::BeginPlay() {
    firstPersonController = Cast<AFirstPersonController>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)); //0 because there is only one player
}
#pragma endregion

#pragma endregion

