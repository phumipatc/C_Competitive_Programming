/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct A
{
    int ptt,goal,shot,w,l,d;
    char name;
    bool operator <(const A & o)const
    {
        if(ptt > o.ptt) return 1;
        else if(ptt < o.ptt) return 0;
        else if(goal-shot > o.goal-o.shot) return 1;
        else if(goal-shot < o.goal-o.shot) return 0;
        else if(goal > o.goal) return 1;
        else if(goal < o.goal) return 0;
        else if(name < o.name) return 1;
        else return 0;

    }
};
A team[10];
int main()
{
    int q;
    scanf("%d",&q);
    for(int c =1; c<=q; c++)
    {
        for(int i=0; i<4; i++)
        {
            team[i].name=i+'A';
            team[i].ptt=team[i].goal=team[i].shot=team[i].w=team[i].l=team[i].d=0;
        }
        for(int i=0; i<6; i++)
        {
            char t1,t2;
            int g1,g2,team1,team2;
            scanf(" %c %c %d %d",&t1,&t2,&g1,&g2);
            if(t1=='A')
                team1=0;
            if(t1=='B')
                team1=1;
            if(t1=='C')
                team1=2;
            if(t1=='D')
                team1=3;
            if(t2=='A')
                team2=0;
            if(t2=='B')
                team2=1;
            if(t2=='C')
                team2=2;
            if(t2=='D')
                team2=3;
            team[team1].goal+=g1;
            team[team1].shot+=g2;

            team[team2].goal+=g2;
            team[team2].shot+=g1;

            if(g1 > g2)
            {
                team[team1].ptt+=3;
                team[team1].w++;
                team[team2].l++;
            }
            else if(g2 > g1)
            {
                team[team2].ptt+=3;
                team[team2].w++;
                team[team1].l++;
            }
            else
            {
                team[team1].ptt++;
                team[team2].ptt++;
                team[team1].d++;
                team[team2].d++;
            }
        }
        sort(team,team+4);
        printf("Case #%d:\n",c);
        for(int i=0; i<4; i++)
        {
            printf("%c %d %d %d %d %d %d\n",team[i].name,team[i].w,team[i].d,team[i].l,team[i].goal,team[i].shot,team[i].ptt);
        }
    }

    return 0;
}
/*
 3
 A B 3 1
 C D 1 0
 A C 0 0
 D B 0 4
 B C 1 3
 D A 1 4
 A B 5 2
 B C 0 5
 C D 4 2
 A C 7 3
 A D 7 4
 B D 4 2
 A B 1 2
 B C 0 5
 C D 4 2
 A C 7 3
 A D 7 4
 B D 4 2
 */
