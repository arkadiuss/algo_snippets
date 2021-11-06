#include<iostream>

int main() {
    __int128 t = 12345678901012;
    __int128 t2 = 12345678901012;
    __int128 t3 = 1234567890;
    std::cout<<(long long) (t*t2/(t3*t3));
}