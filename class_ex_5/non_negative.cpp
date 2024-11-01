// Write a recursive algorithm to output the binary representation for non-negative integers. e.g. input 10, Output: 1010

#include <iostream>

using namespace std;


void binary_conversion(int num, string& result){
    if (num == 0 && result.empty()){
        result = "0";
        return;
    }
    else if (num == 1)
    {
        result = "1";
        return;

    }
    else{
        binary_conversion(num/2, result);
        result += to_string(num%2);
    };
};


int main(){

    string result;
    int num = 10;
    binary_conversion(num, result);

    cout << result << endl;

    return 0;
}