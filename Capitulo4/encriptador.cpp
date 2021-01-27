#include <string>

String s = "Hola";
String encryptedString = "";

for (int i = 0; i < s.length(); i++){
	for (int j = 0; j < 26; j++){


	  if (s.str[i] == normalChar[j]){
		encryptedString += codedChar[j];
		break;
	  }

	  if (s.str[i] < 'a' || s.str[i] > 'z')
	  {
		encryptedString += s.str[i];
		break;
	  }
	}
}

return encryptedString;