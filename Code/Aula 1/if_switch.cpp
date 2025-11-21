#include <iostream>

int main(int argc, char const *argv[])
{
    
    
    int x = 10;
    int y = 20;

    char h = (x > y) ? 'a' : 'b';

    // if (12){
    //     printf("if\n");
    // } 
    // if (true) {
    //     printf("primeiro else if\n");
    // }

    // if (false) {
    //     printf("segundo else if\n");
    // }
    // else {
    //     printf("else\n");
    // }


    // if(true){
    //     if(false){
    //         std::cout << "Partially true" << std::endl;
    //     }
    // } else{
    //     std::cout << "Completely false" << std::endl;
    // }


    char valor = 'a';
    switch (valor) {
    case 'b':
        std::cout << "Case 1" << std::endl;
        break;
    case 'c':
        std::cout << "Case 2" << std::endl; 
        break;
    default:
        std::cout << "Default case" << std::endl;
    }

    return 0;
}
