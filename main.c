#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <json-c/json.h>
#include "includes/data.h"
#include "includes/auth.h"

int main(int argc, char *argv[]) {
    system("open getAuthCode.html");
    char authCode[200];
    printf("Paste authorization code there and hit Enter\n");

    scanf("%199s", authCode);
    requestAccessToken(authCode);

    subject s;
    updateCalendar(&s);
    printf("Completed!\n");
    return 0;
}