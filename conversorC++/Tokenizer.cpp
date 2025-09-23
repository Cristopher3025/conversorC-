#include "Tokenizer.h"


static bool isAlphabetic(char character) {
    return (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z');
}
static bool isDigitChar(char character) {
    return (character >= '0' && character <= '9');
}
static bool isAlphanumeric(char character) {
    return isAlphabetic(character) || isDigitChar(character) || character == '_';
}
static bool isWhitespace(char character) {
    return character == ' ' || character == '\t' || character == '\n' || character == '\r';
}
static char toLowerChar(char character) {
    if (character >= 'A' && character <= 'Z') return static_cast<char>(character - 'A' + 'a');
    return character;
}
static void pushCurrentToken(LinkedListString& tokenList, std::string& currentToken) {
    if (!currentToken.empty()) {
        tokenList.pushBack(currentToken);
        currentToken.clear();
    }
}


LinkedListString tokenize(const std::string& inputLine)
{
    LinkedListString tokenList;
    std::string currentToken;

    for (unsigned int index = 0; index < inputLine.size(); ++index) {
        char inputChar = inputLine[index];

        if (isAlphanumeric(inputChar)) {
            currentToken.push_back(toLowerChar(inputChar));
        }
        else if (isWhitespace(inputChar) || inputChar == ',') {
            pushCurrentToken(tokenList, currentToken);
        }
        else {
            pushCurrentToken(tokenList, currentToken);
            std::string singleSymbol(1, inputChar);
            tokenList.pushBack(singleSymbol);
        }
    }

    pushCurrentToken(tokenList, currentToken);
    return tokenList;
}



