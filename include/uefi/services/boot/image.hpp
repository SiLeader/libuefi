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

#ifndef INCLUDE_UEFI_SERVICES_BOOT_IMAGE_HPP
#define INCLUDE_UEFI_SERVICES_BOOT_IMAGE_HPP

#include <uefi/utils/function.hpp>
#include <uefi/types.hpp>

namespace uefi {
    namespace services {
        namespace boot {
            namespace image {
                using DevicePathProtocol = int;

                namespace functions {
                    using LoadImage = uefi::utils::Function<Status, Bool, Handle, DevicePathProtocol*, void*, uintn_t, Handle*>;
                    using StartImage = uefi::utils::NotImplementedFunction;
                    using UnloadImage = uefi::utils::NotImplementedFunction;
                    using Exit = uefi::utils::Function<Status, Handle, Status, uintn_t, char16_t*>;
                    using ExitBootServices = uefi::utils::Function<Status, Handle, uintn_t>;
                } /* functions */
            } /* image */
        } /* boot */
    } /* services */
} /* uefi */

#endif // INCLUDE_UEFI_SERVICES_BOOT_IMAGE_HPP
