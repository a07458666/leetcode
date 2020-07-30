class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		if (head == NULL)
			return NULL;
		if (k == 0)
			return head;
		ListNode newHead(0);
		newHead.next = head;
		ListNode* currect = &newHead;
		while (currect != NULL)
		{
			ListNode* tempR = currect;
			ListNode* tempL = currect;
			for (int i = 0; i < k / 2; ++i)
			{
				tempR = tempL;
				for (int j = 1 + (i * 2); j < k; ++j)
				{
					tempR = tempR->next;
					if (tempR->next == NULL)
						return newHead.next;
				}
				swapTwoNode(tempL, tempR);
				tempL = tempL->next;
			}

			for (int i = 0; i < k; ++i)
			{
				currect = currect->next;
				if (currect->next == NULL)
					return newHead.next;
			}
		}
		return newHead.next;
	}

	//將n1,n2的next交換   n1->t1 ---- n2->t2->??
	void swapTwoNode(ListNode* n1, ListNode* n2)
	{
		if (n1->next == NULL || n2->next == NULL)
			return;
		swap(n1->next, n2->next);
		if (n1->next->next == NULL)
		{
			n1->next->next = n2->next->next;
			n2->next->next = NULL;
		}
		else if (n2->next->next == NULL)
		{
			n2->next->next = n1->next->next;
			n1->next->next = NULL;
		}
		else
			swap(n1->next->next, n2->next->next);	
	}
};