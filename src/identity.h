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
    identity(const std::string& name);

    /**
     * Import an identity from a file
     * @param file_path the path of the identity to import
     * @param dummy only to differentiate between construcctors
     */
    identity(const std::string& file_path, bool dummy);

    /**
     * Parse text with this identity
     * @param src the source stream to be parsed
     * @param dest the destination stream to store the text
     */
    void parse_text(std::ostream& dest, std::istream& src) const;

    /**
     * Save identity to a particular path
     * @param file_path the path where the file should be saved
     */
    void save_identity(const std::string& file_path) const;
private:
    void create_random_identity();
    std::string name;
    int english_type;  // 0: American, 1: British, 2: Australian (not supported), 3: Canadian (not supported)
    bool hyphens, single_space, caps, oxford, apos, commas;
};

#endif