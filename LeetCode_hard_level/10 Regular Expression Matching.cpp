class Solution {
public:
    bool isMatch(string s, string p) {
        int i, j;
    int m = s.size();
    int n = p.size();
    bool b[m+1][n+1];
    b[0][0] = true;
    for (i = 0; i < m; i++) {
        b[i + 1][0] = false;
    }
    for (j = 0; j < n; j++) {
        b[0][j + 1] = j > 0 && '*' == p[j] && b[0][j - 1];
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (p[j] != '*') {
                b[i + 1][j + 1] = b[i][j] && ('.' == p[j] || s[i] == p[j]);
            } else {
                b[i + 1][j + 1] = b[i + 1][j - 1] && j > 0 || b[i + 1][j] ||
                            b[i][j + 1] && j > 0 && ('.' == p[j - 1] || s[i] == p[j - 1]);
            }
        }
    }
    return b[m][n];
    }
};