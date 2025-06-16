#include <iostream>
using namespace std;

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
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* currentL1 = l1;
        ListNode* currentL2 = l2;
        ListNode* resultL3 = nullptr;
        int carry = 0;
        do {
			int val = 0;

			if (currentL1) {
				val += currentL1->val;
			}
			if (currentL2) {
				val += currentL2->val;
			}

            val += carry;
            carry = val / 10;
            val = val % 10;
            ListNode* temp = new ListNode(val);
			currentL1 = currentL1?currentL1->next:nullptr;
			currentL2 = currentL2? currentL2->next:nullptr;
			if (resultL3) {
				ListNode* last = resultL3;
				while (last->next) {
					last = last->next;
				}
				last->next = temp;
			}
			else {
				resultL3 = temp;
			}

        } while (currentL1 || currentL2);

		if (carry > 0) {
			ListNode* temp = new ListNode(carry);
			if (resultL3) {
				ListNode* last = resultL3;
				while (last->next) {
					last = last->next;
				}
				last->next = temp;
			}
			else {
				resultL3 = temp;
			}
		}
		return resultL3;
    }
};

//
//int main() {
//	Solution solution;
//	ListNode* l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
//	ListNode* l2 = new ListNode(9, new ListNode(9, new ListNode(9,new ListNode(9))));
//	ListNode* result = solution.addTwoNumbers(l1, l2);
//	// Print the result
//	while (result) {
//		cout << result->val << " ";
//		result = result->next;
//	}
//	cout << endl;
//	// Clean up memory
//	delete l1->next->next;
//	delete l1->next;
//	delete l1;
//	delete l2->next->next;
//	delete l2->next;
//	delete l2;
//
//	return 0;
//}