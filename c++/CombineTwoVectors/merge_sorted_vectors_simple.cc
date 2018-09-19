#include <iostream>
#include <vector>
#include <unordered_map>

// Complete the hourglassSum function below.

std::vector<std::pair<int, int>> union_pairs(const std::vector<std::pair<int, int>>& myseta,
        const std::vector<std::pair<int, int>>& mysetb) {
    
    std::unordered_map<int, int> my_map;

    for (auto kv_pair : myseta) {
        my_map.insert(kv_pair);
    }
    for (auto kv_pair : mysetb) {
        my_map[kv_pair.first] += kv_pair.second;
    }
    
    std::vector<std::pair<int, int>> output_pairs;
    output_pairs.reserve(my_map.size());
    
    for (auto key_val : my_map) {
        int key = key_val.first;
        int sum_vals = key_val.second;
        std::cout << key << " " << sum_vals << std::endl;
    }
    return output_pairs;
}

int main(int argc, char**argv) {
    std::vector<std::pair<int, int>> seta;
    std::vector<std::pair<int, int>> setb;
    
    seta.push_back({1,2});
    seta.push_back(std::make_pair(2,4));
    seta.emplace_back(9,3);
    seta.emplace_back(4,2);
    seta.emplace_back(7,5);
    seta.emplace_back(23,100);
    
    setb.insert(setb.end(), {{9,4}, {1,1000}, {23,123}, {7,7}, {8,8}, {11,11}});
    setb.push_back(std::make_pair(50,3));
    
    union_pairs(seta, setb);
    return 0;
}