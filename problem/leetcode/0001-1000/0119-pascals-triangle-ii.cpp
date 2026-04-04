class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> row(rowIndex + 1);

        row[0] = 1;

        for (std::size_t i = 0; i < row.size(); i++) {
            for (std::size_t col = i; col >= 1; col--) {
                row[col] = row[col] + row[col - 1];
            }
        }

        return row;
    }
};
