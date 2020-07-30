class Solution {
public:
	int maxArea(vector<int>& height) {
		int len = height.size();
		int ans = 0;
		int area = 0;
		int posL = 0;
		int posR = len - 1;
		while (posL != posR)
		{
			area = (posR - posL) * min(height[posL], height[posR]);
			ans = area > ans ? area : ans;
			if (height[posL] > height[posR])
				posR--;
			else
				posL++;
		}
		return ans;
	}
};