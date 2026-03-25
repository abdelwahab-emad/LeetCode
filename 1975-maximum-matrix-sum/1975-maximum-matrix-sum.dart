class Solution {
  int maxMatrixSum(List<List<int>> matrix) {
    int neg = 0;
    int sum = 0;
    int mi = 100000000;
    for(int i = 0;i < matrix.length;i++){
        for(int j = 0;j < matrix[i].length;j++){
            int val = matrix[i][j];
            if(val < 0){
                neg++;
            }
            sum += val.abs();
            mi = min(mi, val.abs());
        }
    }
    if(neg % 2 != 0){
        sum -= mi * 2;
    }
    return sum;
  }
}