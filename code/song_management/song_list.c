#include "header.h"
#define MAX_SIZE 100000
#define STRING_SIZE 256

int IsSpace(char ch);
char* strrtrim(char* s);
char* strltrim(char* s);
char* trim(char* s);

int IsSpace(char ch)
{
    if (ch < 0)  // �����ΰ�� �ѱ۷� ����
        return 0;
    else
        return isspace(ch);
}

char* strrtrim(char* s)   //�� ���� ����
{
    char* t;

    t = strchr(s, '\0');
    while (t > s && IsSpace(t[-1]))
        --t;
    *t = '\0';
    return s;
}

char* strltrim(char* s)   //�� ���� ����
{
    char* t;
    char* e;

    t = s;
    e = strchr(s, '\0');
    while (IsSpace(*t))
        ++t;

    memmove(s, t, e - t + 1);

    return s;
}

char* trim(char* s)   //�յ� ���� ����
{
    strltrim(s);
    strrtrim(s);

    return s;
}

void song_list_menu() //�뷡 ����Ʈ �� �޴�
{
    char input_text[STRING_SIZE];   //������ ���ڿ�(�뷡)�� �� �迭
    int mode, err = 0;
    while (1)
    {
        if (err == 0) //�Է� ���ǿ� �¾��� ��
        {
            printf("\n���ϴ� �޴��� �����ϼ���.\n\n");
        }
        else //�Է� ���ǿ� ���� �ʾ��� ��
        {
            printf("\n�ش� �޴��� �������� �ʽ��ϴ�.\n");
            printf("���� �޴� �� �����ϼ���(����:1)\n\n");
            err = 0;
        }
        printf("1. �뷡 ����Ʈ ���\n");
        printf("2. �뷡 �߰�\n");
        printf("3. �뷡 ����\n");
        printf("0. �ڷ� ����\n");
        printf("\n�޴� ���� : ");
        scanf(" %d", &mode);

        switch (mode) {
        case 1: //�뷡 ����Ʈ ���
            song_list_print();
            break;

        case 2: //�뷡 �߰�
            add_song();
            break;

        case 3: //�뷡 ����
            get_dlt_song(input_text); //���� ���ڿ� �Է� �� ���� �� ����
            break;

        case 0: //�ڷ� ����
            return 0;
            break;
        default: //error
            while (getchar() != '\n'); //�Է� ���� ����
            err = 1;
            break;
        }
    }
}

