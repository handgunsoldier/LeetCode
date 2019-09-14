//
// Created by zhang on 9/13/19.
//

#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int nums_size = nums.size();
        std::unordered_map<int, int> M;
        for(const auto& i: nums){
            M[i] +=1;
            std::cout << "Key:\t" <<i << ", Value:\t" << M[i] << std::endl;
        }

        for(const auto i: M){
            std::cout << i.first << ":" << i.second << std::endl;
            if(i.second>=(nums_size+1)/2) return i.first;
        }
        return -1;
    }
};

int main(int argc, char** argv){
    Solution solution;
    std::vector<int> arr = {3,2,3,4,4,4};
    std::cout << solution.majorityElement(arr) << std::endl;

}