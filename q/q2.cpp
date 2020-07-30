class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
if (l1->val == 0 && l1->next == NULL)
			return l2;
		if (l2->val == 0 && l1->next == NULL)
			return l1;
		int num = 0;
		int carry = 0;
		ListNode *first = NULL;
		ListNode *current = NULL;
		do
		{
			num = carry;
			if (l1 != NULL)
				num += l1->val;
			if (l2 != NULL)
				num += l2->val;
			ListNode * temp = new ListNode(num % 10);
			carry = num >= 10 ? 1 : 0;
			if (first == NULL)
			{
				first = temp;
				current = temp;
			}
			else
			{
				current->next = temp;
				current = temp;
			}
			if (l1 != NULL && l1->next != NULL)
				l1 = l1->next;
			else
				l1 = NULL;
			if (l2 != NULL && l2->next != NULL)
				l2 = l2->next;
			else
				l2 = NULL;
		} while (l1 != NULL || l2 != NULL || carry > 0);
		return first;
    }
};