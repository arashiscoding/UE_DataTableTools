// Fill out your copyright notice in the Description page of Project Settings.

#include "DataTableToolsLibrary.h"
#include "Engine/DataTable.h"

void UDataTableToolsLibrary::UpdateDataTable(UDataTable* DataTable, const FString& CsvFileName, bool bEnableOnScreenDebugMessages)
{
	FString CsvFilePath = FPaths::ProjectDir() + CsvFileName;
	CsvFilePath = FPaths::ConvertRelativePathToFull(CsvFilePath);

	if(bEnableOnScreenDebugMessages)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::White, FString::Printf(TEXT("File path to search: \"%s\""), *CsvFilePath));
	}

	if(!FPaths::FileExists(CsvFilePath))
	{
		if(bEnableOnScreenDebugMessages)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::Printf(TEXT("\"%s\" is not found in \"%s\"."), *CsvFileName, *CsvFilePath));
		}
		
		return;
	}

	if(!DataTable)
	{
		if(bEnableOnScreenDebugMessages)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "Data Table is Missing!");
		}
		
		return;
	}

	FString NewCsvContent{};
	FFileHelper::LoadFileToString(NewCsvContent, *CsvFilePath);
	
	DataTable->CreateTableFromCSVString(NewCsvContent);

	if(bEnableOnScreenDebugMessages)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, FString::Printf(TEXT("\"%s\" updated successfully!"), *GetNameSafe(DataTable)));
	}
}
