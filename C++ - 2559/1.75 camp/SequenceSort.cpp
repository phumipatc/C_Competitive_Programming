/*
TASK: SequenceSort
LANG: C++
AUTHOR: PeaTT~
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector< vector<int> > a;
int main(){
    int n,m,i,num,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        vector<int > b;
        b.clear();
        for(j=0;j<m;j++){
            scanf("%d",&num);
            b.push_back(num);
        }
        a.push_back(b);
    }
    sort(a.begin(),a.end());
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
