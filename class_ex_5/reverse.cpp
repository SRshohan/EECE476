#include <iostream>

using namespace std;

// •Design a recursive algorithm in pseudo-code to print a 
// given array with n elements in reverse order. For example, 
// if the input is [3, 5, 1, 7, 9], then the output is 9, 7, 1, 5, 3.

void reverse(int nums[], int siz){
    if (siz == 0){
        return;
    }

    reverse(nums, siz - 1);
};

int main(){


}
    


