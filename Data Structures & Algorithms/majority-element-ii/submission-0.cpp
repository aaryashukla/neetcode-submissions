class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        vector<int>ans;
        for(auto it : nums){
            mpp[it]++;
        }
        for(auto count : mpp){
            if(count.second>n/3){
                ans.push_back(count.first);
            }
        }
        return ans;
    }
};