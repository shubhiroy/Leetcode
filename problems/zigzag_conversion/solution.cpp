    class Solution
{
public:
    string convert(string s, int numRows)
    {
        int count = 0;
        // vector<vector<char>> zigzag;
        string zigzag;
        // for (int i = 0; i < numRows; i++)
        // {
        //     zigzag[i][0] = s[i];
        // }
        if (numRows == 1)
            return s;
        for (int i = 0; i < numRows; i++)
        {
            int j = i;
            bool down = false;
            while (j < s.size() && zigzag.size() < s.size())
            {
                zigzag += s[j];
                down = !down;
                if (i == 0)
                    down = true;
                if (i == numRows - 1)
                    down = false;
                if (down)
                {
                    j += 2 * (numRows - i - 1);
                }
                else
                {
                    j += 2 * i;
                }
            }
        }
        return zigzag;
    }
};