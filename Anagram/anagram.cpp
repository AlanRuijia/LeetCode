class Solution {
public:
    bool isAnagram(string s, string t) {
        size_t len = s.length();
        if (len != t.length())
            return false;
        else{
            std::map<char,int> histogram;
            for (int i = 0; i < len;i++){
                histogram[s[i]]++;
                histogram[t[i]]--;
            }
            std::map<char,int>::iterator it = histogram.begin();
            for (;it!=histogram.end();it++)
                if (it->second != 0)
                    break;
            if (it == histogram.end())
                return true;
            else return false;
        }
    }
};
//Answer:
// public boolean isAnagram(String s, String t) {
//     if (s.length() != t.length()) {
//         return false;
//     }
//     int[] counter = new int[26];
//     for (int i = 0; i < s.length(); i++) {
//         counter[s.charAt(i) - 'a']++;
//         counter[t.charAt(i) - 'a']--;
//     }
//     for (int count : counter) {
//         if (count != 0) {
//             return false;
//         }
//     }
//     return true;
// }