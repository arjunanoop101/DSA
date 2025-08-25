// The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
// More formally, if all the permutations of the array are sorted in one container according to their lexicographical order,
// then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible,
// the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
#include<bits/stdc++.h>

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind=-1;

        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind ==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(int i=nums.size()-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[ind],nums[i]);
                break;
            }
        }

        int l = ind+1;
        int r = nums.size()-1;
        while(l<r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }

    }
};