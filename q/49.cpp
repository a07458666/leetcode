class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		vector<vector<string>> ans;
		unordered_map<string, int> strPos;
		int kind = 0;
		string s;
		for (int i = 0; i < strs.size(); ++i)
		{
			s = strs[i];
			sort(s.begin(), s.end());
			if (strPos.count(s))
			{
				ans[strPos[s]].push_back(strs[i]);
			}
			else
			{
				strPos[s] = kind;
				ans.push_back({ strs[i] });
				kind++;
			}
		}

		return ans;
	}
};