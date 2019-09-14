//
// Created by zhang on 9/8/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        int count = 0;
        if (intervals.size()==0) return count;
        auto compare = [](const std::vector<int>& v1, const std::vector<int>& v2){ return v1[0]< v2[0];};
        std::sort(intervals.begin(), intervals.end(), compare);
        std::vector<int> pre = intervals[0];
        for(int i = 1; i<intervals.size(); i++){
            if(intervals[i][0] < pre[1]){
                count++;
                if(intervals[i][1] < pre[1]){
                    pre = intervals[i];
                }
            } else{
                pre = intervals[i];
            }
        }
        return count;
    }
};

int main(int argc, char** argv){
    Solution sol;
    std::vector<std::vector<int>> intervals = {{1,3},{2,3},{3,4},{1,2}};
    std::cout << sol.eraseOverlapIntervals(intervals) << std::endl;
    return 0;
}