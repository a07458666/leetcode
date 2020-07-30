class Solution {
public:
	string countAndSay(int n)
	{
		string ans = "1";
		string temp = "";
		if (n == 1)
			return ans;
		for (int i = 1; i < n; ++i)
		{
			char target = ' ';
			int count = 0;
			for (int j = 0; j <= ans.size(); ++j)
			{
				if (count == 0)
				{
					target = ans[j];
					count = 1;
				}
				else if (target != ans[j])
				{
					temp.push_back(count + 48);
					temp.push_back(target);
					target = ans[j];
					count = 1;
				}
				else
				{
					count++;
				}
			}
			ans = temp;
			temp.clear();
		}

		return ans;
	}
};
