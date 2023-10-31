

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool canJump(vector <int> & nums) {
            int last = nums.size() - 1;

            for (int i = last; i > -1; i--){
                if (i + nums[i] >= last) {
                    last = i;
                }
            }
            return last == 0;
        }

};

int main() {

    vector <int> nums = {3,2,1,0,4};
    Solution sol;
    
    if (sol.canJump(nums)) {
        cout << "True";
    }

    else {
        cout << "False";
    }

}