#include "gtest/gtest.h"
#include "/OOP_FTI_Tasks/Tasks/Tasks/sort.h"
TEST(oneElem, Vectors) {
    std::vector<int>  testVector = { 1 };
    EXPECT_NO_THROW(sortFunction::sort(testVector.begin(), testVector.end(), std::less<int>{}));

}

TEST(noElem, Vectors) {
    std::vector<int>  testVector;
    EXPECT_NO_THROW(sortFunction::sort(testVector.begin(), testVector.end(), std::less<int>{}));

}

TEST(someElem, Vectors) {
    std::vector<int>  testVector = {3,2,1};
    std::vector<int>  sortedVector = { 1,2,3 };
    sortFunction::sort(testVector.begin(), testVector.end(), std::less<int>{});
    EXPECT_EQ(testVector, sortedVector);
}



TEST(manyElem, Vectors) {
    std::vector<int> testVector(1000);
    for (auto& iterVector : testVector) {
        iterVector = rand();
    }
    std::vector<int>  sortedVector(testVector);
    std::sort(sortedVector.begin(), sortedVector.end());
    sortFunction::sort(testVector.begin(), testVector.end(), std::less<int>{});
    EXPECT_EQ(testVector, sortedVector);
}

