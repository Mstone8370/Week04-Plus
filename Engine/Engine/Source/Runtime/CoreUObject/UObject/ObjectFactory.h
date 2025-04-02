#pragma once
#include "Object.h"
#include "UObjectHash.h"
#include "EngineStatics.h"
#include "UObjectArray.h"

class FObjectFactory
{
public:
    template<typename T>
        requires std::derived_from<T, UObject>
    static T* ConstructObject()
    {
        uint32 id = UEngineStatics::GenUUID();
        FString Name = T::StaticClass()->GetName() + "_" + std::to_string(id);

        T* Obj = new T;  // TODO: FPlatformMemory::Malloc으로 변경, placement new 사용시 Free방법 생각하기
        Obj->ClassPrivate = T::StaticClass();
        Obj->NamePrivate = Name;
        Obj->UUID = id;

        GUObjectArray.AddObject(Obj);

        UE_LOG(LogLevel::Display, "Created New Object : %s", *Name);
        return Obj;
    }

    template<typename T>
        requires std::derived_from<T, UObject>
    static T* DuplicateObject(const T& InObject)
    {
        T* Obj = FObjectFactory::ConstructObject<T>();
        Obj->DuplicateObject(&InObject); // 오브젝트 얕은 복사
        return Obj;
    }
};
