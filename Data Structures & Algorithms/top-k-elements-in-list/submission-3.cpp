class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto &it:nums){
            mp[it]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto &it:mp){
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(k>0){
            int val=pq.top().second;
            ans.push_back(val);
            pq.pop();
            k--;
        }
        return ans;
    }
};
