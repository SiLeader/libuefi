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

#ifndef INCLUDE_UEFI_SERVICES_BOOT_HPP
#define INCLUDE_UEFI_SERVICES_BOOT_HPP

#include <uefi/services/boot/event_timer_task.hpp>
#include <uefi/services/boot/image.hpp>
#include <uefi/services/boot/memory.hpp>
#include <uefi/services/boot/miscellaneous.hpp>
#include <uefi/services/boot/protocol.hpp>

namespace uefi {
    namespace services {
        namespace boot {
            struct Service {
                table::Header header;
                event::functions::RaiseTPL raiseTpl;
                event::functions::RestoreTPL restoreTpl;

                memory::functions::AllocatePages allocatePages;
                memory::functions::FreePages freePages;
                memory::functions::GetMemoryMap getMemoryMap;
                memory::functions::AllocatePool allocatePool;
                memory::functions::FreePool freePool;

                event::functions::CreateEvent createEvent;
                event::functions::SetTimer setTimer;
                event::functions::WaitForEvent waitForEvent;
                event::functions::SignalEvent signalEvent;
                event::functions::CloseEvent closeEvent;
                event::functions::CheckEvent checkEvent;

                protocol::functions::InstallProtocolInterface installProtocolInterface;
                protocol::functions::ReinstallProtocolInterface reinstallProtocolInterface;
                protocol::functions::UninstallProtocolInterface uninstallProtocolInterface;
                protocol::functions::HandleProtocol handleProtocol;
                void *_reserved;
                protocol::functions::RegisterProtocolNotify registerProtocolNotify;
                protocol::functions::LocateHandle locateHandle;
                protocol::functions::LocateDevicePath locateDevicePath;
                miscellaneous::functions::InstallConfigurationTable installConfigurationTable;

                image::functions::LoadImage loadImage;
                image::functions::StartImage startImage;
                image::functions::Exit exit;
                image::functions::UnloadImage unloadImage;
                image::functions::ExitBootServices exitBootServices;

                miscellaneous::functions::GetNextMonotonicCount getNextMonotonicCount;
                miscellaneous::functions::Stall stall;
                miscellaneous::functions::SetWatchdogTimer setWatchdogTimer;

                protocol::functions::ConnectController connectController;
                protocol::functions::DisconnectController disconnectController;

                protocol::functions::OpenProtocol openProtocol;
                protocol::functions::CloseProtocol closeProtocol;
                protocol::functions::OpenProtocolInformation openProtocolInformation;

                protocol::functions::ProtocolsPerHandle protocolsPerHandle;
                protocol::functions::LocateHandleBuffer locateHandleBuffer;
                protocol::functions::LocateProtocol locateProtocol;
                protocol::functions::InstallMultipleProtocolInterfaces installMultipleProtocolInterfaces;
                protocol::functions::UninstallMultipleProtocolInterfaces uninstallMultipleProtocolInterfaces;

                miscellaneous::functions::CalculateCrc32 calculateCrc32;
                miscellaneous::functions::CopyMem copyMem;
                miscellaneous::functions::SetMem setMem;
                event::functions::CreateEventEx createEventEx;
            };
        } /* boot */
    } /* services */
} /* uefi */

#endif // INCLUDE_UEFI_SERVICES_BOOT_HPP
