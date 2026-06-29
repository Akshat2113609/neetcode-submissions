class MyHashSet {
public:
    stack<int>st;
    MyHashSet() {
        
    }
    
    void add(int key) {
        st.push(key);
    }
    
    void remove(int key) {
        if(!st.empty() && contains(key)){
            vector<int>arr;
            while(!st.empty()){
                if(st.top()!=key){
                    arr.push_back(st.top());
                }
                st.pop();
            }
            reverse(arr.begin(),arr.end());
            for(auto& it:arr){
                st.push(it);
            }
        }
        else{
            return ;
        }
    }
    
    bool contains(int key) {
        stack<int>check = st;
        while(!check.empty()){
            if(check.top()==key){
                return true;
            }
            check.pop();
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */