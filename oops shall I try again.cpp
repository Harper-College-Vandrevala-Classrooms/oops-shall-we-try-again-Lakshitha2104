#include <iostream>
#include <limits>

int getvalidinput(int lowerBound = std::numeric_limits<int>::min(),
                  int upperBound = std::numeric_limits<int>::max(),
                  const std::string& prompt = "Enter a value: ",
                  const std::string& errorMsg = "Invalid input. Please try again.") {
    
    int input;

    while (true) {
        std::cout << prompt;
        std::cin >> input;

        if (std::cin.fail() || input < lowerBound || input > upperBound) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << errorMsg << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            return input;
        }
    }
}

int main() {
    int number = getvalidinput(1, 10, "Enter a number between 1 and 10: ", "Invalid number, try again.");
    std::cout << "You entered: " << number << std::endl;

    int age = getvalidinput(0, 120, "Enter your age: ", "Invalid age, please enter a valid number.");
    std::cout << "You entered: " << age << std::endl;

    int anyValue = getvalidinput(); 
    std::cout << "You entered: " << anyValue << std::endl;

    return 0;
}