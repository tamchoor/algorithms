#include "../include/MyBinarySearch.hpp"

namespace MyBinarySearch
{

	int binarySearch(vector<int> &nums, int target)
	{
		int left = 0;
		int right = int(nums.size() - 1);

		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (nums[size_t(mid)] == target){
				return int(mid);
			} else if (nums[size_t(mid)] < target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return -1;
	}

} // MyBinarySearch