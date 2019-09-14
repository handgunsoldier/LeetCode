//
// Created by zhang on 9/13/19.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        int L[n], R[n], H[n];
        std::fill_n(L, n, 0);
        std::fill_n(R, n, n);
        std::fill_n(H, n, 0);

        int ret = 0;
        for (int i = 0; i < m; i++) {
            int cur_L = 0, cur_R = n;

            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') H[j]++;
                else H[j] = 0;
            }

            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') L[j] = std::max(L[j], cur_L);
                else {
                    L[j] = 0;
                    cur_L = j + 1;
                }
            }

            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') R[j] = std::min(R[j], cur_R);
                else {
                    R[j] = n;
                    cur_R = j;
                }
            }

            for (int j = 0; j < n; j++) {
                int temp = (R[j] - L[j]) * H[j];
                ret = std::max(ret, temp);
            }
        }
        return ret;
    }
};

int main(int argc, char** argv) {
    Solution solution;
    std::vector<std::vector<char>> input = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };
    input = {{'1', '0'}};
    std::cout << solution.maximalRectangle(input) << std::endl;
}