from functools import cache

def f(x : int)->str:
    res = ''
    while x > 0:
        res += str(x % 2)
        x >>= 1
    return res[::-1]

n, m = map(int, input().split())
s, t = f(n), f(m)
if len(t) > len(s):
    t = t[len(t) - len(s):]
if len(s) > len(t):
    t = '0' * (len(s) - len(t)) + t

@cache
def dfs(i: int, cnt: int, isLim: bool)->int:
    if i == len(s):
        return cnt
    hi = int(s[i]) if isLim else 1
    res = 0
    for d in range(hi + 1):
        res += dfs(i + 1, cnt + (d and int(t[i])), isLim and d == hi)
    return res
res = dfs(0, 0, True)
print(res % 998244353)