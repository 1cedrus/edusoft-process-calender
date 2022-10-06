#include <stdio.h>
#include <curl/curl.h>
#include "includes/auth.h"
#include "includes/data.h"
#include "includes/calendar.h"

void calendarEventRes(subject *s) {

    CURL *curl;
    CURLcode res;

    char accessToken[250];
    getAccessTokenFromFile(accessToken);

    char headerAuth[300];
    sprintf(headerAuth, "Authorization: Bearer %s", accessToken);

    char paramaterInNeed[400];
    sprintf (paramaterInNeed, "{\"summary\":\"%s\",\"end\":{\"dateTime\":\"%s\",\"timeZone\":\"Asia/Ho_Chi_Minh\"},\"start\":{\"dateTime\":\"%s\",\"timeZone\":\"Asia/Ho_Chi_Minh\"}}", s->name, s->endTime, s->startTime);

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl) {
        struct curl_slist *chunk = NULL;
        chunk = curl_slist_append(chunk, headerAuth);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.googleapis.com/calendar/v3/calendars/primary/events/");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, paramaterInNeed);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK)
            perror("Failed to request");

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}