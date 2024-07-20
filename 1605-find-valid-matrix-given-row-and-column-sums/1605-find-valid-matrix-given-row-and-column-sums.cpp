class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        int m = rowSum.size();
        int n = colSum.size();
        
        vector<vector<int>>matrix(m, vector<int>(n, 0));
        int i=m-1,j=n-1;
        while(i>=0 && j>=0)
        {
            if(rowSum[i]<=colSum[j])
            {
                matrix[i][j] = rowSum[i];
                colSum[j]-=rowSum[i];
                i--;
            }
            else
            {
                matrix[i][j] = colSum[j];
                rowSum[i]-=colSum[j];
                j--;
            }
        }
        return matrix;
    }
};