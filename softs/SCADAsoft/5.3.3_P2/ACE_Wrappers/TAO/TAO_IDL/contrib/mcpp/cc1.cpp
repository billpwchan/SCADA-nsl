/*
 * cc1.c:   dummy cc1 and cc1plus to be invoked by MinGW's GCC
 *      MinGW's GCC does not invoke shell-script named cc1.
 * $Id: cc1.cpp 979 2008-12-31 20:22:32Z mitza $
 */

#include "stdio.h"
#include "string.h"
#include "process.h"

#define ARG_LIM 64

int exec_program( int argc, char ** argv);
// FUZZ: disable check_for_improper_main_declaration
int main (int argc, char ** argv) {
    int     status;

    if (argc - 1 >= ARG_LIM) {
        ACE_OS::fprintf( stderr, "Too many arguments.\n");
        return  1;
    }
    status = exec_program( argc, argv);
                    /* MinGW does not have fork() nor wait().   */
    return  status;
}

int exec_program( int argc, char ** argv) {
    char *  buf[ ARG_LIM];
    char    temp[ FILENAME_MAX];
    char *  tp;
    int     plus = 0;
    int     n = 1;
    int     i;
    int     status;
    size_t  len;

    if (ACE_OS::strstr( argv[ 0], "cc1plus"))
        plus = 1;                   /* C++  */
    tp = ACE_OS::strstr( argv[ 0], "cc1");
    len = tp - argv[ 0];
    ACE_OS::memcpy( temp, argv[ 0], len);
    temp[ len] = '\0';
    tp = temp + len;
    for (i = 1; i < argc; i++)
      if (ACE_OS::strcmp( argv[ i], "-fpreprocessed") == 0)
            break;                  /* Invoke cc1 or cc1plus    */
    if (i < argc) {
        ACE_OS::strcpy( tp, plus ? "cc1plus_gnuc.exe" : "cc1_gnuc.exe");
    } else {                        /* Invoke mcpp              */
        ACE_OS::strcpy( tp, "mcpp.exe");
        if (plus)
            buf[ n++] = "-+";       /* Insert the option        */
    }
    buf[ 0] = temp;
    for (i = 1; i < argc; i++, n++)
        buf[ n] = argv[ i];
    buf[ n] = 0;

    status = spawnv( _P_WAIT, buf[ 0], buf);
    return  status;
}