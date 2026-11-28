////////////////////////////////////////////////////////////////////////////////////////////////////
/// Copyright (C) 2026 AStruthers2000 - All Rights Reserved
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Utilities for spliting/trimming/number extraction
////////////////////////////////////////////////////////////////////////////////////////////////////
export module aoc.parse;

import std;

inline auto split_sv(std::string_view sv, std::string_view delims) -> std::vector<std::string_view>
{
    std::vector<std::string_view> out;
    if (delims.empty()) // ambiguous -> return the whole string as one token
    {
        if (!sv.empty()) out.push_back(sv);
        return out;
    }

    std::size_t pos = 0;
    while (pos <= sv.size())
    {
        auto next = sv.find_first_of(delims, pos);
        if (next != pos) out.push_back(sv.substr(pos, next - pos));
        if (next == std::string_view::npos) break;
        pos = next + 1;
    }

    return out;
}

export namespace AoC::Parse
{

auto split(std::string_view sv, std::string_view delim) -> std::vector<std::string_view>
{
    std::vector<std::string_view> out{};
    if (delim.empty()) // ambiguous -> return the whole string as one token
    {
        if (!sv.empty()) out.push_back(sv);
        return out;
    }

    return sv
        | std::views::split(delim)
        | std::views::transform([](auto&& r) { return std::string_view{ r }; })
        | std::ranges::to<std::vector<std::string_view>>();
}

auto split_any(std::string_view sv, std::string_view delims) -> std::vector<std::string_view>
{
    return split_sv(sv, delims);
}

auto split_lines(std::string_view sv) -> std::vector<std::string_view>
{
    return split_sv(sv, "\n");
}

auto trim(std::string_view sv) -> std::string_view
{
    std::string whitespace{ " \r\t\n" };
    std::size_t const start_pos = sv.find_first_not_of(whitespace);
    std::size_t const end_pos = sv.find_last_not_of(whitespace);
    std::size_t const count = end_pos - start_pos + 1;
    return sv.substr(start_pos, count);
}

auto starts_with(std::string_view sv, std::string_view substr) -> bool
{
    return sv.starts_with(substr);
}

auto ends_with(std::string_view sv, std::string_view substr) -> bool
{
    return sv.ends_with(substr);
}

auto join(std::vector<std::string_view> const& group, std::string_view join_substr) -> std::string
{
    return group
        | std::views::join_with(join_substr)
        | std::ranges::to<std::string>();
}

auto replace(std::string_view sv, std::string_view substr, std::string_view new_substr) -> std::string
{
    return join(split(sv, substr), new_substr);
}

template <typename T>
requires(std::is_integral_v<T>)
auto to_int(std::string_view sv) -> std::optional<T>
{
    auto first = sv.data();
    auto last = sv.data() + sv.size();

    T value{};
    if (sv.empty()) return std::nullopt;

    auto res = std::from_chars(first, last, value, 10);
    if (res.ec != std::errc{} || res.ptr != last) return std::nullopt;

    return value;
}

template <typename T>
requires(std::is_integral_v<T>)
auto extract_ints(std::string_view sv) -> std::vector<T>
{
    auto const is_digit = [](char c) { return c >= '0' && c <= '9'; };

    std::vector<T> out;
    char const* const begin = sv.data();
    char const* const end = begin + sv.size();

    for (char const* p = begin; p < end;)
    {
        // A '-' directly before digits is a sign, unless it follows another digit ("11-22")
        bool const negative = std::is_signed_v<T> && *p == '-' && p + 1 < end && is_digit(p[1])
                              && (p == begin || !is_digit(p[-1]));
        if (!is_digit(*p) && !negative)
        {
            ++p;
            continue;
        }

        T value{};
        auto const [ptr, ec] = std::from_chars(p, end, value);
        if (ec == std::errc{})
        {
            out.push_back(value);
            p = ptr;
        }
        else // out of range: skip the whole number
        {
            ++p;
            while (p < end && is_digit(*p)) ++p;
        }
    }

    return out;
}

} // namespace AoC::Parse
