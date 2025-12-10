#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{

    // int x = abs(-3);
    // short y = 32767 + 1;
    // cout << sizeof(y) << endl;
    // cout << y << endl;


    // unsigned short z = 65535;
    // cout << sizeof(z) << endl;
    // cout << z << endl;

    // Bitwise Operators
    int a = 5; // 0101
    int b = 3; // 0011

    cout << "A = 5 (0101), B = 3 (0011)" << endl;
    cout << "--------------------------" << endl;

    // 1. AND (&): Retorna 1 se AMBOS forem 1
    // 0101 & 0011 = 0001 (1)
    cout << "AND (a & b): " << (a & b) << endl;

    // 2. OR (|): Retorna 1 se QUALQUER UM for 1
    // 0101 | 0011 = 0111 (7)
    cout << "OR  (a | b): " << (a | b) << endl;

    // 3. XOR (^): Retorna 1 se forem DIFERENTES
    // 0101 ^ 0011 = 0110 (6)
    cout << "XOR (a ^ b): " << (a ^ b) << endl;

    // 4. NOT (~): Inverte os bits (0 vira 1, 1 vira 0)
    // Em inteiros com sinal, inverte o valor e subtrai 1 (Complemento de 2)
    cout << "NOT (~a):    " << (~a) << endl;

    // 5. Left Shift (<<): Move bits para esquerda (Multiplica por 2 a cada casa)
    // 0101 << 1 = 1010 (10)
    cout << "SHL (a << 1): " << (a << 1) << endl;

    // 6. Right Shift (>>): Move bits para direita (Divide por 2 a cada casa)
    // 0101 >> 1 = 0010 (2)
    cout << "SHR (a >> 1): " << (a >> 1) << endl;
    
    if(10 > 5)
    if((10 > 5) || (3 != 4))
    // && || == != > < 

    //Ternário
    // int a = 10;
    // int b = 20;
    // int maior = (a > b) ? a : b;
    // cout << "O maior é: " << maior << endl;


    
    
    return 0;
}
