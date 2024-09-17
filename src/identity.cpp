#include <iostream>
#include <fstream>
#include <random>
#include "identity.h"

identity::identity() : identity{ "temp" } {}

identity::identity(const std::string& name) : name{ name } {
    // could use something like OpenSSL instead...
    create_random_identity();
}

identity::identity(const std::string& file_path, bool dummy) {
    std::ifstream fs(file_path);
    if (fs.fail()) {
        std::cerr << "File does not exist, creating random temporary identity." << std::endl;
        create_random_identity();
    } else {
        fs >> english_type;
        fs.ignore(1,',');
        fs >> hyphens;
        fs.ignore(1,',');
        fs >> single_space;
        fs.ignore(1,',');
        fs >> caps;
        fs.ignore(1,',');
        fs >> oxford;
        fs.ignore(1,',');
        fs >> apos;
        fs.ignore(1,',');
        fs >> commas;
        fs.ignore(1,',');
        fs >> name;
    }
}

void identity::parse_text(std::istream& src, std::ostream& dest) {
    std::string token;
    while (src >> token) {
        // parse token
        dest << token;
    }
}

void identity::save_identity(const std::string& file_path) {
    std::ofstream fs(file_path + name + ".csv");
    fs << english_type << ","
        << hyphens << ","
        << single_space << ","
        << caps << ","
        << oxford << ","
        << apos << ","
        << commas << ","
        << name;
}

void identity::create_random_identity() {
    std::random_device device;
    std::mt19937_64 rng(device());
    std::uniform_int_distribution<std::mt19937_64::result_type> distribution_language(0, 1);
    std::uniform_int_distribution<std::mt19937_64::result_type> distribution_bool(0, 1);

    english_type = distribution_language(rng);
    apos = distribution_bool(rng);
    hyphens = distribution_bool(rng);
    single_space = distribution_bool(rng);
    caps = distribution_bool(rng);
    oxford = distribution_bool(rng);
    apos = distribution_bool(rng);
    commas = distribution_bool(rng);
}