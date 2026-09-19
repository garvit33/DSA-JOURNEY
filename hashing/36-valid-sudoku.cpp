class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> st;

        //checks if there are dups in a row 
        for(int row = 0;row<9;row++){
            st.clear();
            for(int col = 0;col<9;col++){
                if(board[row][col] == '.')continue;
                if(st.find(board[row][col]) != st.end()){
                    return false;
                }
                st.insert(board[row][col]);
            }
        }
        //checks if there are dups in a col
        for(int col =0;col<9;col++){
            st.clear();
            for(int row =0;row<9;row++){
                if(board[row][col] == '.')continue;
                if(st.find(board[row][col]) != st.end()){
                    return false;
                }
                st.insert(board[row][col]);
            }
        }
        //checks if there are dups in a 3*3 blocks 
        for(int row = 0;row<9;row+=3){
            for (int col = 0;col<9;col+=3){
                st.clear();
                for(int r = row;r<row+3;r++){
                    for(int c = col;c<col+3;c++){
                        if(board[r][c] == '.')continue;
                        if(st.find(board[r][c]) != st.end()){
                            return false;
                        }
                        st.insert(board[r][c]);
                    }
                }
            }
        }
        return true;
    }
};