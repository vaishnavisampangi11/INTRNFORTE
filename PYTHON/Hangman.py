import random

def choose_word():
    words = ["apple", "banana", "grape", "orange", "mango"]
    return random.choice(words)

def display(word, guessed_letters):
    return " ".join(letter if letter in guessed_letters else "_" for letter in word)

def hangman():
    word = choose_word()
    attempts = len(word) + 2
    guessed_letters = set()
    
    print("Welcome to Hangman!")
    
    while attempts > 0:
        print(display(word, guessed_letters))
        guess = input("Guess a letter: ").lower()
        
        if guess in guessed_letters:
            print("You already guessed that letter!")
            continue
        
        guessed_letters.add(guess)
        
        if guess not in word:
            attempts -= 1
            print(f"Wrong guess! Attempts left: {attempts}")
        
        if all(letter in guessed_letters for letter in word):
            print(f"Congratulations! You guessed the word: {word}")
            return
    
    print(f"Game over! The word was: {word}")

hangman()