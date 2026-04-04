class Solution {
public:
    std::vector< std::vector<int> > generate(int numRows) {
        std::vector< std::vector<int> > out(numRows);

        for (std::size_t row = 0; row < out.size(); row++) {
            out[row].resize(row + 1);

            for (std::size_t col = 0; col < out[row].size(); col++) {
                if (col == 0) {
                    // Left boundary
                    out[row][col] = 1;
                } else if ((col + 1) == out[row].size()) {
                    // Right boundary
                    out[row][col] = 1;
                } else {
                    // Inner
                    out[row][col] = out[row - 1][col - 1] + out[row - 1][col];
                }
            }
        }

        return out;
    }
};
