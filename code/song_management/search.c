#define _CRT_SECURE_NO_WARNINGS
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

//�˻� �Լ� ����
void search();
// �뷡 �˻� �Լ� ����
void searchSong(char* filename, char* searchWord, int found);

int main() {
    // �˻� �Լ� ȣ��
    search();
    return 0;
}

// �˻� �Լ� ����
void search() {
    // �˻��� ���ϸ� ����
    char filename[] = "song_list.txt";
    // �˻��� ���� ���� ����
    char searchWord[STRING_SIZE];
    // �˻� ��� ���θ� ��Ÿ���� ���� �ʱ�ȭ
    int found = 0;
    // ����ڿ��� �˻��� �Է� ��û
    printf("���� �˻��� �����ϼ̽��ϴ�.\n�˻�� �Է��ϼ���: ");
    // ����ڰ� �˻�� �Է��� ������ �ݺ�
    do {
        // ����ڷκ��� �˻��� �Է� ����
        fgets(searchWord, sizeof(searchWord), stdin);
        // ���� ���� ����
        searchWord[strcspn(searchWord, "\n")] = '\0';
        // �˻� �Լ� ȣ��
        searchSong(filename, searchWord, found);
        // ���� �˻� ����� ���ٸ� �ٽ� �˻��� �Է� ��û
        if (!found) {
            printf("�ش� �˻���� �������� �ʽ��ϴ�.\n�˻�� �ٽ� �Է��ϼ���: ");
        }
    } while (!found);
    return 0;
}

// �뷡 �˻� �Լ� ����
void searchSong(char* filename, char* searchWord, int found) {
    // ���� ������ ���� �� ���� ���� �õ�
    FILE* file = fopen(filename, "r");
    // ���� ���� ���� �� �޽��� ��� �� ����
    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    // �뷡 ������ ������ ����ü �迭 ����
    struct Song song[STRING_SIZE];

    // ���Ϸκ��� ������ �о�� ����ü�� ����
    for (int i = 0; i < STRING_SIZE; i++)
        fscanf(file, "%s %s %s %s %s %s %s %s", &song[i].title, &song[i].singer, &song[i].composer, &song[i].lyricist, &song[i].genre, &song[i].playtime, &song[i].album, &song[i].release);

    // �˻���� ��ġ�ϴ� �뷡 ���� ���
    for (int i = 0; i < STRING_SIZE; i++) {
        if (strstr(song[i].title, searchWord) != NULL ||
            strstr(song[i].singer, searchWord) != NULL ||
            strstr(song[i].composer, searchWord) != NULL ||
            strstr(song[i].lyricist, searchWord) != NULL ||
            strstr(song[i].genre, searchWord) != NULL ||
            strstr(song[i].playtime, searchWord) != NULL ||
            strstr(song[i].album, searchWord) != NULL ||
            strstr(song[i].release, searchWord) != NULL) {

            printf("����: %s/", song[i].title);
            printf("����: %s/", song[i].singer);
            printf("�۰: %s/", song[i].composer);
            printf("�ۻ簡: %s/", song[i].lyricist);
            printf("�帣: %s/", song[i].genre);
            printf("����ð�: %s/", song[i].playtime);
            printf("�ٹ���: %s/", song[i].album);
            printf("�ٹ���ó�¥: %s/", song[i].release);
            printf("\n");
            // �˻� ����� ã�����Ƿ� found ������ 1�� ����
            found = 1;
        }
    }

    fclose(file);
}

