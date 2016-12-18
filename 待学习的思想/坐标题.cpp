//
// Created by sooglejay on 16/12/17.
//


class Point {
public:
    int x;
    int y;
};
// 判断输入的 四个点能否组成 矩形，只考虑边跟坐标轴成0，90度的角
int main() {
    int t;
    cin >> t;
    Point point[4];
    while (t--) {
        int i = 0;
        while (i < 4) {
            cin >> point[i].x;
            cin >> point[i].y;
            i++;
        }
        for (int j = 0; j < 4; ++j) {
            int min = point[j].x;
            int minY = point[j].y;
            int index = j;
            for (int k = j + 1; k < 4; ++k) {
                if (min > point[k].x) {
                    index = k;
                    min = point[k].x;
                    minY = point[k].y;
                }
            }

            point[index].x = point[j].x;
            point[index].y = point[j].y;

            point[j].x = min;
            point[j].y = minY;

        }
        int flag = 0;
        if (point[0].x == point[1].x) {
            if (point[2].x != point[3].x) {
                flag = 1;
            } else if (abs(point[1].y - point[0].y) != abs(point[3].y - point[2].y)) {
                flag = 1;
            } else {
                flag = 0;
            }
        } else if (point[2].x == point[3].x) {
            flag = 1;
        } else {

            int a = (point[1].y - point[0].y) * (point[3].x - point[2].x);
            int b = (point[3].y - point[2].y) * (point[1].x - point[0].x);
            if (abs(a) == abs(b)) {
                flag = 0;
            } else {
                flag = 1;
            }
        }


        cout << !flag << "\n";


    }
    return 0;
}



