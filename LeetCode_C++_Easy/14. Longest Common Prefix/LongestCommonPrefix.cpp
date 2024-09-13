#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".


Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {

        if (strs.empty()) return ""; 

        std::string shortString = strs[0];

        for(const auto& i: strs){
            if(shortString.size()>i.size()){
                shortString = i;
            }
        }

        for(int i = 0; i<shortString.size();i++){
            for(const auto& j: strs){
                if(shortString[0]==j[0]){
                    if(shortString[i]!=j[i]) 
                    {
                        std::string prefix = shortString.substr(0, i); 
                        return prefix;
                    }
                } 
                else return "";
            }
        }

       return shortString;
    }
};

int main(){
    Solution sol;
    std::vector<std::string> strs= {"flower","flow","flight"};
    

    std::cout<<sol.longestCommonPrefix(strs);

}