// Fill out your copyright notice in the Description page of Project Settings.


#include "HelloWorldService.h"


// Sets default values
AHelloWorldService::AHelloWorldService()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AHelloWorldService::BeginPlay()
{
	Super::BeginPlay();
	Http = &FHttpModule::Get();
    UE_LOG(LogTemp, Warning, TEXT("HelloWorldService BeginPlay called"));

    GetHelloWorld();
}

// Called every frame
void AHelloWorldService::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TSharedRef<IHttpRequest> AHelloWorldService::RequestWithRoute(FString Subroute) {
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->SetURL(ApiBaseUrl + Subroute);
	return Request;
}

TSharedRef<IHttpRequest> AHelloWorldService::GetRequest(FString Subroute) {
	TSharedRef<IHttpRequest> Request = RequestWithRoute(Subroute);
	Request->SetVerb("GET");
	return Request;
}

void AHelloWorldService::Send(TSharedRef<IHttpRequest>& Request) {
	Request->ProcessRequest();
}

bool AHelloWorldService::ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful) {
	if (!bWasSuccessful || !Response.IsValid()) return false;
	if (EHttpResponseCodes::IsOk(Response->GetResponseCode())) return true;
	else {
		UE_LOG(LogTemp, Warning, TEXT("Http Response returned error code: %d"), Response->GetResponseCode());
		return false;
	}
}

template <typename StructType>
void AHelloWorldService::GetJsonStringFromStruct(StructType FilledStruct, FString& StringOutput) {
	FJsonObjectConverter::UStructToJsonObjectString(StructType::StaticStruct(), &FilledStruct, StringOutput, 0, 0);
}

template <typename StructType>
void AHelloWorldService::GetStructFromJsonString(FHttpResponsePtr Response, StructType& StructOutput) {
	StructType StructData;
	FString JsonString = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct<StructType>(JsonString, &StructOutput, 0, 0);
}

void AHelloWorldService::GetHelloWorld() {
	TSharedRef<IHttpRequest> Request = GetRequest("hello.json");
	Request->OnProcessRequestComplete().BindUObject(this, &AHelloWorldService::HelloWorldResponse);
	Send(Request);
}

void AHelloWorldService::HelloWorldResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
	if (!ResponseIsValid(Response, bWasSuccessful)) return;

	FResponse_HelloWorld HelloWorldResponse;
	GetStructFromJsonString<FResponse_HelloWorld>(Response, HelloWorldResponse);

	UE_LOG(LogTemp, Warning, TEXT("Message is: %s"), *HelloWorldResponse.message);
}

