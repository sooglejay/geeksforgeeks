http://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/

#include <iostream>
using namespace std;
void sovle(int *A,int n){
    int in = A[0];
    int ex = 0;
    for(int i=1;i<n;i++){
        int temp = max(in,ex);
        in  = ex + A[i];
        ex = temp;
    }
    int res = in<ex?ex:in;
    printf("%d\n",res);
}
int main(){
    int t;
    cin>>t;
    while (t--) {
        int N;
        cin >>N;
        int n = 0,A[N];
        while (n<N) {
            cin>>A[n++];
        }
        sovle(A,N);
	}

    
}