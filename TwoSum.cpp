#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        unordered_map<int,int> map;
        
        for(int i=0;i<numbers.size();i++){
            unordered_map<int,int>::const_iterator got = map.find(target-numbers[i]);
            if(got==map.end())
                map.insert(pair<int,int>(numbers[i],i));
            else{
                result.push_back(got->second+1);
                result.push_back(i+1);
                break;
            }
            
        }
        return result;
    }
};
