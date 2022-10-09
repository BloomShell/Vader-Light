#include "..\hpp\base.h"
#include "..\hpp\utils.h"


namespace vader {

	float eval(
		std::string& txt,
		const std::unordered_map<std::string, float>& lexicals
	) {
		Tools::scrubstr(txt);
		auto tokens = Tools::tokenize(txt);
		unsigned int n_tokens = tokens.size();

		// Valences;
		std::vector<float> valences(n_tokens, 0.0f);
		for (int i = 0; i < n_tokens; i++)
			if (lexicals.find(tokens[i]) != lexicals.end()) 
				valences[i] = lexicals.at(tokens[i]);

		// Negations;
		std::vector<float> negations(n_tokens, 0.0f);
		for (int i = 0; i < n_tokens; i++)
			if ((std::find(Assets::NEGATE.begin(), Assets::NEGATE.end(),
				tokens[i]) != Assets::NEGATE.end()) || (tokens[i].find("n't")
					!= std::string::npos)) negations[i] =
				Assets::SINGULAR.at("NEGATIO");

		// Increments;
		std::vector<float> increments(n_tokens, 0.0f);
		for (int i = 0; i < n_tokens; i++)
			if ((std::find(Assets::INCREMENT.begin(), Assets::INCREMENT.end(),
				tokens[i]) != Assets::INCREMENT.end())) increments[i] =
				Assets::SINGULAR.at("PBOOST");

		// Decrements;
		std::vector<float> decrements(n_tokens, 0.0f);
		for (int i = 0; i < n_tokens; i++)
			if ((std::find(Assets::DECREMENT.begin(), Assets::DECREMENT.end(),
				tokens[i]) != Assets::DECREMENT.end())) decrements[i] =
				Assets::SINGULAR.at("NBOOST");

		vader::propagate(negations, Assets::SINGULAR.at("NEGATIO"));
		vader::propagate(decrements, Assets::SINGULAR.at("NBOOST"));
		vader::propagate(increments, Assets::SINGULAR.at("PBOOST"));

		std::vector<float> final(valences.size(), 0.0f);
		for (int i = 0; i < final.size(); i++)
			if (valences[i] != 0) 
				final[i] = valences[i] * negations[i] * 
				decrements[i] * increments[i];
		
		return std::accumulate(final.begin(), final.end(), 0.0f);
	};
}