滑动窗口题模板
```
slidwindow(string s, string t) { 
    unordered_map<char, int> needs, windows; 
    for(char c : t) needs[c]++;
    //记录每个目标字母的个数 
    int left = 0, right = 0, valid = 0;
    //valid表示窗口内数量已经满足的字母的个数 
    while(right < s.size()) { 
        char ch = s[right];
        //增加到窗口里的字母 
        right++; 
        ...
        //修改窗口 while(...)
        //当达到收缩条件 { 
            char ch = s[left];
            //移出窗口的字母 
            left++; 
            ...
            //修改窗口 
            ...
            //得到结果 
        } 
    } 
} 
```