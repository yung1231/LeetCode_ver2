/**
 * Linked List
 */
class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };
    
    MyLinkedList() {
        this->dummyHead = new LinkedNode(0);    // 虛擬頭節點
        this->size = 0; // 紀錄 Linked List 的長度
    }
    
    int get(int index) {
        if(index > size - 1 || index < 0)   // 檢查要得範圍是否合理
            return -1;
        
        LinkedNode* curr = dummyHead->next;
        while(index--) // 遍歷到 index 上的節點
            curr = curr->next;
        
        return curr->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* newHead = new LinkedNode(val);  // 要新增的節點
        
        newHead->next = dummyHead->next;
        dummyHead->next = newHead;
        
        size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* curr = dummyHead;
        
        while(curr->next != nullptr)    // 遍歷到最後面
            curr = curr->next;
        curr->next = new LinkedNode(val);   // 新增
        
        size++;
    }
    
    void addAtIndex(int index, int val) {
        while(index > size || index < 0)    // 檢查要得範圍是否合理
            return ;
        
        LinkedNode* curr = dummyHead;
        LinkedNode* newNode = new LinkedNode(val);  // 要新增的節點
        
        while(index--)  // 遍歷到要新增的位置
            curr = curr->next;
        newNode->next = curr->next;
        curr->next = newNode;
        
        size++;
    }
    
    void deleteAtIndex(int index) {
        LinkedNode* curr = dummyHead;
        
        while(index > size - 1 || index < 0)    // 檢查要得範圍是否合理
            return ;
        
        while(index--)
            curr = curr->next;
        LinkedNode* tmp = curr->next;
        curr->next = curr->next->next;
        delete tmp; // 刪除被拿掉的節點，為了省空間
        size--;
    }
    
private:
    LinkedNode* dummyHead;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

/**
 * curr = dummyHead;
 * while (curr->next != nullptr) {
 *   cout << curr->next->val << " ";
 *   curr = curr->next;
 * }
 * cout << endl;
 */

// ["MyLinkedList","addAtTail","get"]
// [[],[1],[0]]

// ["MyLinkedList","addAtHead","addAtTail","addAtIndex"]
// [[],[1],[3],[3,2]]

// ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
// [[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]