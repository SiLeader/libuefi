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

#ifndef INCLUDE_UEFI_PROTOCOLS_SIMPLE_TEXT_OUTPUT_PROTOCOL_HPP
#define INCLUDE_UEFI_PROTOCOLS_SIMPLE_TEXT_OUTPUT_PROTOCOL_HPP

#include <uefi/types.hpp>
#include <uefi/utils/function.hpp>

namespace uefi {
    namespace protocols {
        struct SimpleTextOutputProtocol;

        struct SimpleTextOutputMode {
            int32_t maxMode;
            int32_t mode, attribute, cursorColumn, cursorRow;
            Bool cursorVisible;
        };

        namespace simple_text_output_protocol {
            using Reset = utils::Function<Status, SimpleTextOutputProtocol*, Bool>;
            using String = utils::Function<Status, SimpleTextOutputProtocol*, char16_t*>;
            using TestString = utils::Function<Status, SimpleTextOutputProtocol*, char16_t*>;
            using QueryMode = utils::Function<Status, SimpleTextOutputProtocol*, uintn_t, uintn_t*, uintn_t*>;
            using SetMode = utils::Function<Status, SimpleTextOutputProtocol*, uintn_t>;
            using SetAttribute = utils::Function<Status, SimpleTextOutputProtocol*, uintn_t>;
            using ClearScreen = utils::Function<Status, SimpleTextOutputProtocol*>;
            using CursorPosition = utils::Function<Status, SimpleTextOutputProtocol*, uintn_t, uintn_t>;
            using EnableCursor = utils::Function<Status, SimpleTextOutputProtocol*, Bool>;
        } /* simple_text_output_protocol */

        struct SimpleTextOutputProtocol {
            simple_text_output_protocol::Reset reset;
            simple_text_output_protocol::String outputString;
            simple_text_output_protocol::TestString testString;
            simple_text_output_protocol::QueryMode queryMode;
            simple_text_output_protocol::SetMode setMode;
            simple_text_output_protocol::SetAttribute setAttribute;
            simple_text_output_protocol::ClearScreen clearScreen;
            simple_text_output_protocol::CursorPosition setCursorPosition;
            simple_text_output_protocol::EnableCursor enableCursor;
            SimpleTextOutputMode *mode;
        };

        constexpr Guid SimpleTextOutputProtocolGuid {0x387477c2, 0x69c7, 0x11d2, 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b};
    } /* protocols */
} /* uefi */

#endif // INCLUDE_UEFI_PROTOCOLS_SIMPLE_TEXT_OUTPUT_PROTOCOL_HPP
