// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int> nums1, vector<int> nums2){
    int n1 = nums1.size();
    int n2 = nums2.size();

    //Merging 
    vector<int> sortedNum;
    for(int i=0; i<n1; i++){
        sortedNum.push_back(nums1[i]);
    }
    for(int i=0; i<n2; i++){
        sortedNum.push_back(nums2[i]);
    }
        
    //sorting 
    for(int i=0; i<(n1+n2); i++){
        for(int j=i; j<(n1+n2); j++){
            if(sortedNum[i]>sortedNum[j]){
                int temp = sortedNum[i];
                sortedNum[i] = sortedNum[j];
                sortedNum[j] = temp;
            }
        }
    }
    
    //find median
    int mid = (n1+n2)/2;
    if( (n1+n2)%2==0 ){
        return (sortedNum[mid-1]+sortedNum[mid])/2.0;
    }
    else{
        return sortedNum[mid];
    }
}

int main(){
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2,4};

    cout << findMedianSortedArrays(nums1,nums2);    
    return 0;
}