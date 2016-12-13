//
// Created by sooglejay on 16/12/13.
//


class Student {
public:
    char name[11];
    int sb1;
    int sb2;
    int sb3;
    float average;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Student ss[N];
        float max = -1F;
        int index=0;
        for(int i = 0 ; i <N;i++){
            cin>>ss[i].name>>ss[i].sb1>>ss[i].sb2>>ss[i].sb3;
            ss[i].average = (ss[i].sb1+ss[i].sb2+ss[i].sb3)*1.0f/3;
            if (ss[i].average>max){
                max = ss[i].average;
                index = i;
            }
        }
        cout<<ss[index].name<<(int)max<<endl;
    }

    return 0;
}
