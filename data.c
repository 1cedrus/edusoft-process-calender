#include <json-c/json.h>
#include <stdio.h>
#include "includes/data.h"


void addSubject(subject *s) {

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
    json_object *newCalender = json_object_new_string(s->calender);
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
    json_object_object_add(newSubject, "Calender", newCalender);
    json_object_object_add(newSubject, "DSSV", newDSSV);

    data = json_object_from_file("data.json");
    json_object_array_add(data, newSubject);
    json_object_to_file("data.json", data);
}


void add(subject *s, int pos, char *buffer) {
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
            s->calender = buffer;
            break;
        case 14:
            s->DSSV = buffer;
            break;
    }
}