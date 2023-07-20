#include <iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int newLen = 0;
    int low = 0;
    if(s.length()==0){
        return 0;
    }
    for(int i=0; i<s.length(); i++){
        // cout << "s[i] : " << s[i] << endl;
        int oldLen = 1;
        for(int j=i-1; j>=low; j--){
            // cout << "newLen : " << newLen << " | oldLen : " << oldLen << endl;
            if(s[i]==s[j]){
                low = j+1;
                // cout << "low : " << low << endl;
                newLen = max(newLen,oldLen); 
                break;
            }
            else{
                oldLen++;
            }
        }
        newLen = max(newLen,oldLen); 
    }
    return newLen;     
}

int main(){
    string s = "pwwkew";
    cout << lengthOfLongestSubstring(s);
    return 0;
}