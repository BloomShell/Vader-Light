#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <numeric>
#include "..\hpp\utils.h"


namespace vader {

	template<typename T>
	void propagate(
		std::vector<T>& v,
		const T& fill_value
	) {
		auto indexes = Tools::nonzero(v);
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

	float eval(
		std::string& txt,
		const std::unordered_map<std::string, float>& lexicals
	);
}