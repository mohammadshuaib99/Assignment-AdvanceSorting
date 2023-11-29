#include <iostream>
#include <vector>

int mergeAndCount(std::vector<int> &nums, int left, int mid, int right)
{
    int count = 0;

    int j = mid + 1;

    for (int i = left; i <= mid; i++)
    {
        while (j <= right && nums[i] > 2LL * nums[j])
        {
            j++;
        }
        count += (j - mid - 1);
    }

    // Merge the two sorted halves
    std::vector<int> temp(right - left + 1);
    int i = left;
    j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j])
        {
            temp[k++] = nums[i++];
        }
        else
        {
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = nums[i++];
    }

    while (j <= right)
    {
        temp[k++] = nums[j++];
    }

    for (int p = 0; p < k; p++)
    {
        nums[left + p] = temp[p];
    }

    return count;
}

int mergeSortAndCount(std::vector<int> &nums, int left, int right)
{
    if (left >= right)
    {
        return 0;
    }

    int mid = left + (right - left) / 2;
    int count = 0;

    count += mergeSortAndCount(nums, left, mid);
    count += mergeSortAndCount(nums, mid + 1, right);
    count += mergeAndCount(nums, left, mid, right);

    return count;
}

int reversePairs(std::vector<int> &nums)
{
    return mergeSortAndCount(nums, 0, nums.size() - 1);
}

int main()
{
    std::vector<int> nums = {1, 3, 2, 3, 1};

    int result = reversePairs(nums);

    std::cout << "Number of reverse pairs: " << result << std::endl;

    return 0;
}
