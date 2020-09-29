//
// Created by Matt Perry 
// This contains the source files for my soultion to the exaustive search for CS411 Hw2
// 

#include "build.h"
// PRE: A vector containing 3 values for a start and end node and cost
// POST: This will return the value of the best toll to build for the bridges given.
int build(int , int , const std::vector<Bridge> & bridges){
    if (bridges.empty()) {
        return 0;
    } 
    else if (bridges.size() == 1) {
        return bridges[0][2];
    } 
    else if(bridges.size() == 2) {
        if(compare_bridge_nodes(bridges[0][0], bridges[0][1], bridges[1][0], bridges[1][1])) {
            return std::max(bridges[0][2], bridges[1][2]);
        } 
        else if (!compare_bridge_nodes(bridges[0][0], bridges[0][1], bridges[1][0], bridges[1][1])) {
            return bridges[0][2] + bridges[1][2];
        }
        return std::max(bridges[0][2], bridges[1][2]);

    } 
    else {
        std::vector<std::vector<Bridge>> all_subsets, legal_subsets;
        generate_all_subsets(bridges, all_subsets);
        return(generate_legal_bridge_sets(all_subsets, legal_subsets));

    }
}

void generate_all_subsets(const std::vector<Bridge> & bridges, std::vector<std::vector<Bridge>> & all_subsets) {
    std::vector<Bridge> subset;
    for(size_t index = 0; index < std::pow(2, bridges.size()); index++) {
        for(size_t i = 0; i < bridges.size(); i++) {
            if(index & (1 << i))
                subset.push_back(bridges[i]);
        }
        all_subsets.push_back(subset);
        subset.clear();
    }
}

int generate_legal_bridge_sets(const std::vector<std::vector<Bridge>> & subsets, std::vector<std::vector<Bridge>> & legal){
    int max = 0;
    for(const auto & set : subsets) {
        int count = 0;
        for (const auto & first : set) {
            count += first[2];
            for (const auto & second : set) {
                if(first != second) {
                    if(compare_bridge_nodes(first[0], first[1], second[0], second[1])){
                        goto end;
                    }

                }
            }
        }
        if( count > max){
            max = count;
        }
        legal.push_back(set);
        end:;

    }
    return max;
}

bool compare_bridge_nodes(const int & a, const int & b, const int & c, const int & d){
    return (a < c && b > d) ||(a > c && b < d) || a == c || b == d;
}
