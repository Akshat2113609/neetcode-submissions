/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* DFS(vector<vector<int>>& grid, int n, int r, int c){
       // bool allSame = true;
        if(n==1){
            return new Node(grid[r][c]==1,true);
        }
        int mid = n/2;
        Node* topLeft = DFS(grid,mid,r,c);
        Node* topRight = DFS(grid,mid,r,c+mid);
        Node* bottomLeft = DFS(grid,mid,r+mid,c);
        Node* bottomRight = DFS(grid,mid,r+mid,c+mid);
        if(topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf
        && bottomRight->isLeaf && topRight->val == topLeft->val &&
        topRight->val == bottomLeft->val && topRight->val == bottomRight->val) {
            return new Node(topRight->val,true);
        }

        return new Node(false,false,topLeft,topRight,bottomLeft,bottomRight);

    }
    Node* construct(vector<vector<int>>& grid) {
        return DFS(grid,grid.size(),0,0);
    }
};