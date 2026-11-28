
class Solution {
public:

    /*
        APPROACH: RECURSION (PICK / NOT PICK)

        For every element, we have two choices:
        1. PICK the current element.
        2. NOT PICK the current element.

        How recursion works:

        - First, recursion goes deep through all PICK choices.
        - When it reaches the base case, it stores that subset.
        - Then it returns and uses pop_back() to undo
          the previous choice (BACKTRACKING).
        - It explores the NOT PICK choice.
        - This continues until every possible combination
          is generated.

        Example:
        nums = {1, 2}

        Possible subsets:
        {}, {1}, {2}, {1, 2}

        Total subsets = 2^n
    */

    void f(vector<vector<int>>& subset,
           int ind,
           vector<int>& set,
           vector<int>& nums) {

        int n = nums.size();

        // BASE CASE:
        // All elements have been considered.
        // Store the current subset in the answer.
        if (ind == n) {
            subset.push_back(set);
            return;
        }

        // CASE 1: PICK
        // Include the current element in the subset.
        set.push_back(nums[ind]);

        // Move to the next index with the current
        // element included.
        f(subset, ind + 1, set, nums);

        // BACKTRACKING:
        // Remove the last picked element.
        // Restore the previous state of the subset.
        set.pop_back();

        // CASE 2: NOT PICK
        // Skip the current element and move forward.
        f(subset, ind + 1, set, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        // Stores all possible subsets.
        vector<vector<int>> subset;

        // Stores the current subset.
        // Initially it is empty.
        vector<int> set;

        // Start recursion from index 0.
        f(subset, 0, set, nums);

        // Return all generated subsets.
        return subset;
    }
};
