
#include "header.h"

const int MAX = 100000;

void playlistMenu()
{
	char getMenu;

	printf("���ϴ� �޴��� �ش��ϴ� ���ڸ� �Է����ּ���.\n\n");
	printf("0. �ڷΰ���\n");
	printf("1. �÷��̸���Ʈ ���\n");
	printf("2. �÷��̸���Ʈ �߰�\n");
	printf("3. �÷��̸���Ʈ ����\n\n");
	printf("�޴� ����: ");
	scanf("%c", &getMenu);

	if (getMenu == '0')
	{
		//�����޴��� ���ư��ϴ�.
	}
	else if (getMenu == '1')
	{
		//�ø� ��� ���
		printPlaylist();
	}
	else if (getMenu == '2')
	{
		//�ø� �߰�
		addPlaylist();
	}
	else if (getMenu == '3')
	{
		//�ø� ����
		deletePlaylist();
	}
	else
	{
		//�ٽ� �ø��޴� ���� �������� �̵�
		playlistMenu();
	}

	return;
}

//�÷��̸���Ʈ ����� ���
void printPlaylist()
{
	char getMenu0 = NULL;
	printf("\n");

	FILE* fp = fopen("Playlist_list.txt", "r");

	char buffer[MAX] = { 0, };

	fread(buffer, 1, MAX, fp);
	printf("%s", buffer);

	fclose(fp);

	buffer[0] = '\n';

	printf("���ϴ� �÷��̸���Ʈ�� �ش��ϴ� ��ȣ�� �Է��ϼ���. (���� \"0\"�Է½� ���� �������� �̵�) : ");
	
	//���ۺ����
	while (getchar() != '\n');


	scanf("%c", &getMenu0);//���ϴ� �ø��� �ش��ϴ� ��ȣ �Է¹ޱ�

	while (getchar() != '\n');

	if (getMenu0 == '0')
	{
		//���� ������ ���
		playlistMenu();
	}
	else
	{
		FILE* fp = fopen("Playlist_list.txt", "r");
		char playlistName[MAX] = { 0, };
		while (feof(fp)==0) //���ϴ� �ø��� �ش��ϴ� ��ȣ�� �߰��� ������ ����
		{
			fgets(playlistName, MAX, fp);
			char c = playlistName[0]; //���ϴ� �ø��� ��Ī�� ��ȣ�ΰ� üũ
			if (c == getMenu0)
			{
				openPlaylist(playlistName);
				break;
			}
		}

		if (feof(fp) == 0)
		{
			fclose(fp);
			printPlaylist();
		}
	}
}

void openPlaylist(char* playlistName)
{
	//���� �÷��̸���Ʈ �̸����� ����� ���ڸ� ������
	//ex) <1. ��ٱ� �÷��̸���Ʈ -> ��ٱ� �÷��̸���Ʈ>�� �޾� ��������
	char* pliName = playlistName + 3;
	
	int len = strlen(pliName);
	if (len > 0 && pliName[len - 1] == '\n') {
		pliName[len - 1] = '\0'; // ���� ���ڸ� ����
	}

	strcat(pliName, ".txt");

	FILE* fs1 = fopen(pliName, "r");
	
	//������ ��ã���� ���
	if (fs1 == NULL)
	{
		//���α׷� ��������
	}

	//�÷��̸���Ʈ �� �뷡���� ���
	char buffer[MAX] = { 0, };

	fread(buffer, 1, MAX, fs1);
	printf("%c", pliName);
	printf("\n%s\n", buffer);

	fclose(fs1);

	printf("\n�Ʒ��� �޴� �� ���ϴ� ��ȣ�� �������ּ���. \n\n");
	printf("0. �ڷΰ���\n");
	printf("1. ���� �÷��̸���Ʈ�� �뷡 �߰�\n");
	printf("2. ���� �÷��̸���Ʈ�� �뷡 ����\n");
	printf("\n�޴����� : ");

	char getMenu;
	scanf("%c", &getMenu);
	if (getMenu == '0')
	{
		//���� �������� �̵�
		printPlaylist();
	}
	if (getMenu == '1')
	{
		addSong();
	}
	if (getMenu == '2')
	{
		deleteSong();
	}
	return;
}


//�÷��̸���Ʈ �߰�
void addPlaylist()
{

}

//�÷��̸���Ʈ ����
void deletePlaylist()
{

}

void addSong()
{

}

void deleteSong()
{

}
