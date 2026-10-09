/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode *p1=l1;
        ListNode *p2= l2;
        ListNode *p=ans;
        int carry=0;
        while(p1!=nullptr&&p2!=nullptr){
            int sum = p1->val + p2->val + carry;
            p->val = sum % 10;
            carry = sum / 10;

            p1 = p1->next;
            p2 = p2->next;

            if (p1 != nullptr || p2 != nullptr || carry != 0) {
                p->next = new ListNode(0);
                p = p->next;
            }
        }
       while (p1 != nullptr) {
            int sum = p1->val + carry;
            p->val = sum % 10;
            carry = sum / 10;

            p1 = p1->next;

            if (p1 != nullptr || carry != 0) {
                p->next = new ListNode(0);
                p = p->next;
            }
        }
        while (p2 != nullptr) {
            int sum = p2->val + carry;
            p->val = sum % 10;
            carry = sum / 10;

            p2 = p2->next;

            if (p2 != nullptr || carry != 0) {
                p->next = new ListNode(0);
                p = p->next;
            }
        }
        if (carry != 0) {
            p->val = carry;
        }
        return ans;
    }
    
};



class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);                  // 局部虚拟头节点，函数结束时自动销毁
        ListNode* cur = &dummy;
        int carry = 0;                        // 进位
        
        while (l1 || l2 || carry) {
            // 取当前位的值，空则为 0
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            
            int sum = v1 + v2 + carry;
            carry = sum / 10;                 // 新进位
            cur->next = new ListNode(sum % 10);  // 当前位
            cur = cur->next;
            
            // 移动指针
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        
        return dummy.next;
    }
};
