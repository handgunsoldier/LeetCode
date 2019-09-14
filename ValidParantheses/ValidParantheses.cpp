//
// Created by zhang on 9/3/19.
//

#include <stack>
#include <string>
#include <iostream>


class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> c;
        for(auto& i: s){
            if(i=='(' or i=='{' or i=='['){
                c.push(i);
            }else if(i==')' and !c.empty() and c.top()=='('){
                c.pop();
            }else if(i=='}' and !c.empty() and c.top()=='{'){
                c.pop();
            }else if(i==']' and !c.empty() and c.top()=='['){
                c.pop();
            } else{
                return false;
            }
        }
        if(c.empty()) return  true;
        return false;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::string s = "(()[{}()])";
    s = "]";
    std::cout << sol.isValid(s) << std::endl;

}
