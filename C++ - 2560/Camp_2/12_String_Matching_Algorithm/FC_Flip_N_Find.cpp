/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int ha[1100],tp[20];
char a[100100],temp[20],cmd[10];
long long coun=0,coun2=0;
int main()
{
    int i,j,k,n,hh,q,st,en,x,aa,len;
    tp[0]=1;
    for(i=1;i<=15;i++) tp[i]=tp[i-1]*2;
    scanf(" %d %d %d",&n,&k,&len);
    scanf("%s",a);
    for(i=0;i<n;i++){
        scanf(" %s",temp);
        hh=0;
        for(j=0;j<k;j++){
            hh=(hh*2)+temp[j]-'0';
        }
        ha[i]=hh;
//        printf("%d\n",ha[i]);
    }
    sort(ha,ha+n);
    hh=0;
    for(i=0;i<k;i++){
        hh=(hh*2)+a[i]-'0';
    }
    for(i=0;i<=len-k;i++){
//        printf("hh %d\n",hh);
        aa=lower_bound(ha,ha+n,hh)-ha;
        if(aa<n&&ha[aa]==hh) coun++;
        if(i!=len-k){
            hh-=(a[i]-'0')*tp[k-1];
            hh=(hh*2)+a[i+k]-'0';
        }
    }
    scanf(" %d",&q);
    while(q--){
        scanf(" %s",cmd);
        if(cmd[1]=='i') printf("%lld\n",coun);
        else{
            coun2=0;
            scanf(" %d",&x);
            st=x-k+1;
            if(st<0) st=0;
            en=x+k-1;
            if(en>=len) en=len-1;
            hh=0;
            for(i=st;i<st+k;i++){
                hh=(hh*2)+a[i]-'0';
            }
            for(i=st;i<=en-k+1;i++){
                aa=lower_bound(ha,ha+n,hh)-ha;
                if(aa<n&&ha[aa]==hh) coun2++;
                if(i!=en-k+1){
                    hh-=(a[i]-'0')*tp[k-1];
                    hh=(hh*2)+a[i+k]-'0';
                }
            }
            coun-=coun2;
            a[x]=('1'-a[x])+'0';
            coun2=0;
            hh=0;
            for(i=st;i<st+k;i++){
                hh=(hh*2)+a[i]-'0';
            }
            for(i=st;i<=en-k+1;i++){
                aa=lower_bound(ha,ha+n,hh)-ha;
                if(aa<n&&ha[aa]==hh) coun2++;
                if(i!=en-k+1){
                    hh-=(a[i]-'0')*tp[k-1];
                    hh=(hh*2)+a[i+k]-'0';
                }
            }
            coun+=coun2;
        }
    }
    return 0;
}
/*
3 5 30
010100101010111101010101110100
11010
10101
00100
8
Find
Flip 10
Find
Flip 22
Find
Flip 6
Flip 5
Find
*/
