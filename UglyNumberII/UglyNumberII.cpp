//
// Created by zhang on 9/13/19.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> ret(n, 0);
        ret[0] = 1;
        if(n<=1) return 1;
        int u2 = 0, u3 = 0, u5 = 0;
        for(int i=1; i<n; i++) {
            ret[i] = std::min(2 * ret[u2], std::min(3 * ret[u3], 5 * ret[u5]));
            if (ret[i] == 2 * ret[u2]) u2++;
            if (ret[i] == 3 * ret[u3]) u3++;
            if (ret[i] == 5 * ret[u5]) u5++;
        }
//        for (const auto& j: ret) {
//            std::cout << j << " ";
//        }
//        std::cout << std::endl;
        return ret[n-1];
    }
};

int main(int argc, char** argv){
    Solution solution;
    std::cout << solution.nthUglyNumber(15) << std::endl;
}