// set: unique elements
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // set<int> shortSet;
        // set<int> returnSet;
        // vector<int> ret;

        // if(nums1.size() > nums2.size()){
        //     vector<int> tmp = nums1;
        //     nums1 = nums2;
        //     nums2 = tmp;
        // }

        // for(auto i = nums1.begin(); i != nums1.end(); i++){
        //     shortSet.insert(*i);
        // }
        // for(auto i = nums2.begin(); i != nums2.end(); i++){
        //     if(shortSet.count(*i) > 0){
        //         returnSet.insert(*i);
        //     }
        // }
        // for(auto i = returnSet.begin(); i != returnSet.end(); i++){
        //     ret.push_back(*i);
        // }
        // return ret;

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++){
        	for (int j = 0; j<nums2.size();j++){
        		int flag = 1;
        		if (nums1[i] == nums2[j]){
        			for (int p = 0; p < ans.size();p++)
        				if (ans[p] == nums1[i]){
        					flag = 0;
        					break;
        				}
        			if (flag)
        				ans.push_back(nums1[i]);
        		}
        	}
        }
        return ans;
    }
};