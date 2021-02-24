#include <iostream>
#include <istream>
#include <string>

const std::string INVALID_MSG = "Invalid input, please try again.\n";

class InputReader{
public:
    InputReader(){}

    /**
     * readInput: Reads user input, checks if it's valid and outputs their selection as an integer. If invalid, it re-prompts the user.
     * args: int choices[] (an array containing the valid choices, ordered numerically)
     * outputs: the user's selection
     * */
    int readInput(int choices[]){
        std::string input;
        bool valid = false;

        while (!valid){
            std::cin >> input;
            
            if (!isNumber(input)) std::cout << INVALID_MSG;
            else{
                for (int i = 0; i < sizeof(choices); ++i){
                    if (std::stoi(input) == choices[i]) valid = true;
                }
            }

            if (!valid) std::cout << INVALID_MSG;
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