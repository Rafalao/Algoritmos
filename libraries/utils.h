#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h> //NEW

typedef struct USER {
    unsigned long int id;
    char* name;
    char* password;
    char* info;
    struct USER* nextUser;
}user;

user* createUser(char* name, char* password, char* info){
    user* newUserNode = (user*)malloc(sizeof(user));
    newUserNode->id = rand()%200000;
    newUserNode->name = name;
    newUserNode->password = password;
    newUserNode->info =  info;
    newUserNode->nextUser = NULL;
    return newUserNode;
}

void addUser(user** userList, user* aUserToadd){
    if ( *userList == NULL) {
        return;
    }
    if ( (*userList)->nextUser == NULL ) {
        (*userList)->nextUser =  aUserToadd;
    };
}

//NEW//
void sleep(size_t m_s){  
    m_s = m_s/1;
    clock_t initial_time = time(NULL); //Tiempo inicial//
    clock_t desired_time = initial_time + m_s ;
    for(clock_t current_time = initial_time; current_time < desired_time; current_time = time(NULL) ){};
}
