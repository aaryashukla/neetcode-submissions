class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(auto num : nums){
            mpp[num]++;   
        }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto const& [val,freq] : mpp){
        pq.push({freq,val});
      
        if(pq.size()>k)   pq.pop();
    }
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
        
    }
};
