#pragma once

#include <concepts>
#include <type_traits>
#include <typeindex>

#include <compare>

#include <coroutine>

#include <chrono>
#include <ctime>

#include <cstdarg>
#include <cstddef>
#include <cstdlib>

#include <functional>

#include <any>
#include <bitset>
#include <optional>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <initializer_list>
#include <variant>
#include <queue>
#include <deque>
#include <stack>
#include <forward_list>
#include <span>
#include <vector>
#include <list>
#include <array>

#include <iterator>

#include <ranges>

#include <utility>

#include <memory>
#include <memory_resource>
#include <new>
#include <scoped_allocator>

#include <cinttypes>
#include <limits>

#include <cassert>
#include <cerrno>
#include <exception>
#include <stdexcept>
#include <system_error>

#include <string>
#include <string_view>
#include <charconv>
#include <cstring>
#include <cctype>
#include <cuchar>
#include <cwchar>
#include <cwctype>
#include <format>


#include <algorithm>
#include <execution>

#include <bit>
#include <cfenv>
#include <cmath>
#include <complex>
#include <numbers>
#include <numeric>
#include <random>
#include <ratio>
#include <valarray>

#include <clocale>
#include <locale>

#include <iomanip>
#include <ios>
#include <syncstream>
#include <iostream>
#include <fstream>
#include <sstream>

#include <filesystem>

#include <atomic>

#include <barrier>
#include <condition_variable>
#include <future>
#include <latch>
#include <mutex>
#include <semaphore>
#include <shared_mutex>
#include <stop_token>
#include <thread>

namespace kat {

	class ExecutionContext;
	class Engine;
	class App;
}