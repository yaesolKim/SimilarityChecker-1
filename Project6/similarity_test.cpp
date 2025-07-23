#include "gmock/gmock.h"
#include "similarity.cpp"

using namespace testing;
class SimilarityFixture : public Test {
public:
	Similarity similarity;

	void lengthChecker(int score, std::string str1, std::string str2) {
		int length_score = similarity.lengthScore(str1, str2);
		EXPECT_EQ(score, length_score);
	}
	void alphabetChecker(int score, std::string str1, std::string str2) {
		int alphabet_score = similarity.alphabetScore(str1, str2);
		EXPECT_EQ(score, alphabet_score);
	}
};

TEST_F(SimilarityFixture, PerfectLength) {
	lengthChecker(60, "asd", "dsa");
}

TEST_F(SimilarityFixture, DoubleLength) {
	lengthChecker(0, "a", "bb");
}

TEST_F(SimilarityFixture, tc3) {
	lengthChecker(20, "aaabb", "baa");
}

//TEST_F(SimilarityFixture, tc4) {
//	lengthChecker(30, "aa", "aae");
//}


TEST_F(SimilarityFixture, SameAlphabetTC) {
	alphabetChecker(40, "asd", "dsa");
	alphabetChecker(40, "aaabb", "ba");
}

TEST_F(SimilarityFixture, NoSameAlphabetTC) {
	alphabetChecker(0, "a", "bb");
}

TEST_F(SimilarityFixture, PartiallySameAlphabetTC) {
	alphabetChecker(0, "aa", "aae");
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}