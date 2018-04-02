// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "HelloWorldService.generated.h"

USTRUCT()
struct FResponse_HelloWorld {
    GENERATED_BODY()
    UPROPERTY() FString message;

    FResponse_HelloWorld() {}
};

UCLASS(Blueprintable, hideCategories = (Rendering, Replication, Input, Actor, "Actor Tick"))
class FIRSTCPP_API AHelloWorldService : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AHelloWorldService();

    void GetHelloWorld();
    void HelloWorldResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
    FHttpModule* Http;
    FString ApiBaseUrl = "http://localhost:8080/";

    TSharedRef<IHttpRequest> RequestWithRoute(FString Subroute);
    TSharedRef<IHttpRequest> GetRequest(FString Subroute);
    void Send(TSharedRef<IHttpRequest>& Request);

    bool ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful);

    template <typename StructType>
    void GetJsonStringFromStruct(StructType FilledStruct, FString& StringOutput);
    template <typename StructType>
    void GetStructFromJsonString(FHttpResponsePtr Response, StructType& StructOutput);

};
