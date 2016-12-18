//
// Created by sooglejay on 16/12/18.
//

//Given two rectangles, find if the given two rectangles overlap or not. A rectangle is denoted by providing the x and y co-ordinates of two points: the left top corner and the right bottom corner of the rectangle.
//
//Note that two rectangles sharing a side are considered overlapping.
//
//rectanglesOverlap
//
//        Input:
//
//The first integer T denotes the number of test cases. For every test case, there are 2 lines of input. The first line consists of 4 integers: denoting the co-ordinates of the 2 points of the first rectangle. The first integer denotes the x co-ordinate and the second integer denotes the y co-ordinate of the left topmost corner of the first rectangle. The next two integers are the x and y co-ordinates of right bottom corner. Similarly, the second line denotes the cordinates of the two points of the second rectangle.
//
//
//Output:
//
//        For each test case, output (either 1 or 0) denoting whether the 2 rectangles are overlapping. 1 denotes the rectangles overlap whereas 0 denotes the rectangles do not overlap.
//
//
//Constraints:
//
//1 <= T <= 10
//
//-10000 <= x,y <= 10000
//
//T denotes the number of test cases. x denotes the x co-ordinate and y denotes the y co-ordinate.
//
//
//Example:
//
//        Input:
//
//2
//0 10 10 0
//5 5 15 0
//0 2 1 1
//-2 -3 0 2
//
//Output:
//
//1
//0
//
//**For More Examples Use Expected Output**


#include <iostream>
using namespace std;

class Point {
public:
    int x;
    int y;
};

void sort(Point *A, int size) {
    for (int j = 0; j < size; ++j) {
        int min = A[j].x;
        int minY = A[j].y;
        int index = j;
        for (int k = j + 1; k < size; ++k) {
            if (min > A[k].x) {
                index = k;
                min = A[k].x;
                minY = A[k].y;
            }
        }

        A[index].x = A[j].x;
        A[index].y = A[j].y;

        A[j].x = min;
        A[j].y = minY;

    }

}

int main() {
    int t;
    cin >> t;
    Point A[4];
    Point B[4];
    while (t--) {
        int i = 0;
        int cy = 0;
        int end = 0;
        while (i < 2) {
            cin >> A[i].x;
            cin >> A[i].y;
            if (i == 0) {
                cy = A[i].y;
            } else {
                if (cy < A[i].y) {
                    end = 1;
                }
            }
            i++;
        }
        sort(A, 2);
        A[2].x = A[0].x;
        A[2].y = A[1].y;

        A[3].x = A[1].x;
        A[3].y = A[0].y;

        i = 0;

        while (i < 2) {
            cin >> B[i].x;
            cin >> B[i].y;
            if (i == 0) {
                cy = B[i].y;
            } else {
                if (cy < B[i].y) {
                    end = 1;
                }
            }
            i++;
        }
        if(end>0) {
            cout << 0 << endl;
            continue;
        }
        sort(B, 2);


        B[2].x = B[0].x;
        B[2].y = B[1].y;

        B[3].x = B[1].x;
        B[3].y = B[0].y;
        sort(A, 4);
        sort(B, 4);

//        for (int j = 0; j < 4; ++j) {
//            cout << A[j].x << '-' << A[j].y << endl;
//        }
//        cout << "\n\n";
//        for (int j = 0; j < 4; ++j) {
//            cout << B[j].x << '-' << B[j].y << endl;
//        }

        int xa0 = A[0].x;
        int xa1 = A[3].x;

        int ya0 = A[1].y;
        int ya1 = A[3].y;


        int xb0 = B[0].x;
        int xb1 = B[3].x;

        int yb0 = B[1].y;
        int yb1 = B[3].y;


        int sx = xa0 < xb0 ? xa0 : xb0;
        int ex = xa1 < xb1 ? xb1 : xa1;

        int sy = ya0 < yb0 ? ya0 : yb0;
        int ey = ya1 < yb1 ? yb1 : ya1;

        int flag = 0;

        int side = 0;
        for (int k = sx; k <= ex; ++k) {
            for (int j = sy; j <= ey; ++j) {

                float km = k+0.1F;
                float jm = j+0.1F;
                if (km <= xb1 && km >= xb0 && km <= xa1 && km >= xa0 && jm <= yb1 && jm >= yb0 && jm <= ya1 && jm >= ya0) {
                    flag=2;
                    break;
                }else  if (k <= xb1 && k >= xb0 && k <= xa1 && k >= xa0 && j <= yb1 && j >= yb0 && j <= ya1 && j >= ya0) {
                    side++;
                }

            }
            if (flag > 1) {
                break;
            }

        }
        if(flag>1){
            cout << 1 << endl;

        }else if(side==xa1-xa0 && xa1-xa0== xb1-yb0){
            cout << 1 << endl;

        }else{
            cout << 0 << endl;
        }

    }
    return 0;
}


