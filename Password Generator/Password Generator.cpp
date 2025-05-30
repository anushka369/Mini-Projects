#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Global strings to be used to randomly generate password components
string string_char = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string string_num = "0123456789";
string string_special = "~!@#$%^&*()";

// Function to convert the string to lowercase
string toLower(string input)
{
    for (char& c : input) 
    {
        c = tolower(c); // Convert each character to lowercase
    }
  
    return input;
}

// Function to get user input
void userInput(int &length, bool &use_special_chars, bool &use_numbers) 
{
    cout << "Enter the length of the password: ";
    cin >> length;

    string special_char_input;
    cout << "Include special characters? (yes/no): ";
    cin >> special_char_input;
    use_special_chars = (toLower(special_char_input) == "yes");

    string numbers_input;
    cout << "Include numbers? (yes/no): ";
    cin >> numbers_input;
    use_numbers = (toLower(numbers_input) == "yes");
}

// Function to generate the password
string generate_password(int length, bool use_special_chars, bool use_numbers) 
{
    // Ensure password length is valid
    if (length < 3) 
    {
        throw invalid_argument("Password length must be at least 3.");
    }

    string password;
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    // Step 1: First character must be an alphabet
    password += string_char[rand() % string_char.length()];

    // Step 2: Generate the remaining characters (length - 2)
    for (int i = 1; i < length - 2; ++i) 
    {
        password += string_char[rand() % string_char.length()];
    }

    // Step 3: Add a number or alphabet based on 'use_numbers'
    if (use_numbers) 
    {
        password += string_num[rand() % string_num.length()];
    }
    
    else 
    {
        password += string_char[rand() % string_char.length()];
    }

    // Step 4: Add a special character or alphabet based on 'use_special_chars'
    if (use_special_chars) 
    {
        password += string_special[rand() % string_special.length()];
    } 
    
    else 
    {
        password += string_char[rand() % string_char.length()];
    }

    return password;
}

// Driver code
int main() 
{
    int length;
    bool use_special_chars;
    bool use_numbers;

    // Get user input
    userInput(length, use_special_chars, use_numbers);

    try 
    {
        // Generate password
        string generated_password = generate_password(length, use_special_chars, use_numbers);

        // Output the generated password
        cout << "\nGenerated Password: " << generated_password << endl;
    } 
    
    catch (const exception& e) 
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
