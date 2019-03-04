cmake_minimum_required(VERSION 3.5)
project(libuefi-test)

file(GLOB_RECURSE BIN_HEADERS *.hpp *.h)
file(GLOB_RECURSE BIN_SOURCES *.cpp *.c)

set(CMAKE_SHARED_LINKER_FLAGS "-nostdlib -Bsymbolic")

add_library(internal SHARED ${BIN_HEADERS} ${BIN_SOURCES})
add_custom_command(
        OUTPUT bootx64.efi
        COMMAND objcopy -j .text -j .sdata -j .data -j .dynamic -j .dynsym -j .rel -j .rela -j .reloc --target=efi-app-x86_64 $< $@
        DEPENDS internal
)
add_custom_target(efi DEPENDS bootx64.efi)