// 
typedef struct {
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
    char *calendar;
    char *DSSV;
} rawSubject;

typedef struct {
    char name[100];
    char startTime[50];
    char endTime[50];
} subject;
//
// Public
void updateCalendar(subject *s);
void calendarEventRes(subject *s);
void clearData(char *fileName);

// Private
void add(rawSubject *s, int pos, char *buffer);
void addSubject(rawSubject *s);
int endTimeGener(const char *rawTime, const char *rawST);
int startTimeGener(const char *rawTime);
int dayThisMonthHas(int month);
void dateUpdater(char *date, int dayIsRaised);
int dayConvert(const char *rawDay);
int isDigit(char ch);
void checkLog(subject *s);