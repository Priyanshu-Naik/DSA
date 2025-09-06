class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        //traverse from right
        while(i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }
        //When we run the loop:
		//Start from i = n-2 = 1 (nums[1] = 1).
		//Compare nums[1] (1) with nums[2] (5).
		//Since 1 < 5, the condition nums[i] >= nums[i+1] is false → loop stops.
        //So the pivot is at index 1 (0-based).
        if(i >= 0){
            int j = n-1;
            while(nums[j] <= nums[i]){
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};