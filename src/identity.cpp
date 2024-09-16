#include <iostream>
#include <fstream>
#include <random>
#include "identity.h"

identity::identity() : identity{ "temp" } {}

identity::identity(const std::string& name) : name{ name } {
    // could use something like OpenSSL instead...
    std::random_device device;
    std::mt19937_64 rng(device());
    std::uniform_int_distribution<std::mt19937_64::result_type> distribution_language(0, 3);
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

identity::identity(const std::string& file_path, bool dummy) {
    std::ifstream fs(file_path);
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

void identity::parse_text(const std::string& src, std::string& dest) {

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
