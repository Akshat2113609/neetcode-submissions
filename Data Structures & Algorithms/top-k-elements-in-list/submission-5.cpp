class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // using max heap 
        // TC: O(n*logn);
        // SC: O(n) 
        // using min heap
        // TC: O(n*logk)
        // SC: O(n+k)
        unordered_map<int,int>mp;
        for(auto &it:nums){
            mp[it]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto &it:mp){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
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
