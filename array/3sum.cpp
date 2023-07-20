// https://leetcode.com/problems/3sum/

/*
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums){
    int n = nums.size();
    int index = 0;
    vector<vector<int>> result;

    //sort
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(nums[i]>nums[j]){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if( (nums[i]+nums[j]+nums[k])==0 ){
                    result.push_back({nums[i],nums[j],nums[k]});
                    index++;
                }
            }
        }
    }
    return result;
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    // vector<int> nums = {0,0,0};
    // vector<int> nums = {0,1,1};
    vector<vector<int>> results;
    results = threeSum(nums);
    for (int i = 0; i < results.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << results[i][j] << " ";
        }    
        cout << endl;
    }

    return 0;
}
*/

//The above code  is not efficient and not giving distinct triplets

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums){
    int n = nums.size();
    vector<vector<int>> result;

    //sort
    sort(nums.begin(),nums.end());

    //Two pointer technique
    for(int i=0; i<n; i++){
        int low = i+1; 
        int high = n-1;
        while (low<high){
            if(nums[i]==0 && nums[low]==0 && nums[high]==0){
                result.push_back({nums[i],nums[low],nums[high]});
                high--;
            }
            else if( (nums[i]+nums[low]+nums[high])==0){
                result.push_back({nums[i],nums[low],nums[high]});
                high--;
            }
            else if(nums[i]<(nums[low]+nums[high])){
                low++;
            }
            else{
                high--;
            }
        }
    }

    return result;
}

int main(){
    // vector<int> nums = {-1,0,1,2,-1,-4};
    vector<int> nums = {0,0,0,0};
    // vector<int> nums = {0,1,1};
    vector<vector<int>> results;
    results = threeSum(nums);
    for (int i = 0; i < results.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << results[i][j] << " ";
        }    
        cout << endl;
    }

    return 0;
}