class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) 
	{
		if (head == NULL || k == 0)
			return head;
		ListNode* currect = head;
		int len = 1;
		while (currect->next != NULL)
		{
			currect = currect->next;
			len++;
		}
		currect->next = head;
		k = k % len;
		for (int i = 0; i < len - k; ++i)
		{
			head = head->next;
			currect = currect->next;
		}
		currect->next = NULL;
		return head;
	}
};