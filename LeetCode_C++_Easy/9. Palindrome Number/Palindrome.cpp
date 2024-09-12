#include <iostream>
#include <vector>
#include <string>

/*
Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

class Solution {
public:
    bool isPalindrome(int x) {

        //Solution 1: Strings
        /*
             std::string str = std::to_string(x);
        std::string new_str = str;
        std::reverse(new_str.begin(), new_str.end());
        if(new_str==str) return true;
        return false;
        */

       //Solution 2: Simple math
       /*
        long long reversed = 0;
        long long temp = abs(x);
        while(temp!=0)
        {
            reversed+= (temp%10)*pow(10,std::to_string(temp).length()-1);
            temp/=10;
        }
        if(reversed == x) return true;
        
        return false;
        */

        //Solution 3: More optimized math
       if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }

        long long reversed = 0;
        long long temp = x;

        while (temp != 0) {
            int digit = temp % 10;
            reversed = reversed * 10 + digit;
            temp /= 10;
        }

        return (reversed == x);
    }
};

int main()
{
    Solution sol;

    std::cout<<sol.isPalindrome(-121);
}