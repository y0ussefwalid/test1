// FCAI – Structured Programming – 2024 - Assignment 2
// Program Name: CS112_A2_T2_S1_20230376_20230278_20230517.cpp
// Program Description: An application encrypt messages using Xor encrypt, Morse Code and Polybius Square
// Last Modification Date: 10/03/2024
// Author1 and ID and Group: Mahmoud Mohamed El-Basel Hegazy,   20230376, Group A
// Author2 and ID and Group: Fares Mohammed Abdulhamid Sarhan,  20230278, Group A
// Author3 and ID and Group: Youssef Walid Mohamed Shaker,      20230517, Group A
// Teaching Assistant: Yomna Esmail Fathy
// Polybius Square done by  : Mahmoud Mohamed El-Basel Hegazy
// Xor encryption done by   : Fares Mohammed Abdulhamid Sarhan
// Morse Code done by       : Youssef Walid Mohamed Shaker
#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <iomanip>
#include <sstream>

//function which takes parameters text and key,
//and encrypts the text with respect to the key
std::string xorencrypt(const std::string& text, const std::string& key) {
    //introduce string to add every encoded character to
    //and get text length and key length to use in for loop
    std::string encrypted_message;
    int textlength = text.length();
    int keylength = key.length();

    //loop through each character in text and preform
    //bitwise xor operation with the corresponding key
    //index
    for (int i = 0; i < textlength; i++) {
        encrypted_message += text[i] ^ key[i % keylength];
    }

    return encrypted_message;
}

//function to convert string to hex
std::string xorToHex(const std::string& input) {
    std::stringstream text;

    //format the text var to hex and if the hex number
    //is only 1, pad with 0s to compensate for the other number
    text << std::hex << std::setfill('0');
    for (unsigned char c : input) {
        text << std::setw(2) << static_cast<int>(c);
    }

    return text.str();
}

//function to convert hex to text
std::string xorToText(const std::string& input) { 

    std::string text;
    std::string tempHex;

    //loop through each character in hex input, then add
    //it to a temporary variable until there is 2 inside
    //when there is 2 characters inside, it will preform
    //operation to convert hex value to char then add 
    //char to text
    for (int i = 0; i < input.length(); i++) {
        tempHex += input[i];

        if (tempHex.length() == 2) {
            std::istringstream conv(tempHex);
            int hexValue;
            conv >> std::hex >> hexValue;
            char asciiChar = static_cast<char>(hexValue);
            text += asciiChar;
            tempHex = "";
        }
    }
    return text;
}

//xor function to start xor encrypt and decrypt
void xOr(int choice, std::string text) {
    std::cout << "*************************\n";
    std::cout << "* Welcome to Xor Cipher *\n";
    std::cout << "*************************\n";
    std::string key;

    //ask user to input a key
    while (true) {
    std::cout << "Please enter your key:";
    std::getline(std::cin >> std::ws, key);

    //check if key is empty or not
    if (key.empty()){
        std::cout << "Key cannot be empty." << std::endl;
    }
    else{
        break;
    }
    }

    //preform encryption if user inputed encrypt
    //and output encrypted text
    if (choice == 1){
        std::string encrypted_text = xorencrypt(text, key);
        std::cout << "Cipher text: " << encrypted_text << std::endl;

        std::string encryptedHex;
        encryptedHex = xorToHex(encrypted_text);
        std::cout << "Hexa: " << encryptedHex << std::endl;
    }

    //preform decrypt if user inputed decrypt
    //and output decrpted messge
    else {
        std::string encryptedText;
        //decrypting message is simply encrypting
        //the encrypted message again
        encryptedText = xorToText(text);

        std::string decrypted_text = xorencrypt(encryptedText, key);
        std::cout << "Plain text: " << decrypted_text << std::endl;
    }
}


