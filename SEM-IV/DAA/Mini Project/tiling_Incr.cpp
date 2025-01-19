#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void tile_subcourtyard(vector<vector<int> >& tiles, int x, int y, int size) {
    // Tile a 2x2 sub-courtyard with an L-shaped tromino
    int dx[3] = {0, 1, 1};
    int dy[3] = {1, 0, 1};
    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i] * size / 2;
        int ny = y + dy[i] * size / 2;
        tiles[nx][ny] = -1; // Place tromino
    }
}

void tile_courtyard(vector<vector<int> >& tiles, int x, int y, int size) {
    // Initialize queue with the entire courtyard
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    q.push(make_pair(x + size - 1, y));
    q.push(make_pair(x, y + size - 1));
    q.push(make_pair(x + size - 1, y + size - 1));

    while (!q.empty()) {
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();

        // Check if sub-courtyard is a 2x2 square
        if (size == 2) {
            tile_subcourtyard(tiles, qx, qy, size);
        } else {
            // Divide sub-courtyard into quadrants and enqueue them
            int half_size = size / 2;
            vector<pair<int, int> > quadrants = {
                make_pair(qx, qy),
                make_pair(qx + half_size, qy),
                make_pair(qx, qy + half_size),
                make_pair(qx + half_size, qy + half_size)
            };
            for (const auto& quadrant : quadrants) {
                int qx1 = quadrant.first;
                int qy1 = quadrant.second;
                int qx2 = qx1 + half_size - 1;
                int qy2 = qy1 + half_size - 1;
                if (tiles[qx1][qy1] != -1) {
                    q.push(make_pair(qx1, qy1));
                    q.push(make_pair(qx2, qy1));
                    q.push(make_pair(qx1, qy2));
                    q.push(make_pair(qx2, qy2));
                }
            }
        }
    }
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    // Initialize tiles with 0 (untiled) and statue with -1
    vector<vector<int> > tiles(1 << n, vector<int>(1 << n, 0));
    tiles[x][y] = -1;

    // Tile courtyard
    tile_courtyard(tiles, 0, 0, 1 << n);

    // Print tiles
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            if (tiles[i][j] == -1) {
                cout << "S ";
            } else if (tiles[i][j] == 0) {
                cout << ". ";
            } else {
                cout << "L ";
            }
        }
        cout << endl;
    }

    return 0;
}