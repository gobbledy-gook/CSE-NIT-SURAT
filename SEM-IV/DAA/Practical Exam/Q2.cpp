#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector <int> sumSub(int start, int end, vector <int> arr){
    int sum =arr[start];
    for(int i = start; i<=end; i++){
        if(sum > (sum + arr[i+1])){
            sum += arr[i];
        }
        else{
            break;
        }
    }
    return {start, end, sum};
}

vector <int> mergeSum(int mid, vector <int> arr){
    int midSum = 0, i = mid, start, end;
    midSum = arr[mid];
    while(i < arr.size()){
        if(midSum < midSum + arr[i]){
            midSum += arr[i];
            i++;
        }
        else{
            break;
        }
    }
    // cout << "Mid RHS: " << i << endl;
    end = i;
    i = mid-1;
    while(i >=0){
        if(midSum < (midSum + arr[i])){
            midSum += arr[i];
            i--;
        }
        else{
            break;
        }
    }
    // cout << "Mid LHS: " << i << endl;
    start = i;
    return {start, end, midSum};
}

vector <int> maxSum(int start, int end, vector <int> arr){
    if(start >= end){
        return arr;
    }
    int mid = (start + end)/2;
    // vector <int> leftSum = maxSum(start, mid, arr);
    // vector <int> rightSum = maxSum(mid + 1, end, arr);
    vector <int> left = maxSum(start, mid, arr);
    vector <int> right = maxSum(mid+1, end, arr);
    vector <int> midarr = mergeSum(mid, arr);
    int lefti = left[0];
    int leftj = left[1];
    int leftsum = left[2];
    int righti = right[0];
    int rightj = right[1];
    int rightsum = right[2];
    int midi = midarr[0];
    int midj = midarr[1];
    int midsum = midarr[2];

    cout << leftsum << " " << rightsum << " " << midsum<< endl;
    if(leftsum > rightsum && leftsum > midsum){
        return {lefti, leftj, leftsum};
    }
    else if(rightsum > leftsum && rightsum > midsum){
        return {righti,rightj, rightsum};
    }
    else{
        return {midi, midj, midsum};
    }
}

int main(){
    vector <int> array = {1, -2, 3, -2, 4, 5, 0};
    vector <int> result;
    result = maxSum(0, 6, array);
    for(int i =0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}