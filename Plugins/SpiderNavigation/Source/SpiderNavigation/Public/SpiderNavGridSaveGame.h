//The MIT License
//
//Copyright(C) 2017 Roman Nix
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files(the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions :
//
//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//THE SOFTWARE.

#pragma once

#include "GameFramework/SaveGame.h"
#include "SpiderNavGridSaveGame.generated.h"

/** Describes relations between navigation points*/
USTRUCT()
struct FSpiderNavRelations
{
	GENERATED_BODY()

    /** Array of indexes of neighboring navigtaion points*/
	UPROPERTY()
	TArray<int32> Neighbors;
};

/**
 *  A USaveGame's extension to store navigation
 */
UCLASS()
class USpiderNavGridSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
    /** Locations of navigation points */
	UPROPERTY()
	TMap<int32, FVector> NavLocations;

    /** Normals of navigation points */
	UPROPERTY()
	TMap<int32, FVector> NavNormals;

    /** Relations between navigation points */
	UPROPERTY()
	TMap<int32, FSpiderNavRelations> NavRelations;

    /** Name of save slot to store navigation grid */
	UPROPERTY()
	FString SaveSlotName;

    /** UserIndex to store navigation grid */
	UPROPERTY()
	uint32 UserIndex;

    /** Constructor */
	USpiderNavGridSaveGame();
};
