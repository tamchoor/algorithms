#include <vector>

/**
 * @brief binary search algorithm
 *
 */
namespace MyBinarySearch
{

	using std::vector;

	/**
	 * @brief Find the required element in a sorted array by
	 * repeatedly halving the array and searching in the half.
	 *
	 * @param nums the sorted vector
	 * @param target the required element
	 * @return index of the required element in the vector
	 *
	 */
	int binarySearch(vector<int> &nums, int target);

} // MyBinarySearch