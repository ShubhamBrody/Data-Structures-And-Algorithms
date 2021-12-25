/**
 * @type of s: string
 * @return type: integer
 */
class Solution {
public:
    int romanToInt(string s) {
        map <char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        // write your awesome code here
        
        int sum = 0;
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(i > 0 && roman[s[i]]%roman[s[i-1]]==0 && (roman[s[i]]/roman[s[i-1]] == 10 || roman[s[i]]/roman[s[i-1]] == 5))
            {
                sum += roman[s[i]] - roman[s[i-1]];
                i--;
                continue;
            }
            sum += roman[s[i]];
        }
        return sum;
    }
};