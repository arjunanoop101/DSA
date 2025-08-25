// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

#include<bits/stdc++.h>
class Solution {
public:
    void generate(vector<vector<int>>&ans,vector<int> &list, vector<int>&nums,int index){
        if(index == nums.size()){
            ans.push_back(list);
            return;
        }

        list.push_back(nums[index]);
        generate(ans,list,nums,index+1);
        list.pop_back();
        generate(ans,list,nums,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>list;
        generate(ans,list,nums,0);
        return ans;
    }
};