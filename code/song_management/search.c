#include "header.h"

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

void searchTag(); //�±� �˻�
void searchZero();//�±� �˻����� 0 �Է½�
void searchWordOfTag(const char *filename, const char *tag, const char *word); //�˻��� �˻�

void searchMenu(){
    int mode;
    int err = 0;
    while (1)
    {
        if (err == 0) {
            printf("\n�뷡 ���� ���α׷��Դϴ�.\n");
            printf("���ϴ� �޴��� �����ϼ���.\n\n");
        }
        else if (err == 1) {
            printf("\n�ش� �޴��� �������� �ʽ��ϴ�.");
            printf("�ٽ� �����ϼ���.\n\n");
            err = 0;
        }
        printf("1. ���� �˻�\n");
        printf("2. �±� �˻�\n");
        printf("0. �ڷ� ����\n\n");
        printf("�޴� ���� : ");
        scanf(" %d", &mode);

        switch (mode) {
        case 1: //���� �˻�
            system("cls");
            search();
            break;

        case 2: //�±� �˻�
            system("cls");
            searchTag();
            break;

        case 0: //�ڷ� ����
            system("cls");
            main();
            break;

        default: //error
            err = 1;
            break;
        }
    }
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
    // return 0;
}

// �뷡 �˻� �Լ� ����
void searchSong(char* filename, char* searchWord, int found) {
    // ���� ������ ���� �� ���� ���� �õ�
    FILE* file = fopen("song_list.txt", "r");
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

void searchTag() {
    char tag[STRING_SIZE], word[STRING_SIZE];
    int err = 0;
    int goback;
    while (1) {
        system("cls");
        if (err == 0) {
            printf("�±� �˻��� �����ϼ̽��ϴ�.\n");
        } else {
            printf("�ش� �˻���� �������� �ʽ��ϴ�.\n");
            err = 0;
        }
        printf("(�±� = ����/����/�۰/�ۻ簡/�帣/����ð�/�ٹ���/�ٹ���ó�¥)\n");
        printf("�˻��� �±׸� �Է��ϼ��� (0 �Է� �� �ڷΰ���) : ");
        scanf("%s", tag);

        if (strcmp(tag,"����") == 0 || strcmp(&tag,"����") == 0 || strcmp(&tag,"�۰") == 0 || strcmp(&tag,"�ۻ簡") == 0 || strcmp(&tag,"�帣") == 0 || strcmp(&tag,"����ð�") == 0 || strcmp(&tag,"�ٹ���") == 0 || strcmp(&tag,"�ٹ���ó�¥") == 0) {
            printf("�˻�� �Է��ϼ��� (0 �Է� �� �ڷΰ���) : ");
            scanf("%s", word);
            printf("\n");
            if (word[0] == '0') {
                searchZero("song_list.txt", tag, word);
                break;
            } else {
                // �˻� ��� ���
                searchWordOfTag("song_list.txt", tag, word);
            }
            break;
        }
        else if(strcmp(&tag,"0") == 0){ // �ڷΰ���
            searchMenu();
            break;
        }
        else{ // �߸��Է�
            err = 1;
        }
    }
}

void searchZero(const char *filename, const char *tag, const char *word) {
    int err = 0;
    int goback = 0;
    while (1) {
        if (err == 0) {
            printf("'0'�� �Է� �ϼ̽��ϴ�. ���� �ڷ� ���ðڽ��ϱ�?\n\n");
        } else {
            printf("�߸� �Է� �ϼ̽��ϴ�. �ٽ� �������ּ���.\n\n");
            err = 0;
        }
        printf("1. �ڷΰ���\n");
        printf("2. '0' �˻��ϱ�\n\n");
        printf("�޴����� : ");
        scanf("%d", &goback);
        printf("\n");
        if (goback == 1) {
            searchTag();
            break;
        } else if (goback == 2) { // '0' �˻�
            searchWordOfTag("song_list.txt", tag, word);
            break;
        } else {
            err = 1;
            break;
        }
    }
}

void searchWordOfTag(const char *filename, const char *tag, const char *word) {
    FILE *file = fopen(filename, "r");

    struct Song song;
    char line[STRING_SIZE * 8]; // ���� �� ������ ���̸� �������� ���۸� �Ҵ�
    printf("���� / ���� / �۰ / �ۻ簡 / �帣 / ����ð� / �ٹ��� / �ٹ���ó�¥\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|\n]", song.title, song.singer, song.composer, song.lyricist, song.genre, song.playtime, song.album, song.release);
        
        if (strcmp(tag, "����") == 0 && strstr(song.title, word) != NULL) {
            printf("%s / %s / %s / %s / %s / %s / %s / %s\n", 
                   song.title, song.singer, song.composer, song.lyricist, song.genre, song.playtime, song.album, song.release);
        }
        else if (strcmp(tag, "����") == 0 && strstr(song.singer, word) != NULL) {
            printf("%s / %s / %s / %s / %s / %s / %s / %s\n", 
                   song.title, song.singer, song.composer, song.lyricist, song.genre, song.playtime, song.album, song.release);
        }
        else if (strcmp(tag, "�۰") == 0 && strstr(song.composer, word) != NULL) {
            printf("%s / %s / %s / %s / %s / %s / %s / %s\n", 
                   song.title, song.singer, song.composer, song.lyricist, song.genre, song.playtime, song.album, song.release);
        }
        else if (strcmp(tag, "�ۻ簡") == 0 && strstr(song.lyricist, word) != NULL) {
            printf("%s / %s / %s / %s / %s / %s / %s / %s\n", 
                   song.title, song.singer, song.composer, song.lyricist, song.genre, song.playtime, song.album, song.release);
        }
        else if (strcmp(tag, "�帣") == 0 && strstr(song.genre, word) != NULL) {
            printf("%s / %s / %s / %s / %s / %s / %s / %s\n", 
                   song.title, song.singer, song.composer, song.lyricist, song.genre, song.playtime, song.album, song.release);
        }
        else if (strcmp(tag, "����ð�") == 0 && strstr(song.playtime, word) != NULL) {
            printf("%s / %s / %s / %s / %s / %s / %s / %s\n", 
                   song.title, song.singer, song.composer, song.lyricist, song.genre, song.playtime, song.album, song.release);
        }
        else if (strcmp(tag, "�ٹ���") == 0 && strstr(song.album, word) != NULL) {
            printf("%s / %s / %s / %s / %s / %s / %s / %s\n", 
                   song.title, song.singer, song.composer, song.lyricist, song.genre, song.playtime, song.album, song.release);
        }
        else if (strcmp(tag, "�ٹ���ó�¥") == 0 && strstr(song.release, word) != NULL) {
            printf("%s / %s / %s / %s / %s / %s / %s / %s\n", 
                   song.title, song.singer, song.composer, song.lyricist, song.genre, song.playtime, song.album, song.release);
        }
    }

    fclose(file);

    printf("\n����ȭ������ ���ư����� �ƹ�Ű�� ��������.");
    _getwch(); // �ѱ��� ���͸� �ľ���.
    system("cls");
    main();
}