class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		if (lists.empty())
			return NULL;
		if (lists.size() == 1)
			return lists[0];
		ListNode* ans = NULL;
		ListNode* current = NULL;
		vector<int> allValue;
		for (int i = 0; i < lists.size(); ++i)
		{
			while (lists[i] != NULL)
			{
				allValue.push_back(lists[i]->val);
				lists[i] = lists[i]->next;
			}
		}
		sort(allValue.begin(), allValue.end());
		for (int i = 0; i < allValue.size(); ++i)
		{
			if (ans == NULL)
			{
				ans = new ListNode(allValue[i]);
				current = ans;
			}
			else
			{
				current->next = new ListNode(allValue[i]);
				current = current->next;
			}
		}
		return ans;
	}
};