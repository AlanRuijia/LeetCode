#include <vector>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

class mySolution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for (int i=0;i<nums.size();i++)
        	m[nums[i]]++;
        for (map<int, int>::iterator itr = m.begin(); itr != m.end(); itr++)
        {
            if (itr -> second > nums.size()/2)
                return itr -> first;
        }
    }
};

class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int candidate = nums[0];
        for (int i=1;i<nums.size();i++){
            if (candidate != nums[i])
                count--;
            else count++;
            if (count == 0 && i+1 <= nums.size())
                candidate = nums[i+1];
        }
        return candidate;
    }
};

class Solution { // seems to be not working
public:
    int majorityElement(vector<int>& nums) {
        int bits[32] = {};
        for (int i=0;i<nums.size();i++){
            int tmp = nums[i];
            for (int j=0; j<32;j++){
                // bits[j] += tmp&1; //!!! Cannot be tmp%2 -1%2 = -1
                // tmp>>=1;
                // if(tmp==0)
                //     break;
                if (nums[i] & (1 << j))
                    bits[j]++;
            }
        }
        int res=0;
        for (int i=0; i<32;i++){
            res+= pow(2,i) * (bits[i]>int(nums.size()/2)?1:0);
            cout << bits[i] << endl;
        }
        return int(res); //!!!
    }
};

int main(){
	Solution1 s;
	int myints[] = {-1,-1,2147483648};
	vector<int> a (myints, myints + sizeof(myints) / sizeof(int));
	cout << s.majorityElement(a);
}