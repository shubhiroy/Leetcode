class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> bracketlist;
        getParenthesis(n, n, "", bracketlist);
        return bracketlist;
    }

    void getParenthesis(int O, int C, string bracket, vector<string> &bracketslist)
    {
        if (O == 0 && C == 0)
        {
            bracketslist.push_back(bracket);
            return;
        }
        // if (O == C)
        // {
        //     getParenthesis(O - 1, C, bracket + '(', bracketslist);
        //     return;
        // }
        // if (O == 0)
        // {
        //     getParenthesis(O, C - 1, bracket + ')', bracketslist);
        //     return;
        // }
        // getParenthesis(O - 1, C, bracket + '(', bracketslist);
        // getParenthesis(O, C - 1, bracket + ')', bracketslist);
        if (O > 0)
        {
            getParenthesis(O - 1, C, bracket + '(', bracketslist);
        }
        if (C > 0 && C > O)
        {
            getParenthesis(O, C - 1, bracket + ')', bracketslist);
        }
    }
};