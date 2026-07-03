class NumMatrix {
public:
    vector<vector<int>>mat;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        mat=vector<vector<int>>(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            int pref=0;
            for(int j=0;j<m;j++){
                pref+=matrix[i][j];
                mat[i+1][j+1]=pref+mat[i][j+1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        row2++;
        col1++;
        col2++;
        int bottomRight = mat[row2][col2];
        int left = mat[row2][col1-1];
        int above = mat[row1-1][col2];
        int topLeft = mat[row1-1][col1-1];
        return bottomRight-left-above+topLeft;
    }
};