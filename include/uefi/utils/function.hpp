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

#ifndef INCLUDE_UEFI_UTILS_FUNCTION_HPP
#define INCLUDE_UEFI_UTILS_FUNCTION_HPP

namespace uefi {
    namespace utils {
        template<class Ret, class... Args> using Function = Ret(__attribute__((stdcall))*)(Args...);
        using NotImplementedFunction = void*;
    } /* utils */
} /* uefi */

#endif // INCLUDE_UEFI_UTILS_FUNCTION_HPP
