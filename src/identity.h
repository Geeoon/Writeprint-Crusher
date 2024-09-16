#ifndef IDENTITY_H
#define IDENTITY_H
#include <string>

class identity {
public:
    /**
     * Create a completely random temporary identity
     */
    identity();

    /**
     * Create a completely random named identity
     * @param name the name of the identity to be created
     */
    identity(const char* name);

    /**
     * Import an identity from a file
     * @param file_path the path of the identity to import
     * @param dummy only to differentiate between construcctors
     */
    identity(const char* file_path, bool dummy);

    /**
     * Parse text with this identity
     * @param src source string to be parsed
     * @param dest destination string to store the text
     */
    void parse_text(const std::string& src, std::string& dest);
private:
    std::string name;
    int english_type;  // 0: American, 1: Australian, 2: British, 3: Canadian
    bool hyphens, single_space, caps, oxford, apos, commas;
};

#endif