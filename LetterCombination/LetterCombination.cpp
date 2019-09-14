//
// Created by zhang on 9/3/19.
//

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> ret = {};
        if(!digits.size()) return ret;
        ret.push_back("");
        std::string num_to_char[] = {
                "0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        for(auto& i: digits){
            std::string cur = "";
            int index = i - '0';
            std::vector<std::string> temp;
            if(index<0 or index>9) return std::vector<std::string>();
            for(auto& j: num_to_char[index]){
                for(auto& l: ret){
                    temp.push_back(l+j);
                }
            }
            ret = temp;
        }
        return ret;
    }
};

int main(int argc, char** argv){
    Solution sol;
    std::string digits = "34";
    auto result = sol.letterCombinations(digits);
    for(auto& i: result){
        std::cout << i << std::endl;
    }
}