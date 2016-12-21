//
// Created by sooglejay on 16/12/20.
//

/* The function should return position where the target string
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{

    int sL = s.size();
    int xL = x.size();
    int res = -1;
    for (int i = 0; i < sL; ++i) {
        int j = i;
        int k = 0;
        for (; k < xL; ++k) {
            if (s[j] != x[k]) {
                break;
            } else {
                j++;
            }
        }
        if (k == xL) {
            res = i;
            break;
        }
    }

    return res;

}