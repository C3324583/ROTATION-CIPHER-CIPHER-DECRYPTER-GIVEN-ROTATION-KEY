#include <stdio.h>
#include <string.h>


int main(){
    //initialising variables
	char text[1000], element;
	int n, i, rotationkey;
	
	printf("Enter message to decrypt: ");//prompt the user to imput a message
	scanf(" %[^\n]s", text);//store the text imputted by the user in the array "text"
	printf("Enter rotation key: ");//prompt the user to imput a rotation key
	scanf("%d", &rotationkey);//store the rotation value in the variable "rotation"
	
	//accounting for rotation keys that are not between 0 and 25 and translating them into their corresponding key within the range
	if(rotationkey>25){
	    n = rotationkey / 26;
	    rotationkey = rotationkey - (26 * n);
	}
	else if(rotationkey<0){
	    n = -rotationkey / 26;
	    rotationkey = -rotationkey - (26 * n);
	    rotationkey = 26 - rotationkey;
	}
	
	//this for loop executes the rotation for all letters in the array "text" until the element occupying index i is empty
	for(i = 0; text[i] != '\0'; ++i){
		element = text[i]; //assigning the value at index "i" of "text" to the variable element
		
		//Each lowercase letter of the string is turned into UPPERCASE by subtracting 32 (according to the ASCII standard) and then rotated backwards by the "rotationkey"
		if(element >= 'a' && element <= 'z'){
			element = element - rotationkey - 32;
			//If the rotation causes the element to have a value outside 'a'....'z' (according to the ASCII standard), 26 is added to give the rotated letter
			if(element > 'Z' || element < 'A'){
				element = element + 26;
			}
			text[i] = element; //storing the rotated letter back in the array "text"
		}
		
		//Each UPPERCASE letter is rotated backwards by the "rotationkey"
		else if(element >= 'A' && element <= 'Z'){
			element = element - rotationkey;
			//If the rotation causes the element to have a value outside 'a'....'z' (according to the ASCII standard), 26 is added to give the rotated letter
			if(element > 'Z' || element < 'A'){
				element = element + 26;
			}
			text[i] = element; //storing the rotated letter back in the array "text"
		}
	}
	
	printf("The decrypted message is: %s", text); //prints the rotated message to the screen
	
	return 0;
}
