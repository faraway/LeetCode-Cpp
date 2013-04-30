/**
 Given a string, find the length of the longest substring without repeating characters. 
 For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
 which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 
 NOTE: This implementation is simpler and better than my java implementation
**/

#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;

        int max = 0;
        int start = 0;
        unordered_map<char,int> map;
        map.insert(pair<char,int>(s[0],0));
        
        for(int i=1;i<s.size();i++){
            unordered_map<char,int>::const_iterator entry = map.find(s[i]);
            if(entry == map.end())
                map.emplace(s[i],i);
            else{
                int temp = entry->second;
                map.erase(entry);
                //map.insert(pair<char,int>(s[i],i)); Copy operation is performed for insert().
                //emplace() inserts element in-place. i.e. no copy or move operations are performed
                map.emplace(s[i],i);
                //if < start, means the former repeated char is out of current range.
                if(temp<start)
                    continue;
                //update max
                if(i-start>max)
                    max= i-start;
                //update new start
                start = temp+1;
            }
        }
        if(s.size()-start>max)
            max=s.size()-start;
        return max;
    }
};
