#include <json-c/json.h>
#include <stdio.h>
#include "includes/data.h"
#include <curl/curl.h>
#include "includes/parser.h"
#include <string.h>


void addSubject(rawSubject *s) {

    // printf("%s\n", s->ID);
    // printf("%s\n", s->name);
    // printf("%s\n", s->groupID);
    // printf("%s\n", s->STC_1);
    // printf("%s\n", s->classID);
    // printf("%s\n", s->STC_2);
    // printf("%s\n", s->KDK);
    // printf("%s\n", s->TH);
    // printf("%s\n", s->day);
    // printf("%s\n", s->ST);
    // printf("%s\n", s->className);
    // printf("%s\n", s->calender);
    // printf("%s\n", s->DSSV);

    FILE *fp = fopen("data.json", "w");
    fprintf(fp, "[]");
    fclose(fp);

    json_object *data;
    json_object *newSubject = json_object_new_object();
    json_object *newID = json_object_new_string(s->ID);
    json_object *newName = json_object_new_string(s->name);
    json_object *newGroupID = json_object_new_string(s->groupID);
    json_object *newSTC_1 = json_object_new_string(s->STC_1);
    json_object *newClassID = json_object_new_string(s->classID);
    json_object *newSTC_2 = json_object_new_string(s->STC_2);
    json_object *newKDK = json_object_new_string(s->KDK);
    json_object *newTH = json_object_new_string(s->TH);
    json_object *newDay = json_object_new_string(s->day);
    json_object *newTime = json_object_new_string(s->time);
    json_object *newST = json_object_new_string(s->ST);
    json_object *newClassName = json_object_new_string(s->className);
    json_object *newCalendar = json_object_new_string(s->calendar);
    json_object *newDSSV = json_object_new_string(s->DSSV);

    json_object_object_add(newSubject, "ID", newID);
    json_object_object_add(newSubject, "Name", newName);
    json_object_object_add(newSubject, "GroupID", newGroupID);
    json_object_object_add(newSubject, "STC_1", newSTC_1);
    json_object_object_add(newSubject, "ClassID", newClassID);
    json_object_object_add(newSubject, "STC_2", newSTC_2);
    json_object_object_add(newSubject, "KDK", newKDK);
    json_object_object_add(newSubject, "TH", newTH);
    json_object_object_add(newSubject, "Day", newDay);
    json_object_object_add(newSubject, "Time", newTime);
    json_object_object_add(newSubject, "ST", newST);
    json_object_object_add(newSubject, "ClassName", newClassName);
    json_object_object_add(newSubject, "Calender", newCalendar);
    json_object_object_add(newSubject, "DSSV", newDSSV);

    data = json_object_from_file("data.json");
    json_object_array_add(data, newSubject);
    json_object_to_file("data.json", data);
}


void add(rawSubject *s, int pos, char *buffer) {
    switch (pos)
    {
        case 0:
            s->ID = buffer;
            break;
        case 1:
            s->name = buffer;
            break;
        case 2:
            s->groupID = buffer;
            break;
        case 3:
            s->STC_1 = buffer;
            break;
        case 4:
            s->classID = buffer;
            break;
        case 5:
            s->STC_2 = buffer;
            break;
        case 6:
            s->KDK = buffer;
            break;
        case 7:
            s->TH = buffer;
            break;
        case 8:
            s->day = buffer;
            break;
        case 9:
            s->time = buffer;
            break;
        case 10:
            s->ST = buffer;
            break;
        case 11:
            s->className = buffer;
            break;
        case 12:
            s->CBGV = buffer;
            break;
        case 13:
            s->calendar = buffer;
            break;
        case 14:
            s->DSSV = buffer;
            break;
    }
}

void dataProcess(subject *s) {

    // json_object *database, *rawName, *rawGroupID, *rawDay, *rawTime, *rawST, *rawClassName, *rawCalendar, *rawSub;
    // size_t nOfSub;

    // database = json_object_from_file("data.json");
    // nOfSub = json_object_array_length(database);

    // for (int sub = 0; sub < nOfSub; sub++) {
    //     rawSub = json_object_array_get_idx(database, sub);
    //     rawName = json_object_object_get(rawSub, "Name");
    //     rawGroupID = json_object_object_get(rawSub, "GroupID");
    //     rawDay = json_object_object_get(rawSub, "Day");
    //     rawTime = json_object_object_get(rawSub, "Time");
    //     rawST = json_object_object_get(rawSub, "ST");
    //     rawClassName = json_object_object_get(rawSub, "ClassName");
    //     rawCalendar = json_object_object_get(rawSub, "Calendar");

        // strcmps->name, "%s %s", json_object_get_string(rawSub), json_object_get_string(rawClassName));
        // strcat(s->name, json_object_get_string(rawSub));
        // strcat(s->name, json_object_get_string(rawClassName));


        sprintf(s->nameOfSub, "anhyeuem");
        // int startTime, endTime;
        // char *calendar = json_object_get_string(rawCalendar);
        // for (int week = 0; week < strlen(calendar); week++) {
        //     if (isDigit(calendar[week])) {
        //         char date[] = "2022-08-15";
        //         dateUpdater(date, week*7);
        //         dateUpdater(date, dayConvert(json_object_get_string(rawDay)));
        //         startTime = startTimeGener(json_object_get_string(rawTime));
        //         endTime = endTimeGener(json_object_get_string(rawTime), json_object_get_string(rawST));
        //         if (startTime >= 10) 
        //             sprintf(s->startTime, "%sT%i:00:00+07:00", date, startTime);
        //         else 
        //             sprintf(s->startTime, "%sT0%i:00:00+07:00", date, startTime);
        //         if (endTime >= 10) 
        //             sprintf(s->endTime, "%sT%i:50:00+07:00", date, endTime);
        //         else 
        //             sprintf(s->endTime, "%sT0%i:50:00+07:00", date, endTime);

        //         dataUploader(s);
        //     }
        // }
    // }
}

