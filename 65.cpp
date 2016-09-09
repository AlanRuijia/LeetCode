#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        s = this->strip(s);
        if (!this->isMultiple(s))
            return false;
        if (!this->isValid(s))
            return false;
        return true;
        
    }
    bool isValid(string s){
        if (s.size() == 0)
            return false;
        if (s[0] == 'e' || s[s.size()-1] == 'e' || (s[0] == '.' && s.size()==1))
            return false;

        if (abs(int(s.find('e'))-int(s.find('.')))==1 && int(s.find('e'))!=-1){
            
            return false;
        }
        for (int i=0;i<s.size();i++){
            if ((s[i] < '0' && (s[i] !='.' && s[i]!='e') )|| (s[i] > '9' && (s[i] !='.' && s[i]!='e')))
                return false;
        }
        return true;
    }
    bool isMultiple(string s){
        if (s.find_first_of('.')!=s.find_last_of('.') && s.find_last_of('.') != s.size()-1 && s.size()>1)
            return false;
        if (s.find_first_of('e')!=s.find_last_of('e'))
            return false;
        if (s.size()-1==s.find_last_of('.'))
            return false;
        if (s.size()-1==s.find_last_of('e'))
            return false;
        return true;
    }
    string strip(string s){
        while(s[0]==' '){
            s.erase(0,1);
        }
        while(s[s.size()-1]==' '){
            s.erase(s.size()-1,1);
        }
        return s;
    }
};
int main(){
    Solution s;
    cout << "res" <<s.isNumber(".1");
}