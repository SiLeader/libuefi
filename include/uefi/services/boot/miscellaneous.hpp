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

#ifndef INCLUDE_UEFI_SERVICES_BOOT_MISCELLANEOUS_HPP
#define INCLUDE_UEFI_SERVICES_BOOT_MISCELLANEOUS_HPP

#include <uefi/utils/function.hpp>
#include <uefi/types.hpp>

namespace uefi {
    namespace services {
        namespace boot {
            namespace miscellaneous {
                namespace functions {
                    using SetWatchdogTimer = uefi::utils::NotImplementedFunction;
                    using Stall = uefi::utils::NotImplementedFunction;
                    using CopyMem = uefi::utils::NotImplementedFunction;
                    using SetMem = uefi::utils::NotImplementedFunction;
                    using GetNextMonotonicCount = uefi::utils::NotImplementedFunction;
                    using InstallConfigurationTable = uefi::utils::NotImplementedFunction;
                    using CalculateCrc32 = uefi::utils::NotImplementedFunction;
                } /* functions */
            } /* miscellaneous */
        } /* boot */
    } /* services */
} /* uefi */

#endif // INCLUDE_UEFI_SERVICES_BOOT_MISCELLANEOUS_HPP
