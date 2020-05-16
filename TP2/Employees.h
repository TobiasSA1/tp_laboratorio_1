typedef struct
{
    int id;
    int sector;
    float salary;
    char name[51];
    char lastName[51];
    int isEmpty;
}eEmployee;


int salary(eEmployee ArrayEmployees[], int tam);

int searchFree(eEmployee ArrayEmployees[], int tam);

eEmployee addEmployee();

int removeEmployee(eEmployee ArrayEmployees[], int tam);

int modifyEmployees(eEmployee ArrayEmployees[], int tam);

void printEmployees();

void printAllEmployees(eEmployee ArrayEmployees[],int tam);

void initializeState(eEmployee ArrayEmployees[], int tam);

void loadListEmployees(eEmployee ArrayEmployees[], int tam);

void sortEmployeesByName_Sector(eEmployee ArrayEmployees[], int tam);
