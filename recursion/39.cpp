// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. 
//  may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. 
// Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>list;

        fun(ans,list,candidates,0,target,0);
        return ans;
    }

    void fun(vector<vector<int>>&ans,vector<int>&list,vector<int>&candidates,int sum, int target,int index){
        if(sum == target){
            ans.push_back(list);
            return;
        }
        if(sum > target || index == candidates.size()){
            return;
        }

        list.push_back(candidates[index]);
        fun(ans,list,candidates,sum+candidates[index],target,index);
        list.pop_back();
        fun(ans,list,candidates,sum,target,index+1);
    }
};