
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "Procedural-WorldsSystemComponent.h"

namespace Procedural_Worlds
{
    class Procedural_WorldsModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(Procedural_WorldsModule, "{2E632380-E824-4870-8DB1-1633707FF264}", AZ::Module);
        AZ_CLASS_ALLOCATOR(Procedural_WorldsModule, AZ::SystemAllocator, 0);

        Procedural_WorldsModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                Procedural_WorldsSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<Procedural_WorldsSystemComponent>(),
            };
        }
    };
}// namespace Procedural_Worlds

AZ_DECLARE_MODULE_CLASS(Gem_Procedural_Worlds, Procedural_Worlds::Procedural_WorldsModule)
