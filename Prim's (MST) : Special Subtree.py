[N, M] = map(int, input().split(' '))
edges = {}
weight_of_mst = 0
for i in range(1, N+1):
    edges[i] = []
for m in range(M):
    [x, y, r] = map(int, input().split(' '))
    edges[x] += [[y,r]]
    edges[y] += [[x,r]]
start = int(input())
in_mst = set([start])
while len(in_mst) < N:
    minn = 1000000
    minnode = -1
    for i in in_mst:
        for j in edges[i]:
            if j[0] not in in_mst:
                if j[1] < minn:
                    minn = j[1]
                    minnode = j[0]
    if minnode > 0:
        in_mst.add(minnode)
        weight_of_mst += minn
print (weight_of_mst)
