#include <iostream>
using namespace std ;

int* resizearray(int *oldarr , int oldsize , int newsize){
    if(newsize == oldsize){
        return oldarr ;
    }

    int *newArr = new int[newsize];

    int limit = (oldsize < newsize) ? oldsize : newsize ;
    for(int i = 0 ; i < limit ; i++){
        newArr[i] = oldarr[i];
    }

    delete[] oldarr ;
    return newArr ;
}

int main(){
    int size ;
    cout << "Enter Size For Array : " << endl ;
    cin >> size ;

    int *array = new int[size];

    for(int i = 0 ; i < size ; i++){
        cout << "Enter Element For Row " << i+1 << endl;
        cin >> array[i];
    }

    int choice ;
    do{
        cout << endl;
        cout << "Select An Option" << endl ;
        cout << "1. Grow Array" << endl ;
        cout << "2. Shrink Array" << endl ;
        cout << "3. Display Array" << endl ;
        cout << "4. Exit" << endl ;
        cout << "Enter Your Choice : " << endl ;
        cin >> choice ;
        switch(choice){
        case 1 :
            int newsize;
            cout << "Enter New Larger Size For Array : " << endl;
            cin >> newsize;

            array = resizearray(array , size , newsize);
            for(int i = size ; i < newsize ; i++){
                cout << "Enter New Element : " << i+1 << endl;
                cin >> array[i] ;
            }
            size = newsize ;
            break ;

        case 2 :
            int nayasize;
            cout << "Enter New Smaller Size For Array : " << endl;
            cin >> nayasize;

            array = resizearray(array , size , nayasize);

            size = nayasize ;
            break ;

        case 3 :
            cout << endl;
            cout << "Current Array Elements :" << endl;
            for(int i = 0 ; i < size ; i++){
                cout << array[i] << endl ;
            }
            cout << endl;
            break ;

        case 4 :
            break ;

        default :
            cout << "Invalid Choice" << endl;
        }
    } while (choice != 4);

    delete[] array;

    return 0;
}