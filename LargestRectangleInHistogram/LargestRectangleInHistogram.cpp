//
// Created by zhang on 9/13/19.
//

#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
//    int largestRectangleArea(std::vector<int>& heights) {
//        int n = heights.size();
//        if (n == 0)
//            return 0;
//        if (n == 1)
//            return heights[0];
////        std::vector<int> L(n, 0);
////        std::vector<int> R(n, n-1);
//        int* L = new int[n];
//        int* R = new int[n];
//
//        L[0] = 0;
//        for (int i = 1; i < n; i++) {
//            int temp = 0;
//            for (int j = i - 1; i >= 0; j--) {
//                if (heights[j] < heights[i]) {
//                    temp = j + 1;
//                    break;
//                }
//            }
//            L[i] = temp;
//        }
//
//        R[n - 1] = n - 1;
//        for (int i = 0; i < n; i++) {
//            int temp = n - 1;
//            for (int j = i + 1; j < n; j++) {
//                if (heights[j] < heights[i]) {
//                    temp = j - 1;
//                    break;
//                }
//            }
//            R[i] = temp;
//        }
//
//        int ret = 0;
//        for (int i = 0; i < n; i++) {
//            int temp = (R[i] - L[i] + 1) * heights[i];
////            std::cout << L[i] << "\t" << R[i] << ":\t" << temp << std::endl;
//            ret = (ret >= temp ? ret : temp);
//        }
//
//        delete[] L;
//        delete[] R;
//        return ret;
//    }
    int largestRectangleArea(std::vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        if (n == 1) return heights[0];
        std::stack<int> s={};
        int ret = 0;

        for(int i=0; i<n; i++){
            if(s.empty() or heights[i]>=s.top()){
                s.push(heights[i]);
            } else{
                int last = s.top();
                s.pop();
                int area = heights[last]*(s.empty() ? );
            }
        }

    }
};

int main(int argc, char** argv) {
    Solution solution;
    std::vector<int> heights = {2, 1, 5, 6, 2, 3};
//    heights = {1, 1};
//    heights = {1, 2, 3, 4, 5};
    heights = {2, 1, 5, 6, 2, 3};
    std::cout << solution.largestRectangleArea(heights) << std::endl;
}