void song_list_print()//�뷡 ����Ʈ ���
{
    printf("\n�뷡 ����Ʈ�� ����մϴ�.");
    printf("\n\n���� / ���� / �۰ / �ۻ簡 / �帣 / ����ð� / �ٹ��� / �ٹ� ��� ��¥\n");
    FILE* fp;
    fp = fopen("song_list.txt", "r");
    if (fp == NULL)
    {
        printf("����");
    }
    char name[STRING_SIZE];
    char singer[STRING_SIZE];
    char song_writer[STRING_SIZE];
    char lylic_writer[STRING_SIZE];
    char genre[STRING_SIZE];
    char playtime[STRING_SIZE];
    char album_name[STRING_SIZE];
    char album_time[STRING_SIZE];
    char song[STRING_SIZE * 8];
    while (fgets(song, sizeof(song), fp) != NULL)
    {
        sscanf(song, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t\n]", name, singer, song_writer, lylic_writer, genre, playtime, album_name, album_time);
        printf("%s / ", name); //���� ���
        int size = 0;

        //���� ���
        while (1)
        {
            if (singer[size] == '|') //�ι� �����ڸ� ������ ��
            {
                while (1) //���⸦ ���� �� �Ǵ� ���� �� ���� �ǳʶٱ�
                {
                    size++;
                    if (singer[size] == NULL) //���ڿ��� ������ ��
                    {
                        break;
                    }
                    else if (singer[size] == ' ') //���⸦ ������ ��
                    {
                        size = size + 1;
                        break;
                    }
                }
            }
            if (singer[size] == NULL) //���ڿ��� ������ ��
            {
                printf(" / ");
                break;
            }
            printf("%c", singer[size]);
            size++;
        }
        size = 0;

        //�۰ ���
        while (1)
        {
            if (song_writer[size] == '|') //�ι� �����ڸ� ������ ��
            {
                while (1) //���⸦ ���� �� �Ǵ� ���� �� ���� �ǳʶٱ�
                {
                    size++;
                    if (song_writer[size] == NULL) //���ڿ��� ������ ��
                    {
                        break;
                    }
                    else if (song_writer[size] == ' ') //���⸦ ������ ��
                    {
                        size = size + 1;
                        break;
                    }
                }
            }
            if (song_writer[size] == NULL) //���ڿ��� ������ ��
            {
                printf(" / ");
                break;
            }
            printf("%c", song_writer[size]);
            size++;
        }
        size = 0;

        //�ۻ簡 ���
        while (1)
        {
            if (lylic_writer[size] == '|') //�ι� �����ڸ� ������ ��
            {
                while (1) //���⸦ ���� �� �Ǵ� ���� �� ���� �ǳʶٱ�
                {
                    size++;
                    if (lylic_writer[size] == NULL) //���ڿ��� ������ ��
                    {
                        break;
                    }
                    else if (lylic_writer[size] == ' ') //���⸦ ������ ��
                    {
                        size = size + 1;
                        break;
                    }
                }
            }
            if (lylic_writer[size] == NULL) //���ڿ��� ������ ��
            {
                printf(" / ");
                break;
            }
            printf("%c", lylic_writer[size]);
            size++;
        }

        printf("%s / ", genre); //�帣 ���
        printf("%s / ", playtime); //����ð� ���
        printf("%s / ", album_name); //�ٹ��� ���
        printf("%s\n", album_time); //�ٹ� ��� ��¥ ���
    }
    fclose(fp);
}
/*
void song_add()//�뷡 �߰�
{
   char name[MAX_SIZE]; //����
   char singer[200]; //����
   char song_writer[200]; //�۰
   char lyric_writer[200]; //�ۻ簡
   char genre[20]; //�帣
   int play_time_hour = 0, play_time_min = 0, play_time_sec = 0; //����ð���
   char album_name[200]; //�ٹ���
   int album_year = 0, album_month = 0, album_day = 0;//�ٹ���ó�¥

   FILE* fp;
   fp = fopen("song_list.txt", "a+");

   //���� �Է�
   printf("\n������ �Է��ϼ���.\n\n");
   printf("���� : ");
   int err=1;
   getchar();
   do
   {
      gets(name, MAX_SIZE);
      if (strlen(name) == 0) //�Է����� �ʾ��� ��
      {
         printf("\n���� �Է��� �߸��Ǿ����ϴ�. ��Ȯ�� �Է����ּ���.(����:����)\n\n");
         printf("���� : ");
      }
      else if (name[0] == ' ' || name[0] == '\t' || name[strlen(name) - 1] == ' ' || name[strlen(name) - 1] == '\t') //�� �ڿ� ������ ���� ��
      {
         printf("\n���� �Է��� �߸��Ǿ����ϴ�. ��Ȯ�� �Է����ּ���.(����:����)\n\n");
         printf("���� : ");
         name[0] = NULL;
      }
      else //�´� �Է��� ��
      {
         err = 0;
      }
   } while (err == 1);
   //printf("\n%s", name);

   //���� �Է�
   printf("\n������ �Է��ϼ���.\n\n");
   printf("���� : ");
   err = 1;
   getchar();
   do
   {
      gets(singer, 200);
      if (strlen(singer) == 0) //�Է����� �ʾ��� ��
      {
         printf("\n���� �Է��� �߸��Ǿ����ϴ�. ��Ȯ�� �Է����ּ���.(����:������)\n\n");
         printf("���� : ");
      }
      else if (singer[0] == ' ' || singer[0] == '\t' || singer[strlen(singer) - 1] == ' ' || singer[strlen(singer) - 1] == '\t') //�� �ڿ� ������ ���� ��
      {
         printf("\n���� �Է��� �߸��Ǿ����ϴ�. ��Ȯ�� �Է����ּ���.(����:������)\n\n");
         printf("���� : ");
         singer[0] = NULL;
      }
      else //�´� �Է��� ��
      {
         err = 0;
      }
   } while (err == 1);
   //printf("\n%s", singer);

   //�۰ �Է�
   printf("\n�۰�� �Է��ϼ���.\n\n");
   printf("�۰ : ");
   err = 1;
   getchar();
   do
   {
      gets(song_writer, 200);
      if (strlen(song_writer) == 0) //�Է����� �ʾ��� ��
      {
         printf("\n�۰ �Է��� �߸��Ǿ����ϴ�. ��Ȯ�� �Է����ּ���.(����:������)\n\n");
         printf("�۰ : ");
      }
      else if (song_writer[0] == ' ' || song_writer[0] == '\t' || song_writer[strlen(song_writer) - 1] == ' ' || song_writer[strlen(song_writer) - 1] == '\t') //�� �ڿ� ������ ���� ��
      {
         printf("\n�۰ �Է��� �߸��Ǿ����ϴ�. ��Ȯ�� �Է����ּ���.(����:������)\n\n");
         printf("�۰ : ");
         song_writer[0] = NULL;
      }
      else //�´� �Է��� ��
      {
         err = 0;
      }
   } while (err == 1);
   //printf("\n%s", song_writer);

   //�ۻ簡 �Է�
   printf("\n�ۻ簡�� �Է��ϼ���.\n\n");
   printf("�ۻ簡 : ");
   err = 1;
   getchar();
   do
   {
      gets(lyric_writer, 200);
      if (strlen(lyric_writer) == 0) //�Է����� �ʾ��� ��
      {
         printf("\n�ۻ簡 �Է��� �߸��Ǿ����ϴ�. ��Ȯ�� �Է����ּ���.(����:������)\n\n");
         printf("�ۻ簡 : ");
      }
      else if (lyric_writer[0] == ' ' || lyric_writer[0] == '\t' || lyric_writer[strlen(lyric_writer) - 1] == ' ' || lyric_writer[strlen(lyric_writer) - 1] == '\t') //�� �ڿ� ������ ���� ��
      {
         printf("\n�ۻ簡 �Է��� �߸��Ǿ����ϴ�. ��Ȯ�� �Է����ּ���.(����:������)\n\n");
         printf("�ۻ簡 : ");
         lyric_writer[0] = NULL;
      }
      else //�´� �Է��� ��
      {
         err = 0;
      }
   } while (err == 1);
   //printf("\n%s", lyric_writer);

   //�ۻ簡 �Է�
   printf("\n�ۻ簡�� �Է��ϼ���.\n\n");
   printf("�ۻ簡 : ");
   err = 1;
   getchar();
   do
   {
      gets(lyric_writer, 200);
      if (strlen(lyric_writer) == 0) //�Է����� �ʾ��� ��
      {
         printf("\n�ۻ簡 �Է��� �߸��Ǿ����ϴ�. ��Ȯ�� �Է����ּ���.(����:������)\n\n");
         printf("�ۻ簡 : ");
      }
      else if (lyric_writer[0] == ' ' || lyric_writer[0] == '\t' || lyric_writer[strlen(lyric_writer) - 1] == ' ' || lyric_writer[strlen(lyric_writer) - 1] == '\t') //�� �ڿ� ������ ���� ��
      {
         printf("\n�ۻ簡 �Է��� �߸��Ǿ����ϴ�. ��Ȯ�� �Է����ּ���.(����:������)\n\n");
         printf("�ۻ簡 : ");
         lyric_writer[0] = NULL;
      }
      else //�´� �Է��� ��
      {
         err = 0;
      }
   } while (err == 1);
   //printf("\n%s", lyric_writer);

   //�帣 �Է�
   printf("\n�帣�� �Է��ϼ���.\n\n");
   printf("�帣 : ");
   err = 1;
   getchar();
   do
   {
      gets(genre, 20);
      if (strcmp(genre,"Ŭ����")==0 || strcmp(genre, "����") == 0 || strcmp(genre, "��") == 0 || strcmp(genre, "�߶��") == 0 || strcmp(genre, "����") == 0 || strcmp(genre, "Ʈ��Ʈ") == 0 || strcmp(genre, "����") == 0 || strcmp(genre, "��") == 0) //�´� �Է��� ��
      {
         err = 0;
      }
      else //��Ģ�� �ٸ� ��
      {
         printf("\n�帣 �Է��� �߸��Ǿ����ϴ�. ��Ȯ�� �Է����ּ���.(����:����)\n\n");
         printf("�帣 : ");
         genre[0] = NULL;
      }
   } while (err == 1);
   //printf("\n%s", genre);

   //����ð� �Է�
   printf("\n����ð��� �Է��ϼ���.\n\n");
   printf("����ð� : ");
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�

   //�ٹ��� �Է�
   printf("\n�ٹ����� �Է��ϼ���.\n\n");
   printf("�ٹ��� : ");
   err = 1;
   getchar();
   do
   {
      gets(album_name, 200);
      if (strlen(album_name) == 0) //�Է����� �ʾ��� ��
      {
         printf("\n�ۻ簡 �Է��� �߸��Ǿ����ϴ�. ��Ȯ�� �Է����ּ���.(����:������)\n\n");
         printf("�ۻ簡 : ");
      }
      else if (album_name[0] == ' ' || album_name[0] == '\t' || album_name[strlen(album_name) - 1] == ' ' || album_name[strlen(album_name) - 1] == '\t') //�� �ڿ� ������ ���� ��
      {
         printf("\n�ۻ簡 �Է��� �߸��Ǿ����ϴ�. ��Ȯ�� �Է����ּ���.(����:������)\n\n");
         printf("�ۻ簡 : ");
         album_name[0] = NULL;
      }
      else //�´� �Է��� ��
      {
         err = 0;
      }
   } while (err == 1);
   //printf("\n%s", album_name);

   //�ٹ� ��� ��¥ �Է�
   printf("\n�ٹ� ��� ��¥�� �Է��ϼ���.\n\n");
   printf("�ٹ� ��� ��¥ : ");
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
   // �����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�����ʿ�
}
*/

