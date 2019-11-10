/*
    TASK:NC_Flow And Fall
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
char a[20],ans[20],mark[20];
int n;
void permute(int now){
    if(now == n){
        cout << ans << endl;
        getch();
        return ;
    }
    for(int i=1;i<=n;i++){
        if(mark[i]) continue;
        mark[i] = 1;
        ans[now] = a[i];
        permute(now+1);
        mark[i] = 0;
    }
}
int main(){
    cin >> a+1;
    n = strlen(a+1);
    permute(0);
    return 0;
}

