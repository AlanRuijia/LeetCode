//Things to remember: ASCII 'a' isn't 1.
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int i = 0;
        int alphabet[26];
        for (int j = 0;j < 26;j++)
        	alphabet[j] = -2;
        while (i<s.length()){
        	if (alphabet[(int)s[i]-int('a')]==-1){
        	    i++;
        		continue;
            }
            else{
        	   if (alphabet[(int)s[i]-int('a')]!=-2){
        		  alphabet[(int)s[i]-int('a')]=-1;
        		  i++;
        		  continue;
        	   }
            }
        	alphabet[(int)s[i]-int('a')]=i;
        	i++;
        }
        int small = -1;
        for (int i=0;i<26;i++){
        	if (alphabet[i]!=-1 && alphabet[i]!=-2){
        		if (small==-1 && alphabet[i]!= -1 && alphabet[i]!= -2)
        			small = alphabet[i];
        		if (small > alphabet[i] && alphabet[i]!= -1 && alphabet[i]!= -2)
        			small = alphabet[i];
        	}
        }
        return small;
    }
};

int main(){
	Solution a;
	cout << a.firstUniqChar("loleet");
}