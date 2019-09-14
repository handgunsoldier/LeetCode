//
// Created by zhang on 9/10/19.
//

#include <iostream>
#include <vector>

class Solution{
public:
    int trap(std::vector<int>& height){
        size_t s = height.size();
        if(!s) return 0;

        std::vector<int> lMax(s, 0);
        std::vector<int> rMax(s, 0);

        for(int i=0; i<s; i++){
            if(i==0) lMax[i] = height[i];
            else{
                lMax[i] = height[i]>lMax[i-1]?height[i]:lMax[i-1];
            }
            printf("lMax[%d] = %d\n", i, lMax[i]);
        }

        for(int i=s-1; i>=0; i--){
            if(i==s-1) rMax[i] = height[i];
            else{
                rMax[i] = height[i] > rMax[i+1]?height[i]:rMax[i+1];
            }
            printf("rMax[%d] = %d\n", i, rMax[i]);
        }

        int ret = 0;
        for(int i=0; i<s; i++){
            ret += std::min(lMax[i],rMax[i]) - height[i];
        }
        return ret;
    }

};

int main(int argc, char** argv){
    Solution sol;
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << sol.trap(height) << std::endl;
}