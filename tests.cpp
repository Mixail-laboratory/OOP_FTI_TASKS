#include <gtest/gtest.h>
#include "ultimateSqrt.h"

const double err = 1.e-7;

TEST(Numbers,NoError) {
    int i_value = 4;
    double d_value = 9;
    long l_value = 49;
    ASSERT_EQ(sqrT(i_value), 2);
    ASSERT_EQ(sqrT(d_value), (double) 3);
    ASSERT_EQ(sqrT(l_value), (long) 7);
}

TEST(Numbers,Error) {
    int i_value = -4;
    double d_value = -9;
    long l_value = -49;
    ASSERT_THROW(sqrT(i_value), std::invalid_argument);
    ASSERT_THROW(sqrT(d_value), std::invalid_argument);
    ASSERT_THROW(sqrT(l_value), std::invalid_argument);
}

TEST(Maps, NoError) {
    std::map<std::string, int> inp {{"first", 1}, {"second", 2}, {"third", 3}};
    auto res = sqrT(inp);
    for(auto const & x: res){
        double i = 1;
        ASSERT_DOUBLE_EQ(x.second, sqrt(i));
        i++;
    }
    std::map<std::string, std::map<std::string, int>> inp2 {{"first map in inp2", inp}};
    auto res2 = sqrT(inp2);
    ASSERT_EQ(res2.at("first map in inp2"), res);
    std::unordered_map <int, double> inp3 = {{1, 1}, {2,4}, {3, 9}, {4, 16}};
    std::unordered_map <int, double> res3 = {{1, 1}, {2,2}, {3, 3}, {4, 4}};
    ASSERT_EQ(res3, sqrT(inp3));
}

TEST(Maps, Error) {
std::map <int, double> inp = {{1, 1}, {2,4}, {3, -9}, {4, 16}};
std::unordered_map <int, double> inp2 = {{1, 1}, {2,-4}, {3, 9}, {4, 16}};
ASSERT_THROW(sqrT(inp), std::invalid_argument);
ASSERT_THROW(sqrT(inp2), std::invalid_argument);
}

TEST(Vector, NoError) {
    std::vector<double> inp = {1,2,3,4,5,6,7,8,9};
    auto res = sqrT(inp);
    double i = 1;
    for(auto const &  x: res){
        ASSERT_DOUBLE_EQ(x, sqrt(i));
        i++;
    }

    std::vector<int> inp2 = {1,2,3,4,5,6,7,8,9};
    auto res2 = sqrT(inp);
    i = 1;
    for(auto const &  x: res2){
        ASSERT_DOUBLE_EQ(x, sqrt(i));
        i++;
    }
}

TEST(Vector, Error) {
    std::vector<double> inp = {1,-2,3,4,5,6,7,8,9};
    std::vector<int> inp2 = {1,2,3,4,-5,6,7,8,9};
    ASSERT_THROW(sqrT(inp), std::invalid_argument);
    ASSERT_THROW(sqrT(inp2), std::invalid_argument);    

}

TEST(List, NoError) {
    std::list<double> inp = {1,2,3,4,5,6,7,8,9};
    auto res = sqrT(inp);
    double i = 1;
    for(auto const &  x: res){
        ASSERT_DOUBLE_EQ(x, sqrt(i));
        i++;
    }

    std::list<int> inp2 = {1,2,3,4,5,6,7,8,9};
    auto res2 = sqrT(inp);
    i = 1;
    for(auto const &  x: res2){
        ASSERT_DOUBLE_EQ(x, sqrt(i));
        i++;
    }
}

TEST(List, Error) {
    std::list<double> inp = {1,-2,3,4,5,6,7,8,9};
    std::list<int> inp2 = {1,2,3,4,-5,6,7,8,9};
    ASSERT_THROW(sqrT(inp), std::invalid_argument);
    ASSERT_THROW(sqrT(inp2), std::invalid_argument);    

}


TEST(ForList, NoError) {
    std::forward_list<double> inp = {1,2,3,4,5,6,7,8,9};
    auto res = sqrT(inp);
    double i = 1;
    for(auto x: res){
        ASSERT_DOUBLE_EQ(x, sqrt(i));
        i++;
    }

    std::forward_list<int> inp2 = {1,2,3,4,5,6,7,8,9};
    auto res2 = sqrT(inp);
    i = 1;
    for(auto const &  x: res2){
        ASSERT_DOUBLE_EQ(x, sqrt(i));
        i++;
    }
}

TEST(ForList, Error) {
    std::forward_list<double> inp = {1,-2,3,4,5,6,7,8,9};
    std::forward_list<int> inp2 = {1,2,3,4,-5,6,7,8,9};
    ASSERT_THROW(sqrT(inp), std::invalid_argument);
    ASSERT_THROW(sqrT(inp2), std::invalid_argument);    

}

TEST(Set, NoError) {
    std::set<double> inp = {1,2,3,4,5,6,7,8,9};
    auto res = sqrT(inp);
    double i = 1;
    for(auto const &  x: res){
        ASSERT_DOUBLE_EQ(x, sqrt(i));
        i++;
    }

    std::set<int> inp2 = {1,2,3,4,5,6,7,8,9};
    auto res2 = sqrT(inp);
    i = 1;
    for(auto const & x: res2){
        ASSERT_DOUBLE_EQ(x, sqrt(i));
        i++;
    }
}

TEST(Set, Error) {
    std::set<double> inp = {1,-2,3,4,5,6,7,8,9};
    std::set<int> inp2 = {1,2,3,4,-5,6,7,8,9};
    ASSERT_THROW(sqrT(inp), std::invalid_argument);
    ASSERT_THROW(sqrT(inp2), std::invalid_argument);    

}

TEST(UnorSet, NoError) {
    std::unordered_set<double> inp = {1,2,3,4,5,6,7,8,9};
    std::unordered_set<double> res = {1, sqrt(7), sqrt(2), sqrt(5), sqrt(3), sqrt(4),sqrt(6), sqrt(8), sqrt(9)};
    auto res2 = sqrT(inp);
    ASSERT_EQ(res2, res);
}

TEST(UnorSet, Error) {
    std::unordered_set<double> inp = {1,-2,3,4,5,6,7,8,9};
    std::unordered_set<int> inp2 = {1,2,3,4,-5,6,7,8,9};
    ASSERT_THROW(sqrT(inp), std::invalid_argument);
    ASSERT_THROW(sqrT(inp2), std::invalid_argument);    

}