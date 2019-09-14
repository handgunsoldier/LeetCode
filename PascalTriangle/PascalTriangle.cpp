//
// Created by zhang on 9/11/19.
//

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> ret(numRows);
        for(int i=0; i<numRows; i++){
            ret[i].push_back(1);
            for(int j=1; j<i+1; j++){
                ret[i].push_back(ret[i-1][j-1] + ret[i-1][j]);
            }
        }
        return ret;
    }

    void display(const std::vector<std::vector<int>>& s){
        for (const auto& i: s) {
            for (const auto& j: i) {
               std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }
};


int main(){
    Solution sol;
    auto s = sol.generate(5);
    sol.display(s);
}