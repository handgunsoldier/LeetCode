//
// Created by zhang on 9/13/19.
//

#include <iostream>

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0) return false;
        while (num!=1){
            if(num!=(num>>2<<2)){
                return false;
            }
            num >>= 2;
        }
        return true;
    }
};

int main(int argc, char** argv){
    Solution solution;
    std::cout << solution.isPowerOfFour(8) << std::endl;
}