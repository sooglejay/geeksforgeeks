//
// Created by sooglejay on 16/12/23.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here

        ListNode *res = head;
        int i = 0, j = 0, size = 0;
        while (head != nullptr) {
            size++;
            head = head->next;
        }
        while (true) {
            head = res;
            i = 0;
            j = 0;

            while (head != nullptr && head->next != nullptr) {
                ListNode *res = head;
                int cur = head->val;
                int nextVal = head->next->val;
                if (cur > nextVal) {
                    head->next->val = cur;
                    head->val = nextVal;
                    j = 0;
                } else {
                    j++;
                }
                head = head->next;
                i++;
                if (i >= size-1) {
                    break;
                }
            }
            if (i == j && j == size-1) {
                break;
            }
        }
        return res;


    }
};

int main() {
    Solution ss = Solution();
    ListNode nod1 = ListNode(3);
    ListNode nod2 = ListNode(4);
    ListNode nod3 = ListNode(1);
    ListNode nod4 = ListNode(12);
    ListNode nod5 = ListNode(11);
    ListNode nod6 = ListNode(11);
    ListNode nod7 = ListNode(11);
    ListNode nod8 = ListNode(11);
    ListNode nod9 = ListNode(11);
    ListNode nod10 = ListNode(10);
    ListNode nod11 = ListNode(10);
    nod1.next = &nod2;
    nod2.next = &nod3;
    nod3.next = &nod4;
    nod4.next = &nod5;
    nod5.next = &nod6;
    nod6.next = &nod7;
    nod7.next = &nod8;
    nod8.next = &nod9;
    nod9.next = &nod10;
    nod10.next = &nod11;

    ListNode *h = ss.removeElements(&nod1, 3);

    while (h) {
        cout << h->val << ' ';
        h = h->next;
    }


}