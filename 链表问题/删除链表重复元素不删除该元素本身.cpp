//
// Created by sooglejay on 16/12/23.
//

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode *re = head;
        while (head != nullptr && head->next != nullptr) {
            int ta = head->val;
            ListNode *tem = head->next;
            while (tem != nullptr && tem->val == ta) {
                tem = tem->next;
            }
            head->next = tem;
            head = tem;
        }
        return re;
    }
};


int main() {
    Solution ss = Solution();
    ListNode nod1 = ListNode(3);
    ListNode nod2 = ListNode(2);
    ListNode nod3 = ListNode(3);
    ListNode nod4 = ListNode(3);
    ListNode nod5 = ListNode(4);
    ListNode nod6 = ListNode(5);
    ListNode nod7 = ListNode(6);
    nod1.next = &nod2;
    nod2.next = &nod3;
    nod3.next = &nod4;
    nod4.next = &nod5;
    nod5.next = &nod6;
    nod6.next = &nod7;

    ListNode *h = ss.removeElements(&nod1, 3);

    while (h) {
        cout << h->val << ' ';
        h = h->next;
    }


}