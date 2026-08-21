class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Check rows
        for (int i = 0; i < 9; i++) {
            set<char> st;

            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;

                if (st.count(board[i][j]))
                    return false;

                st.insert(board[i][j]);
            }
        }

        // Check columns
        for (int j = 0; j < 9; j++) {
            set<char> st;

            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.')
                    continue;

                if (st.count(board[i][j]))
                    return false;

                st.insert(board[i][j]);
            }
        }

        // Check 3x3 boxes
        for (int r = 0; r < 9; r += 3) {
            for (int c = 0; c < 9; c += 3) {

                set<char> st;

                for (int i = r; i < r + 3; i++) {
                    for (int j = c; j < c + 3; j++) {

                        if (board[i][j] == '.')
                            continue;

                        if (st.count(board[i][j]))
                            return false;

                        st.insert(board[i][j]);
                    }
                }
            }
        }

        return true;
    }
};