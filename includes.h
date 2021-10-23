//
// Created by kikin on 22.10.2021.
//

#ifndef HOMEWORK2AVC_INCLUDES_H
#define HOMEWORK2AVC_INCLUDES_H
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <cstddef>

class Includes {
public:

    // Generating a random number within a specified range.
    static int rndInt(int first, int last) {
        return rand() % (last - first + 1) + first;
    }

    static char *rndStr(int len) {
        static const char alphabet[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        char *result = new char[len + 1];

        for (int i = 0; i < len; ++i) {
            result[i] = alphabet[rand() % (sizeof(alphabet) - 1)];
        }
        result[len] = 0;
        return result;
    }

    static char *readStr(FILE *file) {
        char local[128] = {0};
        fscanf(file, "%s", local);
        char *result = (char *) malloc(strlen(local));
        strcpy(result, local);

        return result;
    }

    static int readDigit(FILE *file) {
        int result = 0;
        fscanf(file, "%d", &result);
        return result;
    }

};
#endif //HOMEWORK2AVC_INCLUDES_H
