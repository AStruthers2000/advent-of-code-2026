////////////////////////////////////////////////////////////////////////////////////////////////////
/// Copyright (C) 2026 AStruthers2000 - All Rights Reserved
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Utilities for input loading
////////////////////////////////////////////////////////////////////////////////////////////////////
export module aoc.io;

import std;

export namespace AoC::IO
{

enum class InputType
{
    Input,
    Example
};

//--------------------------------------------------------------------------------------------------
auto read_file(std::filesystem::path const& path) -> std::vector<std::string>
{
    std::ifstream in(path);
    if (!in) return {};

    std::vector<std::string> lines{};
    std::string line;
    while (std::getline(in, line))
    {
        lines.push_back(std::move(line));
    }

    return lines;
}

//--------------------------------------------------------------------------------------------------
auto input_path(int day, InputType input_type) -> std::filesystem::path
{
    auto cwd = std::filesystem::current_path();
    std::string day_str = std::format("day{:02d}/", day);
    std::string file_str = input_type == InputType::Input ? "input.txt" : "example.txt";
    cwd.append("input/");
    cwd.append(day_str);
    cwd.append(file_str);
    cwd.make_preferred();
    return cwd;
}

} // namespace AoC::IO
