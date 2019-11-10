/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    int q,x,y,score=0;
    double dis;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&x,&y);
        dis=sqrt(pow(x,2)+pow(y,2));
        if(dis>10)      score=score;
        else if(dis>8)  score++;
        else if(dis>6)  score+=2;
        else if(dis>4)  score+=3;
        else if(dis>2)  score+=4;
        else            score+=5;
    }
    printf("%d",score);
    return 0;
}
