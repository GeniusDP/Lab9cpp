/*
    This is a header of Lab_9_OP(Strings).
    Authour: B. Zaranik
    12/22/2020.
*/
#include <string>
using namespace std;

extern const int MAXLEN;

//function to input the string
void input(string&);

//makes all work
void solve(string s);

//printing array arr[], size(arr)==len
void printpositions(int* arr, int len);

//to sort the array
void quickSort(int* arr, int* right);

//output
void printCharsOfString(string s);
