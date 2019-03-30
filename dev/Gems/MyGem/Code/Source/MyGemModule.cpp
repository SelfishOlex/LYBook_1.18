
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include <MyGemSystemComponent.h>

namespace MyGem
{
    class MyGemModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(MyGemModule, "{267FC6B5-C11B-4FB1-A9D4-A32CC91FD967}", AZ::Module);
        AZ_CLASS_ALLOCATOR(MyGemModule, AZ::SystemAllocator, 0);

        MyGemModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                MyGemSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<MyGemSystemComponent>(),
            };
        }
    };
}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(MyGem_2cce2311466d48f7b779fd2c752552ee, MyGem::MyGemModule)
