#include <cstdlib>
#include <ctime>
#include <cstring>
#include "container.h"

void firstError() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void secondError() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void thirdError(int size) {
    printf("incorrect number = %d. It must be in the range from 0 to 10000\n", size);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        firstError();
        return 1;
    }

    printf("Start\n");
    Container container;
    if (!strcmp(argv[1], "-f")) {
        FILE *input = fopen(argv[2], "r");
        // Checking for the existence of a file.
        if (!input) {
            printf("File doesn't exist!");
            return 1;
        }
        container.In(input);
        fclose(input);
    } else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            thirdError(size);
            return 3;
        }
        srand(static_cast<unsigned int>(time(0)));
        // Random filling of the container.
        container.InRnd(size);
    } else {
        secondError();
        return 2;
    }

    FILE *first_output = fopen(argv[3], "w");
    fprintf(first_output, "Filled container:\n");
    container.Out(first_output);

    FILE *second_output = fopen(argv[4], "w");
    fprintf(second_output, "Sorted container:\n");
    container.Sort(&container, 0, container.len - 1);

    container.Out(second_output);

    printf("Stop\n");
    fclose(first_output);
    fclose(second_output);
    return 0;
}