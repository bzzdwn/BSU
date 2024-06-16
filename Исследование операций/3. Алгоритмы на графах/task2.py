from collections import deque

n = 0
count = 0
graph = []
met = []
two = False
connect = False
ma = 0

def bfs(v):
    global count, two, met, ma
    dols = [1, 0]
    count = 1
    two = True
    met[v] = 0
    queue = deque([v])
    
    while queue:
        tmp = queue.popleft()
        for i in range(len(graph[tmp])):
            if met[graph[tmp][i]] == -1:
                count += 1
                met[graph[tmp][i]] = (met[tmp] + 1) % 2
                dols[(met[tmp] + 1) % 2] += 1
                queue.append(graph[tmp][i])
            elif met[graph[tmp][i]] == met[tmp]:
                two = False
    
    if two:
        if dols[0] > dols[1]:
            ma += dols[0]
        else:
            ma += dols[1]
    else:
        ma += 1

def main():
    global n, count, graph, met, two, ma
    with open("input.txt", "r") as fin:
        ma = 0
        j = 0
        n = int(fin.readline())
        graph = [[] for _ in range(n)]
        met = [-1] * n
        
        for line in fin:
            line = line.strip()
            values = list(map(int, line.split()))
            for v in values:
                if v != 0:
                    graph[j].append(v - 1)
            j += 1
    
    count = bfs(0)
    times = 1
    
    with open("output.txt", "w") as fout:
        if count == n and not two:
            fout.write("YES")
        elif count == n and two:
            fout.write("NO\n")
            fout.write(str(ma))
        elif count != n:
            for i in range(n):
                if met[i] == -1:
                    count += bfs(i)
                    times += 1
            fout.write("NO\n")
            fout.write(str(ma))