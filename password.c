#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX_NOTES 100 
#define MAX_PASSWORDS 100 
#define TITLE_SIZE 50 
#define CONTENT_SIZE 256 
#define SITE_SIZE 50 
#define USERNAME_SIZE 50 
#define PASSWORD_SIZE 50 
typedef struct { 
char title[TITLE_SIZE]; 
char content[CONTENT_SIZE]; 
} Note; 
typedef struct { 
char site[SITE_SIZE]; 
char username[USERNAME_SIZE]; 
char password[PASSWORD_SIZE]; 
} Password; 

typedef struct { 
Note notes[MAX_NOTES]; 
Password passwords[MAX_PASSWORDS]; 
int note_count; 
int password_count; 
} NotePasswordManager; 
void add_note(NotePasswordManager *manager, const char *title, const 
char *content) { 
if (manager->note_count < MAX_NOTES) { 
strcpy(manager->notes[manager->note_count].title, title); 
strcpy(manager->notes[manager->note_count].content, content); 
manager->note_count++; 
printf("Note '%s' added.\n", title); 
} else { 
printf("Max notes limit reached.\n"); 
} 
} 
void view_notes(NotePasswordManager *manager) { 
if (manager->note_count == 0) { 
printf("No notes available.\n"); 
return; 
} 
for (int i = 0; i < manager->note_count; i++) { 
printf("Title: %s\nContent: %s\n\n", manager->notes[i].title, 
manager->notes[i].content); 

} 
} 
void add_password(NotePasswordManager *manager, const char *site, 
const char *username, const char *password) { 
if (manager->password_count < MAX_PASSWORDS) { 
strcpy(manager->passwords[manager->password_count].site, site); 
strcpy(manager->passwords[manager->password_count].username, 
username); 
strcpy(manager->passwords[manager->password_count].password, 
password); 
manager->password_count++; 
printf("Password for '%s' added.\n", site); 
} else { 
printf("Max passwords limit reached.\n"); 
} 
} 
void view_passwords(NotePasswordManager *manager) { 
if (manager->password_count == 0) { 
printf("No passwords stored.\n"); 
return; 
} 
for (int i = 0; i < manager->password_count; i++) { 
printf("Site: %s\nUsername: %s\nPassword: %s\n\n", manager
>passwords[i].site, manager->passwords[i].username, manager
>passwords[i].password); 

} 
} 
void delete_note(NotePasswordManager *manager, const char *title) { 
for (int i = 0; i < manager->note_count; i++) { 
if (strcmp(manager->notes[i].title, title) == 0) { 
for (int j = i; j < manager->note_count - 1; j++) { 
manager->notes[j] = manager->notes[j + 1]; 
} 
manager->note_count--; 
printf("Note '%s' deleted.\n", title); 
return; 
} 
} 
printf("Note not found.\n"); 
} 
void delete_password(NotePasswordManager *manager, const char *site) 
{ 
for (int i = 0; i < manager->password_count; i++) { 
if (strcmp(manager->passwords[i].site, site) == 0) { 
for (int j = i; j < manager->password_count - 1; j++) { 
manager->passwords[j] = manager->passwords[j + 1]; 
} 
manager->password_count--; 
printf("Password for '%s' deleted.\n", site); 
return; 

} 
} 
printf("Password not found.\n"); 
} 
int main() { 
NotePasswordManager manager = { .note_count = 0, .password_count 
= 0 }; 
int choice; 
char title[TITLE_SIZE], content[CONTENT_SIZE], site[SITE_SIZE], 
username[USERNAME_SIZE], password[PASSWORD_SIZE]; 
while (1) { 
printf("\n--- Notes and Password Management System ---\n"); 
printf("1. Add Note\n"); 
printf("2. View Notes\n"); 
printf("3. Add Password\n"); 
printf("4. View Passwords\n"); 
printf("5. Delete Note\n"); 
printf("6. Delete Password\n"); 
printf("7. Exit\n"); 
printf("Choose an option: "); 
scanf("%d", &choice); 
getchar(); // consume newline 
switch (choice) { 
case 1: 
                printf("Enter note title: "); 
                fgets(title, TITLE_SIZE, stdin); 
                title[strcspn(title, "\n")] = 0; // remove newline 
                printf("Enter note content: "); 
                fgets(content, CONTENT_SIZE, stdin); 
                content[strcspn(content, "\n")] = 0; 
                add_note(&manager, title, content); 
                break; 
            case 2: 
                view_notes(&manager); 
                break; 
            case 3: 
                printf("Enter site name: "); 
                fgets(site, SITE_SIZE, stdin); 
                site[strcspn(site, "\n")] = 0; 
                printf("Enter username: "); 
                fgets(username, USERNAME_SIZE, stdin); 
                username[strcspn(username, "\n")] = 0; 
                printf("Enter password: "); 
                fgets(password, PASSWORD_SIZE, stdin); 
                password[strcspn(password, "\n")] = 0; 
                add_password(&manager, site, username, password); 
                break; 
            case 4: 
                view_passwords(&manager); 
                break; 
            case 5: 
                printf("Enter note title to delete: "); 
                fgets(title, TITLE_SIZE, stdin); 
                title[strcspn(title, "\n")] = 0; 
                delete_note(&manager, title); 
                break; 
            case 6: 
                printf("Enter site name to delete password: "); 
                fgets(site, SITE_SIZE, stdin); 
                site[strcspn(site, "\n")] = 0; 
                delete_password(&manager, site); 
                break; 
            case 7: 
                printf("Exiting the system.\n"); 
                exit(0); 
            default: 
                printf("Invalid option. Please try again.\n"); 
        } 
    } 
 
    return 0;
