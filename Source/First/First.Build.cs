// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class First : ModuleRules
{
	public First(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" 
		});

        PublicIncludePaths.Add("First");
    }
}
