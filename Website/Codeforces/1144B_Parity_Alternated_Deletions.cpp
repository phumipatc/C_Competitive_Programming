/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > even,odd;
int main(){
    int n,temp,sum = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        sum+=temp;
        if(temp%2)  odd.push_back(-temp);
        else        even.push_back(-temp);
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    if(odd.size()>even.size()){
        temp = sum;
        for(int i=0;i<even.size();i++)
            temp+=even[i];
        for(int i=0;i<=even.size();i++)
            temp+=odd[i];
        printf("%d\n",temp);
    }else if(odd.size()<even.size()){
        temp = sum;
        for(int i=0;i<odd.size();i++)
            temp+=odd[i];
        for(int i=0;i<=odd.size();i++)
            temp+=even[i];
        printf("%d\n",temp);
    }else{
        temp = sum;
        for(int i=0;i<even.size();i++)
            temp+=even[i];
        for(int i=0;i<=even.size();i++)
            temp+=odd[i];
        n = temp;
        temp = sum;
        for(int i=0;i<odd.size();i++)
            temp+=odd[i];
        for(int i=0;i<=odd.size();i++)
            temp+=even[i];
        n = min(n,temp);
        printf("%d\n",n);
    }
	return 0;
}
