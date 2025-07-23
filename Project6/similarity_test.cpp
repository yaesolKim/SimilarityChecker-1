#include "gmock/gmock.h"
#include "similarity.cpp"

using namespace testing;
class SimilarityFixture : public Test {
public:
	Similarity similarity;

};

TEST_F(SimilarityFixture, tc1) {
	std::string str1 = "asd";
	std::string str2 = "dsa";
	int score = 60;

	EXPECT_EQ(score, similarity.lengthScore(str1, str2));
}

TEST_F(SimilarityFixture, tc2) {
	std::string str1 = "a";
	std::string str2 = "bb";
	int score = 0;

	EXPECT_EQ(score, similarity.lengthScore(str1, str2));
}

TEST_F(SimilarityFixture, tc3) {
	std::string str1 = "aaabb";
	std::string str2 = "baa";
	int score = 20;

	EXPECT_EQ(score, similarity.lengthScore(str1, str2));
}

TEST_F(SimilarityFixture, tc4) {
	std::string str1 = "aa";
	std::string str2 = "aae";
	int score = 30;

	EXPECT_EQ(score, similarity.lengthScore(str1, str2));
}


int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}