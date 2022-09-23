
#pragma once

#include <AzCore/Component/Component.h>

#include <generic-workshop/generic-workshopBus.h>

namespace generic_workshop
{
    class generic_workshopSystemComponent
        : public AZ::Component
        , protected generic_workshopRequestBus::Handler
    {
    public:
        AZ_COMPONENT(generic_workshopSystemComponent, "{1ACA250F-2D2A-4349-8DE1-9E5DBC3636C2}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        generic_workshopSystemComponent();
        ~generic_workshopSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // generic_workshopRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
