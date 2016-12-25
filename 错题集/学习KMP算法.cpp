//
// Created by sooglejay on 16/12/26.
//

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if(!source||!target){
            return -1;
        }
        int st = 0;
        while (target[st] != '\0') {
            st++;
        }
        int index = 0, j = 0, i = 0;
        while (source[index] != '\0') {
            j = 0;
            i = index;
            while (target[j] != '\0' && source[i] != '\0' && target[j] == source[i]) {
                j++;
                i++;
            }
            if (j==st) {
                return index;
            }
            index++;
        }
        if(index==0&&st==0){
            return st;
        }
        return -1;
    }
};
