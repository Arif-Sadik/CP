#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum multiplication cost
// We use references (&) to avoid copying the large tables
void solveMCM(vector<int> &p, vector<vector<int>> &m, vector<vector<int>> &s) {
    int n = p.size() - 1; // Number of matrices (Dimensions - 1)

    // Base case: The cost to multiply 1 matrix (A1, A2, etc.) is 0
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    // L is the chain length (starting from 2 matrices up to n)
    for (int L = 2; L <= n; L++) {
        // i is the starting matrix of the current sub-chain
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1; // j is the ending matrix of the sub-chain
            m[i][j] = INT_MAX; // Initialize cost as infinity to find the minimum

            // k is the split point: it divides the chain (Ai...Aj) into (Ai...Ak) and (Ak+1...Aj)
            for (int k = i; k < j; k++) {
                // The Core DP Formula:
                // m[i][k]   -> cost of the left half
                // m[k+1][j] -> cost of the right half
                // p[i-1]*p[k]*p[j] -> cost of multiplying the two resulting matrices
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                
                if (q < m[i][j]) {
                    m[i][j] = q;   // Update minimum cost
                    s[i][j] = k;   // Store the best split point k for parenthesization
                }
            }
        }
    }
}

// Recursive function to print the brackets
void print(int i, int j, vector<vector<int>> &s) {
    if (i == j) {
        cout << "A" << i; // Base case: only one matrix left, just print its name
        return;
    }
    cout << "(";
    print(i, s[i][j], s);        // Print the left side of the split (i to k)
    print(s[i][j] + 1, j, s);    // Print the right side of the split (k+1 to j)
    cout << ")";
}

int main() {
    int num_dims;
    // For 3 matrices, you need 4 dimensions (e.g., 10 20 30 40)
    if (!(cin >> num_dims)) return 0; 
    
    vector<int> p(num_dims);
    for (int i = 0; i < num_dims; i++) cin >> p[i];

    int n = num_dims - 1; // Actual count of matrices (e.g., 3)
    
    // We create tables of size 'num_dims' so that indexing 1 to n works easily
    vector<vector<int>> m(num_dims, vector<int>(num_dims, 0));
    vector<vector<int>> s(num_dims, vector<int>(num_dims, 0));

    solveMCM(p, m, s);

    // Output the total minimum cost found in the top-right corner of the table
    cout << "Minimum Multiplications: " << m[1][n] << endl;
    
    cout << "Optimal Parenthesization: ";
    print(1, n, s); // Call print for the full chain from matrix 1 to n
    cout << endl;

    return 0;
}