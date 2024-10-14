#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
// Function to generate a random password based on user preferences
    string generate_password(int length, bool use_upper, bool use_lower, bool use_digits, bool use_special) {
    string character_pool = "";
    string password = "";
    
    // Add selected character sets to the pool
    if (use_upper) {
        character_pool += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    if (use_lower) {
        character_pool += "abcdefghijklmnopqrstuvwxyz";
    }
    if (use_digits) {
        character_pool += "0123456789";
    }
    if (use_special) {
        character_pool += "!@#$%^&*()-_=+[]{}|;:,.<>?/\\`~";
    }
    
    // Ensure at least one type of character is selected
    if (character_pool.empty()) {
        throw invalid_argument("At least one type of character must be selected!");
    }

    // Seed the random number generator
    std::srand(time(0));

    // Generate a random password
    for (int i = 0; i < length; i++) {
        password += character_pool[rand() % character_pool.length()];
    }

    return password;
}

int main() {
    int length;
    char use_upper_choice, use_lower_choice, use_digits_choice, use_special_choice;
    bool use_upper, use_lower, use_digits, use_special;

    try {
        // Get user input for password preferences
        cout << "Enter the desired password length: ";
        cin >> length;

        cout << "Include uppercase letters? (y/n): ";
        cin >> use_upper_choice;
        use_upper = (use_upper_choice == 'y' || use_upper_choice == 'Y');

        cout << "Include lowercase letters? (y/n): ";
        cin >> use_lower_choice;
        use_lower = (use_lower_choice == 'y' || use_lower_choice == 'Y');

        cout << "Include numbers? (y/n): ";
        cin >> use_digits_choice;
        use_digits = (use_digits_choice == 'y' || use_digits_choice == 'Y');

        cout << "Include special characters? (y/n): ";
        cin >> use_special_choice;
        use_special = (use_special_choice == 'y' || use_special_choice == 'Y');

        // Generate and display the password
        string password = generate_password(length, use_upper, use_lower, use_digits, use_special);
        cout << "Generated password: " << password <<endl;

    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() <<endl;
    }

    return 0;
}
