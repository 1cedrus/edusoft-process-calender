#include <curl/curl.h>

char infor[13][15][200];

size_t parser(char *in, size_t nmem, size_t nitems, void* out) {
    size_t bytes = nmem * nitems;
    static int flag = 0, cExtraArrow = 0, nSubjects = 0, nInfor = 0;  

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
                nInfor++;
                flag = 1;
            }   
        }

        else if (flag == 3 && in[i] != '\n' && in[i] != '\r' && cExtraArrow == 0) {
            printf("%c", in[i]);

            if (in[i + 1] == '<') {
                printf("\n");
                flag = 1;
                nInfor++;
            }

            if (nInfor == 15) {
                printf("//////////\n");
                nSubjects++;
                nInfor = 0;
                continue;
            }    

            if (nSubjects == 13) {
                flag = -1;
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