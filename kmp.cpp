#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to compute LPS (Longest Prefix Suffix) array
vector<int> computeLPS(string pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP search function
void KMPSearch(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = computeLPS(pattern);

    int i = 0, j = 0;
    bool found = false;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
            found = true;
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    if (!found)
        cout << "Pattern not found in the text." << endl;
}

int main() {
    string text, pattern;

    cout << "Enter the text: ";
    getline(cin, text); // use getline to include spaces

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    KMPSearch(text, pattern);

    return 0;
}

