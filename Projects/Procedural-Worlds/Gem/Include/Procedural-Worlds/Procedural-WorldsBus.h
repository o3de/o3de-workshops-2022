
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace Procedural_Worlds
{
    class Procedural_WorldsRequests
    {
    public:
        AZ_RTTI(Procedural_WorldsRequests, "{5C5BE29A-AF61-4B87-A492-A72A463D59F7}");
        virtual ~Procedural_WorldsRequests() = default;
        // Put your public methods here
    };

    class Procedural_WorldsBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using Procedural_WorldsRequestBus = AZ::EBus<Procedural_WorldsRequests, Procedural_WorldsBusTraits>;
    using Procedural_WorldsInterface = AZ::Interface<Procedural_WorldsRequests>;

} // namespace Procedural_Worlds
