class Solution {
public:
    int myAtoi(string s) {
        bool startingWhite = true, numReadDone = false, signReadDone = false;
        int sign = 1;
        int resultNum = 0;
        for(int i=0;i<s.size();){
            if(s[i]==' ' && startingWhite){
                while(i<s.size() && s[i]==' '){
                    i++;
                }
                startingWhite=false;
            }else if((s[i]=='-'|| s[i]=='+') && !signReadDone){
                sign = s[i]=='-'? -1 : 1;
                signReadDone = true;
                i++;
            }else if(s[i]>='0' && s[i]<='9' && !numReadDone){
                startingWhite=false;
                signReadDone = true;
                while(i<s.size() && s[i]>='0' && s[i]<='9'){
                    // cout<<"result num = "<<resultNum<<" s[i] = "<<s[i]<<endl;
                    resultNum = numGenerator(resultNum, s[i], sign);
                    // cout<<"result num = "<<resultNum<<endl;
                    i++;
                }
                numReadDone = true;
                break;
            }else{
                break;
            }
        }
        
        return resultNum;
        // return capping(sign*resultNum);
    }
    int numGenerator(long existingNum, char newInt, int sign){
        // cout<<"Here cast = "<<newInt<<" to "<<(int)newInt-'0'<<" Existing num = "<<existingNum<<endl;
        // cout<<"Capping = "<<capping(existingNum*10 + (newInt-'0'))<<endl;
        return capping(existingNum*10 + (sign *(newInt-'0')));
    }
    int capping(long long value){
        const int lowerBound = std::numeric_limits<int>::min();
        const int upperBound = std::numeric_limits<int>::max();
        // const int upperBound = 2147483648;
        if (value < lowerBound) {
            cout<<"value = "<<value<<" lower = "<<lowerBound<<endl;
            return lowerBound;
        } else if (value > upperBound) {
            cout<<"value = "<<value<<" upper = "<<upperBound<<endl;
            return upperBound;
        } else {
            cout<<"value = "<<value<<" return value = "<<value<<endl;
            return value;
        }
    }
};