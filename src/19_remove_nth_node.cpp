/*
207 / 207 test cases passed.
Status: Accepted
Runtime: 12 ms

Given a linked list, remove the nth node from the end of list and return its head.
For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode * next_node) : val(x), next(next_node) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0) return NULL;

        vector<ListNode*> nodeVec;
        ListNode * ret = head;

        // iterate the list
        for (ListNode * node = head; node != NULL; node = node->next) {
            nodeVec.push_back(node);
        }

        if (nodeVec.size() <= 0) return NULL;
        if (n > nodeVec.size()) return NULL;

        int targetIndex = nodeVec.size() - n;
        if (targetIndex - 1 >= 0) {  // previous node exist. Current node is not head. 
            (nodeVec[targetIndex - 1])->next = (nodeVec[targetIndex])->next;
        }
        else {  // current node is head
            ret = (nodeVec[targetIndex])->next;
        }

        return ret;
    }
};


int main() {
    // init
    ListNode a0 = ListNode(5);
    ListNode a1 = ListNode(4, &a0);
    ListNode a2 = ListNode(3, &a1);
    ListNode a3 = ListNode(2, &a2);
    ListNode a4 = ListNode(1, &a3);

    int n = 2;

    Solution mysolution = Solution();
    ListNode * ret = mysolution.removeNthFromEnd(&a4, n);

    // print ret
    for (ListNode * i = ret; i != NULL; i = i->next) {
        cout << i->val << endl;
    }

    cin.get();
    return 0;
}

