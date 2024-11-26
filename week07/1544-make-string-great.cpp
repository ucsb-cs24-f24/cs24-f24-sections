#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        
        if(s.size() <= 1){
            return s;
        }

        stack<char> l;

        for(int i = 0; i < s.size(); i++){
            if(l.empty()){
                l.push(s[i]);
            } else if(abs(l.top() - s[i]) == 32){
                l.pop();
            } else {
                l.push(s[i]);
            }
        }

        string ans = "";
        while(!l.empty()){
            ans = l.top() + ans;
            l.pop();
        }

        return ans;
        
    }
};