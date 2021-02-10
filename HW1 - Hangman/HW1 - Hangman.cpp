// HW1 - Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstring>
void showGallows(int guessLimit);
void showSolved(char word[], char guesses[]);
void updateLetters(char word[], char guesses[]);

int guesses = 7; // Total guesses
char guess; // The char that takes in the user input

char totalGuesses[100]; // Array to hold total guesses
int totalCount = 0; // Used to add to total guesses 

char wordToGuess[100] = "scientist"; // Word to be guessed

char correctLetters[100] = "_________"; // Correctly guessed letters

char incorrectLetters[100]; // Incorrectly guessed letters
int incorrectCount = 0; // Used to add to incorrect letters

// Main
int main()
{
    while (guesses >= 0) {
        // If the user runs out of guesses, game over
        if (guesses == 0) {
            std::cout << "Game Over" << std::endl;
            showGallows(0);
            break;
        }
        
        // Display text to welcome the user
        std::cout << "Let's play Hangman!" << std::endl;
        std::cout << "Your word has " << strlen(wordToGuess) << " letters in it." << std::endl;
        std::cout << "" << std::endl;

        // Displays gallows, incorrect guesses, and the word to solve
        showGallows(guesses);
        std::cout << "Wrong Guesses: " << incorrectLetters << std::endl;
        std::cout << "Word to solve: ";
        showSolved(wordToGuess, totalGuesses);
        std::cout << "" << std::endl;

        if (strcmp(wordToGuess, correctLetters) == 0) {
            std::cout << "You Win!" << std::endl;
            break;
        }

        // Prompts for user input
        std::cout << "What letter do you guess next? ";
        std::cin >> guess;
        std::cout << "Guess: " << guess << std::endl;

        // If a letter is guessed correctly
        if (strchr(wordToGuess, guess) && strchr(totalGuesses, guess) == 0) {
            totalGuesses[totalCount] = guess;
            totalCount++;
            std::cout << "Nice guess!" << std::endl;
            std::cout << "" << std::endl;
        }

        // If a letter has already been guessed
        else if (strchr(totalGuesses, guess)) {
            std::cout << "You've already guessed that!" << std::endl;
            std::cout << "" << std::endl;
        }

        // If the user guesses wrong
        else {
            totalGuesses[totalCount] = guess;
            incorrectLetters[incorrectCount] = guess;
            totalCount++;
            incorrectCount++;
            std::cout << "That's Incorrect" << std::endl;
            std::cout << "" << std::endl;
            guesses--;
        }

        // Update correct letters
        updateLetters(wordToGuess, totalGuesses);
    }
}
// Displays gallows with each wrong guess showing another body part of the hangman
void showGallows(int guessLimit) {
    switch (guessLimit) {
    case 7: {
        std::cout << "----------------" << std::endl;
        std::cout << "|               " << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        break;
    }
    case 6: {
        std::cout << "----------------" << std::endl;
        std::cout << "|       |       " << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        break;
    }
    case 5: {
        std::cout << "----------------" << std::endl;
        std::cout << "|       |       " << std::endl;
        std::cout << "|       O       " << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        break;
    }
    case 4: {
        std::cout << "----------------" << std::endl;
        std::cout << "|       |       " << std::endl;
        std::cout << "|       O       " << std::endl;
        std::cout << "|       |       " << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        break;
    }
    case 3: {
        std::cout << "----------------" << std::endl;
        std::cout << "|       |       " << std::endl;
        std::cout << "|       O       " << std::endl;
        std::cout << "|      /|       " << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        break;
    }
    case 2: {
        std::cout << "----------------" << std::endl;
        std::cout << "|       |       " << std::endl;
        std::cout << "|       O       " << std::endl;
        std::cout << "|      /|-      " << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        break;
    }
    case 1: {
        std::cout << "----------------" << std::endl;
        std::cout << "|       |       " << std::endl;
        std::cout << "|       O       " << std::endl;
        std::cout << "|      /|-      " << std::endl;
        std::cout << "|      /        " << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        break;
    }
    case 0: {
        std::cout << "----------------" << std::endl;
        std::cout << "|       |       " << std::endl;
        std::cout << "|       O       " << std::endl;
        std::cout << "|      /|-      " << std::endl;
        std::cout << "|      / -     " << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        break;
    }
    default: {
        std::cout << "There's been an error!" << std::endl;
    }
    }
}

// Shows correctly guessed letters so far in order
void showSolved(char word[], char guesses[]) {
    updateLetters(wordToGuess, totalGuesses);
    
    for (int letter = 0; letter < strlen(word);letter++) {
        std::cout << correctLetters[letter];
    }

    std::cout << "\n";
}

// Function to update correct letters
void updateLetters(char word[], char guesses[]) {
    for (int i = 0; i < strlen(guesses); i++) {
        for (int x = 0; x < strlen(word); x++) {
            if (guesses[i] == word[x]) {
                correctLetters[x] = guesses[i];
            }
        }
    }
}



