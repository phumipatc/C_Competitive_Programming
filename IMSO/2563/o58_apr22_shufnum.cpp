/*
	Task	: o58_apr22_shufnum
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 30 April 2021 [10:54]
	Algo	: Treap
	Status	: Finished
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MAX_INT = 1e9;
const LL MAX_LL = 1e18;
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
struct node{
	int prior,key,change;
	node *l,*r;
	node(int key):key(key),l(NULL),r(NULL){
		prior = rand();
		change = 0;
	}
};
typedef node* pnode;
pnode root=NULL;
void upd(pnode t){
	if(!t)	return ;
	t->key+=(t->change);
	if(t->l)	t->l->change+=(t->change);
	if(t->r)	t->r->change+=(t->change);
	t->change = 0;
}
void split(pnode t,pnode &l,pnode &r,int A){
	if(!t){
		l = r = NULL;
		return ;
	}
	upd(t);
	if(t->key<=A)	split(t->r,t->r,r,A),l = t;
	else			split(t->l,l,t->l,A),r = t;
}
void merge(pnode &t,pnode l,pnode r){
	if(!l || !r){
		t = (l?l:r);
		return ;
	}
	upd(l),upd(r);
	if((l->prior)>(r->prior))	t=l,merge(t->r,l->r,r);
	else						t=r,merge(t->l,l,r->l);
}
int find(pnode t,int v){
	if(!t)			return 0;
	upd(t);
	if(t->key == v)	return 1;
	if(t->key<v)	return find(t->r,v);
	else			return find(t->l,v);
}
void solve(){
	int opr;
	cin >> opr;
	if(opr == 1){
		int X;
		cin >> X;
		cout << find(root,X) << '\n';
	}else{
		int A,B,C;
		cin >> A >> B >> C;
		if(!find(root,A))	return ;
		pnode p1,p2;
		split(root,p1,p2,A-1);
		if(p1)	p1->change+=B;
		if(p2)	p2->change+=C;
		merge(root,p2,p1);
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int N,q = 1,val;
	cin >> N >> q;
	for(int i=1;i<=N;i++){
		cin >> val;
		pnode newnode = new node(val);
		merge(root,root,newnode);
	}
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}