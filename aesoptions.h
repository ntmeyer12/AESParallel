#ifndef AESOPTIONS_H
#define AESOPTIONS_H

#include <string>

using namespace std;

class AESOptions
{
public:

    AESOptions(int argc, char *argv[]);

    void init();

    string getPlainTextFileName() const;
    void setPlainTextFileName(const string &value);

    string getCipherFileName() const;
    void setCipherFileName(const string &value);

    int getNumThreads() const;
    void setNumThreads(int value);

    int getKeyLength() const;
    void setKeyLength(int value);

    bool getVerbose() const;
    void setVerbose(bool value);

private:

    string  mPlainTextFileName; ///< Name of file containing the plaintext
    string  mCipherFileName;    ///< Name of file for encrypted output
    int     mNumThreads;        ///< Max number of OMP threads
    int     mKeyLength;         ///< AES key length
    bool    mVerbose;           ///< Verbose mode

};

#endif // AESOPTIONS_H
