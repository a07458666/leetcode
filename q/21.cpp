class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		if (l1 == NULL)
			return l2;
		else if (l2 == NULL)
			return l1;
		else if (l1 == NULL && l2 == NULL)
			return NULL;
		ListNode* ans = NULL;
		ListNode* current = NULL;

		while (l1 != NULL && l2 != NULL)
		{
			int val = 0;
			if (l1->val < l2->val)
			{
				val = l1->val;
				l1 = l1->next;
			}
			else
			{
				val = l2->val;
				l2 = l2->next;
			}
			if (ans == NULL)
			{
				ans = new ListNode(val);
				current = ans;
			}
			else
			{
				current->next = new ListNode(val);
				current = current->next;
			}
		}
		if (l1 != NULL)
			current->next = l1;
		else if (l2 != NULL)
			current->next = l2;
		return ans;
	}
};