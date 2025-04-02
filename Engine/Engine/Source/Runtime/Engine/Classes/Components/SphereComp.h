#pragma once
#include "StaticMeshComponent.h"


class USphereComp : public UStaticMeshComponent
{
    DECLARE_CLASS(USphereComp, UStaticMeshComponent)

public:
    USphereComp();
    virtual ~USphereComp() override;

    virtual void DuplicateSubObjects() override;
    virtual void Duplicate(const UObject* SourceObject) override;

    virtual void InitializeComponent() override;
    virtual void TickComponent(float DeltaTime) override;
};
