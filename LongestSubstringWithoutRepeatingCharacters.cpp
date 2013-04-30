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
                map.insert(pair<char,int>(s[i],i));
            else{
                int temp = entry->second;
                map.erase(entry);
                map.insert(pair<char,int>(s[i],i));
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
