#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <numeric>
#include "..\hpp\macros\strings.h"
#include "..\hpp\macros\array.h"


namespace vader {

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


	template<typename T>
	void propagate(
		std::vector<T>& v,
		const T& fill_value
	) {
		auto indexes = nonzero(v);
		std::unordered_set<int> transformed;
		for (std::unordered_set<int>::iterator it = indexes.begin();
			it != indexes.end(); it++) {
			transformed.insert(*it);
			transformed.insert(*it + 1);
			transformed.insert(*it + 2);
			transformed.insert(*it + 3);
		}
		for (int i = 0; i < v.size(); i++)
			if (transformed.find(i) != transformed.end())
				v[i] = fill_value;
			else
				v[i] = 1.0f;
	}


	std::unordered_map<std::string, float> eval(
		std::string& txt,
		const std::unordered_map<std::string, float>& lexicals,
		float alpha = 15.0f
	);
}