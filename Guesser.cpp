#include "Guesser.h"
#include <string>

using std::string;

/*
  Returns an whole number representing the distance between the guess,
  provided as an argument, and the secret. The distance represents the number
  of characters that would have to be changed at the same location to match
  the other string. When the two strings are identical, the distance is 0,
  but for each letter different, the distance increases by 1. When the
  strings are different lengths, each of the extra characters in the longer
  string also counts as an increase in 1 to the distance, up to the length of
  the secret; in other words, if m_secret has a 10 characters and the guess
  has 100, the distance is 10.
*/
unsigned int Guesser::distance(string guess){
  //start with a distance of 0
  int dist = 0;
  //if guesser's length is smaller than the secret's length
  if(guess.size() < m_secret.size()){
    //get the extra length
    int extraCharacters = m_secret.size() - guess.size();
    //see how many characters match
    for(int i=0; i<guess.size(); i++){
      if(guess[i] != m_secret[i]){
        dist++;
      }
    }
    //add the extra length to the dist variable
    dist = dist + extraCharacters;
  //if the secret's size is less than the guess's size
  } else if (m_secret.size() < guess.size()){
    //find out the sie difference
    int extraCharacters = guess.size() - m_secret.size();
    //check for matching characters
    for(int i=0; i<m_secret.size(); i++){
      if(m_secret[i] != guess[i]){
        dist++;
      }
    }
    //add the extra length to dist
    dist = dist + extraCharacters;
  //they are the same size
  } else {
    //check for matching characters
    for(int i=0; i<m_secret.size(); i++){
      if(m_secret[i] != guess[i]){
        dist++;
      }
    }
  }

  //if the distance variable is larger than secret's length
  if(dist > m_secret.size()){
    //return the length of secret
    return m_secret.size();
  //the distance is less than secret's length
  } else {
    //return the distance variable;
    return dist;
  }

  return dist;
}

/*
  Constructor requires that the secret phrase is provided its value as
  an argument. This secret will not change for the lifespan of an instance
  of any Guesser object and must have a length of 32 characters or less,
  otherwise, it will be truncated at that length.
*/
Guesser::Guesser(string secret){
  //if the secret input is 32 characters or less
  if(secret.size() <= 32){
    m_secret = secret;
  //secret input greater than 32 characters
  } else {
    //only want the first 32 characters of secret input
    string secret_section;

    for(int i=0; i<32; i++){
      secret_section[i] = secret[i];
    }
    m_secret = secret_section;
  }

  //guesser starts with 3 guesses
  m_remaining = 3;

  //secret starts not locked
  locked = false;

}

/*
  Determines and returns whether the provided guess matches the secret
  phrase. However, the function also returns false if the secret is locked,
  which happens if either (or both): 
    (A) there are no remaining guesses allowed
    (B) the function detects brute force, as indicated by a guess that has a
        distance greater than 2 from the secret
  See the remaining() and distance() functions for specifications regarding
  determining how many guesses are remaining and the distance between a guess
  and the secret.
*/
bool Guesser::match(string guess){
  //function detects brute force and locks the secret
  if(distance(guess) > 2){
    m_remaining--;
    locked = true;
    return false;
  }

  //if they have no guesses remaining then the secret is locked
  if(m_remaining == 0){
    locked = true;
    return false;
  // if the guess if the same as m_secret return true and reset remaining guesses
  } else if (locked == true){
    if(distance(guess)==0){
      m_remaining = 3;
    } else {
      m_remaining--;
    }
    return false;
  } else if(distance(guess) == 0){
    m_remaining = 3;
    return true;
  // the secret doesn't match the guess remove 1 from remaining chances and return false
  } else {
    m_remaining--;
    return false;
  }

  return false;
}

/*
  Returns the number of guesses remaining. A Guesser object allows up to
  three (3) consecutive guesses without a match. If three guesses are made
  without any being a true match, the secret is locked. However, whenever
  an unlocked secret is guessed with a true match, the guesses remaining
  reset to three (3).
*/
unsigned int Guesser::remaining(){
  //returns how many remaining guesses the person has
  return m_remaining;
}

