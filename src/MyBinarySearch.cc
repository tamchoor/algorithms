#include "../include/MyBinarySearch.hpp"

namespace MyBinarySearch
{

	int binarySearch(vector<int> &nums, int target)
	{
		unsigned long left = 0;
		unsigned long right = nums.size();

		while (left < right)
		{
			unsigned long mid = left + (right - left) / 2;
			if (nums[mid] <= target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}

		if (left > 0 && nums[left - 1] == target)
		{
			return int(left - 1);
		}
		else
		{
			return -1;
		}
	}

} // MyBinarySearch