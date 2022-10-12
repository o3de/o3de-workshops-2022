
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "Procedural-WorldsSystemComponent.h"

namespace Procedural_Worlds
{
    void Procedural_WorldsSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<Procedural_WorldsSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<Procedural_WorldsSystemComponent>("Procedural_Worlds", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void Procedural_WorldsSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("Procedural_WorldsService"));
    }

    void Procedural_WorldsSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("Procedural_WorldsService"));
    }

    void Procedural_WorldsSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void Procedural_WorldsSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    Procedural_WorldsSystemComponent::Procedural_WorldsSystemComponent()
    {
        if (Procedural_WorldsInterface::Get() == nullptr)
        {
            Procedural_WorldsInterface::Register(this);
        }
    }

    Procedural_WorldsSystemComponent::~Procedural_WorldsSystemComponent()
    {
        if (Procedural_WorldsInterface::Get() == this)
        {
            Procedural_WorldsInterface::Unregister(this);
        }
    }

    void Procedural_WorldsSystemComponent::Init()
    {
    }

    void Procedural_WorldsSystemComponent::Activate()
    {
        Procedural_WorldsRequestBus::Handler::BusConnect();
    }

    void Procedural_WorldsSystemComponent::Deactivate()
    {
        Procedural_WorldsRequestBus::Handler::BusDisconnect();
    }
}
