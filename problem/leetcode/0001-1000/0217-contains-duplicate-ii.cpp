#include <unordered_map>
#include <vector>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> & nums, int k) {
        std::unordered_map<int, std::vector<int>> seen;

        for (std::size_t i = 0; i < nums.size(); i++) {
            if (seen.count(nums[i])) {
                for (std::vector<int>::const_iterator it = seen[nums[i]].begin();
                     it != seen[nums[i]].end();
                     it++)
                {
                    if (std::abs((int)(i - *it)) <= k) {
                        return true;
                    }
                }

            }

            seen[nums[i]].push_back(i);
        }

        return false;
    }
};
