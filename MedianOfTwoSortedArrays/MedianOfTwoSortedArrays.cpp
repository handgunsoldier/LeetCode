//
// Created by zhang on 9/3/19.
//

#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if(!nums1.size() and !nums2.size()) return -1.;
        if(!nums1.size()) return findMedianSingleSortedArray(nums2);
        if(!nums2.size()) return findMedianSingleSortedArray(nums1);
        int index1 = 0; int index2 = 0;
        int index_median = (nums1.size()+nums2.size())/2;
        std::vector<int> v(nums1.size()+nums2.size(), -10);
        int index = index1 + index2;
        while (index<=index_median){
            bool is1 = false;
            if(index2>=nums2.size()) is1 = true;
            else if(index1>=nums1.size()) is1= false;
            else if(nums1[index1] < nums2[index2]) is1 = true;
            else is1 = false;
            if(is1){
                v[index] = nums1[index1];
                index1++;
            } else{
                v[index] = nums2[index2];
                index2++;
            }
            index = index1 + index2;
        }
        if((nums1.size()+nums2.size())%2){
            return static_cast<double>(v[index_median]);
        } else{
            return (static_cast<double>(v[index_median]) +
                static_cast<double>(v[index_median-1]))/2.;
        }
    }

    double findMedianSingleSortedArray(std::vector<int>& nums){
        if(!nums.size()) return -1.;
        double  ret = 0.f;
        if(nums.size()%2==0){
            int index1 = nums.size()/2-1;
            int index2 = nums.size()/2;
            ret = (static_cast<double>(nums[index1]
                    + static_cast<double>(nums[index2])))/2.f;
        } else{
            int index = nums.size()/2;
            ret = static_cast<double>(nums[index]);
        }
        return ret;
    }
};

int main(int argc, char** argv){
    Solution sol;
    std::vector<int> v1 = {1};
    std::vector<int> v2 = {2};
    std::cout << sol.findMedianSortedArrays(v1, v2) << std::endl;
}