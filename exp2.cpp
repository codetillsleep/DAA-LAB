
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int linear_search(vector<int>& arr, int& key){
    int index =0;
    for(int i : arr){
        if(i==key){ return index;
        }
        index++;
    }
    return -1;
}


int bs(vector<int>& arr, int& key){
    int n = arr.size();
    int low=0;
    int high = n;
    for(int i=0;i<n;i++){
        int mid = floor((low + high) / 2.0);
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]>key){
            high=mid-1;
        }else if(arr[mid]<key){
            low=mid+1;
        }
    } return -1;
}

int main()
{
    vector<int> arr = {3,4,52,42,5,53};
    int key;
    cout << "enter the key: ";
    cin>>key;
    linear_search(arr,key);
    cout << "linear search result is " << linear_search(arr, key)<<"\n";
    cout << "Binary search result is " <<bs(arr, key);
    

    return 0;
}
