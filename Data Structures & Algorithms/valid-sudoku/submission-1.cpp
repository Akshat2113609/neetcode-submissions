class Solution {
public:
    bool validCheck(vector<char>nums){
        set<char>st;
        int cnt=0;
        for(auto it:nums){
           if(it == '.'){
            continue;
           }
           if(st.find(it)!=st.end()){
            return false;
           }
           st.insert(it);
        }
        return true;
    }
    bool subGridCheck(vector<vector<char>>& board){
        map<pair<int,int>,set<char>>mp;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(mp[{i/3,j/3}].find(board[i][j])!=mp[{i/3,j/3}].end()){
                    return false;
                }
                mp[{i/3,j/3}].insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            if(!validCheck(board[i])){
                return false;
            }
        }
        vector<vector<char>>cols;
        for(int i=0;i<9;i++){
            vector<char>temp;
            for(int j=0;j<9;j++){
                temp.push_back(board[j][i]);
            }
            cols.push_back(temp);
        }
        for(int i=0;i<9;i++){
            if(!validCheck(cols[i])){
                return false;
            }
        }
        if(!subGridCheck(board)){
            return false;
        }
        return true;
    }
};
