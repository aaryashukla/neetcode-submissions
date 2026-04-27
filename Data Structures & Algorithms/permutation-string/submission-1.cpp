class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1hash(26,0);
        vector<int> s2hash(26,0);
        
        int s1len = s1.size();
        int s2len = s2.size();

        if(s1len > s2len){
            return false;
        }

        int left = 0;
        int right = 0;

        // build initial window
        while(right < s1len){
            s1hash[s1[right] - 'a']++;
            s2hash[s2[right] - 'a']++;
            right++;
        }

        right -= 1;

        // sliding window
        while(right < s2len){
            if(s1hash == s2hash){
                return true;
            }

            right += 1;

            if(right != s2len){
                s2hash[s2[right] - 'a']++;   // add new char
                s2hash[s2[left] - 'a']--;    // remove old char
                left++;
            }
        }

        return false;
    }
};