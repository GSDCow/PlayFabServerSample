// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class PlayFabServerSampleServerTarget : TargetRules
{
	public PlayFabServerSampleServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "PlayFabServerSample" } );
		
		DisablePlugins.Add("WMFMediaPlayer");
		DisablePlugins.Add("AsyncLoadingScreen");
		DisablePlugins.Add("WindowsMoviePlayer");
		DisablePlugins.Add("MediaFoundationMediaPlayer");
	}
}
