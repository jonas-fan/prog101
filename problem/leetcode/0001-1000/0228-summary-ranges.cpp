#include <string>
#include <vector>

static std::string makeRange(int lower, int upper) {
    std::ostringstream oss;

    oss << lower;

    if (lower < upper) {
        oss << "->" << upper;
    }

    return oss.str();
}

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int> & nums) {
        std::vector<std::string> out;
        std::size_t lower = 0;
        std::size_t upper = 0;

        if (nums.empty()) {
            return out;
        }

        for (std::size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == (nums[upper] + 1)) {
                upper = i;
            } else {
                out.push_back(makeRange(nums[lower], nums[upper]));
                lower = i;
                upper = i;
            }
        }

        out.push_back(makeRange(nums[lower], nums[upper]));

        return out;
    }
};
