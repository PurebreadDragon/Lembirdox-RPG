#ifndef __INPUT_READER__
#define __INPUT_READER__

#include <iostream>
#include <istream>
#include <string>
#include <vector>

const std::string INVALID_MSG = "Invalid input, please try again.\n";
const std::string INVALID_MSG_NUMBER = "Invalid input, please enter a valid number.\n";

class InputReader{
private:
    std::string message;
public:
    InputReader() { message = INVALID_MSG; }
    InputReader(std::string custom) { message = custom; }

    /**
     * readInput: Reads user input, checks if it's valid and outputs their selection as an integer. If invalid, it re-prompts the user.
     * args: int choices[] (an array containing the valid choices, ordered numerically)
     * outputs: the user's selection
     * */
    int readInput(int choices[], int numChoices){
        std::string input;
        bool valid = false;

        while (!valid){
            std::cin >> input;
            
            if (isNumber(input)) {
                for (int i = 0; i < numChoices; ++i){
                    if (std::stoi(input.substr(0, 4)) == choices[i]){ // input should never be more than 1 character. concatenate if too long
                        valid = true;
                        break;
                    }
                }
            }

            if (!valid) std::cout << INVALID_MSG_NUMBER;
        }

        return std::stoi(input);
    }

    /**
     * This is a version of the above readInput that takes in a vector instead.
     * */
    std::string readInput(std::vector<std::string> choices){
        std::string input;
        bool valid = false;

        while (!valid){
            std::cin >> input;
            
            for (const auto& choice : choices){
                if (choice == input) valid = true;
            }

            if (!valid) std::cout << message;
        }

        return input;
    }

    /**
     * readInputCancel: The difference between this and the above options is 
     * that it allows the user to enter a 0 to cancel their selection as well. 
     * args: int choices[] (an array containing the valid choices, ordered numerically), numChoices (the total number of choices)
     * outputs: the user's selection
     * */
    int readInputCancel(int choices[], int numChoices){
        std::string input;
        bool valid = false;

        while (!valid){
            std::cin >> input;
            
            if (isNumber(input)) {
                for (int i = 0; i < numChoices; ++i){
                    if (std::stoi(input) == choices[i] || std::stoi(input) == 0){
                        valid = true;
                        break;
                    }
                }
            }

            if (!valid) std::cout << INVALID_MSG_NUMBER;
        }

        return std::stoi(input);
    }    

    /**
     * isNumber: Checks if a given input string is a valid integer or not. 
     * Does not accept doubles/decimals
     * args: input (the string to check)
     * outputs: true if number, false if not
     * */
    bool isNumber(std::string input){
        for (int i = 0; i < input.length(); i++){
            if (isdigit(input[i]) == false) return false;
        }

        return true;
    }
};

#endif
