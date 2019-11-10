#include<bits/stdc++.h>
using namespace std;
int bookList[100100];
int main()
{
    int books,enter,i,money=0,ind=0;
    scanf("%d %d",&books,&enter);
    scanf("%d",&bookList[0]);
    for(i=1; i<books; i++){
        scanf("%d",&bookList[i]);
        bookList[i]=bookList[i]+bookList[i-1];
    }
    for(i=0; i<enter; i++){
        scanf("%d",&money);
        ind = lower_bound(bookList,bookList+books,money) - bookList;
        if(money<bookList[ind]){
            ind--;
        }
        if(money>bookList[books-1]){
            printf("%d",books);
            continue;
        }
        printf("%d",ind+1);
    }
}
