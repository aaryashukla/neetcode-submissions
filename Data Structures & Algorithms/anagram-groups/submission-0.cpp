class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to store {SortedString : List of OriginalStrings}
        unordered_map<string, vector<string>> mpp;

        for (string s : strs) {
            string word = s;
            sort(word.begin(), word.end()); // Signature: sorted version
            mpp[word].push_back(s);
        }

        vector<vector<string>> result;
        for (auto it : mpp) {
            result.push_back(it.second);
        }

        return result;
    }
};