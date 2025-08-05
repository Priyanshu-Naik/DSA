class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        //this stores the chars and its freq in the map
        for(char c : s){
            freq[c]++;
        }
        //store the unique chars in the vector
        vector<char> chars;
        for(auto it : freq){
            chars.push_back(it.first);
        }
        //now sort the chars acc to the frequency
        sort(chars.begin(), chars.end(), [&](char a, char b){
            if(freq[a] != freq[b]) return freq[a] > freq[b];
            return a < b;
        });
        // Build result string by repeating characters
        string result = "";
        for (char c : chars) {
            result += string(freq[c], c);  // repeat char `freq[c]` times
        }
        return result;   
    }
};