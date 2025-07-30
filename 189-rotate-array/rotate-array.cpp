class Solution {
public:
    void reverse(vector<int>& nums, int start, int end){
        while(start < end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n - 1);// reverse whole array
        reverse(nums, 0, k - 1);// reverse the kth elements
        reverse(nums, k, n - 1);//reverse the remaining elements
    }
};