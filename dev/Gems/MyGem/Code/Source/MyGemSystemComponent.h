#pragma once

#include <AzCore/Component/Component.h>

#include <MyGem/MyGemBus.h>

namespace MyGem
{
    class MyGemSystemComponent
        : public AZ::Component
        , protected MyGemRequestBus::Handler
    {
    public:
        AZ_COMPONENT(MyGemSystemComponent, "{8B634AF7-BBDC-42E9-B1F8-3F3011D740E2}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

    protected:
        ////////////////////////////////////////////////////////////////////////
        // MyGemRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
