
class Solution {
public:
	string addBinary(string a, string b) 
	{
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		string ans;
		bool carry = false;
		int sum = 0;
		for (int i = 0; i < max(a.size(), b.size()); ++i)
		{
			sum = 0;
			if (i < a.size() && a[i] == '1') sum++;
			if (i < b.size() && b[i] == '1') sum++;
			if (carry) sum++;
			if (sum % 2 == 1)
			{
				ans.push_back('1');
			}
			else
			{
				ans.push_back('0');
			}
			if (sum > 1)
				carry = true;
			else
				carry = false;
		}
		if (carry)
			ans.push_back('1');
		reverse(ans.begin(), ans.end());
		return ans;
	}
};