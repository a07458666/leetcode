class Solution {
public:
	vector<string> letterCombinations(string digits) 
	{
		vector<string> ans;
		if (digits.size() < 1)
			return ans;
		map<char, string>	keyPoint = 
		{ 
			{ '2',"abc" },
			{ '3',"def" },
			{ '4',"ghi" },
			{ '5',"jkl" },
			{ '6',"mno" },
			{ '7',"pqrs" },
			{ '8',"tuv" },
			{ '9',"wxyz" }
		};
		ans.push_back("");
		for (int i = 0; i < digits.size(); ++i)
		{
			string key = keyPoint[digits[i]];
			ans = allResult(ans, key);
		}
		return ans;
	}

	vector<string> allResult(vector<string> s1, string s2)
	{
		vector<string> result;
		for (int i = 0; i < s1.size(); ++i)
		{
			for (int j = 0; j < s2.size(); ++j)
			{
				string temp(s1[i]);
				temp += s2[j];
				result.push_back(temp);
			}
		}
		return result;
	}
};