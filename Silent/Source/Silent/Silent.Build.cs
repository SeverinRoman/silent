// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Silent : ModuleRules
{
	public Silent(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput",  });
		PublicDependencyModuleNames.AddRange(new string[] { "AnimGraphRuntime" });

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
            "Silent",
            "Silent/Enums",
            "Silent/Structs",
            "Silent/Interfaces",
            "Silent/GameMods",
            "Silent/Managers",
            "Silent/UI",
            "Silent/Components"
        });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
