/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.14%)
 * Total Accepted:    554.5K
 * Total Submissions: 2M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 *
 * Example 1:
 *
 *
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: "cbbd"
 * Output: "bb"
 *
 *
 */
class Solution {
    public:
        string longestPalindrome(string s) {
            /*int iLen = s.length();
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
              */
            string result="";
            if(s.size() == 0)
                return result;
            for(int i=0; i<=s.size()-1; i++){
                int j=i, k=i;
                string tmp = "";
                while( j>=0 && k<= s.size()-1 && s[j] == s[k] ){
                    j--;
                    k++;
                }
                if(j!=k)
                    tmp = s.substr(j+1, k-j-1);
                else
                    tmp+=s[i];
                if(tmp.size() >= result.size())
                    result = tmp;
            }
            //寻找偶数长的回文
            for(int i=0, j=1; j<=s.size()-1; i++, j++){
                int m=i, n=j;
                string tmp = "";
                while( m>=0 && n<= s.size()-1 && s[m] == s[n] ){
                    m--;
                    n++;
                }
                if(n-m !=1)
                    tmp = s.substr(m+1, n-m-1);

                if(tmp.size() >= result.size())
                    result = tmp;
            }

            return result;
        }
};
