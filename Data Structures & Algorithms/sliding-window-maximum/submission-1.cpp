class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int maxx=INT_MIN;
        vector<int>ans;
        deque<int>q;
        int i=0;
        int j=0;
        while(i<n){
           while(!q.empty() && nums[q.back()]<nums[i]){
                q.pop_back();
           }
           q.push_back(i);
           if(j > q.front()){
                q.pop_front();
           }
           if((i+1)>=k){
            ans.push_back(nums[q.front()]);
            j++;
           }
           i++;
        }
    return ans;
    }
};
