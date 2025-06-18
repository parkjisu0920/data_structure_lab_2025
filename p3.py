from collections import deque

def bfs(N, forest, bear_x, bear_y, bear_size):
    visited = [[-1]*N for _ in range(N)]
    q = deque()
    q.append((bear_x, bear_y))
    visited[bear_x][bear_y] = 0

    dx = [-1, 0, 0, 1]  # 위, 좌, 우, 아래
    dy = [0, -1, 1, 0]

    candidates = []

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < N and 0 <= ny < N:
                if visited[nx][ny] == -1 and forest[nx][ny] <= bear_size:
                    visited[nx][ny] = visited[x][y] + 1
                    q.append((nx, ny))
                    if 0 < forest[nx][ny] < bear_size:
                        candidates.append((visited[nx][ny], nx, ny))

    if not candidates:
        return None
    candidates.sort()  # 거리, x, y 순
    return candidates[0]

def simulate(N, forest):
    for i in range(N):
        for j in range(N):
            if forest[i][j] == 9:
                bear_x, bear_y = i, j
                forest[i][j] = 0  # 곰 자리 비우기
                break

    bear_size = 2
    eat_count = 0
    total_time = 0

    while True:
        result = bfs(N, forest, bear_x, bear_y, bear_size)
        if result is None:
            break
        dist, nx, ny = result
        total_time += dist
        eat_count += 1
        forest[nx][ny] = 0
        bear_x, bear_y = nx, ny
        if eat_count == bear_size:
            bear_size += 1
            eat_count = 0

    return total_time

def main():
    N = int(input("숲의 크기 N 입력: "))
    print("숲의 지도를 한 줄씩 입력하세요 (숫자 이어 붙여서):")
    forest = []
    for _ in range(N):
        line = input().strip()
        forest.append(list(map(int, line)))
    
    result = simulate(N, forest)
    print("곰이 꿀을 먹고 움직인 총 시간:", result)

if __name__ == "__main__":
    main()
