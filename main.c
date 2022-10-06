#include <curl/curl.h>
#include <stdlib.h>
#include <json-c/json.h>
#include <stdio.h>
#include "includes/data.h"

int main(int argc, char *argv[]) {
    // if (argc < 2) {
    //     printf ("need authen code!\n");
    //     return 1;
    // }
    // getAccessToken(argc, argv);
    subject s;
    dataProcess(&s);
    return 0;
}