#include <stdio.h>
#include <stdlib.h>

int
main ()
{
    
  int a, key, i=0;      // Declare integer variables
  char text[1000];      // Initialise text message with maximum 1000 characters
  char character;       // Declare character
 

  printf ("Would you like to encrypt or decrypt a message?\nEncrypt (1)\nDecrypt (2)\n");   // Ask user whether to encrypt (1) or decrypt (2)
  scanf ("%d", &a);                                                                         // Receive int a to choose which case
  printf ("What is the rotation cipher key?\n");                                            // Ask user what the rotation cipher key is
  scanf ("%d", &key);                                                                       // Receive int key for rotation cipher


  // If statement to ensure key is between 0 and 26, and convert if not
  
  if (key >= 0 && key <= 26)
    {
      key = key;                        // No change needed as within parameters
    }
  
  else if (key > 26)
    {
      key = key % 26;                   // Modulus 26 to change integer to between 0 and 26
    }
  else if (key < 0 && key >= -26)
    {
      key = 26 + key;                   // Add 26 to change integer to between 0 and 26
    }
  else if (key < -26)
    {
      key = abs (key % 26);             // Absolute and modulus 26 to change integer to between 0 and 26
    }
  else
    {
      printf ("Invalid key\n");         // An invalid key has been entered (e.g. !@#$% or characters)
    }
  
  
  // Switch case to go to either encryption or decryption function
  
  switch (a)			
    {

    // Case 1 is the encryption function

    case 1:
      printf ("Please write the message you would like to encrypt:\n");
      scanf (" %[^\n]s", text);
      while (i < 1000 && text[i] != '\0')	                                // While loop, where 1000 is the maximum characters and \0 is string termination
	{
	  character = text[i];	                                                
	  
	  if (character >= 'a' && character <= 'z')	                            // If statement to convert lower to uppercase
	    {
	      character = character - 32;	                                    // Convert to uppercase (ASCII is 32 between upper and lower)
	    }
	  	                
	  if (character >= 'A' && character <= 'Z')	                            // If statement for already uppercase
	    {
	      character = character + key;	                                    // Add rotation cipher key to character
	      if (character > 'Z')	                                            // If statement for the case where rotation key causes it to go over ASCII range
		{
		  character = character - 26;                                       // Remove 26 from character to loop back into ASCII uppercase range
		}
	    }
	  else
	    {
	      character = character;	                                        // If in range, leave the same
	    }
	  text[i] = character;	                                                // Replaced ith character with the encrypted character
	  	  i++;			                                                    // Loop counter
	}
      printf ("The encrypted text is: %s", text);                           // Print encrypted text
      break;

// Case 2 is the decryption function

    case 2:
      printf ("Please write the message you would like to decrypt:\n");
      scanf (" %[^\n]s", text);
      while (i < 1000 && text[i] != '\0')	                                // While loop, where 1000 is the maximum characters and \0 is string termination
	{
	  
	  character = text[i];	                                                
	  	                                                                    
	  if (character >= 'a' && character <= 'z')	                            // If statement to convert lower to uppercase
	    {
	      character = character - 32;	                                    // Convert to uppercase (ASCII is 32 between upper and lower)
	    }
	  
	  if (character >= 'A' && character <= 'Z')	                            // If statement for already uppercase
	    {
	      character = character - key;	                                    // Minus rotation cipher key to character
	      if (character < 'A')	                                            // If statement for the case where rotation key causes it to go back to lowercase
		{
		  character = character + 26;                                       // Add 26 to bring character back to ASCII uppercase range
		}
	    }
	  else
	    {
	      character = character;                                            // If in range, leave the same
	    }
	  text[i] = character;	                                                // Replaced ith character with the encrypted character
	  i++;			                                                        // Loop counter
	}
      printf ("The decrypted text is: %s", text);                           // Print decrypted text
      break;
    }
  return 0;
}

