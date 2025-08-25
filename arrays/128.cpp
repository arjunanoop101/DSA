
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.
#include<bits/stdc++.h>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int maxLenght = 0;
        int lenght = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                continue;
            }
            if(nums[i]+1 == nums[i+1]){
                lenght +=1;
                maxLenght = max(lenght,maxLenght);
            }else{
                lenght = 0;
            }
        }
        return maxLenght+1;
    }
};