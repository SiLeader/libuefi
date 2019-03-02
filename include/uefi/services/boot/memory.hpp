//   Copyright 2018-2019 SiLeader and Cerussite.
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

#ifndef INCLUDE_UEFI_SERVICES_BOOT_MEMORY_HPP
#define INCLUDE_UEFI_SERVICES_BOOT_MEMORY_HPP

#include <uefi/utils/function.hpp>
#include <uefi/types.hpp>

namespace uefi {
    namespace service {
        namespace boot {
            namespace memory {
                enum class AllocateType {
                    AllocateAnyPages,
                    AllocateMaxAddress,
                    AllocateAddress,
                    MaxAllocateType
                };

                enum class MemoryType {
                    ReservedMemoryType,
                    LoaderCode,
                    LoaderData,
                    BootServicesCode,
                    BootServicesData,
                    RuntimeServicesCode,
                    RuntimeServicesData,
                    ConventionalMemory,
                    UnusableMemory,
                    ACPIReclaimMemory,
                    ACPIMemoryNVS,
                    MemoryMappedIO,
                    MemoryMappedIOPortSpace,
                    PalCode,
                    PersistentMemory,
                    MaxMemoryType
                };

                using PhysicalAddress = uint64_t;
                using VirtualAddress = uint64_t;

                struct MemoryDescriptor {
                    uint32_t type;
                    PhysicalAddress physicalStart;
                    VirtualAddress virtualStart;
                    uint64_t numberOfPages;
                    uint64_t attribute;
                };
                constexpr uint64_t MemoryUc = 0x0000000000000001;
                constexpr uint64_t MemoryWt = 0x0000000000000002;
                constexpr uint64_t MemoryWb = 0x0000000000000004;
                constexpr uint64_t MemoryUce = 0x0000000000000008;
                constexpr uint64_t MemoryWp = 0x0000000000000010;
                constexpr uint64_t MemoryRp = 0x0000000000001000;
                constexpr uint64_t MemoryXp = 0x0000000000002000;
                constexpr uint64_t MemoryNv = 0x0000000000004000;
                constexpr uint64_t MemoryMoreReliable = 0x0000000000010000;
                constexpr uint64_t MemoryRo = 0x0000000000020000;
                constexpr uint64_t MemoryRuntime = 0x8000000000000001;

                namespace functions {
                    using AllocatePages = uefi::utils::Function<Status, AllocateType, MemoryType, uintn_t, PhysicalAddress*>;
                    using FreePages = uefi::utils::Function<Status, PhysicalAddress, uintn_t>;
                    using GetMemoryMap = uefi::utils::Function<Status, uintn_t*, MemoryDescriptor*, uintn_t*, uintn_t*, int32_t*>;
                    using AllocatePool = uefi::utils::NotImplementedFunction;
                    using FreePool = uefi::utils::NotImplementedFunction;
                } /* functions */
            } /* memory */
        } /* boot */
    } /* service */
} /* uefi */

#endif // INCLUDE_UEFI_SERVICES_BOOT_MEMORY_HPP
