//
// Created by sooglejay on 16/12/21.
//

/***
 *
 * Given a singly linked list of integers, Your task is to complete a function that returns true if the given list is palindrome, else returns false.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T testcases follow. Each test case contains 2 line the first line contains an integer N denoting the size of the linked list. In the next line are N space separated values of the nodes of the linked list.

Output:
For each test case output will be 1 if the linked list is a pallindrome else 0.

Constraints:
1<=T<=1000
1<=N<=50

Example(To be used only for expected output):
Input
2
3
1 2 1
4
1 2 3 4

Output:
1
0

**For More Examples Use Expected Output**


 *
 * @param head
 * @return
 */

/*The structure of the Node is
struct Node
{
    int data;
    struct Node* next;
};*/

/*You are required to complete this method */
bool isPalindrome(Node *head) {
    //Your code here
    char *list = (char *) malloc(sizeof(char) * 51);
    int i = 0;
    while (head) {
        list[i] = head->data;
        i++;
        head = head->next;
    }

    int e = i - 1;
    int s = 0;
    while (s < e) {
        if (list[s] == list[e]) {
            s++;
            e--;
        } else {
            break;
        }
    }
    return s >= e;

}