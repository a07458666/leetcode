class Solution {
public:
	int reverse(int x) 
	{
		int ans = 0;
		int temp = 0;
		if (abs(x) < 10)
			return x;
		bool firstZero = true;
		while (x != 0)
		{
			if (firstZero && x % 10 == 0)
			{
				firstZero = true;
			}
			else
			{
				if (abs(ans) > INT32_MAX / 10)
					return 0;
				ans *= 10;
				temp = x % 10;
				if (abs(ans) > INT32_MAX - abs(temp))
					return 0;
				ans += temp;
				firstZero = false;
			}
			x /= 10;
		}
		return ans;
	}
};