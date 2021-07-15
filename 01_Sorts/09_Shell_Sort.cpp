#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n.log(n))
// Space Complexity: O(1)
// Adaptability: True
// Stable: False
// K-Passes: False

void shellSort(vector<int> &nums)
{
    int n = nums.size();
    int gap = ceil(n / 2);

    while (gap > 0)
    {
        int i = gap;
        while (i < n)
        {
            int j = i;
            while (j >= gap and nums[j] < nums[j - gap])
            {
                swap(nums[j], nums[j - gap]);
                j -= gap;
            }
            i++;
        }
        gap /= 2;
    }
}

int main()
{
    vector<int> nums{2, 331, 97, 4, 9, 22, 6, 5, 10};
    shellSort(nums);
    for (auto i : nums)
        cout << i << " ";
    cout << endl;
    return 0;
}