void morse_decrypt(std::string& input)
{
    std::string encrypted_char{ "" }, decrypted, nodecryption;
    //added a space to the input to make the loop work properly as it stops when it finds a space
    input += ' ';
    //a map for every morse code and its char
    std::map<std::string, char> morse;
    morse[".-"] = 'a';
    morse["-..."] = 'b';
    morse["-.-."] = 'c';
    morse["-.."] = 'd';
    morse["."] = 'e';
    morse["..-."] = 'f';
    morse["--."] = 'g';
    morse["...."] = 'h';
    morse[".."] = 'i';
    morse[".---"] = 'j';
    morse["-.-"] = 'k';
    morse[".-.."] = 'l';
    morse["--"] = 'm';
    morse["-."] = 'n';
    morse["---"] = 'o';
    morse[".--."] = 'p';
    morse["--.-"] = 'q';
    morse[".-."] = 'r';
    morse["..."] = 's';
    morse["-"] = 't';
    morse["..-"] = 'u';
    morse["...-"] = 'v';
    morse[".--"] = 'w';
    morse["-..-"] = 'x';
    morse["-.--"] = 'y';
    morse["--.."] = 'z';
    morse["-----"] = '0';
    morse[".----"] = '1';
    morse["..---"] = '2';
    morse["...--"] = '3';
    morse["....-"] = '4';
    morse["....."] = '5';
    morse["-...."] = '6';
    morse["--..."] = '7';
    morse["---.."] = '8';
    morse["----."] = '9';
    morse[".-.-.-"] = '.';
    morse["--..--"] = ',';
    morse["..--.."] = '?';
    morse["-.-.-."] = ';';
    morse["..--.-"] = '_';
    morse["...-..-"] = '$';
    morse[".--.-."] = '@';
    morse[".----."] = '\'';
    morse["-.-.--"] = '!';
    morse["-..-."] = '/';
    morse["-.--."] = '(';
    morse["-.--.-"] = ')';
    morse[".-..."] = '&';
    morse["---..."] = ':';
    morse["-...-"] = '=';
    morse[".-.-."] = '+';
    morse["-....-"] = '-';
    morse[".-..-."] = '\"';
    morse[" "] = ' ';
    //this variable is created to find out if the space we stopped on is between words or the end of a char
    int n = 0;
    //the loop is the index of the string
    for (int i = 0; i <= input.size(); i++) {
        //when a space is found and n is morethan 1 it means a char has ended
        if (input[i] == ' ' && n >= 1) {
            //a statement for maps means it stops when it reaches the end
            if (morse.find(encrypted_char) != morse.end()) {
                decrypted += morse[encrypted_char];
                //encrypted char is a string which collects chars until the loop reaches a space and we empty it after a decryption has been done
                encrypted_char = "";
                n = 0;
            }
            // no decryption found for the char
            else {
                std::cout << "nodecryption found for: " << encrypted_char << "\n";
                encrypted_char = "";
                n = 0;

            }
        }
        //to collect chars until the loop reaches a space
        if (n >= 0 && input[i] != ' ') {
            encrypted_char += input[i];
            n++;
        }
        //an end of a word means 3 spaces or more in morse 
        if (input[i] == ' ' && input[i++] == ' ' && n == 0 && input[i--] == ' ') {
            decrypted += input[i];
            n = 0;
            i++;
        }
    }
    std::cout << "the decrypted message: " << decrypted << "\n";
}
void morse_encrypt(std::string& originaltext)
{
    std::string encrypted, noencryption;
    int length = originaltext.length() - 1;
    //an index loop and the switch cases for every possible char 
    for (int i = 0; i <= length; i++) {
        switch (originaltext[i]) {
        case 'a':
            encrypted += ".- ";
            break;
        case 'b':
            encrypted += "-... ";
            break;
        case 'c':
            encrypted += "-.-. ";
            break;
        case 'd':
            encrypted += "-.. ";
            break;
        case 'e':
            encrypted += ". ";
            break;
        case 'f':
            encrypted += "..-. ";
            break;
        case 'g':
            encrypted += "--. ";
            break;
        case 'h':
            encrypted += ".... ";
            break;
        case 'i':
            encrypted += ".. ";
            break;
        case 'j':
            encrypted += ".--- ";
            break;
        case 'k':
            encrypted += "-.- ";
            break;
        case 'l':
            encrypted += ".-.. ";
            break;
        case 'm':
            encrypted += "-- ";
            break;
        case 'n':
            encrypted += "-. ";
            break;
        case 'o':
            encrypted += "--- ";
            break;
        case 'p':
            encrypted += ".--. ";
            break;
        case 'q':
            encrypted += "--.- ";
            break;
        case 'r':
            encrypted += ".-. ";
            break;
        case 's':
            encrypted += "... ";
            break;
        case 't':
            encrypted += "- ";
            break;
        case 'u':
            encrypted += "..- ";
            break;
        case 'v':
            encrypted += "...- ";
            break;
        case 'w':
            encrypted += ".-- ";
            break;
        case 'x':
            encrypted += "-..- ";
            break;
        case 'y':
            encrypted += "-.-- ";
            break;
        case 'z':
            encrypted += "--.. ";
            break;
        case '0':
            encrypted += "----- ";
            break;
        case '1':
            encrypted += ".---- ";
            break;
        case '2':
            encrypted += "..--- ";
            break;
        case '3':
            encrypted += "...-- ";
            break;
        case '4':
            encrypted += "....- ";
            break;
        case '5':
            encrypted += "..... ";
            break;
        case '6':
            encrypted += "-.... ";
            break;
        case '7':
            encrypted += "--... ";
            break;
        case '8':
            encrypted += "---.. ";
            break;
        case '9':
            encrypted += "----. ";
            break;
        case '.':
            encrypted += ".-.-.- ";
            break;
        case ',':
            encrypted += "--..-- ";
            break;
        case '?':
            encrypted += "..--.. ";
            break;
        case '\'':
            encrypted += ".----. ";
            break;
        case '!':
            encrypted += "-.-.-- ";
            break;
        case '/':
            encrypted += "-..-. ";
            break;
        case '(':
            encrypted += "-.--. ";
            break;
        case ')':
            encrypted += "-.--.- ";
            break;
        case '&':
            encrypted += ".-... ";
            break;
        case ':':
            encrypted += "---... ";
            break;
        case ';':
            encrypted += "-.-.-. ";
            break;
        case '=':
            encrypted += "-...- ";
            break;
        case '+':
            encrypted += ".-.-. ";
            break;
        case '-':
            encrypted += "-....- ";
            break;
        case '_':
            encrypted += "..--.- ";
            break;
        case '"':
            encrypted += ".-..-. ";
            break;
        case '$':
            encrypted += "...-..- ";
            break;
        case '@':
            encrypted += ".--.-. ";
            break;
        case ' ':
            encrypted += "   ";
            break;
        default:
            noencryption += originaltext[i];
            break;

        }
    }

    std::cout << "the encrypted message:  " << encrypted;
    std::cout << "\nno encryption found for: " << noencryption;
    std::cout << "\n";
}
//this function insures that the input that enters morse functions is always right and it takes the user choice from the menu
void morse_code(int choice, std::string text)
{
    if (choice == 1)
    {
        std::string not_encrypted;
        //to lower the letters in the string as the switch cases in the function works on lowercase letters
        for (int i = 0; i < text.size(); i++)
        {
            not_encrypted += tolower(text[i]);
        }
        morse_encrypt(not_encrypted);
    }
    else
    {//to check that the input is always in morse code when decrypting the cipher
        for (int i = 0; i < text.size(); i++)
        {
            if (text[i] == '.' || text[i] == '-' || text[i] == ' ')continue;
            else
            {
                std::cout << "\ainvalid input" << "\nplease input a valid morse code which consists of '-' '.' ' ' only\n";
                return;
                    
            }
        }
        morse_decrypt(text);
    }   
}

