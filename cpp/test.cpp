#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <list>
using namespace std;

string longestPalindrome(string s)
{
    int iLen = s.length();
    if (s == "") return "";
    if (iLen == 1) return s;
    int iMaxLen = 0, iCurLen = 0;
    string sMaxStr = "", sCurStr = "";
    for (int i = 0; i < iLen-1; i++)
    {
        iCurLen = 1;
        sCurStr = s[i];
        int k = 1, j = i + 1;
        while ((i-k) >= 0 && (i+k) < iLen && s[i-k] == s[i+k])
        {
            iCurLen += 2;
            sCurStr = s.substr(i-k, k*2+1);
            k++;
        }
        if (iCurLen > iMaxLen)
        {
            iMaxLen = iCurLen;
            sMaxStr = sCurStr;
        }

        if (s[i] == s[j])
        {
            k = 1;
            iCurLen = 2;
            sCurStr = s.substr(i, 2);
            while ((i-k) >= 0 && (j+k) < iLen && s[i-k] == s[j+k])
            {
                iCurLen += 2;
                sCurStr = s.substr(i-k, (k+1)*2);
                k++;
            }
            if (iCurLen > iMaxLen)
            {
                iMaxLen = iCurLen;
                sMaxStr = sCurStr;
            }
        }
    }

    return sMaxStr;
}

int main()
{
    cout << longestPalindrome("cbbd") << endl;

    return 0;
}
