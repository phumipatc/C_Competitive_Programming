/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[5000010];
int main(){
    int q,n,num,minn,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&num);
            a[num] = i;
        }
        minn = a[1],ans = 1;
        for(int i=2;i<=n;i++){
            if(minn == 1)   break;
            if(a[i]<minn){
                minn = a[i];
                ans++;
                ans%=8;
            }
        }
        switch(ans){
            case 0: printf("Dr.Peartt\n");  break;
            case 1: printf("Porn\n");  break;
            case 2: printf("Born\n");  break;
            case 3: printf("Nornt\n");  break;
            case 4: printf("Borss\n");  break;
            case 5: printf("Norn\n");  break;
            case 6: printf("Girg\n");  break;
            case 7: printf("Asira\n");  break;
        }
    }
    return 0;
}
