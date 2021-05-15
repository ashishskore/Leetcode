/*

Important Point to note is, before applying dp, remove all consecutive '*' as its logically same

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input: s = "acdcb", p = "a*c?b"
Output: false
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
*/

#include<iostream>
using namespace std;

bool isMatch(string s, string p) {
    string pattern;
    bool star_found = false;
    
    for (size_t i = 0; i < p.size(); i++)
    {
        if(p[i] != '*') {
            star_found = false;
            pattern += p[i];
            continue;
        } else {
            if(!star_found){
                pattern += p[i];
                star_found = true;
            }
        }
    }
    
    int a = s.size()+1;
    int b = pattern.size()+1;

    if(a==1 and b == 1) return true;
    
    bool dp[a][b];

    for (size_t i = 0; i < a; i++)
        dp[i][0] = false;

    for (size_t i = 0; i < b; i++)
        dp[0][i] = false;

    dp[0][0] = true;
    if(b>1 and pattern[0] == '*')
        dp[0][1] = true; 

    for (size_t i = 1; i < a; i++)
    {
        for (size_t j = 1; j < b; j++)
        {
            if (pattern[j-1] == s[i-1] or pattern[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            } else if (pattern[j-1] == '*') {
                dp[i][j] = dp[i-1][j] | dp[i][j-1];
            } else {
                dp[i][j] = false;
            }
        }
    }
    return dp[a-1][b-1];
}

int main(){
    string s = "ho";
    string p = "**ho";
    cout << isMatch(s,p) << endl;
    return 0;
}

/*
"adceb"
"*a*b"
"acdcb"
"a*c?b"
*/