void PolybiusEncrypt(std::string& plain, char square[5][5])
{
    // define a flag so if the desired character found then output its corresponding columns and rows
    bool found{false};
    std::cout << "Cipher text: ";
    for (auto ch: plain)
    {
        // if the character is not a letter then print it as it doesn't have an encryption map
        if(not std::isalpha(ch))
        {
            std::cout << ch;
            continue;
        }
        if(ch == 'j')
        {
            ch = 'i';
        }
        for (int i = 0; i < 5; ++i)
        {
            found = false;
            for (int j = 0; j < 5; ++j)
            {
                if(tolower(ch) == square[i][j])
                {
                    // add one to the row and columns as arrays start from zero
                    std::cout << i + 1 << j + 1;
                    found = true;
                    break;
                }
            }
            if(found)
                break;
        }
    }
    std::cout << "\n********************************\n";
}

std::string checkCipherText(std::string cipher)
{
    while (true)
    {
        int length = 0;
        // a flag to check if the cipher text contains anything more than numbers
        bool charFlag{false};

        // check if the inputted text contains letters as the ciphered text must not have letters
        for (auto ch: cipher)
        {
            // ciphered text must be of an even length of numbers, so check if the inputted text is not even
            if(std::isdigit(ch))
            {
                length++;
            }
            if(std::isalpha(ch))
            {
                std::cout << "Invalid ciphered text, the text should contain even length of numbers from 1 to 5 only\n";
                std::cout << "cipher text:\n";
                std::getline(std::cin >> std::ws, cipher);
                charFlag = true;
                break;
            }
        }
        if(charFlag)
        {
            continue;
        }
        if(length % 2 != 0)
        {
            std::cout << "Invalid ciphered text, the text should contain even length of numbers from 1 to 5 only\n";
            std::cout << "cipher text:\n";
            std::getline(std::cin >> std::ws, cipher);
            continue;
        }
        // if the ciphered text passed the validations return it
        return cipher;
    }
}

// decrypt the message using the polybius decryption
void PolybiusDecrypt(std::string cipher, char square[5][5])
{
    cipher = checkCipherText(cipher);
    std::cout << "Plain text: ";
    // iterate through each character in the ciphered text and map it to the key
    for (int i = 0; i < cipher.length(); ++i)
    {
        if(std::isdigit(cipher[i]))
        {
            std::cout << square[cipher[i] - '1'][cipher[i + 1] - '1'];
            ++i;
            continue;
        }
        std::cout << cipher[i];
    }
    std::cout << "\n********************************\n";
}

