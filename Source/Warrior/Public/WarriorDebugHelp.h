#pragma once

namespace   Debug
{
   static void print(const FString& DebugMessage,int32 Key=-1, float TimeToDisplay=5.0f, FColor DisplayColor=FColor::Blue, bool bNewerOnTop = true, const FVector2D& TextScale = FVector2D::UnitVector)
   {
   
   	if (GEngine)
   	{
   		GEngine->AddOnScreenDebugMessage(Key,TimeToDisplay,DisplayColor,DebugMessage);
   		UE_LOG(LogTemp, Warning, TEXT("日志输出: %s"), *DebugMessage);
   	}
   }
	
}
