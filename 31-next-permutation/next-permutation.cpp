class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        // Step 1: Find the first index from the right where arr[i] < arr[i + 1]
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }
        // Step 2: If no such index, it's the last permutation → reverse to
        // first
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // Step 3: Find the smallest element on the right of 'ind' that is
        // greater than arr[ind]
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        // Step 4: Reverse the subarray to the right of 'ind'
        reverse(nums.begin() + ind + 1, nums.end());
        return;
    }
};