n, k = map(int, input().split())
s = input()
res = []
i = 0
while i < n:
    j = i + 1
    while j < n and s[j] == s[i]:
        j += 1
    res.append(s[i:j])
    i = j
cnt = 0
for i, si in enumerate(res):
    if si[0] == '1':
        cnt += 1
        if cnt == k:
            res[i - 1], res[i] = res[i][:], res[i - 1][:]
            break
print("".join(res))