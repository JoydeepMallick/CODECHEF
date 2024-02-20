def solve(a, swaps):
  onepos = a.index(1)
  a = a[onepos:] + a[:onepos]
  for i in range(1, n):
    if swaps == 0 or a[i] == i+1: continue
    pos = a.index(i+1)
    swaps -= 1
    a[i], a[pos] = a[pos], a[i]
    return a

for _ in range(int(input())):
  n = int(input())
  a = list(map(int, input().split()))
  ans = solve(a[:], 2)
  onepos = a.index(1)
  starts = []
  for i in range(n):
    if a[i] == 2:
      starts.append(i)
      starts.append((i-1)%n)
      starts.append((i-2)%n)
      if a[i] == 3:
        starts.append((i-2)%n)
        starts.append(i)
    for x in starts:
      a[onepos], a[x] = a[x], a[onepos]
      ans = min(ans, solve(a[:], 1))
      a[onepos], a[x] = a[x], a[onepos]
    print(*ans)
