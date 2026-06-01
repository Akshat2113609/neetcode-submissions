class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Hashmap solution 
        // TC: O(m*n*logn) sorting and loops
        // SC: O(m*n) Hashmap

        //Hashtable solution
        // TC: O(m*n)
        // SC: O(m*n)+O(n)
        // only applicable for strings with lowercase letters
        unordered_map<string,vector<string>>mp;
        for(auto &it:strs){
            vector<int>cnt(26,0);
            for(char c:it){
                cnt[c-'a']++;
            }
            string key = to_string(cnt[0]);
            for(int i=1;i<26;i++){
                key+='/' + to_string(cnt[i]);
            }
            mp[key].push_back(it);
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
