# Hangman-Game

#Task
Everyone  has  played  the  classic  word  guessing  game  hangman.  Your  job  is  to  create  a 
program that will allow a user to play the game. 


#Functionality 
The program will obtain a  random word from the list of 20 words within the text file
![Screenshot (33)](https://user-images.githubusercontent.com/68082619/169064759-f4aa05f8-86b1-43df-bddf-cd94d75eca28.png)

It will then show an output of the following which allows the user to play and guess the word that was randomly selected

![Screenshot (34)](https://user-images.githubusercontent.com/68082619/169064950-fa869650-d628-4c24-b098-9de44c1b712c.png)



 It  makes  calls  to  4  functions.  The 
requirements for each of these functions is also provided. Your job will be to write the code for these functions, 
as well as document/comment the entire program.
FUNCTIONS:
1. readPuzzles – two arguments: string array of words, integer wordCount (reference parameter)
 Returns nothing
 This function opens up the puzzles file, verifies it opens successfully, reads the puzzles from the file into 
the array of words, updates the wordCount to reflect how many puzzles were read.
2. displayPuzzle – two arguments: string word, array of bool guessed
 Returns nothing
 This function loops through each of the letters of the word, looking at the corresponding position of the 
guessed  array.  If  the  letter  has  been  guessed,  display  it.  If  not,  display  the  underscore.  Also,  display  a 
space between each letter, as well as a couple of end lines after the word. It might output something like 
this:
_ A S K _ _ B A _ _ 
3. found – three arguments: string word, array of bool guessed, character guess
 This functions returns a bool, true if letter guess is found in puzzle word, otherwise false
 If the guess  is in the word, the function should also change the guessed  array  to  true  at each position it 
exists
4. winner – two arguments: array of bool guessed, the integer number of letters in the puzzle
 This  function  will  loop  through  all  of  the  elements  of  the  guessed  array.  If  any  element  is  false,  the 
function should return false. If all of the elements are true, the function should return true
