#include <iostream>
#include <vector>
using namespace std;
int buff[256];
void murge(vector<int>& data, int left, int mid, int right){
    int i = left, j = mid+1, k = left;
    while(i <= mid && j <= right){
        if(data[i] <= data[j]){
            buff[k++] = data[i++];
        }else{
            buff[k++] = data[j++];
        }
    }
    while(i <= mid){
        buff[k++] = data[i++];
    }
    while(j <= right){
        buff[k++] = data[j++];
    }
    for(int x = left; x <= right; x++){
        data[x] = buff[x];
    }
}
void murge_sort(vector<int>& data, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        murge_sort(data, left, mid);
        murge_sort(data, mid+1, right);
        murge(data, left, mid, right);
    }
}
int main(){
    vector<int> v1 {5,4,7,3,6,1,8,2};
    murge_sort(v1, 0, 7);
    for(int i : v1){
        cout << i << ", ";
    }
}