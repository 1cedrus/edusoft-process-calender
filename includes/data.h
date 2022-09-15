typedef struct subject {
    char *ID;
    char *name;
    char *groupID;
    char *STC_1;
    char *classID;
    char *STC_2;
    char *KDK;
    char *TH;
    char *day;
    char *time;
    char *ST;
    char *className;
    char *CBGV;
    char *calender;
    char *DSSV;
} subject;


void add(subject *s, int pos, char *buffer);
void addSubject(subject *s);