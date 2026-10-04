#include <iostream>
using namespace std;

int main(){
    int rows , cols ;

    cout << "Enter Number Of Rows : " << endl;
    cin >> rows ;
    cout << "Enter Number Of Cols : " << endl;
    cin >> cols ;

    int **style = new int*[rows];

    for(int i = 0 ; i < rows ; i++){
        style[i] = new int[cols];
    }

    for(int i = 0 ; i < rows ; i++){
        cout << "Row Number : " << i+1 << endl ;
        for(int j = 0 ; j < cols ; j++){
            cout << "Enter Elements In Col : " << j+1 << endl ;
            cin >> style[i][j];
        }
    }

    cout << endl;
    cout << "Matrix : " << endl;
    for(int i = 0 ; i < rows ; i++){
        cout << "|\t";
        for(int j = 0 ; j < cols ; j++){
            cout << style[i][j] << '\t';
        }
        cout << "|\n";
    }

    cout << endl;
    cout << "Row Sums : " << endl ;
    for(int i = 0 ; i < rows ; i++){
        int sum = 0 ;
        for(int j = 0 ; j < cols ; j++){
            sum += style[i][j];
        }
        cout << "Row " << i+1 << " Sum : " << sum << endl ;
    }

    cout << endl;
    cout << "Column Sums : " << endl ;
    for(int i = 0 ; i < rows ; i++){
        int sum = 0 ;
        for(int j = 0 ; j < cols ; j++){
            sum += style[j][i];
        }
        cout << "Col " << i+1 << " Sum : " << sum << endl ;
    }

    int **transpose = new int*[cols];
    for(int i = 0 ; i < cols; i++){
        transpose[i] = new int[rows];
    }

    for(int i = 0 ; i < cols ; i++){
        for(int j = 0 ; j < cols ; j++){
            transpose[i][j] = style[j][i];
        }
    }

    cout << endl;
    cout << "Transpose : " << endl ;
    for(int i = 0 ; i < cols ; i++){
        cout << "|\t";
        for(int j = 0 ; j < rows ; j++){
            cout << transpose[i][j] << '\t';
        }
        cout << "|\n";
    }
}