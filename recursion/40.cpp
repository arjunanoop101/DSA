// Given a collection of candidate numbers (candidates) and a target number (target), 
// find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

    #include <bits/stdc++.h>
    using namespace std;

    class Solution {
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> list;

            sort(candidates.begin(), candidates.end()); // Important for duplicates & pruning
            fun(ans, list, candidates, 0, target, 0);
            return ans;
        }

        void fun(vector<vector<int>>& ans, vector<int>& list, vector<int>& candidates,
                int sum, int target, int index) {

            // If sum equals target, store the combination
            if (sum == target) {
                ans.push_back(list);
                return;
            }

            // Stop recursion if out of bounds or sum exceeds target
            if (index >= candidates.size() || sum > target) {
                return;
            }

            for (int i = index; i < candidates.size(); i++) {
                // Skip duplicate numbers at the same recursion depth
                if (i > index && candidates[i] == candidates[i - 1]) continue;

                list.push_back(candidates[i]); // Choose the number

                // Move to next index (i + 1) since we cannot reuse same element
                fun(ans, list, candidates, sum + candidates[i], target, i + 1);

                list.pop_back(); // Backtrack
            }
        }
    };

