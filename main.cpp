#include "DLL.h"

int main(){
    int x[] = {1,2,3,4,5,6};
    DLL list(x, sizeof(x));
    cout<<list;
}