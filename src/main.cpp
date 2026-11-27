import std;
import aoc;

int main()
{
    // using AoC::IO::read_file;
    // using AoC::IO::input_path;
    // using AoC::IO::InputType;
    // auto lines = read_file(input_path(10, InputType::Example));
    // for (auto const& line : lines)
    // {
    //     std::println("{}", line);
    // }

    std::string line = "ccc: ddd eee fff";
    auto split = AoC::Parse::split(std::string_view{line}.substr(5), " ");
    for (auto word : split)
    {
        std::print("{} ", word);
    }

    return 0;
}
