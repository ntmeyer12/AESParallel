#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "aesoptions.h"

#define DEFAULT_KEY_LENGTH 128

/**
 * @brief Constructor
 * @param argc Argument count
 * @param argv Argument variables
 */
AESOptions::AESOptions(int argc, char *argv[])
{
    init();

    int optChar;

    while ((optChar = getopt(argc, argv, "i:o:k:t:v")) != EOF)
    {
        switch (optChar)
        {
        case 'i': setPlainTextFileName(optarg); break;
        case 'o': setCipherFileName(optarg); break;
        case 'k': setKeyLength(atoi(optarg)); break;
        case 't': setNumThreads(atoi(optarg)); break;
        case 'v': setVerbose(true); break;
        default: break;
        }
    }
}

/**
 * @brief Initializes member data to defaults
 */
void AESOptions::init()
{
    mPlainTextFileName = "";
    mCipherFileName = "out.txt";
    mKeyLength = DEFAULT_KEY_LENGTH;
    mNumThreads = omp_get_max_threads();
    setVerbose(false);
}

/**
 * @brief PlainTextFileName getter
 * @return PlainTextFileName
 */
string AESOptions::getPlainTextFileName() const
{
    return mPlainTextFileName;
}

/**
 * @brief PlainTextFileName setter
 * @param value Ne value
 */
void AESOptions::setPlainTextFileName(const string &value)
{
    mPlainTextFileName = value;
}

/**
 * @brief CipherFileName getter
 * @return CipherFileName
 */
string AESOptions::getCipherFileName() const
{
    return mCipherFileName;
}

/**
 * @brief CipherFileName setter
 * @param value New value
 */
void AESOptions::setCipherFileName(const string &value)
{
    mCipherFileName = value;
}

/**
 * @brief NumThreads getter
 * @return NumThreads
 */
int AESOptions::getNumThreads() const
{
    return mNumThreads;
}

/**
 * @brief NumThreads setter
 * @param value New value
 */
void AESOptions::setNumThreads(int value)
{
    mNumThreads = value;
    if (mNumThreads > 0)
    {
        omp_set_num_threads(mNumThreads);
    }
}

/**
 * @brief KeyLength getter
 * @return KeyLength
 */
int AESOptions::getKeyLength() const
{
    return mKeyLength;
}

/**
 * @brief KeyLength setter
 * @param value New value
 */
void AESOptions::setKeyLength(int value)
{
    mKeyLength = value;
}

/**
 * @brief Verbose getter
 * @return Verbose
 */
bool AESOptions::getVerbose() const
{
    return mVerbose;
}

/**
 * @brief Verbose setter
 * @param value New value
 */
void AESOptions::setVerbose(bool value)
{
    mVerbose = value;
}
