#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));
    
    // Generate a random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have picked a number between 1 and 100. Try to guess it!" << std::endl;

    // Loop until the user guesses the correct number
    while (guess != secretNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        
        // Check if the input is a valid number
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 100." << std::endl;
            continue;
        }

        // Increment the attempt count
        attempts++;
        
        // Provide feedback to the user
        if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;
        }
    }

    return 0;
}
