#include <platform_impl.h>
#include <AzCore/Memory/SystemAllocator.h>
#include <IGem.h>
#include "WindowPositionCommands.h"

namespace WindowPosition
{
    class WindowPositionModule
        : public CryHooksModule
    {
    public:
        AZ_RTTI(WindowPositionModule,
            "{58507FF5-0F1B-4DB0-9993-3CC21218EE35}",
            CryHooksModule);
        AZ_CLASS_ALLOCATOR(WindowPositionModule,
            AZ::SystemAllocator, 0);

        WindowPositionModule() : CryHooksModule() {}

        void OnCrySystemInitialized(ISystem& system,
            const SSystemInitParams& systemInitParams) override
        {
            CryHooksModule::OnCrySystemInitialized(
                system, systemInitParams);
            m_commands.Register();
        }

        void OnSystemEvent(ESystemEvent event,
            UINT_PTR, UINT_PTR) override
        {
            switch (event)
            {
            case ESYSTEM_EVENT_FULL_SHUTDOWN:
            case ESYSTEM_EVENT_FAST_SHUTDOWN:
                m_commands.Unregister();
            default:
                AZ_UNUSED(event);
            }
        }

        WindowPositionCommands m_commands;
    };
}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(WindowPosition_80c357c32e1d4d3e91eb341c83e094da, WindowPosition::WindowPositionModule)
