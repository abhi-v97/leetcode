/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

struct ListNode
{
	int				 val;
	struct ListNode *next;
};

struct ListNode *addTwoNumbersRecursive(struct ListNode *l1, struct ListNode *l2, int carry)
{
	int sum;

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
	struct ListNode *new = (struct ListNode *) malloc(sizeof(struct ListNode));
	new->val = sum % 10;
	new->next = addTwoNumbersRecursive(l1, l2, sum / 10);
	return (new);
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	return (addTwoNumbersRecursive(l1, l2, 0));
}
