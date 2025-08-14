class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "";
        for(int i = 0; i<s.size(); i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                vowels += s[i];
                s[i] = '/';
            }
        }

        int index = vowels.size()-1;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '/'){
                s[i] = vowels[index--];
            }
        }
        return s;
    }
};