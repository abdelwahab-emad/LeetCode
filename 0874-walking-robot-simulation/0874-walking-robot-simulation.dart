class Solution {
  int robotSim(List<int> commands, List<List<int>> obstacles) {
    Set<String> s = {};
    for (var o in obstacles) {
      s.add("${o[0]},${o[1]}");
    }
    List<List<int>> d = [
      [0, 1],
      [1, 0],
      [0, -1],
      [-1, 0]
    ];

    int dir = 0;
    int x = 0, y = 0;
    int ans = 0;

    for (int c in commands) {
      if (c == -2) {
        dir = (dir + 3) % 4;
      } else if (c == -1) {
        dir = (dir + 1) % 4;
      } else {
        for (int i = 0; i < c; i++) {
          int nx = x + d[dir][0];
          int ny = y + d[dir][1];

          if (s.contains("$nx,$ny")) break;

          x = nx;
          y = ny;
          ans = ans > (x * x + y * y) ? ans : (x * x + y * y);
        }
      }
    }

    return ans;
  }
}