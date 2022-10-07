
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace generic_workshop
{
    class generic_workshopRequests
    {
    public:
        AZ_RTTI(generic_workshopRequests, "{390AE4F9-1770-415A-A2CA-EE727CE8F39D}");
        virtual ~generic_workshopRequests() = default;
        // Put your public methods here
    };

    class generic_workshopBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using generic_workshopRequestBus = AZ::EBus<generic_workshopRequests, generic_workshopBusTraits>;
    using generic_workshopInterface = AZ::Interface<generic_workshopRequests>;

} // namespace generic_workshop
