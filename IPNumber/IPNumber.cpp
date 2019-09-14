//
// Created by zhang on 9/9/19.
//

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

int64_t IP2Number(const std::string& s, const char split = '.') {
    std::string ret = "";
    std::vector<std::string> res({});
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != split) {
            ret += s[i];
            if (i == s.size() - 1) {
                res.push_back(ret);
            }
        } else {
            res.push_back(ret);
            ret = "";
        }
    }

    std::vector<int64_t> nums({});
    for (const auto& i: res) {
        int64_t temp = 0;
        for (const auto& j: i) {
            temp = temp * 10 + (j - '0');
        }
        nums.push_back(temp);
    }

    std::string invalidIPv4 = "Invalid IPv4 address:\t";
    if (nums.size() != 4) {
        std::cout << invalidIPv4 << "not 4 sub-numbers!\n";
        return 0;
    }
    for (const auto& i: nums) {
        if (i < 0 or i > 255) {
            std::cout << invalidIPv4 << "sub-numbers larger than 255 or less than 0!\n";
            return 0;
        }
    }

    int64_t temp = 0;
    for (int i = 0; i < 4; i++) {
        temp += nums[i] * (1 << ((3 - i) * 8));
    }
    return temp;
}

std::string Number2IP(int64_t IP, const char split = '.') {
    std::string ret = "";
    for (int i = 0; i < 4; i++) {
        size_t bits_number = (3-i)*8;
        ret += std::to_string(IP>>bits_number);
        if(i!=3) ret += ".";
        IP -= IP>>bits_number<<bits_number;
    }
    return ret;
}

int main(int argc, char** argv) {
    std::string s = "192.168.255.255";
    int64_t IP_number = IP2Number(s);
    std::cout << IP_number << std::endl;
    std::cout << Number2IP(IP_number) << std::endl;
    std::cout << Number2IP(3232238233ll) << std::endl;
}
