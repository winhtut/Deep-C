//
// Created by National Cyber City on 1/21/2024.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct {
    int id;
    char name[20];
    float salary;
}Employee;

void writeEmployeeToFile(const char *filename , Employee *employee ,size_t count ){
    FILE *file = fopen(filename,"wb");
    if(!file){
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    fwrite(employee,sizeof(Employee),count,file );
    fclose(file);

}

void readEmployeeFromFile(const char *filename){

    FILE *file = fopen(filename,"rb");

    Employee emp;
    if(!file){
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    while (fread(&emp,sizeof(Employee),1,file)==1){
        printf(" ID: %d , Name : %s , Salary: %.2f\n",emp.id,emp.name,emp.salary);
    }
    fclose(file);
}

Employee* findEmployeeByName(const char *filename , const char *name){

    FILE *file = fopen(filename,"rb");
    static Employee emp;
    int found=0;

    if(!file){
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    while (fread(&emp,sizeof(Employee),1,file )==1){
        if(strcmp(emp.name,name)==0){
            found=1;
            break;
        }
    }
    fclose(file);
    if(found){
        return &emp;

    } else{
        return NULL;
    }

}

int main(){
    Employee employees[]={
            {1,"Alice",70000.0},
            {2,"Bob",55000.0},
            {3,"Charlie",60000.0}
    };
    writeEmployeeToFile("employees.bin",employees,3);
    readEmployeeFromFile("employees.bin");

    Employee *emp = findEmployeeByName("employees.bin","WinHtut");
    if(emp!=NULL){
        printf("\nFound: ID: %d,Name:%s,Salary:%.2f\n",emp->id,emp->name,emp->salary);

    } else{
        printf("\nEmployee not found.\n");
    }
    return 0;
}