bool PolybiusValidateKey(std::string& key)
{
    // validate that the key provided from the user contains numbers only from 1 to 5
    for (auto ch: key)
    {
        if(not (ch >= '1' and ch <= '5'))
        {
            return false;
        }
    }
    return true;
}

void PolybiusGetKey(std::string& key)
{
    while (true)
    {
        std::cout << "enter a sequence of the numbers from 1 to 5 in any order without spaces:";
        std::cin >> key;
        if(key.length() != 5)
        {
            // if the user entered any bad input other than the requested input
            // then ignore the input and ask again
            std::cin.ignore(100,'\n');
            std::cout << "enter a valid key\n";
        }
        else
        {
            if(PolybiusValidateKey(key))
            {
                break;
            }
            std::cout << "enter a valid key\n";
        }
    }

}

void Polybius(int choice, std::string text)
{
    std::cout << "*************************************\n";
    std::cout << "* Welcome to Polybius Square Cipher *\n";
    std::cout << "*************************************\n";

    // see if the user wants to enter the key or use the default
    std::string keyOption{};
    std::string key;

    while (true)
    {
        std::cout << "do you want to enter a key or use the default?(y/n)\n";
        std::cin >> keyOption;
        if (tolower(keyOption[0]) == 'y')
        {
            // get the key from the user and validate that it is correct
            PolybiusGetKey(key);
            break;
        }
            // if the user entered n for no then use the default key
        else if (tolower(keyOption[0]) == 'n')
        {
            break;
        }
        // if the user entered anything else then ignore these characters and ask again
        std::cin.ignore(100, '\n');
        std::cout << "please enter y for yes or n for no only\n";
    }
    // if the user entered no the initialize the key with a default value
    if (key.length() == 0)
    {
        key = "12345";
    }
    char square[5][5];
    char fill{'a'};
    for (auto row: key)
    {

        for (auto column: key)
        {
            if (fill == 'j')
            {
                ++fill;
            }
            square[row - '1'][column - '1'] = fill;
            ++fill;
        }
    }
    switch (choice) {
        case 1:
            PolybiusEncrypt(text, square);
            break;
        case 2:
            PolybiusDecrypt(text, square);
            break;
        default:
            std::cout << "Invalid input\n";
    }
}

// show the user the cipher algorithms option and make them choose which cipher do they want
void ciphers(int choice, std::string text)
{
    std::cout << "Which Cipher do you like to choose?\n";
    std::string cipherChoice{};

    do
    {
        std::cout << "1- Polybius Square Cipher\n";
        std::cout << "2- Morse code cipher\n";
        std::cout << "3- Xor cipher\n";
        std::cout << "4- Return\n";
        std::cout << "enter choice:";
        std::cin >> cipherChoice;

        if(cipherChoice > "4" or cipherChoice < "1" or cipherChoice.length() != 1)
        {
            std::cout << "Invalid choice, enter a choice between 1 and 4\n";
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
    } while (cipherChoice > "4" or cipherChoice < "1" or cipherChoice.length() != 1);

    switch (std::stoi(cipherChoice))
    {
        case 1:
            Polybius(choice, text);
            break;
        case 2:
            morse_code(choice, text);
            break;
        case 3:
            xOr(choice, text);
        default:
            return;
    }
}

int main()
{
    std::cout << "**************************************\n";
    std::cout << "* Welcome to encrypting messages app *\n";
    std::cout << "**************************************\n";
    std::cout << "What do you like to do today?\n";
    std::string text{};
    // see the user choice if they want to encrypt or decrypt the message
    std::string textChoice{};
    while (true)
    {
        do {
            std::cout << "1- Cipher a message\n";
            std::cout << "2- Decipher a message\n";
            std::cout << "3- End\n";
            std::cout << "enter your choice:";
            std::cin >> textChoice;

            if(textChoice > "3" or textChoice < "1" or textChoice.length() != 1)
            {
                std::cout << "Invalid choice, enter a choice between 1 and 3\n";
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
        } while (textChoice > "3" or textChoice < "1" or textChoice.length() != 1);

        switch (std::stoi(textChoice))
        {
            case 1:
                std::cout << "Please enter the message to cipher:\n";
                std::getline(std::cin >> std::ws, text);
                break;
            case 2:
                std::cout << "Please enter the message to decipher:\n";
                std::getline(std::cin >> std::ws, text);
                break;
            default:
                std::cout << "Good bye\n";
                return 0;
        }
        ciphers(std::stoi(textChoice),text);
    }
}