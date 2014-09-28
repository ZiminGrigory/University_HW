#include <iostream>

class Exception{};

class TestClassSecond{
public:
    TestClassSecond(){
        std::cout << "constructor TestClassSecond \n";
    }
    ~TestClassSecond(){
        std::cout << "destructor TestClassSecond \n";
    }
};


class TestClassFirst{
public:
    TestClassFirst(){
        std::cout << "constructor TestClassFirst \n";
        std::cout << "Generation of exception \n";
        throw Exception();
    }
    ~TestClassFirst(){
        std::cout << "destructor ClassFirst \n";
    }
private:
    TestClassSecond object;
};

