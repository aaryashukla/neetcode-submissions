class Solution {
public:
    int findMin(vector<int> &nums) {
        sort(nums.begin(),nums.end());
        int MINI = INT_MAX;
        for(int i =0;i<nums.size(); i++){
            if(nums[i]<MINI){
                MINI = nums[i];
            }

        }
        return MINI;
        
        
    }
};
