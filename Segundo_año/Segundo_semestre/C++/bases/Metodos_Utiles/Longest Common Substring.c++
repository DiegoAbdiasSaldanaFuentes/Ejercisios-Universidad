#include <iostream>
#include <vector>
using namespace std;

// Function to find the length of the longest LCS 
// with space optimization
int longestCommonSubstr(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();

    // Create a 1D array to store the previous row's results
    vector<int> prev(n + 1, 0);
    
    int res = 0;
    for (int i = 1; i <= m; i++) {
      
        // Create a temporary array to store the current row
        vector<int> curr(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                curr[j] = prev[j - 1] + 1;
                res = max(res, curr[j]);
            } else {
                curr[j] = 0;
            }
        }
      
        // Move the current row's data to the previous row
        prev = curr;
    }
    return res;
}

// Driver Code
int main() {
    string s1 = "geeksforgeeks";
    string s2 = "ggeegeeksquizpractice";
    cout << longestCommonSubstr(s1, s2) << endl;
    return 0;
}