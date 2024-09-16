#include <iostream>
#include <memory>
#include <cstring>
#include <unistd.h>
#include "identity.h"

void print_usage(char* name);

int main(int argc, char* argv[]) {
    int is_piped{!isatty(STDIN_FILENO)};
    if (argc < 2) {
        std::cerr << "No command line arguments supplied." << std::endl;
        print_usage(argv[0]);
        return -1;
    }

    std::unique_ptr<identity> ident;
    char* output_file = nullptr;
    // command line argument parsing
    for (int i = 1; i < argc; i += 2) {
        // check if each option have a corresponding value
        if (i + 1 >= argc) {
            std::cerr << "Invalid usage." << std::endl;
            print_usage(argv[0]);
            return -1;
        }
        char* value = argv[i + 1];

        if (strncmp(argv[i], "--create-identity", 17) == 0) {
            // create identity
            ident = std::make_unique<identity>(value);
        } else if (strncmp(argv[i], "-i", 2) == 0) {
            ident = std::make_unique<identity>(value, false);
        } else if (strncmp(argv[i], "-f", 2) == 0) {
            // save to file
            output_file = value;
        } else {
            std::cerr << "Unknown argument: " << value << std::endl;
            return -1;
        }
    }
    return 0;
}

void print_usage(char* name) {
    std::cerr << "Usage: " << name << " [--create-identity name] [-i name]"
        << " [-f file]" << std::endl;
}
