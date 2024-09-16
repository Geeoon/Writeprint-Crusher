#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "identity_lib.h"

void print_usage(char* name);

int main(int argc, char* argv[]) {
    int is_piped = isatty(STDIN_FILENO) == 0;
    if (argc < 2) {
        fprintf(stderr, "No command line arguments supplied.");
        print_usage(argv[0]);
        return -1;
    }

    identity* ident = NULL;
    char* name = NULL;
    // command line argument parsing
    for (int i = 1; i < argc; i += 2) {
        // check if each option have a corresponding value
        if (i + 1 >= argc) {
            fprintf(stderr, "Invalid usage.\n");
            print_usage(argv[0]);
            return -1;
        }
        char* value = argv[i + 1];

        if (strncmp(argv[i], "--create-identity", 17) == 0) {
            // ident = create_identity();
            if (!ident) {
                fprintf(stderr, "Error creating identity.\n");
                return -1;
            }
            name = value;
        } else if (strncmp(argv[i], "-i", 2) == 0) {
            // load identity from value
        } else if (strncmp(argv[i], "-f", 2) == 0) {
            // save to file
        } else {
            fprintf(stderr, "Unknown argument: %s\n", argv[i]);
            return -1;
        }
    }
    return 0;
}

void print_usage(char* name) {
    fprintf(stderr, "Usage: %s [--create-identity name] [-i name] [-f file]\n",
        name);
}
