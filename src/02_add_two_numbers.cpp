// Source : https://leetcode.com/problems/add-two-numbers/
// Author : coolspeed
// Date   : 2015-04-26

/********************************************************************************** 
* 
* You are given two linked lists representing two non-negative numbers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.
* 
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
*               
**********************************************************************************/

#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(NULL) {}

	ListNode(int x, ListNode * next_node) : val(x), next(next_node) {}
};


class Solution {
public:
	int carry;
	ListNode * previous_node;  // node of ret

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode * head = NULL;

		while (true) {
			// break
			if (l1 == NULL && l2 == NULL && this->carry == 0) {
				break;
			}

			int sum;
			int first_num, second_num;
			// 3 inputs: l1, l2, carry
			// 3 outputs: ret, carry, node address cache
			if (l1 == NULL)
				first_num = 0;
			else
				first_num = l1->val;
			if (l2 == NULL)
				second_num = 0;
			else
				second_num = l2->val;

			sum = first_num + second_num + this->carry;
			int ret_num = sum % 10;
			
			ListNode * curr_node = new ListNode(ret_num);  // output current node

			this->carry = (int)((sum / 10) > 0);  // output carry
			if (this->previous_node != NULL) this->previous_node->next = curr_node; // set previous node to point to current node
			this->previous_node = curr_node; // output node address cache

			// output head
			if (head == NULL) head = curr_node;

			// set up next
			if (l1 != NULL) l1 = l1->next;
			if (l2 != NULL) l2 = l2->next;
			
		}

		return head;
	}
};


void _delete_list(ListNode * node) {
	if (node == NULL) {
		return;
	}
	else {
		if (node->next != NULL) {
			_delete_list(node->next);
		}

		delete node;
	}
}


int main(int argc, char ** argv){
	// set up
	ListNode node13 = ListNode(5);
	ListNode node12 = ListNode(4, &node13);
	ListNode node11 = ListNode(2, &node12);
	
	ListNode node23 = ListNode(4);
	ListNode node22 = ListNode(6, &node23);
	ListNode node21 = ListNode(5, &node22);

	ListNode * l1 = & node11;
	ListNode * l2 = & node21;
	Solution mysolution = Solution();

	// run the solution
	ListNode * myresult = mysolution.addTwoNumbers(l1, l2);

	// print the result
	for (ListNode * i = myresult; i != NULL; i = i->next) {
		cout << i->val << endl;
	}

	// GC
	_delete_list(myresult);

	cin.get();
	return 0;
}


