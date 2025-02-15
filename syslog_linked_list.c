#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "/var/log/syslog"
#define MAX_LINE 512

// Ba�l� liste d���m�
typedef struct LogNode {
    char message[MAX_LINE];
    struct LogNode* next;
} LogNode;

// Ba�l� listeye eleman ekleme
void insertLog(LogNode** head, const char* logMessage) {
    LogNode* newNode = (LogNode*)malloc(sizeof(LogNode));
    if (!newNode) {
        perror("Bellek tahsis hatas�");
        return;
    }
    strncpy(newNode->message, logMessage, MAX_LINE);
    newNode->next = *head;
    *head = newNode;
}

// Ba�l� listedeki loglar� yazd�rma
void displayLogs(LogNode* head) {
    LogNode* current = head;
    while (current) {
        printf("%s", current->message);
        current = current->next;
    }
}

// Ba�l� listeyi temizleme
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

// Bağli liste duğumu
typedef struct LogNode {
    char message[MAX_LINE];
    struct LogNode* next;
} LogNode;

// Bağli listeye eleman ekleme
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

// Bağli listedeki loglari yazdirma
void displayLogs(LogNode* head) {
    LogNode* current = head;
    while (current) {
        printf("%s", current->message);
        current = current->next;
    }
}

// Bağli listeyi temizleme
void freeList(LogNode* head) {
    LogNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Syslog dosyasini okuyarak bağli listeye ekleme
void readSyslog(LogNode** head) {
    FILE* file = fopen(LOG_FILE, "r");
    if (!file) {
        perror("Syslog dosyasi açilamadi");
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
        perror("Syslog dosyas� a��lamad�");
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
    printf("Syslog dosyas�ndan veriler okunuyor...\n");
    readSyslog(&logList);
    printf("\n--- Syslog Kay�tlar� ---\n");
    displayLogs(logList);
    freeList(logList);
    return 0;
}

