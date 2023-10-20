#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char yourName[10];
    char yourPassword[10];
    union {
        int flag;
        char flag_string[4];
    } flag;
};

struct User users[10];
int userCount = 0;

void addUser(char *yourName, char *yourPassword);
void registerUser();
int login(char *yourName, char *password);

int main() {
    registerUser(); 

    char yourName[20];
    char yourPassword[20];

    printf("Enter your username: ");
    scanf("%s", yourName);

    printf("Enter your password: ");
    scanf("%s", yourPassword);

    if (login(yourName, yourPassword) == 1) {
        printf("Login successfully.\n");
    } else {
        printf("incorrect username or password,try again.\n");
    }

    return 0;
}

void addUser(char *yourName, char *yourPassword) {
    if (userCount >= 10) {
        printf("Maximum user limit reached.\n");
        return;
    }

    strcpy(users[userCount].yourName, yourName);
    strcpy(users[userCount].yourPassword, yourPassword);
    userCount++;
}

void registerUser() {
    char yourName[10];
    char yourPassword[20];
    char flag_string[4];

    printf("Enter a username for registration: ");
    scanf("%s", yourName);

    printf("Enter a password: ");
    scanf("%s", yourPassword);

    printf("Enter '1' to activa the account, or '0' to deactiva it: ");
    scanf("%s", flag_string);

    if (strcmp(flag_string, "true") == 0 || strcmp(flag_string, "1") == 0) {
        users[userCount].flag.flag = 1;
    } else if (strcmp(flag_string, "false") == 0 || strcmp(flag_string, "0") == 0) {
        users[userCount].flag.flag = 0;
    } else {
        printf("Invalid flag value.\n");
        return;
    }

    addUser(yourName, yourPassword);
}

int login(char *yourName, char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].yourName, yourName) == 0 && strcmp(users[i].yourPassword, password) == 0 && users[i].flag.flag == 1) {
            return 1;
        }
    }
    return 0;
}
