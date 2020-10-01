typedef struct{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
}eEmployee;

int initEmployees(eEmployee ArrayEmployees[], int tam);
int printEmployees(eEmployee miEmployee);
int printAllEmployees(eEmployee ArrayEmployees[], int tam);

void loadListEmployees(eEmployee ArrayEmployees[], int tam,int legajo);
int searchFree(eEmployee ArrayEmployees[],int tam);
eEmployee addEmployee();

int removeEmployee(eEmployee ArrayEmployees[], int tam,int id);
int modifyEmployees(eEmployee ArrayEmployees[], int tam);
int sortEmployeesByName_Sector(eEmployee ArrayEmployees[], int tam);
int salary(eEmployee ArrayEmployees[], int tam);
int findEmployeeById(eEmployee ArrayEmployees[], int tam,int id);
