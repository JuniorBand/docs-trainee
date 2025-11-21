#include <iostream>

int main(int argc, char const *argv[])
{

    bool condition = false;

    // for (int i = 0; i < 20; i++) {
    //     if (i % 2 == 0) {
    //         continue;
    //     }
    //     std::cout << i << " ";
    // }

    // int i = 0;
    // for(i; i < 10; printf("Eu vou no final: %d\n", ++i)){
    //     std::cout << i << "\n";
    // }

    char j[] = {'a', 'b', 'c', 'd'};
    for(char z : j){
        std::cout << z << " ";
    }

    
    while(false){
        //statements
    }

    do {
        std::cout << "travou" << std::endl;
    } while (false);


    return 0;
}
