//
// Created by zhang on 9/13/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        combination(candidates, 0, target);
        return ret_;
    }

    void combination(const std::vector<int>& candidates, int start, int target){
        if(target<0) return;
        if(target==0){
            ret_.push_back(temp_);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            if(candidates[i]>target) return;
            if(i>0 and candidates[i]==candidates[i-1] and i> start) continue;
            temp_.push_back(candidates[i]);
            combination(candidates, i+1, target-candidates[i]);
            temp_.pop_back();
        }

    };

private:
    std::vector<int> temp_={};
    std::vector<std::vector<int>> ret_ = {};
};

int main(int argc, char** argv){
    Solution solution;
    std::vector<int> candidates = {10,1,2,7,6,1,5};
    auto ret = solution.combinationSum2(candidates, 8);
    for (const auto& i: ret) {
        for (const auto& j: i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

