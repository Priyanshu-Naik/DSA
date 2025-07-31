class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixFreq;
        prefixFreq[0] = 1; // base case for sum = k starting from index 0

        int count = 0;
        int sum = 0;

        for (int num : nums) {
            sum += num;

            // Check if there's a prefix sum that makes (sum - k)
            if (prefixFreq.find(sum - k) != prefixFreq.end()) {
                count += prefixFreq[sum - k];
            }

            // Record current sum
            prefixFreq[sum]++;
        }

        return count;
    }
};