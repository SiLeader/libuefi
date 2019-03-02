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

#ifndef INCLUDE_UEFI_SERVICES_BOOT_EVENT_TIMER_TASK_HPP
#define INCLUDE_UEFI_SERVICES_BOOT_EVENT_TIMER_TASK_HPP

#include <uefi/utils/function.hpp>
#include <uefi/types.hpp>

namespace uefi {
    namespace services {
        namespace boot {
            namespace event {
                enum class Tpl {
                    Application,
                    Callback,
                    Notify,
                    HighLevel,
                };

                namespace functions {
                    using CreateEvent = uefi::utils::NotImplementedFunction;
                    using CreateEventEx = uefi::utils::NotImplementedFunction;
                    using CloseEvent = uefi::utils::NotImplementedFunction;
                    using SignalEvent = uefi::utils::NotImplementedFunction;
                    using WaitForEvent = uefi::utils::NotImplementedFunction;
                    using CheckEvent = uefi::utils::NotImplementedFunction;
                    using SetTimer = uefi::utils::NotImplementedFunction;
                    using RaiseTPL = uefi::utils::NotImplementedFunction;
                    using RestoreTPL = uefi::utils::NotImplementedFunction;

                    using InstallProtocolInterface = uefi::utils::NotImplementedFunction;
                    using UninstallProtocolInterface = uefi::utils::NotImplementedFunction;
                    using ReinstallProtocolInterface = uefi::utils::NotImplementedFunction;
                    using RegisterProtocolNotify = uefi::utils::NotImplementedFunction;
                    using LocateHandle = uefi::utils::NotImplementedFunction;
                    using HandleProtocol = uefi::utils::NotImplementedFunction;
                    using LocateDevicePath = uefi::utils::NotImplementedFunction;
                    using OpenProtocol = uefi::utils::NotImplementedFunction;
                    using CloseProtocol = uefi::utils::NotImplementedFunction;
                    using OpenProtocolInformation = uefi::utils::NotImplementedFunction;
                    using ConnectController = uefi::utils::NotImplementedFunction;
                    using DisconnectController = uefi::utils::NotImplementedFunction;
                    using ProtocolsPerHandle = uefi::utils::NotImplementedFunction;
                    using LocateHandleBuffer = uefi::utils::NotImplementedFunction;
                    using LocateProtocol = uefi::utils::NotImplementedFunction;
                    using InstallMultipleProtocolInterfaces = uefi::utils::NotImplementedFunction;
                    using UninstallMultipleProtocolInterfaces = uefi::utils::NotImplementedFunction;

                    using LoadImage = uefi::utils::NotImplementedFunction;
                    using StartImage = uefi::utils::NotImplementedFunction;
                    using UnloadImage = uefi::utils::NotImplementedFunction;
                    using Exit = uefi::utils::NotImplementedFunction;
                    using ExitBootServices = uefi::utils::NotImplementedFunction;

                    using SetWatchdogTimer = uefi::utils::NotImplementedFunction;
                    using Stall = uefi::utils::NotImplementedFunction;
                    using CopyMem = uefi::utils::NotImplementedFunction;
                    using SetMem = uefi::utils::NotImplementedFunction;
                    using GetNextMonotonicCount = uefi::utils::NotImplementedFunction;
                    using InstallConfigurationTable = uefi::utils::NotImplementedFunction;
                    using CalculateCrc32 = uefi::utils::NotImplementedFunction;
                } /* functions */
            } /* event */
        } /* boot */
    } /* services */
} /* uefi */

#endif // INCLUDE_UEFI_SERVICES_BOOT_EVENT_TIMER_TASK_HPP
