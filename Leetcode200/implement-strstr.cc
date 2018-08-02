//  Implement strStr()

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.empty())
            return (needle.empty() ? 0 : -1);
        if (needle.empty()) return 0;
        int len1 = haystack.length(), len2 = needle.length();
        if (len1 < len2)    return -1;
        for (int i=0; i<=len1-len2; i++) {
            if (haystack[i] != needle[0])   continue;
            int j, k;
            for (j=i, k=0; k<len2 && haystack[j]==needle[k]; j++, k++);
            if (k == len2)  return i;
        }
        return -1;
    }
};