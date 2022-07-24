// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GConfigBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class UGConfigBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

private:
	static FString GetConfigPath(const FString& FileName);
	

public:
	UFUNCTION(BlueprintCallable,  Category = "GConfig")
	static float AddDirectoriesToCopy(FString& DirectoryPath);

	// 加载数据部分
	UFUNCTION(BlueprintCallable, BlueprintPure, Meta=(Displayname="LoadConfig(String)"), Category = "GConfig")
	static FString LoadConfig(const FString FileName, const FString Section, const FString Key);

	UFUNCTION(BlueprintCallable, BlueprintPure, Meta=(Displayname="LoadConfig(Text)"), Category = "GConfig")
	static FText LoadConfigText(const FString FileName, const FString Section, const FString Key);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Meta=(Displayname="LoadConfig(Int)"), Category = "GConfig")
	static int32 LoadConfigInt(const FString FileName, const FString Section, const FString Key);

	UFUNCTION(BlueprintCallable, BlueprintPure, Meta=(Displayname="LoadConfig(Float)"), Category = "GConfig")
	static float LoadConfigFloat(const FString FileName, const FString Section, const FString Key);

	UFUNCTION(BlueprintCallable, BlueprintPure, Meta=(Displayname="LoadConfig(Double)"), Category = "GConfig")
	static double LoadConfigDouble(const FString FileName, const FString Section, const FString Key);

	UFUNCTION(BlueprintCallable, BlueprintPure, Meta=(Displayname="LoadConfig(Bool)"), Category = "GConfig")
    static bool LoadConfigBool(const FString FileName, const FString Section, const FString Key);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Meta=(Displayname="LoadConfig(Array[String])"), Category = "GConfig")
	static TArray<FString> LoadConfigArray(const FString FileName, const FString Section, const FString Key);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Meta=(Displayname="LoadConfig(SingleLineArray[String])"), Category = "GConfig")
	static TArray<FString> LoadConfigSingleLineArray(const FString FileName, const FString Section, const FString Key);

	UFUNCTION(BlueprintCallable, BlueprintPure, Meta=(Displayname="LoadConfig(Color)"), Category = "GConfig")
	static FColor LoadConfigColor(const FString FileName, const FString Section, const FString Key);

	UFUNCTION(BlueprintCallable, BlueprintPure, Meta=(Displayname="LoadConfig(Vector2D)"), Category = "GConfig")
	static FVector2D LoadConfigVector2D(const FString FileName, const FString Section, const FString Key);

	UFUNCTION(BlueprintCallable, BlueprintPure, Meta=(Displayname="LoadConfig(Vector)"), Category = "GConfig")
	static FVector LoadConfigVector(const FString FileName, const FString Section, const FString Key);

	UFUNCTION(BlueprintCallable, BlueprintPure, Meta=(Displayname="LoadConfig(Vector4)"), Category = "GConfig")
	static FVector4 LoadConfigVector4(const FString FileName, const FString Section, const FString Key);

	UFUNCTION(BlueprintCallable, BlueprintPure, Meta=(Displayname="LoadConfig(Rotator)"), Category = "GConfig")
	static FRotator LoadConfigRotator(const FString FileName, const FString Section, const FString Key);

	

	// 存储数据部分	
	UFUNCTION(BlueprintCallable, Meta=(Displayname="SaveConfig(String)"), Category = "GConfig")
	static void SaveConfig(const FString FileName, const FString Section, const FString Key, const FString Value);

	UFUNCTION(BlueprintCallable, Meta=(Displayname="SaveConfig(Text)"), Category = "GConfig")
	static void SaveConfigText(const FString FileName, const FString Section, const FString Key, const FText Value);
	
	UFUNCTION(BlueprintCallable, Meta=(Displayname="SaveConfig(Int)"), Category = "GConfig")
	static void SaveConfigInt(const FString FileName, const FString Section, const FString Key, const int32 Value);

	UFUNCTION(BlueprintCallable, Meta=(Displayname="SaveConfig(float)"), Category = "GConfig")
	static void SaveConfigFloat(const FString FileName, const FString Section, const FString Key, const float Value);
	
	UFUNCTION(BlueprintCallable, Meta=(Displayname="SaveConfig(double)"), Category = "GConfig")
	static void SaveConfigDouble(const FString FileName, const FString Section, const FString Key, const double Value);
	
	UFUNCTION(BlueprintCallable, Meta=(Displayname="SaveConfig(bool)"), Category = "GConfig")
	static void SaveConfigBool(const FString FileName, const FString Section, const FString Key, const bool Value);

	UFUNCTION(BlueprintCallable, Meta=(Displayname="SaveConfig(Array[String])"), Category = "GConfig")
	static void SaveConfigArray(const FString FileName, const FString Section, const FString Key, const TArray<FString> Value);

	UFUNCTION(BlueprintCallable, Meta=(Displayname="SaveConfig(SingleLineArray[String])"), Category = "GConfig")
	static void SaveConfigSingleLineArray(const FString FileName, const FString Section, const FString Key, const TArray<FString> Value);

	UFUNCTION(BlueprintCallable, Meta=(Displayname="SaveConfig(Color)"), Category = "GConfig")
	static void SaveConfigColor(const FString FileName, const FString Section, const FString Key, const FColor Value);

	UFUNCTION(BlueprintCallable, Meta=(Displayname="SaveConfig(Vector2D)"), Category = "GConfig")
	static void SaveConfigVector2D(const FString FileName, const FString Section, const FString Key, const FVector2D Value);

	UFUNCTION(BlueprintCallable, Meta=(Displayname="SaveConfig(Vector)"), Category = "GConfig")
	static void SaveConfigVector(const FString FileName, const FString Section, const FString Key, const FVector Value);

	UFUNCTION(BlueprintCallable, Meta=(Displayname="SaveConfig(Vector4)"), Category = "GConfig")
	static void SaveConfigVector4(const FString FileName, const FString Section, const FString Key, const FVector4 Value);

	UFUNCTION(BlueprintCallable, Meta=(Displayname="SaveConfig(Rotator)"), Category = "GConfig")
	static void SaveConfigRotator(const FString FileName, const FString Section, const FString Key, const FRotator Value);
};
