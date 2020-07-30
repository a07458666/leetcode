class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) 
	{
		if (strs.empty())
			return "";
		int index = 0;
		while (true)
		{
			if (strs[0].size() == index)
				return strs[0].substr(0, index);
			char target = strs[0][index];
			for (int i = 1; i < strs.size(); ++i)
			{
				if (strs[i].size() == index)
					return strs[0].substr(0, index);
				if (strs[i][index] != target)
					return strs[0].substr(0, index);
			}
			index++;
		}
	}
};