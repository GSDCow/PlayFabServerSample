// Fill out your copyright notice in the Description page of Project Settings.

#include "PSS_GameInstance.h"
#include "PlayfabGSDK.h"
#include "GSDKUtils.h"

void UPSS_GameInstance::Init()
{
	if (IsDedicatedServerInstance() == true)
	{
		FOnGSDKShutdown_Dyn OnGsdkShutdown;
		OnGsdkShutdown.BindDynamic(this, &UPSS_GameInstance::OnGSDKShutdown);
		FOnGSDKHealthCheck_Dyn OnGsdkHealthCheck;
		OnGsdkHealthCheck.BindDynamic(this, &UPSS_GameInstance::OnGSDKHealthCheck);
		FOnGSDKServerActive_Dyn OnGSDKServerActive;
		OnGSDKServerActive.BindDynamic(this, &UPSS_GameInstance::OnGSDKServerActive);
		FOnGSDKReadyForPlayers_Dyn OnGSDKReadyForPlayers;
		OnGSDKReadyForPlayers.BindDynamic(this, &UPSS_GameInstance::OnGSDKReadyForPlayers);

		UGSDKUtils::RegisterGSDKShutdownDelegate(OnGsdkShutdown);
		UGSDKUtils::RegisterGSDKHealthCheckDelegate(OnGsdkHealthCheck);
		UGSDKUtils::RegisterGSDKServerActiveDelegate(OnGSDKServerActive);
		UGSDKUtils::RegisterGSDKReadyForPlayers(OnGSDKReadyForPlayers);
	}
	
#if UE_SERVER
	UGSDKUtils::SetDefaultServerHostPort();
#endif
}

void UPSS_GameInstance::OnStart()
{
	UGSDKUtils::ReadyForPlayers();
}

void UPSS_GameInstance::OnGSDKShutdown()
{
	FPlatformMisc::RequestExit(false);
}

bool UPSS_GameInstance::OnGSDKHealthCheck()
{
	return true;
}

void UPSS_GameInstance::OnGSDKServerActive()
{
}

void UPSS_GameInstance::OnGSDKReadyForPlayers()
{
}
