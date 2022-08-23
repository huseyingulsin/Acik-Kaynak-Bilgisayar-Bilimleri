#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define LONG_STRING 101
#define SHORT_STRING 11

int karakterSil(char *edited, char *original, char *toDelete) {
	int editedIndex = 0;

	// For every character in the original text
	for (int i = 0; i < (int)strlen(original); i++) {
		bool removeChar = false;

		// Check every character in the removal set
		for (int j = 0; j < (int)strlen(toDelete); j++) {

			// Set a flag if both characters are equal case insensitively
			if (toupper(original[i]) == toupper(toDelete[j])) {
				removeChar = true;
				break;
			}
		}

		// If not flagged then append the edited string with the current character
		if (!removeChar) {
			edited[editedIndex] = original[i];
			editedIndex++;
		}
	}

	// String terminator
	edited[editedIndex] = '\0';

	// Number of removed characters
	return strlen(original) - strlen(edited);
}

int main(int argc, char const *argv[]) {
	char editedText[LONG_STRING];
	char text[LONG_STRING];
	char toDelete[SHORT_STRING];

	scanf("%s", text);
	scanf("%s", toDelete);

	int deleteCount = karakterSil(editedText, text, toDelete);

	printf("%d\n", deleteCount);
	printf("%s\n", editedText);

	return 0;
}
