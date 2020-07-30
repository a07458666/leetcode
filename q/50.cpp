class Solution {
public:
	double myPow(double x, int n) 
	{
		bool isNe = false;
		double temp = 1;
		if (n == 0 || x == 1)
			return 1;
		else if (x == 0)
			return 0;
		else if (n < 0)
		{
			if (n == INT32_MIN)
			{
				n = INT32_MAX;
				temp = x;
			}	
			else
				n *= -1;
			isNe = true;
		}
		while (n != 1)
		{
			if (n % 2 == 0)
			{
				x *= x;
				n /= 2;
			}
			else
			{
				temp *= x;
				n--;
			}
		}
		if (isNe)
			return 1 / (x * temp);
		else
			return x * temp;
	}
};