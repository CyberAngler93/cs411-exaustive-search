//
// Created by Matt Perry 
// This contains the prototypes for functions required for my solution to the exhaustive search for CS411 Hw2
// build.h
// Last updated 9/28/20

#ifndef CS411_HW2_BUILD_H
#define CS411_HW2_BUILD_H
#include <vector>
#include <algorithm>
#include <cmath>
using Bridge = std::vector<int>;
int build(int , int , const std::vector<Bridge> &);
int max_toll(const std::vector<std::vector<Bridge>> &subsets);
void generate_all_subsets(const std::vector<Bridge> &, std::vector<std::vector<Bridge>> &);
bool compare_bridge_nodes(const int &, const int &, const int &, const int &);
#endif //CS411_HW2_BUILD_H
