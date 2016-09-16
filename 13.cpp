
class Solution {
public:
    int romanToInt(string s) {
		int i=0;
		int res=0;
		while (i!= int(s.size())) { 
			if (!s.compare(i,2,"CD")){
				i+=2;
				res+=400;
				continue;
			} 
			if (!s.compare(i,2,"CM")){
				i+=2;
				res+=900;
				continue;
			}
			if (!s.compare(i,2,"XL")){
				i+=2;
				res+=40;
				continue;
			} 
			if (!s.compare(i,2,"XC")){
				i+=2;
				res+=90;
				continue;
			}
			if (!s.compare(i,2,"IV")){
				i+=2;
				res+=4;
				continue;
			} 
			if (!s.compare(i,2,"IX")){
				i+=2;
				res+=9;
				continue;
			}
			if (s[i] == 'M') //! char is ' '
				res+=1000;
			if (s[i] == 'D')
				res+=500;
			if (s[i] == 'C')
				res+=100;
			if (s[i] == 'L')
				res+=50;
			if (s[i] == 'X')
				res+=10;
			if (s[i] == 'V')
				res+=5;
			if (s[i] == 'I')
				res+=1;
			i++;
		}       
		return res;
    }
};

