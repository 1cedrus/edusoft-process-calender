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
    char nameOfSub[100];
    char startTime[50];
    char endTime[50];
} subject;


void dataProcess(subject *s);
void add(rawSubject *s, int pos, char *buffer);
void addSubject(rawSubject *s);
void dataUploader(subject *s);
int endTimeGener(const char *rawTime, const char *rawST);
int startTimeGener(const char *rawTime);
int dayThisMonthHas(int month);
void dateUpdater(char *date, int dayIsRaised);
int dayConvert(const char *rawDay);
int isDigit(char ch);
size_t saveAccessToken(char *in, size_t nmem, size_t nitems, void* out);