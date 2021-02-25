#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

using namespace std;

char normalChar[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 
                    'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 
                    'x', 'y', 'z'}; 
                    
char codedChar[26] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 
                    'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 
                    'B', 'N', 'M'}; 

string stringEncryption(string s) {
    
		// initializing an empty String 
		string encryptedString = ""; 

		// comparing each character of the string and 
		// encoding each character using the indices 
		for (int i = 0; i < s.length(); i++) { 
			for (int j = 0; j < 26; j++) { 

				// comparing the character and 
				// adding the corresponding char 
				// to the encryptedString 
				if (s[i] == normalChar[j]) { 
					encryptedString += codedChar[j]; 
					break; 
				} 

				// if there are any special characters 
				// add them directlyto the string 
				if (s[i] < 'a' || s[i] > 'z') { 
					encryptedString += s[i]; 
					break; 
				} 
			} 
		} 

		// return encryptedString 
		return encryptedString; 
}

string stringDecryption(string s) { 

		// Intializing the string 
		string decryptedString = ""; 

		// Run the for loop for total string 
		for (int i = 0; i < s.length(); i++) { 
			for (int j = 0; j < 26; j++) { 

				// compare each characters and decode them 
				// using indices 
				if (s[i] == codedChar[j]) { 
					decryptedString += normalChar[j]; 
					break; 
				} 

				// Add the special characters directly to 
				// the String 
				if (s[i] < 'A' || s[i] > 'Z') { 
					decryptedString += s[i]; 
					break; 
				} 
			} 
		} 

		// return the decryptedString 
		return decryptedString; 
	}


int main() {
    string str = "welcome to geeksforgeeks";
    
    //print plain text
    cout << "Plain text: " + str + "\n";
    
    // Changing whole string to lower case 
	// function call to stringEncryption and storing in 
	// encryptedString 
	string encryptedString = stringEncryption(str);
	
	// printing encryptedString 
	cout <<"Encrypted message: " + encryptedString + "\n";

	// function call to stringDecryption and printing 
	// the decryptedString 
	cout << "Decrypted message: " + stringDecryption(encryptedString) + "\n";

    return 0;
}