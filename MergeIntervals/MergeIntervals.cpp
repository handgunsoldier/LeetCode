//
// Created by zhang on 9/8/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::vector<std::vector<int>> s;
        if (intervals.size() == 0) return s;
        auto compare = [](const std::vector<int>& v1, const std::vector<int>& v2) { return v1[0] < v2[0]; };
        std::sort(intervals.begin(), intervals.end(), compare);
//        show(intervals);
        int first = -1;
        int second = -1;
        for (int i = 0; i < intervals.size(); i++) {
            if (first<0 and second<0) {
                first = intervals[i][0];
                second = intervals[i][1];
            } else if (intervals[i][0] <= second) {
                if (intervals[i][1] > second) second = intervals[i][1];
            } else {
                std::vector<int> res = {first, second};
                s.push_back(res);
                first = intervals[i][0];
                second = intervals[i][1];
            }
            if(i==intervals.size()-1){
                s.push_back(std::vector<int>({first, second}));
            }
        }
        return s;
    }

    void show(const std::vector<std::vector<int>>& res) {
        for (const auto& i: res) {
            for (const auto& j: i) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }

};


int main(int argc, char** argv) {
    Solution sol;
    std::vector<std::vector<int>> intervals = {{2,  6},
                                               {1,  3},
                                               {8,  10},
                                               {15, 18}};

    intervals = {{1,4},{4,5}};
    intervals = {{1,2},{0,0}};
    auto ret = sol.merge(intervals);
    sol.show(ret);
    std::cout << ret.size() <<std::endl;
    return 0;
}