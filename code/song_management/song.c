#include "header.h"
//#include "playlist.h"

#define STRING_SIZE 256

int main() {
    int mode;
    int err = 0;
    while (1)
    {
        if (err == 0) {
            printf("\n�뷡 ���� ���α׷��Դϴ�.\n");
            printf("���ϴ� �޴��� �����ϼ���.\n\n");
        }
        else if (err == 1) {
            printf("\n�ش� �޴��� �������� �ʽ��ϴ�.\n");
            printf("���� �޴� �� �����ϼ���(����:1)\n\n");
            err = 0;
        }
        printf("1. �뷡 ����Ʈ ����\n");
        printf("2. �˻� ���\n");
        printf("3. �÷��̸���Ʈ\n");
        printf("4. ����\n\n");
        printf("�޴� ���� : ");
        scanf(" %d", &mode);

        switch (mode) {
        case 1: //�뷡 ����Ʈ ����
            song_list_menu();
            break;

        case 2: //�˻� ���
            searchMenu();
            break;

        case 3: //�÷��̸���Ʈ
            //playlistMenu();
            break;

        case 4: //����
            printf("���α׷��� �����մϴ�\n");
            break;

        default: //error
            while (getchar() != '\n'); //�Է� ���� ����
            err = 1;
            break;
        }
    }

    return 0;
}
