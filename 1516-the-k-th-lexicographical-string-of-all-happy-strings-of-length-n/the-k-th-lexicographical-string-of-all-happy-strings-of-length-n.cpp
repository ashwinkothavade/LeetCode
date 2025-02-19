class Solution {
public:
    void generateHappyStrings(int n, string &curr, vector<string> &res) {
        if (curr.size() == n) {
            res.push_back(curr);
            return;
        }
        for (char ch : {'a', 'b', 'c'}) {
            if (curr.empty() || curr.back() != ch) {
                curr.push_back(ch);
                generateHappyStrings(n, curr, res);
                curr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        string curr = "";
        generateHappyStrings(n, curr, happyStrings);
        return (k <= happyStrings.size()) ? happyStrings[k - 1] : "";
    }
};
