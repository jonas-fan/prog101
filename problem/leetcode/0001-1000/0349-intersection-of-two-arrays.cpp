#include <vector>
#include <unordered_set>

static void unique(
    const std::vector<int> & nums,
    std::unordered_set<int> & out
    )
{
    for (std::size_t i = 0; i < nums.size(); i++) {
        out.insert(nums[i]);
    }
}

class Solution {
public:
    std::vector<int> intersection(std::vector<int> & nums1, std::vector<int> & nums2) {
        std::unordered_set<int> seen1;
        std::unordered_set<int> seen2;
        std::vector<int> out;

        unique(nums1, seen1);
        unique(nums2, seen2);

        for (std::unordered_set<int>::const_iterator it = seen1.begin(); it != seen1.end(); it++) {
            if (seen2.count(*it)) {
                out.push_back(*it);
            }
        }

        return out;
    }
};
