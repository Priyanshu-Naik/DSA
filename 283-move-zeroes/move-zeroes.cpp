class Solution {
public:
    void moveZeroes(vector<int>& nums) {//two pointer approach
        int insertPos = 0;
        int n = nums.size();
        //insert the non-zero elements to the start one by one
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                nums[insertPos] = nums[i];
                insertPos++;
            }
        }
        //Make the remaining elements as zeros
        while(insertPos < n){
            nums[insertPos] = 0;
            insertPos++;
        }
    }
};