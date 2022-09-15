#include <curl/curl.h>
#include <stdlib.h>
#include <json-c/json.h>
#include "includes/data.h"
// #include <string.h>

// char infor[13][15][200];

// void show() {
//     for (int i = 0; i < 13; i++) {
//         for (int j = 0; i < 15; i++) {
//             printf("%s\n", infor[i][j]);
//         }
//         printf("//////\n");
//     }
// }
subject *s = NULL;
char *buffer = NULL;    

size_t parser(char *in, size_t nmem, size_t nitems, void* out) {
    // printf("%li\n", nmem);
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
                printf(" \n");
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
            printf("%c", in[i]);
            count += 1;
            buffer = realloc(buffer, count);
            buffer[count - 1] = in[i];

            if (in[i + 1] == '<') {
                printf("\n");
                flag = 1;
                count += 1;
                buffer = realloc(buffer, count);
                buffer[count - 1] = '\0';
                printf("%s\t%i\n", buffer, count);
                add(s, nInfor, buffer);
                // free(buffer);
                buffer = NULL;
                count = 0;
                nInfor += 1;
            }

            if (nInfor == 15) {
                printf("//////////\n");
                addSubject(s);
                // // free(s);
                // s = NULL;
                // s = malloc(sizeof(subject));
                nSubjects++;
                nInfor = 0;
                // continue;
            }    

            if (nSubjects == 13) {
                flag = -1;
                // printf("%s", data);
                return bytes;
            }
        }
    }
    return bytes;
}

int main(void) {
    CURL *curl;
    CURLcode code;

    curl = curl_easy_init();
    if (curl) {
        struct curl_slist *chunk = NULL;
        chunk = curl_slist_append(chunk, "Cookie: ASP.NET_SessionId=mpgost55ka031445a3sktx45");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
        curl_easy_setopt(curl, CURLOPT_URL, "https://qldt.ptit.edu.vn/default.aspx?page=thoikhoabieu&sta=1");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, parser);

        code = curl_easy_perform(curl);
        if(code != CURLE_OK) 
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(code));

        curl_easy_cleanup(curl);   
        curl_slist_free_all(chunk);    
    }

    return 0;
}