int dayConvert(const char *rawDay) {
    if (!strcmp(rawDay, "Hai")) return 0;
    if (!strcmp(rawDay, "Ba")) return 1;
    if (!strcmp(rawDay, "Bốn")) return 2;
    if (!strcmp(rawDay, "Năm")) return 3;
    if (!strcmp(rawDay, "Sáu")) return 4;
    if (!strcmp(rawDay, "Bảy")) return 5;
    if (!strcmp(rawDay, "CN")) return 6;
}

int isDigit(char ch) {
    if (ch >= '0' && ch <= '9') return 1;
    return 0;
}

void dateUpdater(char *date, int dayIsRaised) {
    int year, month, day, count = 0;
    char *token = strtok(date, "-");
    while (token != NULL) {
        if (count == 0) year = atoi(token);
        if (count == 1) month = atoi(token);
        if (count == 2) day = atoi(token);
        count++;
    }
    
    day += dayIsRaised;

    if (dayThisMonthHas(month) == 0 && day > 31) {
        day -= 31;
        month += 1;
        if (month > 12) {
            month -= 12;
            year += 1;
        }
    }
    else if (dayThisMonthHas(month) == 1 && day > 30) {
        day -= 30;
        month += 1;
    }
    else {
        if (year % 4 == 0 && year % 100 != 0 && day > 29) {
            day -= 29;
            month += 1;
        } 
        else if (day > 28) {
            day -= 28;
            month += 1;
        }
    }
    sprintf(date, "%i-%i-%i", year, month, day);
}

int dayThisMonthHas(int month) {
    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 0;
            break;

        case 4:
        case 9:
        case 6:
        case 11:
            return 1;
            break;

        case 2:
            return 3;
            break;
    }
}

int startTimeGener(const char *rawTime) {   
    switch (atoi(rawTime))
    {
    case 1:
        return 7;
        break;
    case 3:
        return 9;
        break;
    case 5:
        return 12;
        break;
    case 7:
        return 14;
        break;
    case 9:
        return 16;
        break;
    case 11:
        return 18;
        break;
    }
}

int endTimeGener(const char *rawTime, const char *rawST) {   
    switch (atoi(rawTime))
    {
    case 1:
        return 7 + atoi(rawST);
        break;
    case 3:
        return 9 + atoi(rawST);
        break;
    case 5:
        return 12 + atoi(rawST);
        break;
    case 7:
        return 14 + atoi(rawST);
        break;
    case 9:
        return 16 + atoi(rawST);
        break;
    case 11:
        return 18 + atoi(rawST);
        break;
    }
}



void dataUploader(subject *s) {
    CURL *curl;
    CURLcode res;

    char *paramaterJson;
    sprintf (paramaterJson, "{\"summary\":\"%s\",\"end\":{\"dateTime\":\"%s\",\"timeZone\":\"Asia/Ho_Chi_Minh\"},\"start\":{\"dateTime\":\"%s\",\"timeZone\":\"Asia/Ho_Chi_Minh\"}}", s->nameOfSub, s->endTime, s->startTime);

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl) {
        struct curl_slist *chunk = NULL;
        chunk = curl_slist_append(chunk, "Authorization: Bearer ya29.a0Aa4xrXNniMv0tbYP-o7JOGivxAhKBz0CsxpJKpwu0QU4U7fWOW4pQ3aqin36O8lmYSvRBA5JrG5TuKqcEl1xJNzok7uWjZf_gMRrYefyCr55Xrh95Z1sJ_GA69N1TlAv58ylO7FqztrBeRHYB6yiYuk-LFxQaCgYKATASARISFQEjDvL9IRsAaHOLcmN-EpMwwu3Cgw0163");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.googleapis.com/calendar/v3/calendars/primary/events/");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, paramaterJson);

        res = curl_easy_perform(curl);

    /* Check for errors */ 
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));

    /* always cleanup */ 
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

void getDataFromWeb(void) {
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
}

void clearData(char *fileName) {
    FILE *fp = fopen(fileName, "w"); 
    fclose(fp);
}


void getAccessToken(char *argv[]) {
    CURL *curl;
    CURLcode res;
    clearData("access_token.json");

    char *paramaterInNeed;
    sprintf(paramaterInNeed, "client_id=812237032448-g3s99dj31nlt7i9hp1f2beltkc8rirhk.apps.googleusercontent.com&code=%s&client_secret=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&redirect_uri=urn:ietf:wg:oauth:2.0:oob&grant_type=authorization_code", argv[1]);
    
    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl) {
        struct curl_slist *chunk = NULL;
        chunk = curl_slist_append(chunk, "Content-type: application/x-www-form-urlencoded");
        chunk = curl_slist_append(chunk, "Cache-Control: no-cache");

        curl_easy_setopt(curl, CURLOPT_URL, "https://accounts.google.com/o/oauth2/v2/auth");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
        curl_easy_setopt(curl, CURLOPT_URL, "https://accounts.google.com/o/oauth2/token");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, paramaterInNeed);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, saveAccessToken);
        
        res = curl_easy_perform(curl);


        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

size_t saveAccessToken(char *in, size_t nmem, size_t nitems, void* out) {
    size_t bytes = nmem * nitems;
    FILE *fp = fopen("access_token.json", "a"); 
    fprintf(fp, "%s", in);
    fclose(fp);
    return bytes;
}