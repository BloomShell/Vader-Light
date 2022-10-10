#include "..\hpp\base.h"
#include "..\hpp\macros\strings.h"


namespace vader {

	float eval(
		std::string& txt,
		const std::unordered_map<std::string, float>& lexicals
	) {
		scrubstr(txt);
		auto tokens = tokenize(txt);
		unsigned int n_tokens = tokens.size();

		// Valences;
		std::vector<float> valences(n_tokens, 0.0f);
		for (int i = 0; i < n_tokens; i++)
			if (lexicals.find(tokens[i]) != lexicals.end()) 
				valences[i] = lexicals.at(tokens[i]);

		// Negations;
		std::vector<float> negations(n_tokens, 0.0f);
		for (int i = 0; i < n_tokens; i++)
			if ((std::find(vader::NEGATE.begin(), vader::NEGATE.end(),
				tokens[i]) != vader::NEGATE.end()) || (tokens[i].find("n't")
					!= std::string::npos)) negations[i] =
				vader::SINGULAR.at("NEGATIO");

		// Increments;
		std::vector<float> increments(n_tokens, 0.0f);
		for (int i = 0; i < n_tokens; i++)
			if ((std::find(vader::INCREMENT.begin(), vader::INCREMENT.end(),
				tokens[i]) != vader::INCREMENT.end())) increments[i] =
				vader::SINGULAR.at("PBOOST");

		// Decrements;
		std::vector<float> decrements(n_tokens, 0.0f);
		for (int i = 0; i < n_tokens; i++)
			if ((std::find(vader::DECREMENT.begin(), vader::DECREMENT.end(),
				tokens[i]) != vader::DECREMENT.end())) decrements[i] =
				vader::SINGULAR.at("NBOOST");

		vader::propagate(negations, vader::SINGULAR.at("NEGATIO"));
		vader::propagate(decrements, vader::SINGULAR.at("NBOOST"));
		vader::propagate(increments, vader::SINGULAR.at("PBOOST"));

		std::vector<float> final(valences.size(), 0.0f);
		for (int i = 0; i < final.size(); i++)
			if (valences[i] != 0) 
				final[i] = valences[i] * negations[i] * 
				decrements[i] * increments[i];
		
		return std::accumulate(final.begin(), final.end(), 0.0f);
	};
}