class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) 
	{
		vector<int> ans;
		if (words.empty())
			return ans;
		map<string, int> wordCount;
		map<string, int> wordList;
		int wordSize = words[0].size();
		if (wordSize * words.size() > s.size())
			return ans;
		for (int i = 0; i < words.size(); ++i)
			wordList[words[i]] += 1;

		for (int i = 0; i < s.size(); ++i)
		{
			for (int j = 0; j < words.size(); ++j)
			{
				string substring = s.substr(i + j * wordSize, wordSize);
				if (!wordList.count(substring))
				{
					break;
				}
				else
				{
					wordCount[substring]++;
					if (wordCount[substring] > wordList[substring])
						break;
				}
			}

			if (wordCount == wordList)
			{
				ans.push_back(i);
			}
			wordCount.clear();
		}
		return ans;
	}
};
