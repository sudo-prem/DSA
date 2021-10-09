#include <bits/stdc++.h>
using namespace std;

// == Analysis =========================================
// Time Complexity: O(n.log(n))
// Space Complexity: O(1)
// Adaptability: True
// Stability: False
// K-Passes: False
// Algorithm:
//  Take a variable gap initialised to ceil(n/2) and
//  comapare elements at gap distance apart and swap.
//  Reduce gap by half and continue comaparing with
//  the new gap, and so on until gap becomes 0

void shellSort(vector<int> &nums)
{
    int n = nums.size();

    for (int gap = ceil(n / 2.0); gap >= 1; gap = ceil(gap / 2.0))
    {
        for (int i = gap; i < n; ++i)
        {
            for (int j = i; j - gap >= 0; j -= gap)
            {
                if (nums[j] < nums[j - gap])
                    swap(nums[j], nums[j - gap]);
                else
                    break;
            }
        }
        if (gap == 1)
            break;
    }
}

int main()
{
    vector<int> nums{2, 331, 97, 4, 9, 22, 6, 5, 10};

    shellSort(nums);
    for (int i : nums)
        cout << i << " ";
    cout << endl;

    return 0;
}