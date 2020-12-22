#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

const int MAXLEN=1000;

//#############################
//PREIMAGES OF FUNCTIONS
    void input(string& s);
    void solve(string s);
    void printpositions(int* arr, int len);
    void quickSort(int* arr, int left, int right);
    void printCharsOfString(string s);
    void mySwap(int& x, int& y);
//PREIMAGES OF FUNCTIONS
//#############################




//function to input the string
void input(string& s){
    cout << "Input please the string: " << endl;
    getline(cin, s, '\n');
}

//the "main" function
void solve(string s){
    //array for counting "how many times
    //was character i(ASCII) used"
    int cnt[256]={};

    //result array
    int positions[MAXLEN];//MAXLEN was declared in "mystring.h"
    int lenPos=0;//length of arr



    //feeling cnt[]
    int i=s.length();
    while(i --> 0){
        cnt[s[i]]++;
    }

    //getting characters, which
    //have been used only at ones
    for(int i=0; i<256; i++)
        if(cnt[i]==1){
            positions[lenPos++]=s.find(i)+1;
        }
    //output
    printCharsOfString(s);
    quickSort(positions, 0, lenPos-1);
    printpositions(positions, lenPos);
}

void printCharsOfString(string s){
    //printing charcters
    cout << "Infromation about the string: " << endl;
    for(int i=0; i<s.length(); i++)
        cout << setw(4) << s[i];
    cout << endl;
    //printing positions
    for(int i=0; i<s.length(); i++)
        cout << setw(4) << 1 + i;
    cout << endl;
    cout << "###############################" << endl;
}

void printpositions(int* arr, int len){
    if(len){
        cout << "This is array of positions: " << endl;
        for(int i=0; i<len; i++){
            cout << setw(4) << arr[i];
        }
        cout << endl;
    }
    else cout << "There are any such characters!" << endl;
}

//swapping 2 variables
void mySwap(int& x, int& y){
    x^=y^=x^=y;
}


//to sort the array
void quickSort(int* a, int left, int right){
    if(right-left>0){
        int i=left, j=right;
        int jstep=-1;
        bool direct=true;
        while(i!=j){
            if( (a[i]>a[j])==direct ){
                mySwap(a[i], a[j]);
                mySwap(i, j);
                jstep=-jstep;
                direct=!direct;
            }
            j+=jstep;
        }
        quickSort(a, left, i-1);
        quickSort(a, i+1, right);
    }
}
