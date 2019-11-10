#include<iostream>
#include<conio.h>
using namespace std;
double a[1000000];
/*
int cmp(const void *a,const void *b){
    if(*(double *)a > *(double *)b){
        return 1;
    }else{
        return -1;
    }
}
*/
int main()
{
    int x,i,j;
    double sum=0,min=10000000,max=-1000000,old;
    printf("Enter times :");
    cin>>x;
        for(i=0;i<x;i++){
                         cout<<"Enter Number "<<i+1<<" :";
            cin>>a[i];
            sum+=a[i];
            if(min>a[i])
                min=a[i];
            if(max<a[i])
                max=a[i];
            }
        //qsort(a,x,sizeof(double),cmp);
        cout<<"sum = "<<sum<<endl<<"min = "<<min<<endl<<"max = "<<max<<endl<<"Avg = "<<sum/x<<endl;
        /*
        cout<<"Ascending = ";
        for(i=0;i<x;i++)
            cout<<a[i]<<endl;
        cout<<"Descending = ";
        for(i=x-1;i>=0;i--)
            cout<<a[i];
        */
        for(i=0;i<x-1;i++){
            for(j=0;j<x;j++){
                if(a[j]<a[j+1]){
                    old=a[j];
                    a[j]=a[j+1];
                    a[j+1]=old;
                }
            }
        }

        cout<<"Ascending = ";
        for(i=x-1;i>=0;i--)
            cout<<a[i]<<" ";
        cout<<endl;

        cout<<"Descending = ";
        for(i=0;i<x;i++)
            cout<<a[i]<<" ";
            cout<<"\n";

  getch();
}
