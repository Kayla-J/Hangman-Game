/**Kayla Jamar
Project 5
This program will function as the simple game of hangman. It should display the letter
once the user has guessed it otherwise it will continue to show the underscore.
once the user guess the word, it will tell the user they had won. if they had lossed
then the program will show the word.
Due:11/10/2020
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

//Change these ?? to a value
const int MAX_WORDS = 21;
const int MAX_WORD_SIZE =12;
const int MAX_GUESSES = 6;
const int NUM_LETTERS =129;

//FUNCTION DECLARATIONS -
/*name: readPuzzles
  INCOMING:  array of words and integer wordCount
  OUTGOING:  None
*/
void readPuzzles(string words[],int& wordCount);
//FUNCTION DECLARATIONS -
/*name: displayPuzzle
  INCOMING:  string word and bool guessed array
  OUTGOING:  None
*/
void displayPuzzle (string word, bool guessed[]);

//FUNCTION DECLARATIONS -
/*name: found
  INCOMING:  string word, bool guessed array and character guess
  OUTGOING:  bool guessed array
*/

bool found (string word,bool guessed[], char guess);
//FUNCTION DECLARATIONS -
/*name: winner
  INCOMING: bool guessed array and integer letters
  OUTGOING:  bool guessed array
*/
bool winner (bool guessed [], int letters);

int main()
{
  string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string words[MAX_WORDS];
  int wordNum=0, letters=0, misses=0, numWords=0;
  char guess;
  bool guessed[MAX_WORD_SIZE];

  readPuzzles(words, numWords);

    srand(time(0));
  wordNum=rand() % numWords;
  letters = words[wordNum].length();

  for (int i=0; i<letters; i++){
    guessed[i] = false;
  }

  do
  {
    displayPuzzle(words[wordNum], guessed);

    cout << "Available: " << alpha << endl;

    cout << "Guess: ";
    cin >> guess;
    guess = toupper(guess);

    for (int i=0; i<NUM_LETTERS; i++)
      if (alpha[i] == guess)
        alpha[i] = ' ';

    if (!(found(words[wordNum], guessed, guess)))
      misses++;

    cout << "Misses: " << misses << endl;
  } while (!winner(guessed,letters) && (misses < MAX_GUESSES));

  if (misses == MAX_GUESSES){
    cout << "You lose. The word was: " << words[wordNum] << endl;
  }
  else{
    cout << "You win. Nice job!" << endl;
  }

  return 0;
}


/**Returns nothing
This function opens up the puzzles file,
 verifies it opens successfully,
reads the puzzles from the file into the array of words,
updates the wordCount to reflect how many puzzles were read.**/
void readPuzzles(string words[],int& wordCount){
    ifstream puzzle;
    puzzle.open ("puzzles.txt");
    for (int i=0;i<MAX_WORDS;i++){

        puzzle>>words[i];

      wordCount++;

    }

}

/**	Returns nothing
•This function loops through each of the letters of the word, looking at the corresponding position of the guessed array.
If the letter has been guessed, display it.
If not, display the underscore.
Also, display a space between each letter, as well as a couple of end lines after the word.
It might output something like this:
_ A S K _ _ B A _ _ **/

void displayPuzzle (string word, bool guessed[]){
 cout<<word<<endl;
     for (int g=0;g<word.length();g++){

            if (guessed[g]==false){
                cout<<" "<<"_"<<" ";

              }
                else {
        cout<<" "<<word[g]<<" ";
                }


     }


     }


/**This functions returns a bool, true if letter guess is found in puzzle word, otherwise false
If the guess is in the word, the function should also change the guessed array to true at each position it exists**/

bool found (string word,bool guessed[], char guess){
    for (int i=0;i<word.length();i++){


        if (word[i]==guess){

            guessed[i]=true;

        return true;

        }

    }


        return false;



}

/**This function will loop through all of the elements of the guessed array.
If any element is false, the function should return false.
If all of the elements are true, the function should return true.**/
bool winner (bool guessed [], int letters){
    for (int g=0;g<letters;g++){
            if (guessed[g]==false){
                return false;
            }


            }

              return true;
    }







