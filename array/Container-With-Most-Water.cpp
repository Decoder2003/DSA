// https://leetcode.com/problems/container-with-most-water/

/*
The below code is not is not optimised, its taking tush much time to execute

#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> height){
    int n = height.size();
    int max = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            
            if(height[i]>height[j] || height[i]==height[j]){
                if( (height[j]*(j-i))>max){
                    max = height[j]*(j-i);
                    cout << "height[j]*(j-i) : " << height[j] << "*" << (j-i) << endl;
                    cout << "max : " << max << endl;
                }
            }

            else{
                if( (height[i]*(j-i))>max){
                    max = height[i]*(j-i);
                    cout << "height[i]*(j-i) : " << height[i] << "*" << (j-i) << endl;
                    cout << "max : " << max << endl;
                }
            }

        }
    }
    return max;
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "ANS : " << maxArea(height);
    return 0;
}
*/

#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> height){
    int low = 0;
    int high = height.size()-1;
    int max = 0;

    while(low<high){
        cout << "[" << low << "," << high << "]" << endl;
        if(height[low]>height[high] || height[low]==height[high] ){
            if( (height[high]*(high-low))>max ){
                max = height[high]*(high-low);
                cout << "height[high]*(high-low) : " << height[high] << "*" << (high-low) << endl;
                cout << "max : " << max << endl;
            }
            high--;
        }
        else{
            if( (height[low]*(high-low))>max ){
                max = height[low]*(high-low);
                cout << "height[low]*(high-low) : " << height[low] << "*" << (high-low) << endl;
                cout << "max : " << max << endl;
            }
            low++;
        }
    }

    return max;
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "ANS : " << maxArea(height);
    return 0;
}