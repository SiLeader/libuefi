#   Copyright 2018-2019 SiLeader and Cerussite.
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.

cmake_minimum_required(VERSION 3.10)
project(libuefi-app)

file(GLOB_RECURSE BIN_HEADERS *.hpp *.h)
file(GLOB_RECURSE BIN_SOURCES *.cpp *.c)

set(CMAKE_SHARED_LINKER_FLAGS "-T /usr/lib/elf_x86_64_efi.lds -shared -nostdlib -Bsymbolic ${CMAKE_SHARED_LINKER_FLAGS}")

add_library(internal SHARED ${BIN_HEADERS} ${BIN_SOURCES})
target_link_libraries(internal uefi)
add_custom_command(
        OUTPUT bootx64.efi
        COMMAND objcopy -j .text -j .sdata -j .data -j .dynamic -j .dynsym -j .rel -j .rela -j .reloc --target=efi-app-x86_64 ${CMAKE_BINARY_DIR}/$< ${CMAKE_BINARY_DIR}/$@
        DEPENDS internal
)
add_custom_target(efi DEPENDS bootx64.efi)

add_custom_command(
        OUTPUT image/efi/boot/bootx64.efi
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/$< ${CMAKE_BINARY_DIR}/$@
        DEPENDS bootx64.efi
)
add_custom_target(deploy DEPENDS image/efi/boot/bootx64.efi)

set(QEMU_COMMAND_LINE qemu-system-x86_64 -bios OVMF.fd -net none -hda fat:rw:${CMAKE_CURRENT_BINARY_DIR}/image)
add_custom_target(
        qemu
        COMMAND ${CMAKE_COMMAND} -E echo [exec] ${QEMU_COMMAND_LINE}
        COMMAND ${QEMU_COMMAND_LINE}
        DEPENDS deploy
)
