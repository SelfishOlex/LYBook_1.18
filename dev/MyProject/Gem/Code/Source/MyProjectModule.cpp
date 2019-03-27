
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include <MyProjectSystemComponent.h>
#include <MyComponent.h>
#include <OscillatorComponent.h>

namespace MyProject
{
    class MyProjectModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(MyProjectModule, "{EF8168DD-CF8D-4E57-ACE6-4D6F36AD3A03}", AZ::Module);
        AZ_CLASS_ALLOCATOR(MyProjectModule, AZ::SystemAllocator, 0);

        MyProjectModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                MyProjectSystemComponent::CreateDescriptor(),
                MyComponent::CreateDescriptor(),
                OscillatorComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<MyProjectSystemComponent>(),
            };
        }
    };
}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(MyProject_d47b06fd4781433ab34ec87ed474cb35, MyProject::MyProjectModule)
