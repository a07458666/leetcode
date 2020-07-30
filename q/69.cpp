class Solution {
public:
	int mySqrt(int x) 
	{
		int realAns = sqrt(x);
		long long ans = x / 2;
		long long move = x;
		long long ansV2 = 0;
		long long ansV3 = 0;
		while (true)
		{
			move /= 2;
			move = move == 0 ? 1 : move;
			ansV2 = ans * ans;
			ansV3 = (ans + 1) * (ans + 1);
			if (ansV2 <= x && ansV3 > x)
				break;
			else if (ansV2 > x)
				ans -= move;
			else
				ans += move;
		}
		return ans;
	}
};