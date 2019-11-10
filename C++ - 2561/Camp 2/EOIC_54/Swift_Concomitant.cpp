/*
    TASK:
    LANG: CPP
    AUTHOR: Phumipat C.
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int cnt=0,a[100],sum;
void play(int tmp[],int k){
    int i,ch=1;
        stack<int> st;
    if(k==0){

        for(i=0;i<sum;i++){
            if(a[i]%2==0)
                st.push(a[i]);
            else{
                if(st.empty()){
                    ch=0;
                    return;
                }
                else if(st.top()/2==a[i]/2)
                    st.pop();
                else{
                    ch=0;
                    return;
                }
            }
        }
        if(ch)  cnt++;
    }
    else{
        for(i=0;i<6;i++){
            if(tmp[i]!=0){
                if(i%2==0 && tmp[i]==tmp[i+1])  continue;
                tmp[i]--;
                a[k]=i;
                play(tmp,k-1);
                tmp[i]++;
            }
        }
    }
}
int main()
{
    int x[10];
    scanf("%d %d %d",&x[0],&x[2],&x[4]);
    x[1]=x[0],x[3]=x[2],x[5]=x[4];
    sum = x[0]+x[1]+x[2]+x[3]+x[4]+x[5];
    play(x,sum);
    printf("%d\n",cnt);
    return 0;
}