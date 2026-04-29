#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-03-15

// Direction arrays: Up, Down, Left, Right
// If we are at (r, c), going UP means row-1, col+0
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
char move_name[] = {'U', 'D', 'L', 'R'};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> grid(n);
    
    // We use a very large number (infinity) to represent squares that haven't been reached yet.
    int INF = 1e9;
    vector<vector<int>> monster_time(n, vector<int>(m, INF));
    vector<vector<int>> my_time(n, vector<int>(m, INF));
    
    // This array remembers WHICH direction we moved to reach a specific square.
    // We need this at the end to trace our steps backwards and print the path.
    vector<vector<int>> came_from(n, vector<int>(m, -1));

    queue<pair<int, int>> monster_queue;
    queue<pair<int, int>> my_queue;
    
    int start_r = -1, start_c = -1;

    // --- STEP 1: READ THE MAP AND FIND STARTING POSITIONS ---
    for (int r = 0; r < n; r++) {
        cin >> grid[r];
        for (int c = 0; c < m; c++) {
            if (grid[r][c] == 'M') {
                monster_queue.push({r, c});
                monster_time[r][c] = 0; // Monsters start at time 0
            } else if (grid[r][c] == 'A') {
                start_r = r;
                start_c = c;
                my_queue.push({r, c});
                my_time[r][c] = 0; // You start at time 0
            }
        }
    }

    // --- STEP 2: MONSTER BFS (When does the gas reach each square?) ---
    while (!monster_queue.empty()) {
        auto [r, c] = monster_queue.front();
        monster_queue.pop();

        // Check all 4 directions
        for (int i = 0; i < 4; i++) {
            int next_r = r + dr[i];
            int next_c = c + dc[i];

            // 1. Is it inside the map bounds?
            // 2. Is it a floor (not a wall '#')?
            // 3. Is this the first/fastest time a monster reached this square?
            if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m) {
                if (grid[next_r][next_c] != '#' && monster_time[r][c] + 1 < monster_time[next_r][next_c]) {
                    
                    monster_time[next_r][next_c] = monster_time[r][c] + 1;
                    monster_queue.push({next_r, next_c});
                    
                }
            }
        }
    }

    // --- STEP 3: YOUR BFS (Finding the escape route) ---
    int exit_r = -1, exit_c = -1; // Variables to save where we successfully escape
    
    while (!my_queue.empty()) {
        auto [r, c] = my_queue.front();
        my_queue.pop();

        // WIN CONDITION: Are we standing on the outer edge of the map?
        if (r == 0 || r == n - 1 || c == 0 || c == m - 1) {
            exit_r = r;
            exit_c = c;
            break; // Stop the BFS! We found an exit.
        }

        // Check all 4 directions to run
        for (int i = 0; i < 4; i++) {
            int next_r = r + dr[i];
            int next_c = c + dc[i];

            if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m) {
                if (grid[next_r][next_c] != '#') {
                    
                    int time_to_reach = my_time[r][c] + 1;
                    
                    // CORE LOGIC: We can only step here if we haven't visited it yet, 
                    // AND we get there strictly faster than any monster.
                    if (time_to_reach < my_time[next_r][next_c] && time_to_reach < monster_time[next_r][next_c]) {
                        
                        my_time[next_r][next_c] = time_to_reach;
                        came_from[next_r][next_c] = i; // Save the direction (0=U, 1=D, 2=L, 3=R)
                        my_queue.push({next_r, next_c});
                        
                    }
                }
            }
        }
    }

    // --- STEP 4: PRINT THE RESULT AND TRACE THE PATH ---
    if (exit_r == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        
        string path = "";
        int r = exit_r;
        int c = exit_c;
        
        // Walk backwards from the exit until we hit our starting point 'A'
        while (r != start_r || c != start_c) {
            int move_made = came_from[r][c];
            path += move_name[move_made]; // Add 'U', 'D', 'L', or 'R' to our string
            
            // To go backwards, we do the exact OPPOSITE of the move we made.
            // If we moved Right (dc = +1) to get here, we subtract 1 to go back.
            r -= dr[move_made];
            c -= dc[move_made];
        }
        
        // Because we traced from the finish line to the start, the string is backwards.
        reverse(path.begin(), path.end());
        
        cout << path.length() << "\n";
        cout << path << "\n";
    }

    return 0;
}