/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int countt[30];
char opr[10];
int n,now = 1,alp = 0,state = 0;
void debug(){
    for(int i=0;i<26;i++)
        printf("%d ",countt[i]);
    printf("\n");
}
void update(){
    while((n-now)%26){
        countt[alp]++;
        if(state == 0)  alp++;
        else            alp--;
        alp+=26,alp%=26;
        now++;
    }
    for(int i=0;i<26;i++)
        countt[i]+=(n-now)/26;
    countt[alp]++;
    if(state == 0)  alp++;
    else            alp--;
    alp+=26,alp%=26;
    now = n+1;
    // debug();
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int q;
    char ask;
    cin >> q;
    while(q--){
        cin >> opr >> n;
        update();
        if(opr[0] == 'R'){
            state^=1;
            if(state == 0)  alp+=2,alp%=26;
            else            alp+=24,alp%=26;
        }else{
            cin >> ask;
            cout << countt[ask-'a'] << "\n";
        }
    }
    return 0;
}