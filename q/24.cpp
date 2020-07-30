class Solution {
public:
	ListNode* swapPairs(ListNode* head)
	{
		ListNode newHead(0);
		newHead.next = head;
		ListNode* currect = &newHead;
		bool isSwap = true;
		while (currect != NULL)
		{
			if (isSwap)
			{
				swapTwoNode(currect, currect->next);
			}
			isSwap = !isSwap;
			currect = currect->next;
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