void add_song() {
    char title_buffer[STRING_SIZE] = "";   //����
    char singers_buffer[STRING_SIZE] = "";   //����
    char composers_buffer[STRING_SIZE] = "";   //�۰
    char lyricists_buffer[STRING_SIZE] = "";   //�ۻ簡
    char genre_buffer[STRING_SIZE] = "";    //�帣
    char playtime_buffer[STRING_SIZE]; //����ð�
    char album_buffer[STRING_SIZE];    //�ٹ���
    char release_buffer[STRING_SIZE];  //�ٹ���ó�¥
    FILE* fp = fopen("song_list.txt", "a");   //�߰����� ���� ����


    printf("\n������ �Է��ϼ���.\n");   //����
    while (1) {
        printf("\n");
        printf("���� :");
        gets(title_buffer, STRING_SIZE);   //���� �Է¹ޱ�

        char* title = trim(title_buffer);   //�յ� ���� ����

        //printf("%s\n", title);         //����� �ԷµǾ����� Ȯ��(�˻�)
        if (strlen(title) == 0) {   //Ʋ�� �Է��� ���
            printf("\n���� �Է��� �߸��Ǿ����ϴ�.��Ȯ�� �Է����ּ���.(����:����)\n");
            continue;
        }
        else {      //�´� �Է��� ���
            fprintf(fp, "%s | ", title);
        }
        break;
    }   //���� ��

    printf("\n������ �Է��ϼ���.\n");   //����
    while (1) {
        printf("\n");
        printf("���� :");
        gets(singers_buffer);   //���� �Է¹ޱ�

        char* singers = trim(singers_buffer);   //�յ� ���� ����

        if (strlen(singers) == 0) {   //Ʋ�� �Է��� ���
            printf("\n���� �Է��� �߸��Ǿ����ϴ�.��Ȯ�� �Է����ּ���.(����:������)\n");
            continue;
        }
        else {      //�´� �Է��� ���
            char* singer_buffer = strtok(singers, ",");   //","�� �������� �ڸ���
            char* singer = trim(singer_buffer);   //�յ� ���� ����
            //�ߺ� Ȯ��

            fprintf(fp, "%s ", singer);         //ù ���� ���Ͽ� ����
            singer = strtok(NULL, ",");

            while (singer != NULL) {            //������ �� ���� ��� ��� �߰� ����
                char* next_singer = trim(singer);   //�յ� ���� ����
                //�ߺ� Ȯ��
                fprintf(fp, ", %s ", next_singer);
                singer = strtok(NULL, ",");
            }
            fputs("| ", fp);
        }
        break;
    }      //���� ��


    printf("\n�۰�� �Է��ϼ���.\n");   //�۰
    while (1) {
        printf("\n");
        printf("�۰ :");
        gets(composers_buffer);   //�۰ �Է¹ޱ�

        char* composers = trim(composers_buffer);   //�յ� ���� ����

        if (strlen(composers) == 0) {   //Ʋ�� �Է��� ���
            printf("\n�۰ �Է��� �߸��Ǿ����ϴ�.��Ȯ�� �Է����ּ���.(����:������)\n");
            continue;
        }
        else {      //�´� �Է��� ���
            char* composer_buffer = strtok(composers, ",");   //","�� �������� �ڸ���
            char* composer = trim(composer_buffer);   //�յ� ���� ����
            //�ߺ� Ȯ��

            fprintf(fp, "%s ", composer);         //ù �۰ ���Ͽ� ����
            composer = strtok(NULL, ",");

            while (composer != NULL) {            //�۰�� �� ���� ��� ��� �߰� ����
                char* next_composer = trim(composer);   //�յ� ���� ����
                //�ߺ� Ȯ��
                fprintf(fp, ", %s ", next_composer);
                composer = strtok(NULL, ",");
            }
            fputs("| ", fp);
        }
        break;   //�۰ ��
    }

    printf("\n�ۻ簡�� �Է��ϼ���.\n");   //�ۻ簡
    while (1) {
        printf("\n");
        printf("�ۻ簡 :");
        gets(lyricists_buffer);   //�ۻ簡 �Է¹ޱ�

        char* lyricists = trim(lyricists_buffer);   //�յ� ���� ����

        if (strlen(lyricists) == 0) {   //Ʋ�� �Է��� ���
            printf("\n�ۻ簡 �Է��� �߸��Ǿ����ϴ�.��Ȯ�� �Է����ּ���.(����:������)\n");
            continue;
        }
        else {      //�´� �Է��� ���
            char* lyricist_buffer = strtok(lyricists, ",");   //","�� �������� �ڸ���
            char* lyricist = trim(lyricist_buffer);   //�յ� ���� ����
            //�ߺ� Ȯ��

            fprintf(fp, "%s ", lyricist);         //ù �ۻ簡 ���Ͽ� ����
            lyricist = strtok(NULL, ",");

            while (lyricist != NULL) {            //�ۻ簡�� �� ���� ��� ��� �߰� ����
                char* next_lyricist = trim(lyricist);   //�յ� ���� ����
                //�ߺ� Ȯ��
                fprintf(fp, ", %s ", next_lyricist);
                lyricist = strtok(NULL, ",");
            }
            fputs("| ", fp);
        }
        break;   //�ۻ簡 ��
    }

    printf("\n�帣�� �Է��ϼ���.\n");   //�帣
    while (1) {
        printf("\n");
        printf("�帣 :");
        gets(genre_buffer);

        char* genre = trim(genre_buffer);   //�յ� ���� ����

        if (strcmp(genre, "Ŭ����") * strcmp(genre, "����") * strcmp(genre, "��") * strcmp(genre, "�߶��") * strcmp(genre, "����") * strcmp(genre, "Ʈ��Ʈ") * strcmp(genre, "����") * strcmp(genre, "��") == 0 || strlen(genre) == 0) {   //�´� �Է��� ���
            fprintf(fp, "%s | ", genre);
        }
        else {      //Ʋ�� �Է��� ���
            printf("\n�帣 �Է��� �߸��Ǿ����ϴ�.��Ȯ�� �Է����ּ���.(����:����)\n");
            continue;
        }
        break;
    }      //�帣 ��

    printf("\n�ð��� �Է��ϼ���.\n");   //����ð�
    while (1) {
        char minute_str[STRING_SIZE] = "";
        char second_str[STRING_SIZE] = "";
        int count_m = 0;
        int count_s = 0;
        int error = 0;
        printf("\n");
        printf("�ð� :");
        gets(playtime_buffer);

        char* playtime = trim(playtime_buffer);   //�յ� ���� ����

        //"��","��" ���� ���� ����
        char* ptr_m = strstr(playtime, "��");
        while (ptr_m != NULL) // ���̻� "��"�� �������� ���� ������ �ݺ�
        {
            ptr_m = strstr(ptr_m + 1, "��"); // ���� ���� ��ġ Ž��
            count_m++;
        }
        char* ptr_s = strstr(playtime, "��");
        while (ptr_s != NULL) // ���̻� "��"�� �������� ���� ������ �ݺ�
        {
            ptr_s = strstr(ptr_s + 1, "��"); // ���� ���� ��ġ Ž��
            count_s++;
        }

        //����ð� ���� ���� Ȯ��
        if (strlen(playtime) == 0) { error = 1; }   //Ʋ�� �Է��� ���   
        else if (count_m == 1 && count_s == 1) {   //��� 1���� �ִ� ���
            strcpy(minute_str, strtok(playtime, "��"));
            char* temp = strtok(NULL, "��");
            strcpy(second_str, strtok(temp, "��"));
            if (strtok(NULL, "��") != NULL) { error = 1; }
        }
        else if (count_m == 1 && count_s == 0) {   //�Է¿� "��"�� 1�� �ִ� ���
            if (strcmp(playtime, "��") == 0) {
                error = 1;
            }
            else {
                strcpy(minute_str, strtok(playtime, "��"));
                if (strtok(NULL, "��") != NULL) { error = 1; }
            }
        }
        else if (count_m == 0 && count_s == 1) {   //�Է¿� "��"�� 1�� �ִ� ���
            if (strcmp(playtime, "��") == 0) {
                error = 1;
            }
            else {
                strcpy(second_str, strtok(playtime, "��"));
                if (strtok(NULL, "��") != NULL) { error = 1; }
            }
        }
        else { error = 1; }      //�������� ��� Ʋ�� ���

        if (error == 1) {      //���� ó��
            printf("\n�ð� �Է��� �߸��Ǿ����ϴ�.��Ȯ�� �Է����ּ���.(����:02��44��)\n");
            continue;
        }

        //����ð� �ǹ� ��Ģ Ȯ��
        if (strcmp(minute_str, "")) {   //"��"�� ������ �ƴϸ�
            for (int i = 0; i < strlen(minute_str); i++)   //���ڿ��� �������� Ȯ��
            {
                if (!isdigit(minute_str[i])) { error = 1; }
            }
            if (error == 0) {
                int minute = atoi(minute_str);
                if (minute <= 0) {         //"��"�� 0���� ũ��
                    error = 1;
                }
                else {
                    fprintf(fp, "%02d��", minute);
                }
            }
        }
        if (strcmp(second_str, "")) {   //"��"�� ������ �ƴϸ�
            for (int i = 0; i < strlen(second_str); i++)   //���ڿ��� �������� Ȯ��(�а� �� ���� ���� ���� �� error=1)
            {
                if (!isdigit(second_str[i])) { error = 1; }
            }
            if (error == 0) {
                int second = atoi(second_str);
                if (second <= 0 || second >= 60) {   //"��"�� 1~59����
                    error = 1;
                }
                else {
                    fprintf(fp, "%d��", second);
                }
            }
        }
        if (error == 1) {
            printf("\n�ð� �Է��� �߸��Ǿ����ϴ�.��Ȯ�� �Է����ּ���.(����:02��44��)\n");
            continue;
        }

        fputs(" | ", fp);
        break;
    }      //����ð� ��

    printf("\n�ٹ����� �Է��ϼ���.\n");   //�ٹ���
    while (1) {
        printf("\n");
        printf("�ٹ��� :");
        gets(album_buffer);   //�ٹ��� �Է¹ޱ�

        char* album = trim(album_buffer);   //�յ� ���� ����

        if (0) {   //Ʋ�� �Է��� ���
            printf("\n�ٹ��� �Է��� �߸��Ǿ����ϴ�.��Ȯ�� �Է����ּ���.(����:��簻)\n");
            continue;
        }
        else {      //�´� �Է��� ���
            fprintf(fp, "%s | ", album);
        }
        break;
    }   //�ٹ��� ��

    printf("\n�ٹ� ��� ��¥�� �Է��ϼ���.\n");   //�ٹ� ��� ��¥
    while (1) {
        char* year_str = "";
        char* month_str = "";
        char* day_str = "";
        int count_hyphen = 0;
        int count_slash = 0;
        int count_dot = 0;
        int error = 0;
        printf("\n");
        printf("�ٹ� ��� ��¥ :");
        gets(release_buffer);

        char* release = trim(release_buffer);   //�յ� ���� ����

        //'-','/','.' ���� ���� ����
        char* ptr_hyphen = strchr(release, '-');
        while (ptr_hyphen != NULL) // ���̻� '-'�� �������� ���� ������ �ݺ�
        {
            ptr_hyphen = strchr(ptr_hyphen + 1, '-'); // ���� ���� ��ġ Ž��
            count_hyphen++;
        }
        char* ptr_slash = strchr(release, '/');
        while (ptr_slash != NULL) // ���̻� '/'�� �������� ���� ������ �ݺ�
        {
            ptr_slash = strchr(ptr_slash + 1, '/'); // ���� ���� ��ġ Ž��
            count_slash++;
        }
        char* ptr_dot = strchr(release, '.');
        while (ptr_dot != NULL) // ���̻� '.'�� �������� ���� ������ �ݺ�
        {
            ptr_dot = strchr(ptr_dot + 1, '.'); // ���� ���� ��ġ Ž��
            count_dot++;
        }

        //�ٹ� ��� ��¥ ���� ���� Ȯ��
        if (count_hyphen == 2 && count_slash == 0 && count_dot == 0) {   //'-'�� 2���� ���
            year_str = strtok(release, "-");
            month_str = strtok(NULL, "-");
            day_str = strtok(NULL, "-");
        }
        else if (count_hyphen == 0 && count_slash == 2 && count_dot == 0) {   //'/'�� 2���� ���
            year_str = strtok(release, "/");
            month_str = strtok(NULL, "/");
            day_str = strtok(NULL, "/");
        }
        else if (count_hyphen == 0 && count_slash == 0 && count_dot == 2) {   //'.'�� 2���� ���
            year_str = strtok(release, ".");
            month_str = strtok(NULL, ".");
            day_str = strtok(NULL, ".");
        }
        else if (count_hyphen == 0 && count_slash == 0 && count_dot == 0) {   //��� ������ ���
            if (strlen(release) == 8) {
                for (int i = 0; i < strlen(release); i++)   //���ڿ��� �������� Ȯ��
                {
                    if (!isdigit(release[i])) { error = 1; }
                }
                if (error == 0) {
                    int temp = atoi(release);
                    int year = temp / 10000;
                    int month = (temp % 10000) / 100;
                    int day = temp % 100;
                    //check_date(year, month, day)   //��¥ Ȯ�� �Լ�(true/false)
                }
            }
            else { error = 1; }
        }
        else { error = 1; }      //�������� ��� Ʋ�� ���

        for (int i = 0; i < strlen(year_str); i++)   //���ڿ��� �������� Ȯ��
        {
            if (!isdigit(year_str[i])) { error = 1; }
        }
        for (int i = 0; i < strlen(month_str); i++)   //���ڿ��� �������� Ȯ��
        {
            if (!isdigit(month_str[i])) { error = 1; }
        }
        for (int i = 0; i < strlen(day_str); i++)   //���ڿ��� �������� Ȯ��
        {
            if (!isdigit(day_str[i])) { error = 1; }
        }

        if (error == 1) {
            printf("\n�ٹ� ��� ��¥ �Է��� �߸��Ǿ����ϴ�.��Ȯ�� �Է����ּ���.\n(����:2024-04-01 �Ǵ� 2024/04/01 �Ǵ� 2024.04.01 �Ǵ� 20240401)\n");
            continue;
        }

        //�ٹ� ��� ��¥ �ǹ� ��Ģ Ȯ��
        int year = atoi(year_str);
        int month = atoi(month_str);
        int day = atoi(day_str);
        //check_date(year, month, day)   //��¥ Ȯ�� �Լ�(true/false)
        fprintf(fp, "%04d-%02d-%02d", year, month, day);

        fputs(" \n", fp);
        break;
    }      //�ٹ� ��� ��¥ ��

    fclose(fp);
}

