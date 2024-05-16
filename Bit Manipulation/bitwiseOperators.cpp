#include<bits/stdc++.h>
using namespace std;

int main() {
    int a = 2;
    int b = 3;

    // Bitwise operators operats on bit levels of decimal digits
    // an integer data is of 4 bytes i.e. 32 bits. Hence, every operations happen will affect all 32 bits.

    // a&b -> 10 & 11 = 10
    cout << (a&b) << endl;

    // a^b -> 10 ^ 11 = 01
    cout << (a^b) << endl;

    // a|b -> 10 | 11 = 11
    cout << (a|b) << endl;

    // ~a -> every 32 bits will be affected. 
    // step 1: all 0s will become 1 and vice versa
    // step 2: to print the number we need to find 2's compliment of the number
    // 2a: find 1's compliment by inverting all 0s and 1s
    // 2b: add 1 to the inverted number
    cout << (~a) << endl;

    // padding: the replacement bit after performing left shift or right shift operations
    // In case of positive numbers, padding always happens with 0.
    // In negative numbers, padding depends on the compiler

    // left shift operator
    // it multiplies by 2 to the given number if the number is small
    // as if the number is greater, it will have leading 1s and that will cause us to give negative numbers

    // In left shift, zeroes will keep adding at last
    // following expression says to right shift 3 for 2 times
    // If we see the last few bits of 3, it will be 0011
    // after shifting it towards left for 2 times, it will become 1100
    cout << (3 << 2) << endl; // 3 * 2 = 6, 6 * 2 = "12"

    // right shift operator
    // it divides any number by 2

    cout << (3 >> 2) << endl; // 3 / 2 = 1, 1 / 2 = 0

    return 0;
}