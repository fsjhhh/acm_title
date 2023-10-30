def qmi(a, k, p):
    res = 1
    while k:
        if k & 1:
            res = res * a % p
        k >>= 1
        a = a * a % p
    return res

n = int(input())
if n == 2:
    print(7)
else :
    mod = 998244353
    res = 1
    m = qmi(n, n, mod) - n + 1
    m = (m + mod) % mod
    print(m)