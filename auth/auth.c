#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>
#include <json-c/json.h>
#include "../data/data.h"
#include "auth.h"

int requestAccessToken(char *authCode) {

    CURL *curl;
    CURLcode res;

    clearData("./auth/requestRespond.json");

    char paramaterInNeed[300];
    sprintf(paramaterInNeed, "client_id=812237032448-g3s99dj31nlt7i9hp1f2beltkc8rirhk.apps.googleusercontent.com&code=%s&client_secret=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&redirect_uri=urn:ietf:wg:oauth:2.0:oob&grant_type=authorization_code", authCode);

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl) {
        struct curl_slist *chunk = NULL;
        chunk = curl_slist_append(chunk, "Content-type: application/x-www-form-urlencoded");
        chunk = curl_slist_append(chunk, "Cache-Control: no-cache");

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
        curl_easy_setopt(curl, CURLOPT_URL, "https://accounts.google.com/o/oauth2/token");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, paramaterInNeed);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, saveRequestRespond);
        
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            perror("Failed to request access token");
            return 1;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}

void getAccessTokenFromFile(char *accessToken) {

    json_object *database = json_object_from_file("./auth/requestRespond.json");
    json_object *rawAccessToken = json_object_object_get(database, "access_token");

    sprintf(accessToken, "%s", json_object_get_string(rawAccessToken));

}

size_t saveRequestRespond(char *in, size_t nmem, size_t nitems, void* out) {

    size_t bytes = nmem * nitems;
    FILE *fp = fopen("./auth/requestRespond.json", "a"); 
    if (fp == NULL) perror("Can't open \"/auth/requestRespond.json\""); 

    fprintf(fp, "%s", in);
    fclose(fp);

    return bytes;

}
