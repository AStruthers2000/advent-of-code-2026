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

    for (auto const& word : std::views::split(sv, delim))
    {
        out.emplace_back(word);
    }
    return out;
}

auto split_any(std::string_view sv, std::string_view delims) -> std::vector<std::string_view>
{
    return split_sv(sv, delims);
}

auto split_lines(std::string_view sv) -> std::vector<std::string_view>
{
    return split_sv(sv, "\n");
}

} // namespace AoC::Parse
