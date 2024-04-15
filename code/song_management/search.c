#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 256

struct Song {
    char title[STRING_SIZE];
    char singer[STRING_SIZE];
    char composer[STRING_SIZE];
    char lyricist[STRING_SIZE];
    char genre[STRING_SIZE];
    char playtime[STRING_SIZE];
    char album[STRING_SIZE];
    char release[STRING_SIZE];
};

void searchSong(char* filename, char* searchWord);

int main() {
    char filename[] = "song_list.txt"; 
    char searchWord[STRING_SIZE];
    int found = 0;

    printf("���� �˻��� �����ϼ̽��ϴ�.\n�˻�� �Է��ϼ���: ");
    fgets(searchWord, sizeof(searchWord), stdin);
    searchWord[strcspn(searchWord, "\n")] = '\0';
    do {
        searchSong(filename, searchWord);
        if (!found) {
            printf("�ش� �˻���� �������� �ʽ��ϴ�.\n�˻�� �ٽ� �Է��ϼ���: ");
            fgets(searchWord, sizeof(searchWord), stdin);
            searchWord[strcspn(searchWord, "\n")] = '\0';
        }
    } while (!found);
    return 0;
}

void searchSong(char* filename, char* searchWord) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    struct Song song;

    while (fgets(song.title, sizeof(song.title), file)) {
        song.title[strcspn(song.title, "\n")] = '\0';

        if (strstr(song.title, searchWord) != NULL ||
            strstr(song.singer, searchWord) != NULL ||
            strstr(song.composer, searchWord) != NULL ||
            strstr(song.lyricist, searchWord) != NULL ||
            strstr(song.genre, searchWord) != NULL ||
            strstr(song.playtime, searchWord) != NULL ||
            strstr(song.album, searchWord) != NULL ||
            strstr(song.release, searchWord) != NULL) {

            printf("����: %s/", song.title);
            printf("����: %s/", song.singer);
            printf("�۰: %s/", song.composer);
            printf("�ۻ簡: %s/", song.lyricist);
            printf("�帣: %s/", song.genre);
            printf("����ð�: %s/", song.playtime);
            printf("�ٹ���: %s/", song.album);
            printf("�ٹ���ó�¥: %s/", song.release);
            printf("\n");
        }
    }

    fclose(file);
}
