#include <iostream>
#include <typeinfo>

using namespace std;

int* passingargument(int *ptr){
    *ptr = 1000;
    return ptr;
}
int main(){
    int a = 10;

    cout << passingargument(&a) << endl;

    cout << a;

 
}