class Solution {
public:
	string multiply(string num1, string num2) 
	{
		string ans;
		int len1 = num1.size();
		int len2 = num2.size();
		if (num1.size() == 1 && num1[0] == '0')
			return "0";
		if (num2.size() == 1 && num2[0] == '0')
			return "0"; 
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		int len = num1.size() + num2.size();
		int* ansVal = new int[len + 1];
		fill(ansVal, ansVal + len, 0);
		int carry = 0;
		int add = 0;
		int val1;
		int val2;
		for (int i = 0; i < len1; ++i)
		{
			val1 = len1 <= i ? 1 : num1[i] - 48;
			for (int j = 0; j < len2; ++j)
			{
				val2 = len2 <= j ? 1 : num2[j] - 48;
				ansVal[i + j] += (val1 * val2);
			}
		}
		for (int i = 0; i < len; ++i)
		{
			ansVal[i + 1] += ansVal[i] / 10;
			ansVal[i] = ansVal[i] % 10;
		}
		bool noZero = false;
		for (int i = len - 1; i >= 0; --i)
		{
			if (ansVal[i] != 0)
				noZero = true;
			if (noZero)
				ans = ans + char(ansVal[i] + 48);
		}
		return ans;
	}
};