#include <json-c/json.h>
#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"
#include "../auth/auth.h"


void addSubject(rawSubject *s) {
    
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

    data = json_object_from_file("./crawler/rawSubject.json");
    json_object_array_add(data, newSubject);
    json_object_to_file("./crawler/rawSubject.json", data);
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

void updateCalendar(subject *s) {

    clearData("../check.log");

    json_object *database, *rawName, *rawGroupID, *rawDay, *rawTime, *rawST, *rawClassName, *rawCalendar, *rawSub;
    size_t nOfSub;

    database = json_object_from_file("./crawler/rawSubjects.json");
    nOfSub = json_object_array_length(database);

    for (int sub = 0; sub < nOfSub; sub++) {
        rawSub = json_object_array_get_idx(database, sub);
        rawName = json_object_object_get(rawSub, "Name");
        rawGroupID = json_object_object_get(rawSub, "GroupID");
        rawDay = json_object_object_get(rawSub, "Day");
        rawTime = json_object_object_get(rawSub, "Time");
        rawST = json_object_object_get(rawSub, "ST");
        rawClassName = json_object_object_get(rawSub, "ClassName");
        rawCalendar = json_object_object_get(rawSub, "Calendar");

        sprintf(s->name, "%s x %s", json_object_get_string(rawName), json_object_get_string(rawClassName));
        int startTime, endTime;
        char date[] = "2022-08-15";
        const char *calendar = json_object_get_string(rawCalendar);
        for (int week = 0; week < strlen(calendar); week++) {
            if (week != 0) dateUpdater(date, 7);
            if (isDigit(calendar[week])) {
                char *dateClone = strdup(date);
                dateUpdater(dateClone, dayConvert(json_object_get_string(rawDay))); 
                startTime = startTimeGener(json_object_get_string(rawTime));
                endTime = endTimeGener(json_object_get_string(rawTime), json_object_get_string(rawST));
                if (startTime >= 10) 
                    sprintf(s->startTime, "%sT%i:00:00+07:00", dateClone, startTime);
                else 
                    sprintf(s->startTime, "%sT0%i:00:00+07:00", dateClone, startTime);
                if (endTime >= 10) 
                    sprintf(s->endTime, "%sT%i:50:00+07:00", dateClone, endTime);
                else 
                    sprintf(s->endTime, "%sT0%i:50:00+07:00", dateClone, endTime);

                calendarEventRes(s);
                checkLog(s);
            }
        }
    }
}

int dayConvert(const char *rawDay) {
    if (!strcmp(rawDay, "Hai")) return 0;
    if (!strcmp(rawDay, "Ba")) return 1;
    if (!strcmp(rawDay, "Tư")) return 2;
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
    if (dayIsRaised == 0) return;
    int year, month, day, count = 0;
    char *token = strtok(date, "-");
    while (token != NULL) {
        if (count == 0) year = atoi(token);
        if (count == 1) month = atoi(token);
        if (count == 2) day = atoi(token);
        count++;
        token = strtok(NULL, "-");
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
    else if (dayThisMonthHas(month == 2)) {
        if (year % 4 == 0 && year % 100 != 0 && day > 29) {
            day -= 29;
            month += 1;
        } 
        else if (day > 28) {
            day -= 28;
            month += 1;
        }
    }
    if (month < 10 && day < 10) 
        sprintf(date, "%i-0%i-0%i", year, month, day);
    else if (month < 10)     
        sprintf(date, "%i-0%i-%i", year, month, day);
    else if (day < 10)
        sprintf(date, "%i-%i-0%i", year, month, day);
    else 
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
            return 2;
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
        return 7 + atoi(rawST) - 1;
        break;
    case 3:
        return 9 + atoi(rawST) - 1;
        break;
    case 5:
        return 12 + atoi(rawST) - 1;
        break;
    case 7:
        return 14 + atoi(rawST) - 1;
        break;
    case 9:
        return 16 + atoi(rawST) - 1;
        break;
    case 11:
        return 18 + atoi(rawST) - 1;
        break;
    }
}

void checkLog(subject *s) {
    FILE *fp = fopen("../check.log", "a");
    fprintf(fp, "%s\t%s\t%s\n", s->name, s->startTime, s->endTime);
    fclose(fp);
}

void clearData(char *fileName) {
    FILE *fp = fopen(fileName, "w"); 
    fclose(fp);
}

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