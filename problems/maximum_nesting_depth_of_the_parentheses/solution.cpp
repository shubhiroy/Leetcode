class Solution {
public:
    int maxDepth(string s) {
        // stack<char> brackets;
        // int maxDepth = 0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='('){
        //         brackets.push(s[i]);
        //         if(brackets.size()>maxDepth){
        //             maxDepth=brackets.size();
        //         }
        //     }else if(s[i]==')'){
        //         brackets.pop();
        //     }
        // }
        // return maxDepth;

        int open=0, maxDepth=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open++;
                if(open>maxDepth){
                    maxDepth=open;
                }
            }else if(s[i]==')'){
                open--;
            }
        }
        return maxDepth;
    }
};