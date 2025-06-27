import random
import string

def generate_password(length, use_digits=True, use_special=True):
    # Define character sets
    characters = string.ascii_letters  # Includes uppercase and lowercase letters
    if use_digits:
        characters += string.digits  # Adds numbers
    if use_special:
        characters += string.punctuation  # Adds special characters

    # Ensure the password meets length requirements
    if length < 10:
        print("Password length must be at least 10 characters for security.")
        return None

    # Generate the password randomly
    password = ''.join(random.choice(characters) for _ in range(length))
    return password

# Get user input for password length
try:
    length = int(input("Enter password length (minimum 10): "))
    if length < 10:
        raise ValueError("Length should be at least 10.")

    # Get user preferences
    use_digits = input("Include numbers? (yes/no): ").strip().lower() == "yes"
    use_special = input("Include special characters? (yes/no): ").strip().lower() == "yes"

    # Generate and display the password
    password = generate_password(length, use_digits, use_special)
    if password:
        print("Generated Password:", password)

except ValueError as e:
    print("Invalid input:", e)
