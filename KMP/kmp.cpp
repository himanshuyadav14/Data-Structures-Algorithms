#include <iostream>
#include <vector>
using namespace std;

// Function to build the LPS (Longest Prefix Suffix) array
vector<int> buildLPS(string pattern) {
    int m = pattern.size();
    vector<int> lps(m);
    
    int len = 0; // Length of the previous longest prefix suffix
    lps[0] = 0; // lps[0] is always 0
    
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                // Don't increment i here
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    return lps;
}

// KMP pattern searching algorithm
void KMPSearch(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    
    // Build the LPS array
    vector<int> lps = buildLPS(pattern);
    
    int i = 0; // index for text
    int j = 0; // index for pattern
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            // Pattern found at index i - j
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1]; // Get the next position from the LPS array
        } else if (i < n && pattern[j] != text[i]) {
            // Mismatch after j matches
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";
    
    KMPSearch(text, pattern);
    
    return 0;
}
