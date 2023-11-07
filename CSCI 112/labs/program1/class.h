
typedef struct {
    char ctitle[60];
    char cnumber[15];
    char cproflast[30];
    char cproffirst[30]; //init all struct vars as char arrays(strings)
    char cseats[15];
    char cdate[15];
    char ctime[15];
} Class;

int userQuery(char *line[], Class classes[], int size);
void makeStruct(char *line[], Class classes[], int size);
void printNum(char* numin, Class classes[], int size);      //methods
void printDate(char* datein, Class classes[], int size);
void printProf(char* profin, Class classes[], int size);


