class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<int, int> hashTable;
		int maxLen = 0;
		int first = 0;
		for (int end = 0; end < s.size();end++)
		{
			int data = s.at(end);
			if (hashTable.count(data) == 1 && hashTable[data] + 1 > first)
			{
				first = hashTable[data] + 1;
			}
			hashTable[data] = end;
			maxLen = (end - first) + 1 > maxLen ? (end - first) + 1 : maxLen;
		}
		return maxLen;
	}
};