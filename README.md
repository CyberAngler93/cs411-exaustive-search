# cs411-exhaustive-search
This is a soltuion to the bridge toll problem, utilizing exhaustive search.
## About
This depends on a build function that has a couple helper functions
- generate_all_subsets
- compare_bridge_nodes
- max_toll
Give a lsit of bridges that we could build. The goal is to find the best option(make the most money) by use of exhaustive search.
### Important Constraints
1. No city can have more then one bridge to it
2. No bridges can cross
## Things that could be imporved on.
The method of subset generation could be augmented to not include sets that violate the rules stated above while keep track of a max toll. 
Alternatively the method for subset creation could utilize recursive backtracking.
