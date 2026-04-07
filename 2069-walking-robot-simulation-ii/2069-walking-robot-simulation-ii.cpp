class Robot {
public:
    int w, h;
    int x = 0, y = 0;
    int dir = 0;
    int cycle;

    Robot(int width, int height) {
        w = width;
        h = height;
        cycle = 2 * (w + h) - 4;
    }
    
    void step(int num) {
        int move = num % cycle;
        if (move == 0) move = cycle;

        while (move--) {
            if (dir == 0) {
                if (x + 1 < w) x++;
                else {
                    dir = 1;
                    y++;
                }
            } 
            else if (dir == 1) {
                if (y + 1 < h) y++;
                else {
                    dir = 2;
                    x--;
                }
            } 
            else if (dir == 2) {
                if (x - 1 >= 0) x--;
                else {
                    dir = 3;
                    y--;
                }
            } 
            else {
                if (y - 1 >= 0) y--;
                else {
                    dir = 0;
                    x++;
                }
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};