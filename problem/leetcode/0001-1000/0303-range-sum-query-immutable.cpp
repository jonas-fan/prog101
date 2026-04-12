#include <vector>

class NumArray {
public:
    NumArray(std::vector<int> & nums) {
        this->nums = nums;
    }

    int sumRange(int left, int right) {
        int out = 0;

        while (left <= right) {
            out += this->nums[left++];
        }

        return out;
    }

private:
    std::vector<int> nums;
};
