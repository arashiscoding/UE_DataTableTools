// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DataTableToolsLibrary.generated.h"

class UDataTable;

UCLASS()
class UDataTableToolsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	/**
	 * Updates the given Data Table with its corresponding csv file at runtime
	 * @param CsvFileName Name of the new csv file. Should be placed in the root folder of the project. Next to the 'Content' folder (Both in Development build and in Packaged build)
	 * @param bEnableOnScreenDebugMessages Show debug messages on screen if ENABLEALLSCREENMESSAGES console command has been enabled.
	 */
	UFUNCTION(BlueprintCallable)
	static void UpdateDataTable(UDataTable* DataTable, const FString& CsvFileName, bool bEnableOnScreenDebugMessages = true);
};
