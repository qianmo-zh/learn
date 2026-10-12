#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow=-1;
        int fast=0;
        while(fast < static_cast<int>(nums.size())){
            if(nums[fast]!=0){
                slow++;
                std::swap(nums[fast], nums[slow]);
            }
            fast++;
        }

    }
};