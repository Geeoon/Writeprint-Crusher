#include <random>
#include "identity.h"

identity::identity() : identity{ "temp" } {}

identity::identity(const char* name) : name{ name } {
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

identity::identity(const char* file_path, bool dummy) {

}

void identity::parse_text(const std::string& src, std::string& dest) {

}
