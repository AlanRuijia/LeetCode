// nums.size() is 3
//Initializaiton of vector
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
//        for (int i = 0, p =0; i < nums.size()-p;){
//        	if (nums[i] != 0)
//				i++;
//        	else{
//        		int j;
//				p++;
//        		for (j = i; j < nums.size()-1; j++){
//        			nums[j] = nums[j+1];
//        		}
//        		nums[j] = 0;
//        	}
//        }
		for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
			if (nums[cur] != 0) {
				swap(nums[lastNonZeroFoundAt++], nums[cur]);
			}
		}
    }
};

int main(){
	Solution s;
	int num[3] = {0,0,1};

	vector<int> nums(num, num + sizeof(num)/sizeof(int));
	s.moveZeroes(nums);
    std::vector<int>::iterator it;
    for (it=nums.begin();it != nums.end();it++)
	   cout << *it << ' ';
}