class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> letters;
        for (int i = 0; i < s.size(); ++i) {
            if (!letters.contains(s[i])) letters[s[i]] = 1;
            else letters[s[i]]++;
        }
        for (int j = 0; j < t.size(); ++j) {
            if (!letters.contains(t[j])) return false;
            letters[t[j]]--;
        }
        for (auto& elements : letters) {
            if (elements.second != 0) return false;
        }
        return true;
    }
};
