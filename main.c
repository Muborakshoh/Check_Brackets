#include <stdio.h>
#include <stdbool.h>

bool check(const char* str, int index, int balance) {

    if (balance < 0) {

        return false;
    }
    if (str[index] == '\0') {

        return balance == 0;
    }

    if (str[index] == '(') {

        return check(str, index + 1, balance + 1);
    } else if (str[index] == ')') {

        return check(str, index + 1, balance - 1);
    } else {

        return check(str, index + 1, balance);
    }
}


bool checkBrackets(const char* str) {
    return check(str, 0, 0);
}

int main() {
    const char* test1 = "(a + b) * (c - d)";
    const char* test2 = "((a + b) * c))";

    printf("Test 1: %s\n", checkBrackets(test1) ? "Correct" : "Incorrect");
    printf("Test 2: %s\n", checkBrackets(test2) ? "Correct" : "Incorrect");

    return 0;
}
