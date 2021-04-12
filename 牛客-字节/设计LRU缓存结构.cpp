#include <unordered_map>
#include <iterator>
 
class Solution {
public:
 
    vector<int> LRU(vector<vector<int> >& operators, int k)
    {
        vector<int> result;
        if (operators.empty() || k <= 0) {
            return result;
        }
 
        cap = k;
 
        for (auto c : operators) {
            if (c[0] == 1) {
                set(c[1], c[2]);
            } else {
                int val = get(c[1]);
                result.push_back(val);
            }
        }
 
        return result;
    }
 
    int get(int key)
    {
        auto iter = smap.find(key);
        if (iter == smap.end()) {
            return -1;
        }
 
        auto val =iter->second->second;
        slist.push_front({key,val});
        slist.erase(iter->second);
        smap[key] = slist.begin();
 
        return val;
    }
 
    void set(int key, int val)
    {
        auto iter = smap.find(key);
        if (iter != smap.end()) {
            slist.erase(iter->second);
        }
 
        slist.push_front({key, val});
        smap[key] = slist.begin();
 
        if (slist.size() > cap) {
            smap.erase(slist.back().first);
            slist.pop_back();
        }
 
    }
    private:
    int cap;
    unordered_map<int, list<pair<int,int>>::iterator> smap;
    list<pair<int,int>> slist;
};