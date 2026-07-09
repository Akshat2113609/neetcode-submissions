class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode(int val){
            this->val = val;
            this->next = nullptr;
        }
};
class LinkedList {

private:
    ListNode* head;
    ListNode* tail;
public:

    LinkedList() {
        head = new ListNode(-1);
        tail = head;
    }

    int get(int index) {
        int cnt=0;
        ListNode* temp = head->next;
        while(temp!=nullptr){
            if(cnt==index){
                return temp->val;
            }
            cnt++;
            temp=temp->next;
        }
    return -1;
    }

    void insertHead(int val) {
        ListNode* newHead = new ListNode(val);
        newHead->next=head->next;
        if(newHead->next==nullptr){
            tail = newHead;
        }
        head->next=newHead;
    }
    
    void insertTail(int val) {
        ListNode* newTail = new ListNode(val);
        tail->next=newTail;
        tail = tail->next;
    }

    bool remove(int index) {
        int cnt=0;
        ListNode* temp = head;
        while(temp->next!=nullptr && cnt<index){
            cnt++;
            temp=temp->next;
        }
        if(temp->next == nullptr) return false;
        ListNode* todelete = temp->next;
        if(todelete == tail){
            tail=temp;
        }
        temp->next = temp->next->next;
        delete todelete;
        return true;
    }

    vector<int> getValues() {
        vector<int>res;
        ListNode*temp = head->next;
        while(temp!=nullptr){
            res.push_back(temp->val);
            temp=temp->next;
        }
    return res;
    }
};
