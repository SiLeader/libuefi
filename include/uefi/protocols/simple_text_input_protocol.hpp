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

#ifndef INCLUDE_UEFI_PROTOCOLS_SIMPLE_TEXT_INPUT_PROTOCOL_HPP
#define INCLUDE_UEFI_PROTOCOLS_SIMPLE_TEXT_INPUT_PROTOCOL_HPP

#include <uefi/types.hpp>
#include <uefi/utils/function.hpp>

namespace uefi {
    namespace protocols {
        struct SimpleTextInputProtocol;

        struct InputKey {
            uint16_t scanCode;
            char16_t unicodeChar;
        };

        namespace simple_text_input_protocol {
            using Reset = utils::Function<Status, SimpleTextInputProtocol*, Bool>;
            using ReadKey = utils::Function<Status, SimpleTextInputProtocol*, InputKey*>;
        } /* simple_text_input_protocol */

        struct SimpleTextInputProtocol {
            simple_text_input_protocol::Reset reset;
            simple_text_input_protocol::ReadKey readKeyStroke;
            Event waitForKey;
        };
        constexpr Guid SimpleTextInputProtocolGuid{0x387477c1, 0x69c7, 0x11d2, 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b};
    } /* protocols */
} /* uefi */

#endif // INCLUDE_UEFI_PROTOCOLS_SIMPLE_TEXT_INPUT_PROTOCOL_HPP
