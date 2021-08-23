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