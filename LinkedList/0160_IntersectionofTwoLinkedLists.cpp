/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currA = headA;
        ListNode* currB = headB;
        int lenA = 0, lenB = 0;
        
        while(currA != NULL){   // 統計長度
            currA = currA->next;
            lenA++;
        }
        while(currB != NULL){   // 統計長度
            currB = currB->next;
            lenB++;
        }
        
        currA = headA;
        currB = headB;
        while(lenA > lenB){ // 讓長度統一
            currA = currA->next;
            lenA--;
        }
        while(lenA < lenB){ // 讓長度統一
            currB = currB->next;
            lenB--;
        }
        
        while(currA != NULL){  // 遍歷比較
            if(currA == currB)  // 若相同則返回(這裡相同是要 val 和 pointer 值都要一樣)
                return currA;
            currA = currA->next;    // 往下一個節點
            currB = currB->next;    // 往下一個節點
        }
        
        return NULL;    // 沒有一樣的 返回 NULL
    }
};

/**
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currA = headA;
        ListNode* currB = headB;
        int lenA = 0, lenB = 0;
        
        while(currA != NULL){   // 統計長度
            currA = currA->next;
            lenA++;
        }
        while(currB != NULL){   // 統計長度
            currB = currB->next;
            lenB++;
        }
        
        currA = headA;
        currB = headB;
        if(lenA < lenB){   // 將最長的保持在 A 上
            swap(lenA, lenB);
            swap(currA, currB);
        }
        
        int diff = lenA - lenB;
        while(diff--)
            currA = currA->next;
        
        for(int i = 0; i < lenB; i++){  // 遍歷比較
            if(currA == currB)  // 若相同則返回(這裡相同是要 val 和 pointer 值都要一樣)
                return currA;
            currA = currA->next;    // 往下一個節點
            currB = currB->next;    // 往下一個節點
        }
        
        return NULL;    // 沒有一樣的 返回 NULL
    }
};
*/