class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> sumsIndex;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(sumsIndex.find(complement) != sumsIndex.end()){
                return {sumsIndex[complement], i};
            }
            sumsIndex[nums[i]] = i;//Store the number with its index
        }
        return {};
    }
};