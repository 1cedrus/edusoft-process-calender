#include <curl/curl.h>
#include <stdlib.h>
#include <json-c/json.h>
#include <stdio.h>
#include "includes/data.h"

int main(int argc, char *argv[]) {
    subject s;
    dataProcess(&s);
    printf("%s\n", s.nameOfSub);
    return 0;
}