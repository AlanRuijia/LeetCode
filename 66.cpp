#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int adden = 1;
        for (int i=digits.size()-1;i>=0;i--){
            digits[i]+=adden;
            if (digits[i] == 10){
                digits[i] = 0;
                adden =1;
            }
            else {
                adden=0;
                break;
            }
        }
        if (adden==1){
            digits.insert(digits.begin(),1);
        }
        // for (int i=digits.size()-1;i>=0;i--)
        //     cout << digits[i] << " ";
        // cout << endl;
        return digits;
    }
};

int main(){
    int myints[] = {6,1,4,5,3,9,0,1,9,5,1,8,6,7,0,5,5,4,3};
    std::vector<int> ii(myints,myints+sizeof(myints)/sizeof(int));
    for (int i=ii.size()-1;i>=0;i--)
            cout << ii[i] << " ";
    cout << endl;
    Solution s;
    s.plusOne(ii);
}