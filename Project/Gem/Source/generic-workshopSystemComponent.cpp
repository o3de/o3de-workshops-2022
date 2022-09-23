
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "generic-workshopSystemComponent.h"

namespace generic_workshop
{
    void generic_workshopSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<generic_workshopSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<generic_workshopSystemComponent>("generic_workshop", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void generic_workshopSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("generic_workshopService"));
    }

    void generic_workshopSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("generic_workshopService"));
    }

    void generic_workshopSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void generic_workshopSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    generic_workshopSystemComponent::generic_workshopSystemComponent()
    {
        if (generic_workshopInterface::Get() == nullptr)
        {
            generic_workshopInterface::Register(this);
        }
    }

    generic_workshopSystemComponent::~generic_workshopSystemComponent()
    {
        if (generic_workshopInterface::Get() == this)
        {
            generic_workshopInterface::Unregister(this);
        }
    }

    void generic_workshopSystemComponent::Init()
    {
    }

    void generic_workshopSystemComponent::Activate()
    {
        generic_workshopRequestBus::Handler::BusConnect();
    }

    void generic_workshopSystemComponent::Deactivate()
    {
        generic_workshopRequestBus::Handler::BusDisconnect();
    }
}
