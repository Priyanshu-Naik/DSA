class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        int count = 0;
        int End_time = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < End_time){
                count++;
            }
            else{
                End_time = intervals[i][1];
            }
        }
        return count;
    }
};