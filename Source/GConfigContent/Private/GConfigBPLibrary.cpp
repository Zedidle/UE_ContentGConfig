// Copyright Epic Games, Inc. All Rights Reserved.

#include "GConfigBPLibrary.h"
#include "Misc/Paths.h"
#include "GConfig.h"

UGConfigBPLibrary::UGConfigBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
}


FString UGConfigBPLibrary::GetConfigPath(const FString& FileName)
{
	return FPaths::ProjectContentDir() / "Config" / FileName + ".ini";
}

// 尝试修改项目打包时，设置原封不动的拷贝目录。暂未想到怎么做
float UGConfigBPLibrary::AddDirectoriesToCopy(FString& DirectoryPath)
{
	UE_LOG(LogTemp, Warning, TEXT("zfc -- UGConfigBPLibrary::SetDirectoriesToCopy"));

	// TArray<FString> out_Arr;
	// GConfig->GetArray(TEXT("/Script/UnrealEd.ProjectPackagingSettings"), TEXT("DirectoriesToAlwaysStageAsNonUFS"), out_Arr, "Game");
	// for (FString s : out_Arr){
	// 	UE_LOG(LogTemp, Warning, TEXT("zfc -- UGConfigBPLibrary::GConfigSampleFunction %s"), *s);
	// }

	// TArray<FString> out_Arr;
	// out_Arr.AddUnique("Config");
	// GConfig->SetArray(
	// 	TEXT("/Script/UnrealEd.ProjectPackagingSettings"),
	// 	TEXT("DirectoriesToAlwaysStageAsNonUFS"),
	// 	out_Arr,
	// 	FPaths::ProjectConfigDir() / "DefaultGame.ini");
	// UE_LOG(LogTemp, Warning, TEXT("zfc -- UGConfigBPLibrary::GConfigSampleFunction %s"), *(FPaths::ProjectConfigDir() / "DefaultGame.ini"));
	
	return -1;
}


FString UGConfigBPLibrary::LoadConfig(const FString FileName, const FString Section, const FString Key)
{
	return GConfig->GetStr(
		*Section,
		*Key,
		GetConfigPath(FileName));
	// GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, ConStr);
}

FText UGConfigBPLibrary::LoadConfigText(const FString FileName, const FString Section, const FString Key)
{
	FText Value;
	GConfig->GetText(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName)
		);
	return Value;
}

int32 UGConfigBPLibrary::LoadConfigInt(const FString FileName, const FString Section, const FString Key)
{
	int32 Value;
	GConfig->GetInt(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName)
	);
	return Value;
}

float UGConfigBPLibrary::LoadConfigFloat(const FString FileName, const FString Section, const FString Key)
{
	float Value;
	GConfig->GetFloat(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName)
	);
	return Value;
}

double UGConfigBPLibrary::LoadConfigDouble(const FString FileName, const FString Section, const FString Key)
{
	double Value;
	GConfig->GetDouble(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName)
		);
	return Value;
}

bool UGConfigBPLibrary::LoadConfigBool(const FString FileName, const FString Section, const FString Key)
{
	bool Value;
	GConfig->GetBool(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName)
	);
	return Value;
}

TArray<FString> UGConfigBPLibrary::LoadConfigArray(const FString FileName, const FString Section, const FString Key)
{
	TArray<FString> out_Arr;
	GConfig->GetArray(
		*Section,
		*Key,
		out_Arr,
		GetConfigPath(FileName)
		);
	return out_Arr;
}

TArray<FString> UGConfigBPLibrary::LoadConfigSingleLineArray(const FString FileName, const FString Section,
	const FString Key)
{
	TArray<FString> out_Arr;
	GConfig->GetSingleLineArray(
		*Section,
		*Key,
		out_Arr,
		GetConfigPath(FileName)
		);
	return out_Arr;
}

FColor UGConfigBPLibrary::LoadConfigColor(const FString FileName, const FString Section, const FString Key)
{
	FColor Value;
	GConfig->GetColor(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName)
		);
	return Value;
}

FVector2D UGConfigBPLibrary::LoadConfigVector2D(const FString FileName, const FString Section, const FString Key)
{
	FVector2D Value;
	GConfig->GetVector2D(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName)
		);
	return Value;
}

FVector UGConfigBPLibrary::LoadConfigVector(const FString FileName, const FString Section, const FString Key)
{
	FVector Value;
	GConfig->GetVector(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName)
		);
	return Value;
}

FVector4 UGConfigBPLibrary::LoadConfigVector4(const FString FileName, const FString Section, const FString Key)
{
	FVector4 Value;
	GConfig->GetVector4(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName)
		);
	return Value;
}

FRotator UGConfigBPLibrary::LoadConfigRotator(const FString FileName, const FString Section, const FString Key)
{
	FRotator Value;
	GConfig->GetRotator(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName)
		);
	return Value;
}


void UGConfigBPLibrary::SaveConfig(const FString FileName, const FString Section, const FString Key, const FString Value)
{
	GConfig->SetString(
		*Section,//区块、分类
		*Key,//配置的具体名字
		*Value,//参数的具体值
		GetConfigPath(FileName));//配置路径，不存在会创建
	//还有setint，setbool，setfloat
	//GConfig->Flush(true, FPaths::GameDir() / "MyConfig.ini");
}

void UGConfigBPLibrary::SaveConfigText(const FString FileName, const FString Section, const FString Key,
	const FText Value)
{
	GConfig->SetText(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName));
}


void UGConfigBPLibrary::SaveConfigInt(const FString FileName, const FString Section, const FString Key, const int32 Value)
{
	GConfig->SetInt(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName));
}

void UGConfigBPLibrary::SaveConfigFloat(const FString FileName, const FString Section, const FString Key,
	const float Value)
{
	GConfig->SetFloat(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName));
}

void UGConfigBPLibrary::SaveConfigDouble(const FString FileName, const FString Section, const FString Key,
	const double Value)
{
	GConfig->SetDouble(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName));
}

void UGConfigBPLibrary::SaveConfigBool(const FString FileName, const FString Section, const FString Key,
	const bool Value)
{
	GConfig->SetBool(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName));
}

void UGConfigBPLibrary::SaveConfigArray(const FString FileName, const FString Section, const FString Key,
	const TArray<FString> Value)
{
	GConfig->SetArray(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName));
}

void UGConfigBPLibrary::SaveConfigSingleLineArray(const FString FileName, const FString Section, const FString Key,
	const TArray<FString> Value)
{
	GConfig->SetSingleLineArray(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName));
}

void UGConfigBPLibrary::SaveConfigColor(const FString FileName, const FString Section, const FString Key,
	const FColor Value)
{
	GConfig->SetColor(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName));
}

void UGConfigBPLibrary::SaveConfigVector2D(const FString FileName, const FString Section, const FString Key,
	const FVector2D Value)
{
	GConfig->SetVector2D(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName));
}

void UGConfigBPLibrary::SaveConfigVector(const FString FileName, const FString Section, const FString Key,
	const FVector Value)
{
	GConfig->SetVector(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName));
}

void UGConfigBPLibrary::SaveConfigVector4(const FString FileName, const FString Section, const FString Key,
	const FVector4 Value)
{
	GConfig->SetVector4(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName));
}

void UGConfigBPLibrary::SaveConfigRotator(const FString FileName, const FString Section, const FString Key,
	const FRotator Value)
{
	GConfig->SetRotator(
		*Section,
		*Key,
		Value,
		GetConfigPath(FileName));
}
