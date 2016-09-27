#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int start=0, end=s.size()-1;
        char vowels[10] = {'a','e','i','o','u', 'A', 'E', 'I', 'O', 'U'};
        bool startFlag = false, endFlag = false;
        while (start < end){
            int i=0,j=0;
            for (i=0;i<10;i++)
                if (s[start]==vowels[i]){
                    // cout << s[start] << endl;
                    break;
                }
            if (i==10)
                start++;
            for (j=0;j<10;j++)
                if (s[end]==vowels[j]){
                    // cout << s[end] << endl;
                    break;
                }
            if (j==10)
                end--;
            if (i!=10 && j!=10){
                char tmp = s[start];
                // cout << i << endl << j << endl;
                // cout << start << endl << end << endl;
                s.replace(start,1,1,s[end]);
                s.replace(end,1,1,tmp);
                // cout << s << endl;
                start++;
                end--;
            }
        }
        return s;
    }
};

int main(){
    Solution s;
    // cout << s.reverseVowels("aA");
}