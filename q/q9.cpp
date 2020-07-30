class Solution {
public:
		bool isPalindrome(int x)
	{
		int inputNum = x;
		int ans = 0;
		if (inputNum < 0)
			return false;
		if (inputNum < 10)
			return true;

		while (inputNum > 0)
		{
			if (abs(ans) > INT32_MAX / 10)
				return false;
			ans *= 10;
			if (abs(ans) > INT32_MAX - abs(inputNum % 10))
				return false;
			ans += inputNum % 10;
			inputNum /= 10;
		}
		return ans == x;
	}
};
