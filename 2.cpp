// Runtime: 24 ms, faster than 99.98%; Memory Usage: 9.8 MB, less than 100.00%

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int getLength(ListNode* start){
    int num = 0;
    while(start){
        num++;
        start = start->next;
    }
    return num;   
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int size1 = getLength(l1);
        int size2 = getLength(l2);
        if(size1 < size2){
            ListNode* temp = l1;
            l1 = l2;
            l2 = temp;
        }
        int c = 0;
        ListNode* start = l1;
        ListNode* pre = l1;
        int sum;
        while(l2){
            sum = l1->val + l2->val + c;
            l1->val = sum % 10;
            c = sum / 10;
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            sum = l1->val + c;
            l1->val = sum % 10;
            c = sum / 10;
            pre = l1;
            l1 = l1->next;
        }
        if(c!= 0)
            pre->next = new ListNode(c);
        return start;
    }
};