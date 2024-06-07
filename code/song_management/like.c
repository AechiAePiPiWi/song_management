#include "header.h"

void push_like();
void like_song_print();

int is_valid_number(const char* str) {
    // ���ڿ��� �� ���ڰ� �������� Ȯ��
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]) && str[i] != '\n') {
            return 0;
        }
    }
    return 1;
}

void like_menu() {
    int err = 0;
    while (1)
    {
        if (err == 1)
        {
            printf("�ش� �޴��� �������� �ʽ��ϴ�. �ٽ� �����ϼ���.\n\n");
            err = 0;
        }
        else {
            printf("\n���ƿ� �޴��� �����ϼ̽��ϴ�.\n");
            printf("���ϴ� �޴��� �����ϼ���.\n\n");
        }
        printf("1. ���ƿ� ������\n");
        printf("2. ���ã�� - ���ƿ� �� �뷡 ���\n");
        printf("0. �ڷΰ���\n\n");

        char input[STRING_SIZE];
        int number; //�޴� ������ �ùٸ� �Է��� �� ���� ���� ����

        printf("�޴� ����: ");
        while (fgets(input, sizeof(input), stdin)) {
            // ���๮�� ����
            input[strcspn(input, "\n")] = '\0';

            if (is_valid_number(input)) { //��� �Է��� ���ڷ� �̷���� �ִ��� Ȯ��
                number = atoi(input);
                break;
            }
            else { //���ڷθ� �̷���� ���� ������
                err = 1;
                continue;
            }
        }

        switch (number)
        {
        case 1:
            push_like();
            break;
        case 2:
            like_song_print();
            break;
        case 0:
            return 0;
        }
    }
    return 0;
}

// �������� Ȯ���ϴ� �Լ�
int is_digit(char ch) {
    return ch >= '0' && ch <= '9';
}

// ���� ������ ���ڸ� 1 �ø��� �Լ�
void like_plus(char* line) {
    int len = strlen(line);
    // ���ڸ� ã�� ���� �ڿ������� Ž��
    for (int i = len - 1; i >= 0; i--) {
        if (is_digit(line[i])) {
            // ���ڸ� ���ڿ����� ���ڷ� ��ȯ
            int num_start = i;
            while (i >= 0 && is_digit(line[i])) {
                i--;
            }
            i++;

            char number_str[STRING_SIZE];
            strncpy(number_str, &line[i], num_start - i + 1);
            number_str[num_start - i + 1] = '\0';

            // ���ڸ� 1 ����
            int number = atoi(number_str);
            number += 1;

            // ���ڸ� ���ڿ��� �ٽ� ��ȯ
            char new_number_str[STRING_SIZE];
            sprintf(new_number_str, "%d", number);

            // ���� ���ڸ� ���ο� ���ڷ� ��ü
            strncpy(&line[i], new_number_str, strlen(new_number_str));
            line[i + strlen(new_number_str)] = '\n';
            break;
        }
    }
}

void like_song(const char* filename, int target_line) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("������ �� �� �����ϴ�");
        exit(EXIT_FAILURE);
    }

    // �ӽ� ������ �����Ͽ� ������ ������ �� ����
    FILE* temp_file = fopen("temp.txt", "w");
    if (!temp_file) {
        perror("�ӽ� ������ �� �� �����ϴ�");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    char line[STRING_SIZE];
    int current_line = 1;

    while (fgets(line, sizeof(line), file)) {
        if (current_line == target_line) {
            // ���� ������ ���ڸ� 1 ����
            like_plus(line);
        }
        fputs(line, temp_file);
        current_line++;
    }

    fclose(file);
    fclose(temp_file);

    // ���� ������ �����
    if (remove(filename) != 0) {
        perror("���� ������ ������ �� �����ϴ�");
        exit(EXIT_FAILURE);
    }

    if (rename("temp.txt", filename) != 0) {
        perror("�ӽ� ������ ���� ���Ϸ� �̸��� ������ �� �����ϴ�");
        exit(EXIT_FAILURE);
    }
}

void push_like()
{
    printf("\n���ƿ並 ���� �뷡�� �����ϼ���.");
    printf("\n\n���� / ���� / �۰ / �ۻ簡 / �帣 / ����ð� / �ٹ��� / �ٹ� ��� ��¥ / ���ƿ�\n\n");
    FILE* fp;
    fp = fopen("song_list.txt", "r"); //�ؽ�Ʈ ���� �ҷ�����
    char name[STRING_SIZE]; //����
    char singer[STRING_SIZE]; //����
    char song_writer[STRING_SIZE]; //�۰
    char lylic_writer[STRING_SIZE]; //�ۻ簡
    char genre[STRING_SIZE]; //�帣
    char playtime[STRING_SIZE]; //����ð�
    char album_name[STRING_SIZE]; //�ٹ���
    char album_time[STRING_SIZE]; //�ٹ� ��� ��¥

    int num = 1;

    char song[STRING_SIZE * 8]; //�ҷ��� �� ��
    while (fgets(song, sizeof(song), fp) != NULL) //�� �� �� �ҷ�����
    {
        sscanf(song, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t\n]", name, singer, song_writer, lylic_writer, genre, playtime, album_name, album_time); //��Ű�� �����ڷ� �ϳ��� �ҷ�����
        printf("%d. %s / ",num, name); //�뷡 ��ȣ�� ���� ���
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
                        size = size + 1; //���� �ι��� �̸����� �̵�
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

        int k = strlen(name) + strlen(singer) + strlen(song_writer) + strlen(lylic_writer) + 4; //���� ���� ó��
        for (k; k < strlen(song); k++) {
            if (song[k] == '\t')
                printf(" / ");
            else
                printf("%c", song[k]);
        }
        num++;
    }
    fclose(fp); //�뷡 ��� ��

    printf("\n\n��ȣ�� �Է��ϼ��� :");
    char input[STRING_SIZE];
    int number; //�޴� ������ �ùٸ� �Է��� �� ���� ���� ����

    while (fgets(input, sizeof(input), stdin)) {
        // ���๮�� ����
        input[strcspn(input, "\n")] = '\0';

        if (is_valid_number(input)) { //��� �Է��� ���ڷ� �̷���� �ִ��� Ȯ��
            number = atoi(input);
            break;
        }
        else { //���ڷθ� �̷���� ���� ������
            printf("�߸��� �뷡�� ��ȣ�Դϴ�.\n");
            return 0;
        }
    }

    const char* filename = "song_list.txt";
    like_song(filename, number);
    printf("%s�� ���ƿ䰡 1 ���� �߽��ϴ�.\n", name);

    return 0;
}

