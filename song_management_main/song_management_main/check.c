#include "header.h"

void check() { // song_list.txt ������ �ִ��� Ȯ��
    FILE* txttest = fopen("song_list.txt", "r");
    if (txttest == NULL) {      //������ ���� ����
        printf("�뷡����Ʈ ������ ������ �����Ǿ����ϴ�.");
        Sleep(1500);
        system("cls");          //1.5�� �Ŀ� ������Ʈ â ����
        FILE* txttest = fopen("song_list.txt", "w");
        fclose(txttest);
    }
    else {                      //������
        // printf("Ȯ��");
        fclose(txttest);
    }
}