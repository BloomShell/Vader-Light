#include "..\hpp\utils.h"


namespace Tools {

    void scrubstr(
        std::string& input,
        bool tolower
    )
    {
        input = std::regex_replace(input, std::regex("[^\\w\']+"), " ");
        input = std::regex_replace(input, std::regex("\\s+"), " ");
        if (tolower) std::for_each(input.begin(), input.end(),
            [](char& c) { c = std::tolower(c); });
        boost::trim_right(input);
        boost::trim_left(input);
    }

    std::vector<std::string> tokenize(
        const std::string& input
    ) {
        std::vector<std::string> tokens;
        boost::split(tokens, input, boost::is_any_of(" "));
        return tokens;
    }
}