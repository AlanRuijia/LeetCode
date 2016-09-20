class Solution {
public:
	int get_digits(int n){
		int mySum = 0;
		while(n){
			mySum += pow(n%10,2);
			n/=10;
		}
		return mySum;
	}
    bool isHappy(int n) {
        
        map<int, int> m;
        flag = true;
        m[n]++;
        while (n!=1 && flag){
        	n = get_digits(n);
        	m[n]++;
        	for (map<int,int>::iterator itr=m.begin();itr!=m.end();itr++){
        		if (itr->second > 1)
        			flag = false;
        	}
        	if (!flag)
        		break;
        }
        return n==1;
    }
};