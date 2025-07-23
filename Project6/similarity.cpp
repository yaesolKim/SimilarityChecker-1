#include <iostream>

class Similarity {
public:
	int lengthScore(std::string a, std::string b) {
		if (a.length() == b.length()) return MAX_LENGTH_POINT;
		if (isLengthDiffLargerThanDouble(a, b)) return MIN_LENGTH_POINT;

		auto len1 = std::max(a.length(), b.length());
		auto len2 = std::min(a.length(), b.length());
		double gap = len1 - len2;
		return static_cast<int>((1 - gap/len2) * 60);
	}

	bool isLengthDiffLargerThanDouble(std::string& a, std::string& b)
	{
		return a.length() >= b.length() * 2 || b.length() >= a.length() * 2;
	}

private:
	const int MAX_LENGTH_POINT = 60;
	const int MIN_LENGTH_POINT = 0;
};