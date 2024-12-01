// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Unreal_1128/Unreal_1128GameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnreal_1128GameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UNREAL_1128_API UClass* Z_Construct_UClass_AUnreal_1128GameMode();
UNREAL_1128_API UClass* Z_Construct_UClass_AUnreal_1128GameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_Unreal_1128();
// End Cross Module References

// Begin Class AUnreal_1128GameMode
void AUnreal_1128GameMode::StaticRegisterNativesAUnreal_1128GameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AUnreal_1128GameMode);
UClass* Z_Construct_UClass_AUnreal_1128GameMode_NoRegister()
{
	return AUnreal_1128GameMode::StaticClass();
}
struct Z_Construct_UClass_AUnreal_1128GameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Unreal_1128GameMode.h" },
		{ "ModuleRelativePath", "Unreal_1128GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUnreal_1128GameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AUnreal_1128GameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Unreal_1128,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AUnreal_1128GameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AUnreal_1128GameMode_Statics::ClassParams = {
	&AUnreal_1128GameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUnreal_1128GameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AUnreal_1128GameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AUnreal_1128GameMode()
{
	if (!Z_Registration_Info_UClass_AUnreal_1128GameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AUnreal_1128GameMode.OuterSingleton, Z_Construct_UClass_AUnreal_1128GameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AUnreal_1128GameMode.OuterSingleton;
}
template<> UNREAL_1128_API UClass* StaticClass<AUnreal_1128GameMode>()
{
	return AUnreal_1128GameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AUnreal_1128GameMode);
AUnreal_1128GameMode::~AUnreal_1128GameMode() {}
// End Class AUnreal_1128GameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_daeun4001_OneDrive_Desktop_gamepgm_Unreal_Unreal_1128_Source_Unreal_1128_Unreal_1128GameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AUnreal_1128GameMode, AUnreal_1128GameMode::StaticClass, TEXT("AUnreal_1128GameMode"), &Z_Registration_Info_UClass_AUnreal_1128GameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AUnreal_1128GameMode), 98859969U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_daeun4001_OneDrive_Desktop_gamepgm_Unreal_Unreal_1128_Source_Unreal_1128_Unreal_1128GameMode_h_2929633410(TEXT("/Script/Unreal_1128"),
	Z_CompiledInDeferFile_FID_Users_daeun4001_OneDrive_Desktop_gamepgm_Unreal_Unreal_1128_Source_Unreal_1128_Unreal_1128GameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_daeun4001_OneDrive_Desktop_gamepgm_Unreal_Unreal_1128_Source_Unreal_1128_Unreal_1128GameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
