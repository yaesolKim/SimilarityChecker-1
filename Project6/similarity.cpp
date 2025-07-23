#include <iostream>

class Similarity {
public:
	int lengthScore(std::string a, std::string b) {
		if (a.length() == b.length()) return 60;
		if (a.length() >= b.length() * 2 || b.length() >= a.length() * 2) return 0;

		
		if (a.length() > b.length()) {
			double gap = (a.length() - b.length()) / b.length();
			return static_cast<int>((1 - gap) * 60);
		}

		double gap = b.length() - a.length();
		return static_cast<int>((1 - gap / a.length()) * 60);

	}
};