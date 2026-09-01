// class Solution {
// public:
//     int minMoves(vector<string>& classroom, int energy) {
//         int n = classroom.size();
//         int m = classroom[0].size();
//         int sx, sy;
//         int cnt = 0;
//         vector<vector<int>> id(n, vector<int>(m, -1));
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 if(classroom[i][j] == 'S') {
//                     sx = i;
//                     sy = j;
//                 }
//                 if(classroom[i][j] == 'L') {
//                     id[i][j] = cnt++;
//                 }
//             }
//         }
//         int full = (1 << cnt) - 1;
//         queue<tuple<int,int,int,int,int>> q;
//         q.push({sx, sy, energy, 0, 0});
//         set<tuple<int,int,int,int>> visited;
//         visited.insert({sx, sy, energy, 0});
//         int dx[] = {1, -1, 0, 0};
//         int dy[] = {0, 0, 1, -1};
//         while(!q.empty()) {
//             auto [x, y, e, mask, moves] = q.front();
//             q.pop();
//             if(mask == full)
//                 return moves;
//             for(int d = 0; d < 4; d++) {
//                 int nx = x + dx[d];
//                 int ny = y + dy[d];
//                 if(nx < 0 || nx >= n || ny < 0 || ny >= m)
//                     continue;
//                 if(classroom[nx][ny] == 'X')
//                     continue;
//                 if(e == 0)
//                     continue;
//                 int ne = e - 1;
//                 int nmask = mask;
//                 if(classroom[nx][ny] == 'L') {
//                     nmask |= (1 << id[nx][ny]);
//                 }
//                 if(classroom[nx][ny] == 'R') {
//                     ne = energy;
//                 }
//                 auto state = make_tuple(nx, ny, ne, nmask);
//                 if(!visited.count(state)) {
//                     visited.insert(state);
//                     q.push({nx, ny, ne, nmask, moves + 1});
//                 }
//             }
//         }
//         return -1;
//     }
// };




class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        int sx, sy, cnt = 0;

        vector<vector<int>> id(n, vector<int>(m, -1));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                if(classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }
        int full = (1 << cnt) - 1;
        vector<vector<vector<vector<bool>>>> vis(
            n,
            vector<vector<vector<bool>>>(
                m,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << cnt, false)
                )
            )
        );
        queue<array<int,5>> q;
        q.push({sx, sy, energy, 0, 0});
        vis[sx][sy][energy][0] = true;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur[0];
            int y = cur[1];
            int e = cur[2];
            int mask = cur[3];
            int moves = cur[4];
            if(mask == full)
                return moves;
            if(e == 0)
                continue;
            for(int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if(classroom[nx][ny] == 'X')
                    continue;
                int ne = e - 1;
                int nmask = mask;
                if(classroom[nx][ny] == 'L')
                    nmask |= (1 << id[nx][ny]);
                if(classroom[nx][ny] == 'R')
                    ne = energy;
                if(!vis[nx][ny][ne][nmask]) {
                    vis[nx][ny][ne][nmask] = true;
                    q.push({nx, ny, ne, nmask, moves + 1});
                }
            }
        }
        return -1;
    }
};