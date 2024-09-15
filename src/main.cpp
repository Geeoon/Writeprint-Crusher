#include <iostream>
#include <unistd.h>

void print_usage(char* name);

int main(int argc, char* argv[]) {
    bool is_piped{!isatty(STDIN_FILENO)};
    if (argc < 2) {
        std::cerr << "No command line arguments supplied." << std::endl;
        print_usage(argv[0]);
        return -1;
    }

    for (int i = 0; i < argc; i++) {
        
        std::cout << argv[i] << std::endl;
    }
    return 0;
}

void print_usage(char* name) {
    std::cerr << "Usage: " << name << " [--create-identity name] [-i name] [-f file]" << std::endl;
}
