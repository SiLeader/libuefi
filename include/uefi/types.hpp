//   Copyright 2018 SiLeader and Cerussite.
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

#ifndef INCLUDE_UEFI_TYPES_HPP
#define INCLUDE_UEFI_TYPES_HPP

#ifndef CHAR_BIT
#   define CHAR_BIT __CHAR_BIT__
#endif

namespace uefi {
#define INT(n) using int ## n ## _t = __INT ## n ## _TYPE__
#define UINT(n) using uint ## n ## _t = __UINT ## n ## _TYPE__

#define IFAST(n) using int_fast ## n ## _t = __INT_FAST ## n ## _TYPE__
#define UFAST(n) using uint_fast ## n ## _t = __INT_FAST ## n ## _TYPE__

#define ILEAST(n) using int_least ## n ## _t = __INT_LEAST ## n ## _TYPE__
#define ULEAST(n) using uint_least ## n ## _t = __UINT_LEAST ## n ## _TYPE__
#define IU(n) INT(n); UINT(n); IFAST(n); UFAST(n); ILEAST(n); ULEAST(n)

    IU(8);
    IU(16);
    IU(32);
    IU(64);

#undef IU
#undef ULEAST
#undef ILEAST
#undef UFAST
#undef IFAST
#undef UINT
#undef INT

#ifdef __amd64__
    using intn_t = int64_t;
    using uintn_t = uint64_t;
#else
    using intn_t = int32_t;
    using uintn_t = uint32_t;
#endif

    using intmax_t = __INTMAX_TYPE__;
    using uintmax_t = __UINTMAX_TYPE__;

    using size_t = __SIZE_TYPE__;
    using ptrdiff_t = __PTRDIFF_TYPE__;
    using intptr_t = __INTPTR_TYPE__;
    using uintptr_t = __UINTPTR_TYPE__;

    using Status = uintn_t;
    using Handle = void*;
    using Event = void*;
    using Lba = uint64_t;
    using Tpl = uintn_t;
    using Bool = uint8_t;
    static constexpr Bool True = 1, False=0;

    namespace table {
        struct Header {
            uint64_t signature;
            uint32_t revision;
            uint32_t headerSize;
            uint32_t crc32;
            uint32_t _reserved;
        };
    } /* table */

    struct alignas(8) Guid {
        uint32_t _0;
        uint16_t _4, _6;
        uint8_t _8, _9, _10, _11, _12, _13, _14, _15;

        constexpr Guid(uint32_t __0, uint16_t __4, uint16_t __6, uint8_t __8, uint8_t __9, uint8_t __10, uint8_t __11, uint8_t __12, uint8_t __13, uint8_t __14, uint8_t __15) noexcept
                : _0(__0)
                , _4(__4)
                , _6(__6)
                , _8(__8)
                , _9(__9)
                , _10(__10)
                , _11(__11)
                , _12(__12)
                , _13(__13)
                , _14(__14)
                , _15(__15) {
        }
        constexpr Guid() noexcept
                : Guid(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) {
        }
        Guid(const Guid&) = default;
        Guid(Guid&&) = default;

        Guid& operator=(const Guid&) = default;
        Guid& operator=(Guid&&) = default;

        ~Guid() = default;
    };
} /* uefi */

#endif // INCLUDE_UEFI_TYPES_HPP
