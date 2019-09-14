//
// Created by zhang on 9/3/19.
//

#include <iostream>
#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if(numRows<=1)
            return s;
        std::string ret = "";
        for(int i=0; i < numRows; i++){
            int j = i;
            int d1 = 2*(numRows-i-1);
            int d2 = 2*i;
            bool odd = true;
            while (j<s.size()){
                ret += s[j];
                if(!d1) j += d2;
                else if(!d2) j+=d1;
                else {
                    j += odd ? d1 : d2;
                    odd = !odd;
                }
            }
        }
        return ret;
    }
};

int main(int argc, char** argv){
    Solution sol;
    std::string s = "PAYPALISHIRING";
    std::cout << sol.convert(s, 4) << std::endl;
}