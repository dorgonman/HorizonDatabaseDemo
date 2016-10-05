// Created by dorgon, All Rights Reserved.
// email: dorgonman@hotmail.com
// blog: dorgon.horizon-studio.net

#include "HorizonDatabaseDemo.h"
#include "HorizonDatabaseDemoGameMode.h"

//#include "Horizon/Database/HorizonDatabase.h"


#include <string>
static FORCEINLINE void CreateDirectoryRecursively(FString FolderToMake)
{
	//FolderToMake is not const so split can be used, and does not damage input

	//Loop Proteciton
	const int32 MAX_LOOP_ITR = 3000; //limit of 3000 directories in the structure

									 // Normalize all / and \ to TEXT("/") and remove any trailing TEXT("/") 
									 //if the character before that is not a TEXT("/") or a colon
	FPaths::NormalizeDirectoryName(FolderToMake);

	//Normalize removes the last "/", but my algorithm wants it
	FolderToMake += "/";

	FString Base;
	FString Left;
	FString Remaining;

	//Split off the Root
	FolderToMake.Split(TEXT("/"), &Base, &Remaining);
	Base += "/"; //add root text to Base

	int32 LoopItr = 0;
	while (Remaining != "" && LoopItr < MAX_LOOP_ITR)
	{
		Remaining.Split(TEXT("/"), &Left, &Remaining);

		//Add to the Base
		Base += Left + FString("/"); //add left and split text to Base

									 //Create Incremental Directory Structure!
		FPlatformFileManager::Get().GetPlatformFile().CreateDirectory(*Base);

		LoopItr++;
	}
}


AHorizonDatabaseDemoGameMode::AHorizonDatabaseDemoGameMode() {
	FPaths::Combine();
	//IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	//IFileHandle* FileHandle = PlatformFile.OpenWrite(*testFilePath);

	//../../../HorizonDatabaseDemo/PersistentDownloadDir/Horizon/
//
//	FString myFolder = "/Horizon/";
//#if (PLATFORM_ANDROID)
//	extern FString GExternalFilePath;
//	FString folderPath = GExternalFilePath + myFolder;//androidPlatformFile.FileRootPath(TEXT("")) + FPaths::GamePersistentDownloadDir() 
//#else
//	FString folderPath = FPaths::GamePersistentDownloadDir() + myFolder;
//	//folderPath = FPaths::ConvertRelativePathToFull(folderPath);
//#endif
//
//	CreateDirectoryRecursively(folderPath);
//
//
//	FString connectString = folderPath + FString("save.db");
//
//
//	UE_LOG(LogTemp, Log, TEXT("======================connectString: %s"), *connectString);
//	//const soci::backend_factory* backEnd = soci::factory_sqlite3();
//
//
//	//const soci::backend_factory* backEnd = soci::factory_sqlite3();
//	//soci::session sql(*backEnd, "/sdcard/UE4Game/HorizonDatabaseDemo/HorizonDatabaseDemo/PersistentDownloadDir/Horizon/myFullPath.db");  //android can't open db if path is relative
//	//soci::session sql(*backEnd, std::string(TCHAR_TO_UTF8(*connectString)));
//	soci::session* sql = new soci::session(soci::sqlite3, std::string(TCHAR_TO_UTF8(*connectString)));
//	//HorizonDatabase db;
//	try {
//		*sql << "drop table if exists test1";
//		*sql <<
//			"create table test1 ("
//			"    id integer,"
//			"    name varchar(100)"
//			")";
//		*sql << "insert into test1(id, name) values(7, \'John\')";
//
//		//sql << "insert into test1(id, name) ddd values(7, \'John\')";
//	}
//	catch (...) {
//		//UE_HORIZON_LOG("oops! something error");
//	}
//	soci::rowid rid(*sql);
//	*sql << "select oid from test1 where id = 7", soci::into(rid);
//
//	int id;
//	std::string name;
//
//	*sql << "select id, name from test1 where oid = :rid",
//		soci::into(id), soci::into(name), soci::use(rid);
//
//	UE_LOG(LogTemp, Log, TEXT("=============TEST select from sqlite: %d, %s"), id, *FString(name.c_str()));
//
//	*sql << "drop table test1";
//

	/*sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open(":memory:", &db);

	if (rc) {
	const char * errorMsg = sqlite3_errmsg(db);
	FString Fs1 = FString(ANSI_TO_TCHAR(errorMsg));
	FString Fs2 = FString(UTF8_TO_TCHAR(errorMsg));
	UE_LOG(LogTemp, Log, TEXT("1oops! Can't open database: %s\n"), *Fs1);
	UE_LOG(LogTemp, Log, TEXT("2oops! Can't open database: %s\n"), *Fs2);
	}
	else {
	UE_LOG(LogTemp, Log, TEXT("Opened database successfully"));
	}
	sqlite3_close(db);*/
}