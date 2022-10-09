#pragma once
#include <array>
#include <string>
#include <boost/algorithm/string.hpp>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <regex>


namespace Assets {
    const std::array<std::string, 60> INCREMENT = {
        "absolutely", "amazingly", "awfully","completely", "considerable",
        "considerably","decidedly", "deeply", "effing", "enormous", "enormously",
        "entirely", "especially", "exceptional", "exceptionally", "extreme",
        "extremely", "fabulously", "flipping", "flippin", "frackin", "fracking",
        "fricking", "frickin", "frigging", "friggin", "fully", "fuckin", "fucking",
        "fuggin", "fugging","greatly", "hella", "highly", "hugely", "incredible",
        "incredibly", "intensely", "major", "majorly", "more", "most", "particularly",
        "purely", "quite", "really", "remarkably","so", "substantially", "total",
        "totally", "tremendous", "tremendously","thoroughly","uber", "unbelievably",
        "unusually", "utter", "utterly","very" };
    const std::array<std::string, 24> DECREMENT = {
        "almost", "barely", "hardly", "just enough","kind of", "kinda", "kindof",
        "kind-of", "less", "little", "marginal", "marginally","occasional",
        "occasionally", "partly", "scarce", "scarcely", "slight", "slightly",
        "somewhat","sort of", "sorta", "sortof", "sort-of" };
    const std::array<std::string, 60> NEGATE = {
        "aint","arent","cannot","cant","couldnt","darent","didnt","doesnt","don't",
        "ain't","aren't","can't","couldn't", "daren't","didn't","doesn't","dont",
        "hadnt","hasnt","havent","isnt","mightnt","mustnt","neither","don't","hadn't",
        "hasn't","haven't","isn't","mightn't","mustn't","neednt","needn't","never",
        "no","none","nope","nor","not","nothing","nowhere","oughtnt","shant","shouldnt",
        "uhuh","wasnt","werent","oughtn't","shan't","shouldn't","wasn't","weren't",
        "without","wont","wouldnt","won't","wouldn't","rarely","seldom","despite" };
    const std::unordered_map<std::string, float> SINGULAR =
        { {"PBOOST", 1.293f}, {"NBOOST", -1.293f}, {"NEGATIO", -0.74f} };
}

namespace Tools {

    template<typename T, typename ... Types>
    struct is_any : std::bool_constant<(
        std::is_same_v<T, Types> || ...)> {};

    template<typename T>
    std::unordered_set<int> nonzero(
        const std::vector<T>& v
    ) {
        static_assert(is_any<T, float, double, int>::value,
            "Must be vector of doubles, floats or ints.");
        std::unordered_set<int> indexes;
        for (int i = 0; i < v.size(); i++)
            if (v[i] != 0) indexes.insert(i);
        return indexes;
    };

    void scrubstr(
        std::string& input,
        bool tolower = true
    );

    std::vector<std::string> tokenize(
        const std::string& input
    );
}