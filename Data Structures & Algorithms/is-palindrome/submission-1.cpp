class Solution {
public:
    bool isAlphaNum(char c){
        if((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0'&&c<='9')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        string processed =  "";
        for(auto& it:s){
            if(isAlphaNum(it)){
                processed+=tolower(it);
            }
        }
        cout<<processed<<endl;
        int n = processed.size();
        int low=0;
        int high = n-1;
        while(low<high){
            if(processed[low]!=processed[high]){
                return false;
            }
            else{
                low++;
                high--;
            }
        }
    return true;
    }
};
