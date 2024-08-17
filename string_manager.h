#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

char** parse(char* input){
    int tNum=1,i=0;
    while(input[i]!='\0'){
        if (input[i] == '\n') {
            tNum++;
        }
        i++;
    }

    char** tokens = (char**)malloc((tNum+1) * sizeof(char*));
    char* token = strtok(input, "\n");
    tokens[0] = token;

    for(int i=1;i<tNum;i++){
        token = strtok(NULL,"\n");
        tokens[i] = token;
    }
    tokens[tNum] = NULL;

    return tokens;
}

int isNewline(char c) {
    return (c == '\n');
}

void addCharacter(char* output, size_t* outputLength, char c) {
    output[*outputLength] = c;
    (*outputLength)++;
}

char* removeUnwantedNewLine(const char* input) {
    // Calculate the length of the input string
    size_t inputLength = strlen(input);

    // Create a buffer to hold the modified string
    char* output = (char*)malloc((inputLength + 1) * sizeof(char));
    size_t outputLength = 0;

    // Variables to track the state of parsing
    int consecutiveNewlines = 0;

    // Iterate through the input string
    for (size_t i = 0; i < inputLength; i++) {
        char currentChar = input[i];

        if (isNewline(currentChar)) {
            consecutiveNewlines++;

            // Only add a single newline to the output
            if (consecutiveNewlines == 1) {
                addCharacter(output, &outputLength, currentChar);
            }
        } else {
            consecutiveNewlines = 0;

            // Copy other characters to the output
            addCharacter(output, &outputLength, currentChar);
        }
    }

    // Null-terminate the output string
    output[outputLength] = '\0';

    return output;
}

bool isFreshLabel(const char* input) {
    size_t length = strlen(input);
    if (length < 3 || input[0] != 'L')
        return false;

    for (size_t i = 1; i < length - 1; i++) {
        if (input[i] < '0' || input[i] > '9')
            return false;
    }

    if (input[length - 1] != ':')
        return false;

    return true;
}

// bool isLabel(const char* input) {
//     int i = 0;
//     while (input[i] != '\0') {
//         if (input[i] == ':')
//             return true;
//         i++;
//     }
//     return false;
// }

char* addTabToToken(const char* token) {
    size_t tokenLength = strlen(token);

    // Calculate the length of the modified token
    size_t modifiedLength = tokenLength + 2; // Add 1 for the tab character
    char* modifiedToken = (char*)malloc((modifiedLength + 1) * sizeof(char)); // Allocate memory for the modified token

    // Add the tab character and the original token
    modifiedToken[0] = '\t';
    for (size_t i = 0; i < tokenLength; i++) {
        modifiedToken[i + 1] = token[i];
    }
    modifiedToken[modifiedLength] = '\0';
    return modifiedToken;
}


char* tokensToString(char** tokens) {
    size_t numTokens = 0;
    size_t totalLength = 0;

    // Calculate the number of tokens and total length of the concatenated string
    while (tokens[numTokens] != NULL) {
        totalLength += strlen(tokens[numTokens]);
        numTokens++;
    }

    // Calculate the length of the output string
    size_t outputLength = totalLength + numTokens; // Add 1 for each newline character

    // Allocate memory for the output string
    char* output = (char*)malloc((outputLength + 1) * sizeof(char));

    size_t currentPosition = 0;

    // Copy tokens and add newline characters between them
    for (size_t i = 0; i < numTokens; i++) {
        size_t tokenLength = strlen(tokens[i]);
        strcpy(output + currentPosition, tokens[i]);
        currentPosition += tokenLength;

        // Add newline character unless it's the last token
        if (i != numTokens - 1) {
            output[currentPosition] = '\n';
            currentPosition++;
        }
    }

    output[currentPosition] = '\0'; // Null-terminate the output string

    return output;
}


char* transformText(char* input){
    if (input == NULL)
        return NULL;
    char* stage1 = removeUnwantedNewLine(input);
    char** tokens = parse(stage1);
    for(int i=0;tokens[i]!=NULL;i++){
        if (isFreshLabel(tokens[i]) == false) {
            // modify each token and add to it \t at the beginning
            tokens[i] = addTabToToken(tokens[i]);
        }
    }
    return tokensToString(tokens);
}