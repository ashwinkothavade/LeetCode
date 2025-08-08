class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for (char it : s) {
            if (isalnum(it)) { // includes letters and digits
                t.push_back(tolower((unsigned char)it));
            }
        }
        int n = t.size();
        for (int i = 0; i < n / 2; i++) {
            if (t[i] != t[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
};
