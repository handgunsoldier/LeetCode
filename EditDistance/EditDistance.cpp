//
// Created by zhang on 9/11/19.
//

#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        size_t s1 = word1.size();
        size_t s2 = word2.size();
        if(!s1)
            return s2;
        if(!s2)
            return s1;
//        std::vector<std::vector<int>> dp(s1 + 1, std::vector<int>(s2 + 1, 0));
        int dp[s1+1][s2+1];
        for (int i = 0; i < s1+1; i++) dp[i][0] = i;
        for (int i = 0; i < s2+1; i++) dp[0][i] = i;
        for (int i = 1; i < s1 + 1; i++) {
            for (int j = 1; j < s2 + 1; j++) {
                int r1 = dp[i][j - 1] + 1;
                int r2 = dp[i - 1][j] + 1;
                int r3 = dp[i - 1][j - 1] + (word1[i-1] == word2[j-1] ? 0 : 1);
                dp[i][j] = std::min(std::min(r1, r2), r3);
            }
        }
        return dp[s1][s2];
    }
};

int main(int argc, char** argv){
    Solution solution;
    std::string word1 = "horse";
    std::string word2 = "ros";
    std::cout << solution.minDistance(word1, word2) << std::endl;
    word1 = "intention";
    word2 = "execution";
    std::cout << solution.minDistance(word1, word2) << std::endl;
}