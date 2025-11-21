#include <iostream>

#define PI 3.14f
using namespace std;

int main(int argc, char const *argv[]){


    int a = 5; // 4 bytes (-2E31 to 2E31-1)
    float c = 5.5f; // 4 bytes (1,2E-38 to 3,4E+38)
    double d = 10.99f; // 8 bytes (2,2E-308 to 1,8E+308)
    char e = 'a'; // 1 byte (-128 to 127)
    bool f = true; // 1 byte (true or false/1 or 0)
    
    short s = 32767; // 2 bytes (-32768 to 32767)
    long long b = 10L; // 8 bytes (-2^63 to 2^63-1)
    unsigned char g = 255; // 1 byte (0 to 255)
    signed short sh = 2*32768; // 2 bytes (-32768 to 32767)
    
    auto t = '2'; // tipo inferido pelo compilador
    auto string = "Hello";  // const char*

    // Constante/define
    const int constante = 3;
    cout << PI * 3 << endl;
    

    std::cout << "Hello, World!\n" << sh << std::endl;
    return 0; // boa pratica
}




   // printf("Hi");
    // for (int i = 0; i < 10; i++){
    //     printf("%d", i);
    // }

 

    // bool x = 1;

    // cout << (bool)(0.0f/2.0f) + x << "\n";

    // char a = 'A';
    // int y = a;

    // cout << y << "\n";

    // cout << y-- << "\n";

    // cout << y << "\n";
