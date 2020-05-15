/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,accu,batt,now = 0,temp,ba,ac;
    cin >> n >> batt >> accu;
    ba = batt,ac = accu;
    for(int i=0;i<n;i++){
        cin >> temp;
        if(temp == 1){
            if(ba)      ba--,now++,ac = min(ac+1,accu);
            else if(ac) ac--,now++;
        }else{
            if(ac)      ac--,now++;
            else if(ba) ba--,now++;
        }
    }
    printf("%d\n",now);
	return 0;
}
