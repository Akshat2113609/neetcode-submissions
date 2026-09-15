class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.size();
        int size2 = s2.size();
        if(size1 > size2){
            return false;
        }
        vector<int>hash(26,0);
        for(auto& it:s1){
            hash[it-'a']++;
        }
        vector<int>newhash(26,0);
        for(int i=0;i<size1;i++){
            newhash[s2[i]-'a']++;
        }
        if(hash==newhash){
            return true;
        }
        int i = 0;
        int j = size1;
        while(j<size2){
            newhash[s2[i]-'a']--;
            i++;
            newhash[s2[j]-'a']++;
            j++;
            if(hash==newhash){
                return true;
            }
        }
    return false;
    }
};
