#include<stdio.h>
#include<math.h>
int main()
{
    double k,d,x,y,m,r;
    scanf("%lf %lf",&k,&d);
    m = (40-k)/15;
    r = sqrt(1+pow(m,2));
    x = 15+(d/r);
    y = 40+(d*m/r);
    if(floor(fmod(x/60.0,2))==0)
        printf("%.1lf ",fmod(x,60.0));
    else
        printf("%.1lf ",60.0-fmod(x,60.0));
    y = fabs(y);
    if(floor(fmod(y/100,2.0))==0)
        printf("%.1lf\n",fmod(y,100.0));
    else
        printf("%.1lf\n",100-fmod(y,100.0));
    return 0;
}
