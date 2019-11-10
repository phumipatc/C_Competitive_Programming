/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,type;
    bool operator < (const A&o) const{
        if(type>o.type) return false;
        else            return true;
    }
};
A ans[400000];
int countt;
void dac(int n,int imid,int jmid,int ifix,int jfix){
    int quad;
    if(ifix<imid && jfix<jmid)
        quad=1;
    else if(ifix<imid && jfix>=jmid)
        quad=2;
    else if(ifix>=imid && jfix>=jmid)
        quad=3;
    else
        quad=4;
    ans[countt].type=quad-1,ans[countt].i=imid-1,ans[countt].j=jmid-1;
    countt++;
    if(n>2){
        if(quad==1)
            dac(n/2,n/4,n/4,ifix,jfix);
        else
            dac(n/2,n/4,n/4,imid-1,jmid-1);
        if(quad==2)
            dac(n/2,imid-n/4,jmid+n/4,ifix,jfix);
        else
            dac(n/2,imid-n/4,jmid+n/4,imid-1,jmid);
        if(quad==3)
            dac(n/2,imid+n/4,jmid-n/4,ifix,jfix);
        else
            dac(n/2,imid+n/4,jmid-n/4,imid,jmid-1);
        if(quad==4)
            dac(n/2,imid+n/4,jmid+n/4,ifix,jfix);
        else
            dac(n/2,imid+n/4,jmid+n/4,imid,jmid);
    }
}
int main(){
    int n,ifix,jfix,i;
    countt=0;
    scanf("%d %d %d",&n,&ifix,&jfix);
    dac(n,n/2,n/2,jfix,ifix);
    sort(ans,ans+countt);
    printf("%d\n",countt);
    for(i=0;i<countt;i++)
        printf("%d %d %d\n",ans[i].type,ans[i].j,ans[i].i);
return 0;
}
