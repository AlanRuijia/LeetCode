class Solution {
public:
    int getSum(int a, int b) {
    	// while (b != 0) {
     //        int c = a ^ b;
     //        b = (a & b) << 1;
     //        a = c;
     //    }
     //    return a;
    	if (a==0)
    		return b;
    	if (b ==0)
    		return a;
        int add = 0,res = 0, p=1;
        while(a!=0 || b!=0 || add!=0){
        	int temp1 = a%2,temp2=b%2;
        	if (temp1^temp2^add)
        		res = (res) | p;
        	p = p << 1;
        	add = (temp1&temp2) | (temp1&add) | (temp2&add);
        	a = a>>1;
        	b = b>>1;
        }
        return res;
    }
};