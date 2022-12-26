#include <stdio.h>
#include "../data.h"
#include <stdlib.h>
#include <curl/curl.h>

rawSubject *s = NULL;
char *buffer = NULL;    

size_t parser(char *in, size_t nmem, size_t nitems, void* out) {

    size_t bytes = nmem * nitems;

    static int flag = 0, cExtraArrow = 0, nSubjects = 0, nInfor = 0, count = 0;  

    if (nSubjects == 0 && nInfor == 0 && count == 0) 
        s = malloc(sizeof(subject));

    for (int i = 0; i < bytes; i++) {
        if (flag == 0 && in[i] == 'g' && in[i+1] == 'r' && in[i+2] == 'i' && in[i+3] == 'd') 
            flag = 1;

        else if (flag == 1 && in[i] == '<' && in[i+1] == 't' && in[i+2] == 'd') 
            flag = 2;

        else if (flag == 2 && in[i] == '>') 
            flag = 3;

        else if (flag == 3 && in[i] == '<') 
            cExtraArrow++;

        else if (flag == 3 && in[i] == '>') {
            cExtraArrow--;

            if (cExtraArrow == 0 && nInfor == 7 && in[i + 1] == '<') {
                // printf(" \n");
                count += 1;
                buffer = realloc(buffer, count);
                buffer[count - 1] = '\0';
                add(s, nInfor, buffer);
                buffer = NULL;
                nInfor += 1;
                count = 0;
                flag = 1;
            }   
        }

        else if (flag == 3 && in[i] != '\n' && in[i] != '\r' && cExtraArrow == 0) {
            // printf("%c", in[i]);
            count += 1;
            buffer = realloc(buffer, count);
            buffer[count - 1] = in[i];

            if (in[i + 1] == '<') {
                // printf("\n");
                flag = 1;
                count += 1;
                buffer = realloc(buffer, count);
                buffer[count - 1] = '\0';
                // printf("%s\t%i\n", buffer, count);
                add(s, nInfor, buffer);
                buffer = NULL;
                count = 0;
                nInfor += 1;
            }

            if (nInfor == 15) {
                // printf("//////////\n");
                addSubject(s);
                nSubjects++;
                nInfor = 0;
            }    

            if (nSubjects == 13) {
                flag = -1;
                return bytes;
            }
        }
    }
    return bytes;
}

void getDataFromWeb(void) {
    CURL *curl;
    CURLcode code;

    char sessionID[200];
    FILE *fp =  fopen("sessionID.ssid", "r");
    fscanf(fp, "%199s", sessionID);
    fclose(fp);

    char header[250];
    sprintf(header, "Cookie: ASP.NET_SessionId=%s", sessionID);

    curl = curl_easy_init();
    if (curl) {
        struct curl_slist *chunk = NULL;
        chunk = curl_slist_append(chunk, header);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
        curl_easy_setopt(curl, CURLOPT_URL, "https://qldt.ptit.edu.vn/default.aspx?page=thoikhoabieu&sta=1");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, parser);

        code = curl_easy_perform(curl);
        if(code != CURLE_OK) perror("Failed to request");

        curl_easy_cleanup(curl);   
        curl_slist_free_all(chunk);    
    }
}

int main (void) {

    FILE *fp = fopen("rawSubject.json", "w");
    fprintf(fp, "[]");
    fclose(fp);

    getDataFromWeb();
    return 0;
}
