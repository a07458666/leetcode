class Solution {
public:
	int divide(int dividend, int divisor) 
	{
		int sign = true;
		if (divisor == 1)
			return dividend;
		if (dividend > 0)
		{
			sign = !sign;
			dividend = -dividend;	
		}
			
		if (divisor > 0)
		{
			sign = !sign;
			divisor = -divisor;
		}
		int ans = 0;
		vector<int> odds = { 1 };
		vector<int> divs = { divisor };
		while (dividend <= divisor)
		{
			if (INT32_MIN - divs.back() < divs.back() && divs.back() + divs.back() >= dividend)
			{
				divs.push_back(divs.back() + divs.back());
				odds.push_back(odds.back() + odds.back());
				dividend -= divs.back();
				ans += odds.back();
			}
			else
			{
				if (divs.back() >= dividend)
				{
					dividend -= divs.back();
					if (INT32_MAX - odds.back() < ans)
						return INT32_MAX;
					ans += odds.back();
				}
				divs.pop_back();
				odds.pop_back();
			}
		}
		if (!sign)
			ans = -ans;
		return ans;
	}
};