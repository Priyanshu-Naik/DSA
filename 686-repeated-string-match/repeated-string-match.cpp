class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int cnt = 1;
        while(repeated.length() < b.length()) {
            repeated += a;
            cnt++;
        }
        if (repeated.find(b) != string::npos)
            return cnt;

        repeated += a;
        cnt++;
        if (repeated.find(b) != string::npos)
            return cnt;

        return -1;
    }
};