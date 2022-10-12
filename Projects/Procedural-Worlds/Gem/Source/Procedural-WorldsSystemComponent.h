
#pragma once

#include <AzCore/Component/Component.h>

#include <Procedural-Worlds/Procedural-WorldsBus.h>

namespace Procedural_Worlds
{
    class Procedural_WorldsSystemComponent
        : public AZ::Component
        , protected Procedural_WorldsRequestBus::Handler
    {
    public:
        AZ_COMPONENT(Procedural_WorldsSystemComponent, "{189E0405-C8A1-47B9-9F50-FEA570257D20}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        Procedural_WorldsSystemComponent();
        ~Procedural_WorldsSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // Procedural_WorldsRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
