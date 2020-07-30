class Solution {
public:
	vector<string> generateParenthesis(int n) 
	{
		vector<string> ans;
		if (n <= 0) return ans;
		ans.push_back("()");
		for (int i = 0; i < n - 1; ++i)
			ans = getTwoBranch(ans);
		return ans;
	}

	vector<string> getTwoBranch(vector<string> in)
	{
		vector<string> result;
		for (int i = 0; i < in.size(); ++i)
		{
			int pos = 0;
			string str(in[i]);
			while (pos < str.size())
			{
				bool isInsert = false;
				if (pos > 0 && str[pos - 1] == '(' && str[pos] == ')')
					isInsert = true;
				else if (str[pos] == '(' && str[pos + 1] == ')')
					isInsert = true;
				if (isInsert)
				{
					string temp(str);
					temp.insert(pos, "()");
					result.push_back(temp);
				}
				pos++;
			}
			str.insert(pos, "()");
			result.push_back(str);
		}
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
};