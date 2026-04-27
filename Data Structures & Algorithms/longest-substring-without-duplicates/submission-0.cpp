class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256,-1);
        int l = 0;
        int maxlen = 0;
        for(int r = 0; r<s.size(); r++){
            if(last[s[r]]>=l){// duplicate found!!!!
            l = last[s[r]]+1;
            } 
            last[s[r]]= r;
            maxlen = max(maxlen,r-l+1);
        }
        return maxlen;
        
    }
};
