//
// Created by zhang on 9/8/19.
//

#include <iostream>
#include <vector>

class Solution {
public:
    void decode(const std::string& s) {
        decode(s, 0);
    }

    void decode(const std::string& s, size_t index) {
        if (index > s.size() - 1) {
            display();
            return;
        } else{
            c.push_back('a'-'0'+s[index]);
            decode(s, index+1);
            c.pop_back();
            if(index+1<=s.size()-1){
                int cur = s[index] - '0';
                int next = s[index+1] - '0';
                int temp = 10*cur + next;
                if(temp<=25){
                    c.push_back('a'+temp);
                    decode(s, index+2);
                    c.pop_back();
                }
            }
            return;
        }
    }

    void display() {
        for (const auto& i: c) {
            std::cout << i ;
        }
        std::cout << std::endl;
    }
private:
    std::vector<char> c = {};
};

int main(int argc, char** argv) {
    std::string s = "2222";
    Solution sol;
    sol.decode(s);
}