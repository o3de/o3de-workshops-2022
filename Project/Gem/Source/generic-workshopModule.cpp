
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "generic-workshopSystemComponent.h"

namespace generic_workshop
{
    class generic_workshopModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(generic_workshopModule, "{51CC5389-F91F-445B-B561-B0365EC87927}", AZ::Module);
        AZ_CLASS_ALLOCATOR(generic_workshopModule, AZ::SystemAllocator, 0);

        generic_workshopModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                generic_workshopSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<generic_workshopSystemComponent>(),
            };
        }
    };
}// namespace generic_workshop

AZ_DECLARE_MODULE_CLASS(Gem_generic_workshop, generic_workshop::generic_workshopModule)
