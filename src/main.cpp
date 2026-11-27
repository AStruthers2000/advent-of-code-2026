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

    std::string line = "HelloSPLIT HEREworld!";
    auto split = AoC::Parse::split_any("Hello world,this-is|a*sentence_with+weird/delims", " ,-|*_+/");
    for (auto word : split)
    {
        std::println("{}", word);
    }

    return 0;
}
