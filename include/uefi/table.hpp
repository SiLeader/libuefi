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

#ifndef INCLUDE_UEFI_TABLE_HPP
#define INCLUDE_UEFI_TABLE_HPP

#include <uefi/types.hpp>
#include <uefi/services/boot.hpp>

#include <uefi/protocols/simple_text_input_protocol.hpp>
#include <uefi/protocols/simple_text_output_protocol.hpp>

namespace uefi {
    namespace table {
        constexpr uint32_t revision(uint32_t major, uint32_t minor) noexcept {
            return (major << 16) | minor;
        }
        constexpr uint32_t SystemTableRevision = revision(2, 70);
        constexpr uint32_t SpecificationRevision = SystemTableRevision;

        struct ConfigurationTable {
            Guid vendorGuid;
            void *vendorTable;
        };

        constexpr Guid Acpi20TableGuid {0x8868e871, 0xe4f1, 0x11d3, 0xbc, 0x22, 0x00, 0x80, 0xc7, 0x3c, 0x88, 0x81};
        constexpr Guid Acpi10TableGuid {0xeb9d2d30, 0x2d88, 0x11d3, 0x9a, 0x16, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d};

        struct SystemTable {
            Header header;
            char16_t firmwareVendor;
            uint32_t firmwareRevision;
            Handle consoleInHandle;
            protocols::SimpleTextInputProtocol *conIn;
            Handle consoleOutHandle;
            protocols::SimpleTextOutputProtocol *conOut;
            Handle standardErrorHandle;
            protocols::SimpleTextOutputProtocol *stdErr;

            void *runtimeService;
            uefi::services::boot::Service *bootService;

            uintn_t numberOfTableEntries;
            ConfigurationTable *configurationTable;
        };
    } /* table */
} /* uefi */

#endif // INCLUDE_UEFI_TABLE_HPP
