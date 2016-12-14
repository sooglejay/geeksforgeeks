//
// Created by sooglejay on 16/12/14.
//


/*You have to complete this function*/
//递归算法


//隐含有回退思想，举个例子，你遇到一个岔路口，一共有10条岔路假设标号为0-9。
// 你首先 选择了0号岔路，走到路的尽头，此时你递归回到原点，重新选择1-9之中的另一条路
// 假设你选择了1号路，又走到了尽头，此时你再次递归回到原点
// 。。。
// 如此，引出了第二个递归的技术点，就是终止条件，此处的终止条件很明显，就是全部的路都走完就结束

// 总结起来，递归有两个关键点需要理解：
// 一个是周而复始（进入下一次递归函数的位置，如下注释代码）
// 另一个是终止条件，就是退出一次递归调用的地方

// 只要每一条路都有尽头，那么无论有多少条路，都会有结束的一天
void get(char buffer[], char A[], int i, int j, int n) {
    if (j == n) {
        buffer[i] = '\0';
        cout << buffer << '$';
        return;
    }
    buffer[i] = A[j];
    // 开始进入下一次递归
    get(buffer, A, i + 1, j + 1, n);
    buffer[i] = ' ';
    buffer[i + 1] = A[j];
    //开始进入下一次递归
    get(buffer, A, i + 2, j + 1, n);
}

void printSpace(char str[]) {
//Your code here
    int n = strlen(str);
    char B[2 * n];
    B[0] = str[0];
    get(B, str, 1, 1, n);
}