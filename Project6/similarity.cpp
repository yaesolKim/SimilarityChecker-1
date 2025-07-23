#include <iostream>
#include <set>
#include <unordered_map>

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

	int alphabetScore(std::string a, std::string b) {
		std::set<char> str1, str2, str;

		for (char c : a) {
			str1.insert(c);
			str.insert(c);
		}
		for (char c : b) {
			str2.insert(c);
			str.insert(c);
		}
		
		double totalCnt = str.size();
		double sameCnt = 0;

		for (auto s : str) {
			if (isSameCharFound(str1, s, str2)) {
				sameCnt++;
			}			
		}
		
		if (sameCnt == totalCnt) return MAX_ALPHABET_POINT;
		if (sameCnt == 0) return MIN_ALPHABET_POINT;

		return static_cast<int>((sameCnt/totalCnt) * MAX_ALPHABET_POINT);

	}

	bool isSameCharFound(std::set<char>& str1, char& s, std::set<char>& str2)
	{
		return str1.find(s) != str1.end() && str2.find(s) != str2.end();
	}

	bool isLengthDiffLargerThanDouble(std::string& a, std::string& b)
	{
		return a.length() >= b.length() * 2 || b.length() >= a.length() * 2;
	}

private:
	const int MAX_LENGTH_POINT = 60;
	const int MIN_LENGTH_POINT = 0;

	const int MAX_ALPHABET_POINT = 40;
	const int MIN_ALPHABET_POINT = 0;
};