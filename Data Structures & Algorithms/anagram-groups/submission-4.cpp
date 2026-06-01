class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(auto &it:strs){
            string key=it;
            sort(key.begin(),key.end());
            mp[key]={};
        }
        for(auto &it:strs){
            string uk=it;
            sort(uk.begin(),uk.end());
            if(mp.find(uk)!=mp.end()){
                mp[uk].push_back(it);
            }
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
