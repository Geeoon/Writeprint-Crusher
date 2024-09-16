#ifndef IDENTITY_PRIV_H_
#define IDENTITY_PRIV_H_

typedef struct identity {
    /**
     * 0: American
     * 1: Australian
     * 2: British
     * 3: Canadian
     */
    int english_type;
    bool hyphenated, double_spaces, capitalization, oxford, apostrophe, fanboys;
    char* name;
} identity;

#endif
