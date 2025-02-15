#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "/var/log/syslog"
#define MAX_LINE 512

// Baðlý liste düðümü
typedef struct LogNode {
    char message[MAX_LINE];
    struct LogNode* next;
} LogNode;

// Baðlý listeye eleman ekleme
void insertLog(LogNode** head, const char* logMessage) {
    LogNode* newNode = (LogNode*)malloc(sizeof(LogNode));
    if (!newNode) {
        perror("Bellek tahsis hatasý");
        return;
    }
    strncpy(newNode->message, logMessage, MAX_LINE);
    newNode->next = *head;
    *head = newNode;
}

// Baðlý listedeki loglarý yazdýrma
void displayLogs(LogNode* head) {
    LogNode* current = head;
    while (current) {
        printf("%s", current->message);
        current = current->next;
    }
}

// Baðlý listeyi temizleme
void freeList(LogNode* head) {
    LogNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "/var/log/syslog"
#define MAX_LINE 512

// BaÄŸli liste duÄŸumu
typedef struct LogNode {
    char message[MAX_LINE];
    struct LogNode* next;
} LogNode;

// BaÄŸli listeye eleman ekleme
void insertLog(LogNode** head, const char* logMessage) {
    LogNode* newNode = (LogNode*)malloc(sizeof(LogNode));
    if (!newNode) {
        perror("Bellek tahsis hatasi");
        return;
    }
    strncpy(newNode->message, logMessage, MAX_LINE);
    newNode->next = *head;
    *head = newNode;
}

// BaÄŸli listedeki loglari yazdirma
void displayLogs(LogNode* head) {
    LogNode* current = head;
    while (current) {
        printf("%s", current->message);
        current = current->next;
    }
}

// BaÄŸli listeyi temizleme
void freeList(LogNode* head) {
    LogNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Syslog dosyasini okuyarak baÄŸli listeye ekleme
void readSyslog(LogNode** head) {
    FILE* file = fopen(LOG_FILE, "r");
    if (!file) {
        perror("Syslog dosyasi aÃ§ilamadi");
        return;
    }
    char buffer[MAX_LINE];
    while (fgets(buffer, MAX_LINE, file)) {
        insertLog(head, buffer);
    }
    fclose(file);
}

int main() {
    LogNode* logList = NULL;
    printf("Syslog dosyasindan veriler okunuyor...\n");
    readSyslog(&logList);
    printf("\n--- Syslog Kayitlari ---\n");
    displayLogs(logList);
    freeList(logList);
    return 0;
}
}

// Syslog dosyasini okuyarak bagli listeye ekleme
void readSyslog(LogNode** head) {
    FILE* file = fopen(LOG_FILE, "r");
    if (!file) {
        perror("Syslog dosyasý açýlamadý");
        return;
    }
    char buffer[MAX_LINE];
    while (fgets(buffer, MAX_LINE, file)) {
        insertLog(head, buffer);
    }
    fclose(file);
}

int main() {
    LogNode* logList = NULL;
    printf("Syslog dosyasýndan veriler okunuyor...\n");
    readSyslog(&logList);
    printf("\n--- Syslog Kayýtlarý ---\n");
    displayLogs(logList);
    freeList(logList);
    return 0;
}

