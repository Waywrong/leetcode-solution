//  Roman to Integer

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        
        for(int i=0; i<s.size()-1; i++) {
            int temp = returnInt(s[i]);
            int temp2 = returnInt(s[i+1]);
            if(temp<temp2)
                sum -= temp;
            else 
                sum += temp;
        }
        
        return sum + returnInt(s[s.size()-1]);
    }
    
    int returnInt(char c) {
        switch(c) {
            case 'I':   return 1;
            case 'X':   return 10;
            case 'C':   return 100;
            case 'D':   return 500;
            case 'V':   return 5;
            case 'L':   return 50;
            case 'M':   return 1000;
            default:    return 0;
        }
    }
};
