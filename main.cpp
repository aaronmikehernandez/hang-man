/*
//  main.cpp
 
  Hangman
  Create a group of words. Pick a randow word from the group as the secret word.
  While player hasn't made too many incorrect guesses and hasn't guessed the secret word,
      Tell the player how many guesses are left
       Show player the letters he/she guessed
       Show player how much of secret word he/she has guessed
       Get player's next guess
   While player has entered a letter that he/she has already guessed
        Get player's guess
        Add the new guess to the group of letters
     If the guess is secret word
       Tell player the word is correct
        update the word guessed so far with the new letters
    Otherwise, 
        Tell the player that the guess is incorrect
        Increment the number of incorrect guesses made
    If the player has too many incorrect guesses
        Tell the player that he/she has been hanged
    Otherwise
        Congratulate the player on guessing the secret word
 
//  Created by Aaron H. on 1/15/17.
//  Copyright © 2017 Aaron H. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype> 
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int myRandom(int number) {
    return rand()%number;
}

int main(int argc, const char * argv[]) {
    const int MAX_TRIES = 8;        // max tries for the player

    // words to guess
    vector<string> words;
    words.push_back("CALCULUS");
    words.push_back("CARIBOU");
    words.push_back("BLENDER");
    words.push_back("COFFEE");
    words.push_back("EINSTEIN");
    
    srand(static_cast <unsigned int> (time(0)));            // seed the number generator

    random_shuffle(words.begin(), words.end(), myRandom);  // randomly shuffle words
    
    
    const string THE_WORD = words[0];
    int wrong = 0;
    string soFar(THE_WORD.size(), '-');
    string used = "";
    
    cout << "Welcome to Hangman. Good Luck!" << endl;
    
    while ((wrong < MAX_TRIES) && (soFar != THE_WORD)) {
        cout << "\n\nYou have " << (MAX_TRIES-wrong);
        cout << " incorrect guesses left. \n";
        cout << "\nYou've used the following letters: \n" << used << endl;
        cout << "\nSo far, the word is: \n" << soFar << endl;
        
        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        
        guess = toupper(guess);
        while(used.find(guess) != string::npos) {
            cout << "\nYou've already used the letter, " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }
        
        used += guess;
        
        if(THE_WORD.find(guess) != string::npos) {
            cout << "That's right! " << guess << " is in the word.\n";
            
            for(int i=0; i<THE_WORD.size(); i++) {
                if(THE_WORD[i] == guess) {
                    soFar[i] = guess;
                }
            }
        } else {
            cout << "Sorry, " << guess << " isn't in the word." << endl;
            wrong++;
    }
        
    }
    
    //shut down
    if(wrong == MAX_TRIES) {
        cout << "\nYou've been hanged!" << endl;
    } else {
        cout << "\nYou've guessed it!" << endl;
    }
    
    cout << "\nThe word was " << THE_WORD << endl;
    return 0;
}
