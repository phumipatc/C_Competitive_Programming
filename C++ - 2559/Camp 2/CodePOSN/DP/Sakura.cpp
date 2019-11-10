#include<bits/stdc++.h>
using namespace std;
char a[12000000][16],tmp[16];
int dir[15][3];
int main()
{
    int num = 26,st = 0,len;
    dir[1][0] = 0,dir[1][1] = 26;
    for(int i=0; i<26; i++)
        a[i][0] = 'a'+i,a[i][1] ='\0';
    for(int i = st; i<num; i++)
    {
        len = strlen(a[i]);
        if(len>1&&dir[len][0]==0)
            dir[len][0] = i,dir[len-1][1] = i-1;
        if(len == 10)
            break;
        strcpy(tmp,a[i]);
        for(int j = a[i][len-1]-'a'+1; j<26; j++){
            tmp[len] = 'a'+j,tmp[len+1] ='\0',strcpy(a[num],tmp),num++;
        }
    }
    dir[10][1] = num;
   int n,p,q,mid;
   scanf("%d",&n);
   while(n--)
   {
       int ch = 0;
       scanf(" %s",tmp);
       len = strlen(tmp);
       p = dir[len][0];
       q = dir[len][1];
       while(p<=q)
       {
           mid = (p+q)/2;
           if(strcmp(a[mid],tmp)<0)      p=mid+1;
           else if(strcmp(a[mid],tmp)>0) q = mid-1;
           else if(strcmp(a[mid],tmp)==0){ printf("%d\n",mid+1);ch =1; break;}
       }
       if(!ch)
        printf("0\n");

   }
    return 0;
}
