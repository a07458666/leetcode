
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		if (head->next == NULL && n == 1)
			return NULL;
		ListNode* tail = head;
		ListNode* tail_n = NULL;
		int pos = 0;
		int aaa = tail->val;
		while (tail->next != NULL)
		{
			tail = tail->next;
			pos++;
			aaa = tail->val;
			if (pos == n)
				tail_n = head;
			else if (tail_n != NULL && pos > n)
				tail_n = tail_n->next;
		}
		if (tail_n != NULL)
		{
			tail_n->next = tail_n->next->next;
		}
		else
		{
			head = head->next;
		}
		return head;
	}
};