#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    	//null judgement is important!!!
    	std::vector<int> v;
    	if (nums1.size()==0 or nums2.size()==0)
    		return v;
    	sort(nums2.begin(),nums2.end());
    	sort(nums1.begin(), nums1.end());
    	std::vector<int>& small=nums1.size()>nums2.size()?nums1:nums2;
    	std::vector<int>& big=nums1.size()>nums2.size()?nums2:nums1;
    	std::vector<int>::iterator bigItr = big.begin();
    	std::vector<int>::iterator smallItr = small.begin();
    	while (smallItr!=small.end()){
    		if (*smallItr == *bigItr){
    			v.push_back(*smallItr);
    			smallItr++;
    			bigItr++;
    		}
    		else if (*smallItr < *bigItr)
    			smallItr++;
    		else bigItr++;
    	}
  		return v; 
  		// map<int,int> m;  
    //     vector<int> out;  
          
    //     for(int i : nums1) m[i]++;  
    //     for(int j : nums2) {  
    //         if (m[j] > 0) {  
    //         m[j]--;  
    //         out.push_back(j);  
    //         }  
    //     }  
    //     return out;     
    }
};

int main(){
	int myints1[] = {3,1,2}, myints2[] ={1,1}; 
	vector<int> i(myints1,myints1+sizeof(myints1)/sizeof(int)),j(myints2,myints2+sizeof(myints2)/sizeof(int));
	for (std::vector<int>::iterator it = i.begin();it!=i.end();it++){
		cout << *it << " ";
	}
	cout << endl;
	for (std::vector<int>::iterator it = j.begin();it!=j.end();it++){
		cout << *it << " ";
	}
	cout << endl;
	Solution s;
	std::vector<int> v = s.intersect(i,j);

	for (std::vector<int>::iterator it = v.begin();it!=v.end();it++){
		cout << *it << endl;
	}
}