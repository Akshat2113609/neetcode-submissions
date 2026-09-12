class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res=0;
        vector<int>pref(n,-1);
        vector<int>suff(n,-1);
        pref[0]=height[0];
        suff[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            pref[i]=max(pref[i-1],height[i]);
        }
        for(int j=n-2;j>=0;j--){
            suff[j]=max(suff[j+1],height[j]);
        }
        for(int i=0;i<n;i++){
            res+=min(pref[i],suff[i])-height[i];
        }
        return res;
    }
};
