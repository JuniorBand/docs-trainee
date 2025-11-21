#include <iostream>

//Function declaration

int function(char a, int b, double c);

int function2(int a){ return function('a', a, a);}

void testingFunctions();

int main(int argc, char const *argv[])
{
    //char a = function2(a);
    //printf("acsisahif %c", a);
    function('a', 12, 'b');
    testingFunctions();

    return 0;
}


int function(char a, int b, double c){
    int x = b * 2;
    printf("HEY\n %d", x);
    return 0;
}

void testingFunctions(){
    char buffer[10];
    int idade;
    std::cin >> idade;
    std::cout << sizeof(buffer) << std::endl;
    sprintf(buffer, "Eu tenho %d anos", idade);
    std::cout << buffer << std::endl;
    std::cout << sizeof(buffer) << std::endl;

    snprintf(buffer, sizeof(buffer), "Eu tenho %d anos", idade);
    std::cout << buffer << std::endl;
    std::cout << sizeof(buffer) << std::endl;

}


