//  String to Integer (atoi)

class Solution {
public:
    int myAtoi(string str) {
        int i = 0, len = str.length();
        for (; i<len && str[i]==' '; i++)   continue;
        if (i == len)   return 0;
        if (!isdigit(str[i]) && str[i]!='+' && str[i]!='-')
            return 0;
        int k = (str[i]=='-') ? -1 : 1;
        if (str[i]=='+' || str[i]=='-') i ++;
        long res = 0;
        for (; i<len && isdigit(str[i]); i++) {
            res = res * 10 + (str[i] - '0');
            if (k==1 && res>INT_MAX)    return INT_MAX;
            if (k==-1 && -res<INT_MIN)  return INT_MIN;
        }
        return res * k;
    }
};