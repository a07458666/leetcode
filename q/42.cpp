class Solution {
public:
		int trap(vector<int>& height)
	{
		int ans = 0;
		if (height.size() < 3)
			return ans;
		vector<int> leftWall(height.size(), 0);
		vector<int> RightWall(height.size(), 0);

		for (int i = 1; i < height.size(); ++i)
		{
			int posR = height.size() - 1 - i;
			leftWall[i] = (max(height[i - 1], leftWall[i - 1]));
			RightWall[posR] = (max(height[posR + 1], RightWall[posR + 1]));
		}
		for (int i = 1; i < height.size() - 1; ++i)
		{
			ans += max(min(leftWall[i], RightWall[i]) - height[i], 0);
		}
		return ans;
	}
};