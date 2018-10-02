#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <omp.h>

#include "aes.h"
#include "aesoptions.h"

using namespace std;

int main(int argc, char *argv[])
{
    AESOptions opts(argc, argv);
    AES aes;
    double wtime;

    if (opts.getNumThreads() > 0 && opts.getNumThreads() != omp_get_num_threads())
    {
        omp_set_num_threads(opts.getNumThreads());
    }

    if (opts.getVerbose())
    {
        cout << "Plaintext file: " << opts.getPlainTextFileName() << endl;
        cout << "Cipher file:    " << opts.getCipherFileName() << endl;
        cout << "Key length:     " << opts.getKeyLength() << endl;
        cout << "Num threads:    " << opts.getNumThreads() << endl;

        cout << "Number of processors available = " << omp_get_num_procs() << endl;
        cout << "Max Number of threads =          " << omp_get_max_threads() << endl;
    }


    wtime = omp_get_wtime();

    aes.encrypt(opts);

#if 0
    //    int id;
    //    //  Have each thread say hello
    //    # pragma omp parallel private(id)
    //    {
    //        id = omp_get_thread_num();
    //        cout << "  This is process " << id << "\n";
    //    }
#endif

    wtime = omp_get_wtime() - wtime;

    cout << omp_get_max_threads() << "," << wtime << endl;

    return 0;
}

