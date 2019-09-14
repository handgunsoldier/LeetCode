//
// Created by zhang on 9/3/19.
//

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string countAndSay(int n) {
        if(n<=1) return std::to_string(1);
        std::string last = countAndSay(n-1);
        std::string ret = "";
        int cur = 0;
        for(int i=0; i < last.size(); i++){
            cur++;
            if(i+1<last.size() and last[i+1] == last[i]){
                continue;
            } else {
                ret += std::to_string(cur);
                ret += last[i];
                cur = 0;
            }
        }
        return ret;
    }
};

int main(int argc, char** argv){
    Solution sol;
//    for(int i=1; i<=30; i++){
//        std::cout << sol.countAndSay(i) << std::endl;
//    }
    std::cout << sol.countAndSay(6) << std::endl;
    return 0;
}
