//
// Created by sooglejay on 16/12/22.
//

/***
 * Rock Paper Scissors!

A tournament is being held for champion players of the game Rock, Paper, and Scissors. For Player A and Player B, determine who wins each game.
The game is a draw if both players choose the same item. Paper wins over rock because paper covers rock. Scissors wins over paper because scissors cuts paper. Rock wins over scissors because rock breaks scissors.

Input:
The first line in the data set is an integer that represents the number of datapairs that follow. The data begins on the second line. R represents rock, P represents paper, and S represents scissors.


Output:
The output is to be formatted exactly like that for the sample output given below.
Assumptions: The only letters in the input will be upper case R, P, and S. The first letter in the pair is the choice for player A and the second letter is the choice for player B.If ‘A’ wins print ‘A’, if ‘B’ wins print ‘B’ and if it draws print ‘DRAW’ for each match.


Constraints:
1<= T <= 50



Example:

Input:
7
RR
RS
SR
SP
PP
PS
RP

Output:

DRAW
A
B
A
DRAW
B
B

**For More Examples Use Expected Output**
 */
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string two;

        cin >> two;
        int A1 = 'R' - 'S';
        int A2 = 'S' - 'P';
        int A3 = 'P' - 'R';

        int res = two[0] - two[1];
        if (res == 0) {
            cout << "DRAW" << endl;
        } else if (res == A1 || res == A2 || res == A3) {
            cout << "A" << endl;
        } else {
            cout << "B" << endl;
        }


    }
}