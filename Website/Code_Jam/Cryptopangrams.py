
def gcd(n,m):
    if m == 0:
        return n
    return gcd(m, n % m)

t = int(input())
char = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
mapp = dict()
for k in range(1, t + 1):
    mapp.clear()
    m, n = [int(e) for e in input().split(" ")]
    a = [int(e) for e in input().split(" ")]
    a = [0] + a
    ans = [0]*(n+2)
    now = 1
    while a[now] == a[now+1] :
        now+=1
    GCD = gcd(a[now], a[now+1])
    ans[now] = a[now]/GCD
    ans[now+1] = GCD
    ans[now+2] = a[now+1]/GCD
    idx = now-1
    while idx > 0 :
        ans[idx] = a[idx]/ans[idx+1]
        idx-=1
    idx = now+3
    while idx <= n + 1 :
        ans[idx] = a[idx-1]/ans[idx-1]
        idx+=1
    temp = [0]*(n + 2)
    for i in range (n + 2) :
        temp[i] = ans[i]
    ans.sort()
    now = 0
    for i in range (1, n + 2) :
        if not (i < n and ans[i] == ans[i+1]) :
            mapp[ans[i]] = char[now]
            now+=1
    stri = ""
    for i in range (1, n + 2) :
        stri+=mapp[temp[i]]
    print("Case #{}: {}".format(k, stri))