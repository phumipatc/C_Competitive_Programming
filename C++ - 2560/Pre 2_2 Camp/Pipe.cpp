/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[310][310],m,n;
vector<int> ans;
void pipe(int i,int j,int from,int dis){
    if(from==1){
        if(a[i][j]==11){
            if(j-1==0){
                ans.push_back(dis);
                return ;
            }
            pipe(i,j-1,3,dis+1);
        }
        if(a[i][j]==12){
            if(j+1>m){
                ans.push_back(dis);
                return ;
            }
            pipe(i,j+1,2,dis+1);
        }
        if(a[i][j]==21){
            if(i+1>n){
                ans.push_back(dis);
                return ;
            }
            pipe(i+1,j,1,dis+1);
        }
        if(a[i][j]==31){
            if(i+1>n){
                ans.push_back(dis);
                return ;
            }
            pipe(i+1,j,1,dis+1);
        }
    }
    if(from==2){
        if(a[i][j]==11){
            if(i-1==0){
                ans.push_back(dis);
                return ;
            }
            pipe(i-1,j,4,dis+1);
        }
        if(a[i][j]==13){
            if(i+1>n){
                ans.push_back(dis);
                return ;
            }
            pipe(i+1,j,1,dis+1);
        }
        if(a[i][j]==22){
            if(j+1>m){
                ans.push_back(dis);
                return ;
            }
            pipe(i,j+1,2,dis+1);
        }
        if(a[i][j]==31){
            if(j+1>m){
                ans.push_back(dis);
                return ;
            }
            pipe(i,j+1,2,dis+1);
        }
    }
    if(from==3){
        if(a[i][j]==12){
            if(i-1==0){
                ans.push_back(dis);
                return ;
            }
            pipe(i-1,j,4,dis+1);
        }
        if(a[i][j]==14){
            if(i+1>n){
                ans.push_back(dis);
                return ;
            }
            pipe(i+1,j,1,dis+1);
        }
        if(a[i][j]==22){
            if(j-1==0){
                ans.push_back(dis);
                return ;
            }
            pipe(i,j-1,3,dis+1);
        }
        if(a[i][j]==31){
            if(j-1==0){
                ans.push_back(dis);
                return ;
            }
            pipe(i,j-1,3,dis+1);
        }
    }
    if(from==4){
        if(a[i][j]==13){
            if(j-1==0){
                ans.push_back(dis);
            }
            pipe(i,j-1,3,dis+1);
        }
        if(a[i][j]==14){
            if(j+1>m){
                ans.push_back(dis);
            }
            pipe(i,j+1,2,dis+1);
        }
        if(a[i][j]==21){
            if(i-1==0){
                ans.push_back(dis);
            }
            pipe(i-1,j,4,dis+1);
        }
        if(a[i][j]==31){
            if(i-1==0){
                //up out
                ans.push_back(dis);
            }
            pipe(i-1,j,4,dis+1);
        }
    }
}
int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);

    for(i=1;i<=m;i++)
        if(a[1][i]==11 || a[1][i]==12 || a[1][i]==21 || a[1][i]==31)
            pipe(1,i,1,1);

    for(i=1;i<=m;i++)
        if(a[n][i]==13 || a[n][i]==14 || a[n][i]==21 || a[n][i]==31)
            pipe(n,i,4,1);

    for(i=1;i<=n;i++)
        if(a[i][1]==11 || a[i][1]==13 || a[i][1]==22 || a[i][1]==31)
            pipe(i,1,2,1);

    for(i=1;i<=n;i++)
        if(a[i][m]==12 || a[i][m]==14 || a[i][m]==22 || a[i][m]==31)
            pipe(i,m,3,1);

    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size()/2);
    for(i=0;i<ans.size();i+=2)
        printf("%d ",ans[i]);
}
