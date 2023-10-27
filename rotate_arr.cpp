#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int len = nums.size();
        vector <int> temp(len);

        for (int i = 0; i < len; i++) {
            int c = (i + k)%len;

            temp[c] = nums[i];
        }

        nums = temp;
        return;
    }
    
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    int k = 3;

    Solution s;
    s.rotate(nums, k);

    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}
