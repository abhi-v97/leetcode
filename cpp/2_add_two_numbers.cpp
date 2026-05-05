// Definition for singly-linked list.
struct ListNode
{
	int		  val;
	ListNode *next;

	ListNode(): val(0), next(nullptr)
	{
	}

	ListNode(int x): val(x), next(nullptr)
	{
	}

	ListNode(int x, ListNode *next): val(x), next(next)
	{
	}
};

#include <cstdlib>

class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		return (addTwoNumbersRecursive(l1, l2, 0));
	}

	ListNode *addTwoNumbersRecursive(ListNode *l1, ListNode *l2, int carry)
	{
		int sum = 0;

		if (l1 == NULL && l2 == NULL && carry == 0)
			return (NULL);
		sum = carry;
		if (l1)
		{
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2)
		{
			sum += l2->val;
			l2 = l2->next;
		}
		ListNode *node = new ListNode(sum % 10, addTwoNumbersRecursive(l1, l2, sum / 10));
		return (node);
	}
};
