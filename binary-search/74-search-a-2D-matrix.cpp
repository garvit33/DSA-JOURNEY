class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //num of rows
        int rows = matrix.size();
        //num of cols
        int cols = matrix[0].size();
        
        //left at start of matrix
        int left = 0;
        //right at end of matrix
        int right = (rows*cols)-1;

        while(left<=right){
            //we get mid assuming a flattened array 
            int mid = left+(right-left)/2;

            //convert mid into its 2d index
            int row = mid/cols;
            int col = mid%cols;

            //check if target ==
            if(matrix[row][col] == target){
                return true;
            }
            
            //if target is smaller then we shift right to mid of the matrix
            if(matrix[row][col] > target){
                right = mid-1;
            }

             //if target is greater then we shift left to mid of the matrix
            else{
                left = mid+1;
            }
            
        }
        return false;
    }
};