// �� ���� ������ ���ڸ� �����ϴ� �Լ�
int getLastNumber(char* line) {
    int len = strlen(line);
    // ���ڸ� ã�� ���� �ڿ������� Ž��
    for (int i = len - 1; i >= 0; i--) {
        if (is_digit(line[i])) {
            // ���ڸ� ���ڿ����� ���ڷ� ��ȯ
            int num_start = i;
            while (i >= 0 && is_digit(line[i])) {
                i--;
            }
            i++;

            char number_str[STRING_SIZE]; //���ڸ� ������ char ����
            strncpy(number_str, &line[i], num_start - i + 1);
            number_str[num_start - i + 1] = '\0';

            int number = atoi(number_str); //���ڸ� int������ ��ȯ
            return number; //������ ���� ����
        }
    }
}

int compare(const void* a, const void* b) { //qsort()�� ����� ������������ ������ �� ����� �� �Լ�
    int int_a = *(int*)a;
    int int_b = *(int*)b;

    if (int_a < int_b) return 1;
    else if (int_a > int_b) return -1;
    else return 0;
}

void like_song_print() //���ƿ� ��� ���
{
    printf("\n�� ���ã��\n\n");
    printf("���� / ���� / �۰ / �ۻ簡 / �帣 / ����ð� / �ٹ��� / �ٹ���ó�¥ / ���ƿ�\n\n");

    int last_numbers[STRING_SIZE] = { 0 }; //���ƿ� ���ڵ��� ������ �迭, �ߺ��� ���� ����ȴ�.
    int number_count = 0; //�迭�� �� ���� ����
    char line[STRING_SIZE * 8]; //�� �پ� ������ �迭

    // ������ �о��
    FILE* file = fopen("song_list.txt", "r");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        int last = getLastNumber(line); //���ƿ� ���ڸ� �ӽ� ����
        if (last != 0) //���ƿ䰡 0�� �ƴϸ�
        {
            int k = 0;
            int exist = 0; //�ߺ��� �ִ��� �˻��ϴ� ����
            while (1)
            {
                if (k > number_count) //�ߺ��� ������
                    break;
                else if (last_numbers[k] == last) //�ߺ��� ����
                {
                    exist = 1; //�����Ѵٰ� �˷���
                    break;
                }
                k++;
            }
            if (exist == 0) //�ߺ��� ��� exist�� 0�̸� 
            {
                last_numbers[number_count] = last; //�迭�� ���ƿ� ���� ����
                number_count++; //�迭 ũ�� ����
            }
        }
    }
    fclose(file);

    qsort(last_numbers, number_count, sizeof(int), compare); //���ƿ� ���ڰ� �� �迭�� ������������ ����

    char name[STRING_SIZE]; //����
    char singer[STRING_SIZE]; //����
    char song_writer[STRING_SIZE]; //�۰
    char lylic_writer[STRING_SIZE]; //�ۻ簡
    char genre[STRING_SIZE]; //�帣
    char playtime[STRING_SIZE]; //����ð�
    char album_name[STRING_SIZE]; //�ٹ���
    char album_time[STRING_SIZE]; //�ٹ� ��� ��¥

    for (int i = 0; i < number_count; i++) //���ƿ� ���ڰ� �� �迭��ŭ �ݺ�
    {
        file = fopen("song_list.txt", "r");
        while (fgets(line, sizeof(line), file) != NULL)
        {
            int last = getLastNumber(line); //���ƿ� ���� �ӽ� ����
            if (last == last_numbers[i]) //���� ���ƿ� ���ڰ� ���ƿ� �迭�� �� ���ڿ� ��ġ�ϸ� ��½���
            {
                sscanf(line, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t\n]", name, singer, song_writer, lylic_writer, genre, playtime, album_name, album_time); //��Ű�� �����ڷ� �ϳ��� �ҷ�����
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
                                size = size + 1; //���� �ι��� �̸����� �̵�
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

                int k = strlen(name) + strlen(singer) + strlen(song_writer) + strlen(lylic_writer) + 4; //���� ���� ó��
                for (k; k < strlen(line); k++) {
                    if (line[k] == '\t')
                        printf(" / ");
                    else if (k + 1 == strlen(line) && line[k] != '\n') //������ �� ���� ���
                        printf("%c\n", line[k]);
                    else
                        printf("%c", line[k]);
                }
            }
        }
        fclose(file);
    }

    return 0;
}