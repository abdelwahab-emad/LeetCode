class Solution {
  bool areSimilar(List<List<int>> mat, int k) {
    int n = mat.length, m = mat[0].length;
    k %= m;

    for (int i = 0; i < n; i++) {
      List<int> temp = List.filled(m, 0);
      for (int j = 0; j < m; j++) {
        if (i % 2 == 0) {
          temp[j] = mat[i][(j + k) % m];
        } else {
          temp[j] = mat[i][(j - k % m + m) % m];
        }
      }
      for (int j = 0; j < m; j++) {
        if (temp[j] != mat[i][j]) return false;
      }
    }
    return true;
  }
}