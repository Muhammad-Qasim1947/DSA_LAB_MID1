#include <iostream>
using namespace std;

int main(){
    int size ;
    cout << "Enter Size Of Array : " << endl ;
    cin >> size ;

    int *arr = new int[size];

    cout << "Enter 5 elements :" << endl ;
    for(int i = 0 ; i < size ; i++){
        cin >> arr[i];
    }

    cout << "Array : " << endl ;
    for(int i = 0 ; i < size ; i++){
        cout << " " << arr[i];
    }

    int sum = 0 ;
    for(int i = 0 ; i < size ; i++){
        sum += arr[i];
    }
    cout << endl ;
    cout << "Sum = " << sum ;

    float average = float(sum)/size ;
    cout << " Average = " << average ;

    int max = arr[0];
    for(int i = 1 ; i < size ; i++){
        if(arr[i] > max){
            max = arr[i] ;
        }
    }
    cout << " Max = " << max ;

    int min = arr[0];
    for(int i = 1 ; i < size ; i++){
        if(arr[i] < min){
            min = arr[i] ;
        }
    }
    cout << " Min = " << min ;
}