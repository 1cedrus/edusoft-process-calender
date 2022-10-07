#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include<unistd.h>
#include <curl/curl.h>
#include <json-c/json.h>
#include "data/data.h"
#include "auth/auth.h"

int main(int argc, char *argv[]) {

    int set;

    system("open ./auth/getAuthCode.html");
    sleep(1);

    char authCode[200];
    printf("Paste authorization code here and hit enter\n");

    scanf("%199s", authCode);
    set = requestAccessToken(authCode);
    if (!set) printf("_________Get access token succeed!_________\n");
    else {
        printf("_________Get access token failed!_________\n")
        return 1;
    }


    printf("__________Ready to start!_________\n")
    subject s;
    updateCalendar(&s);

    printf("All schedule is updated completely!\n");

    return 0;

}