void get_dlt_song(char* dlt_song) { // ���� ���ڿ� �Է� �� ���� �Լ� -> �ش� ���ڿ� ���� �Լ��� �Ѿ
    char dlt_songname[STRING_SIZE];   // ������ �뷡 ����
    char dlt_singer[STRING_SIZE];   // ������ �뷡 ����
    int line_number_check[MAX_SIZE] = { 0 };   // �뷡 �ߺ��� ������ �뷡 ���� �� ����� �迭
    int line_num = 0;   // �ߺ� �뷡 ���� ���� ����

    printf("�뷡�� �����մϴ�.\n");
    printf("������ �뷡�� ������ �Է��ϼ���: ");
    fgets(dlt_songname, STRING_SIZE, stdin);
    dlt_songname[strcspn(dlt_songname, "\n")] = '\0'; // ���� ���� ����

    printf("������ �뷡�� ������ �Է��ϼ���: ");
    fgets(dlt_singer, STRING_SIZE, stdin);
    dlt_singer[strcspn(dlt_singer, "\n")] = '\0'; // ���� ���� ����

    FILE* file = fopen("song_list.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char buffer[STRING_SIZE];   // txt���Ͽ��� �о�� ���ڿ� ����
    char dlt_print[STRING_SIZE];   // �뷡 ������ �����ڸ� '\t' ���� ' / ' �� �ٲ� ����� �迭
    int line_number = 1; // �ߺ� �뷡 �� �� ��ȣ�� ������ ����
    int selected_line = 0; // �뷡�� �ߺ����� ������ ������ Ư�� �뷡�� ���� ���, �ߺ��Ǹ� ����ڰ� ������ ��ȣ ������ ����
    while (fgets(buffer, STRING_SIZE, file) != NULL) {
        char* token = strtok(buffer, "\t"); // ���� �����ڷ� ����Ͽ� ���ڿ��� ����
        char* song = strtok(NULL, "\t");

        // �Է��� ����� ������ txt���Ͽ��� ���ϸ�, �ߺ� �뷡 ���� ī��Ʈ
        if (strcmp(dlt_songname, token) == 0 && strcmp(dlt_singer, song) == 0) {
            line_number_check[line_num] = line_number;
            line_num++;
        }
        line_number++;
    }

    fclose(file);

    if (line_num > 1) { // ���� �뷡 ����� ������ �ߺ��� ���
        line_number = 1; // �� ��ȣ �ʱ�ȭ
        file = fopen("song_list.txt", "r"); // ������ �ٽ� ��� ���
        while (fgets(buffer, STRING_SIZE, file) != NULL) {
            strcpy(dlt_print, buffer);
            char* token = strtok(buffer, "\t"); // ���� �����ڷ� ����Ͽ� ���ڿ��� ����
            char* song = strtok(NULL, "\t");

            // ����� ���� ��ġ�� �ش� �뷡 ���� ���
            if (strcmp(dlt_songname, token) == 0 && strcmp(dlt_singer, song) == 0) {
                printf("%d.  ", line_number);
                for (int k = 0; k < strlen(dlt_print); k++) {
                    if (dlt_print[k] == '\t')
                        printf(" / ");
                    else
                        printf("%c", dlt_print[k]);
                }
            }
            line_number++;
        }
        fclose(file);

        printf("������ �뷡�� ��ȣ�� �����ϼ���: ");
        scanf("%d", &selected_line);
        getchar();

        // ������ ��ȣ�� �߸��� ��� ���� �޽��� ��� �� ����
        int valid_selection = 0;
        for (int i = 0; i < line_num; i++) {
            if (selected_line == line_number_check[i]) {
                valid_selection = 1;
                break;
            }
        }
        if (!valid_selection) {
            printf("�߸��� �뷡�� ��ȣ�Դϴ�.\n");
            return;
        }
    }
    else if (line_num == 1) { // ���� �뷡�� �ߺ����� ���� ���
        line_number = 1; // �� ��ȣ �ʱ�ȭ
        file = fopen("song_list.txt", "r"); // ������ �ٽ� ��� ���
        while (fgets(buffer, STRING_SIZE, file) != NULL) {
            strcpy(dlt_print, buffer);
            char* token = strtok(buffer, "\t"); // ���� �����ڷ� ����Ͽ� ���ڿ��� ����
            char* song = strtok(NULL, "\t");

            // ����� ���� ��ġ�� �ش� �뷡 ���� ���
            if (strcmp(dlt_songname, token) == 0 && strcmp(dlt_singer, song) == 0) {
                for (int k = 0; k < strlen(dlt_print); k++) {
                    if (dlt_print[k] == '\t')
                        printf(" / ");
                    else
                        printf("%c", dlt_print[k]);
                }
                selected_line = line_number;
            }
            line_number++;
        }
        fclose(file);
    }
    else {
        printf(".!! ���� ����� �������� �ʽ��ϴ�\n");
        return;
    }

    // ������ ��ȣ�� �ش��ϴ� ���� �ٽ� �б� ���� fopen
    file = fopen("song_list.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    // ������ ��ȣ�� �ش��ϴ� ���� �ٽ� �о dlt_song�� ����
    line_number = 1;
    while (fgets(buffer, STRING_SIZE, file) != NULL) {
        if (line_number == selected_line) {
            strcpy(dlt_song, buffer);
            break;
        }
        line_number++;
    }

    fclose(file);

    // dlt_song ���ڿ��� song_list���� �����ϴ� �Լ�
    song_dlt("song_list.txt", dlt_song);
}

void song_dlt(const char* filename, const char* dlt_song) {   // dlt_song ���ڿ��� song_list���� �����ϴ� �Լ�
    FILE* input_file = fopen(filename, "r");    // ���� txt ����
    if (input_file == NULL) {
        printf("%s������ ã�� ���߽��ϴ�.\n", filename);
        return;
    }

    FILE* output_file = fopen("temp.txt", "w"); // ���� ����� txt ����
    if (output_file == NULL) {
        printf("���� ���� ����\n");
        fclose(input_file);
        return;
    }

    char line[STRING_SIZE];   // ���� ���ڿ��� ��Ƶ� �迭
    int found = 0;  // ���ڿ� �߰� ���� Ȯ�� ����

    while (fgets(line, sizeof(line), input_file)) {
        // ã������ ���ڿ��� ���Ե� ���� �ƴ� ��� �� ���Ͽ� ����
        if (strstr(line, dlt_song) == NULL) {
            fputs(line, output_file);
        }
        else {
            found = 1; // ���ڿ� �߰�
        }
    }

    char dlt_ans[STRING_SIZE];   // ���� ���� �亯 �Է� �迭
    if (found) {
        printf("���� �����Ͻðڽ��ϱ�? (Delete/...)\n");
        scanf("%s", &dlt_ans);   // ���� ����
        if (strcmp(dlt_ans, "Delete") == 0)   // "Delete"�� ��ġ�� ���� ����
            printf("���������� �뷡�� �����߽��ϴ�.\n");
        else
            return;   // ��ġ���� ������ ����
    }
    else {
        printf("..! ���� ����� �������� �ʽ��ϴ�\n");
    }

    fclose(input_file);
    fclose(output_file);

    remove(filename);   // ���� ���� ����
    rename("temp.txt", filename);   // ���� �� ������ �̸� ����
}