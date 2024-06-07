#include "playlist.h"
#include "searchInPli.h"
#define STRING_SIZE 256
#define MAX 1000
#define FILE_NAME 100

void delName(int index, const char* fileName);

void playlistMenu()
{
	int loop = 1;
	while (loop)
	{
		char input[STRING_SIZE];
		int getMenu;
		printf("\n���ϴ� �޴��� �ش��ϴ� ���ڸ� �Է����ּ���.\n\n");
		printf("0. �ڷΰ���\n");
		printf("1. �÷��̸���Ʈ ���\n");
		printf("2. �÷��̸���Ʈ �߰�\n");
		printf("3. �÷��̸���Ʈ ����\n");
		printf("4. �÷��̸���Ʈ ���� ����\n\n");
		printf("�޴� ����: ");
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0'; // ����Ű ����
		sscanf(input, "%d", &getMenu);

		switch (getMenu)
		{
		case 0:
		{
			//�����޴��� ���ư��ϴ�.
			loop = 0;
			break;
		}
		case 1:
		{
			//�ø� ��� ���
			printPlaylist();
			break;
		}
		case 2:
		{
			//�ø� �߰�
			addPlaylist();
			break;
		}
		case 3:
		{
			//�ø� ����
			deletePlaylist();
			break;
		}
		case 4:
		{
			//�ø� ���� ���� �Լ�
		}

		}
	}
	return;
}

//�÷��̸���Ʈ ����� ���
void printPlaylist()
{
	while (1)
	{
		system("cls");
		int getMenu;
		int index = 1;
		int listCount = 1;
		char input[STRING_SIZE];
		printf("\n");

		FILE* fp = fopen("Playlist_list.txt", "r");

		char buffer[MAX] = { 0, };

		while (fgets(buffer, MAX, fp) != NULL)
		{
			printf("%d. ", index);
			printf(buffer);
			index++;
		}


		buffer[0] = '\n';

		printf("\n���ϴ� �÷��̸���Ʈ�� �ش��ϴ� ��ȣ�� �Է��ϼ���. (���� \"0\"�Է½� ���� �������� �̵�) : ");

		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0'; // ����Ű ����
		sscanf(input, "%d", &getMenu);

		//���ϴ� �÷��̸���Ʈ�� ��ȣ�� ���� �Է¹���

		if (getMenu == 0)
		{
			fclose(fp);
			break;
		}

		else
		{
			fseek(fp, 0, SEEK_SET);//���� �����͸� �ٽ� ������ ó������ �̵�
			char playlistName[FILE_NAME] = { 0, };
			while (fgets(playlistName, MAX, fp) != NULL) //���ϴ� �ø��� �ش��ϴ� ��ȣ�� �߰��� ������ ����
			{
				if (listCount == getMenu)
				{
					fclose(fp);
					openPlaylist(playlistName);
				}
				else
				{
					listCount++;
				}
			}
			fclose(fp);
		}
	}

}

void openPlaylist(char playlistName[]) //playlistName�� ���� : 1. ��ٱ� �÷��̸���Ʈ
{
	while (1)
	{
		char input[STRING_SIZE];
		system("cls");
		//���� �÷��̸���Ʈ �̸����� ����� ���ڸ� ������
		//ex) <1. ��ٱ� �÷��̸���Ʈ -> ��ٱ� �÷��̸���Ʈ>�� �޾� ��������
		char textFileName[FILE_NAME] = { 0, };
		strcpy(textFileName, playlistName);

		int len = 0; // strlen(pliName);
		len = strlen(textFileName);

		if (len > 0 && textFileName[len - 1] == '\n')
		{
			textFileName[len - 1] = '\0'; // ���� ���ڸ� ����
		}
		printf("\n%s\n", playlistName);

		strcat(textFileName, ".txt");

		FILE* fp = fopen(textFileName, "r");

		char buffer[MAX] = { 0, };

		int index = 1;
		while (fgets(buffer, MAX, fp) != NULL)
		{
			printf("%d. ", index);
			printf(buffer);
			index++;
		}
		fclose(fp);

		printf("\n�Ʒ��� �޴� �� ���ϴ� ��ȣ�� �������ּ���. \n\n");
		printf("0. �ڷΰ���\n");
		printf("1. ���� �÷��̸���Ʈ�� �뷡 �߰�\n");
		printf("2. ���� �÷��̸���Ʈ�� �뷡 ����\n");
		printf("\n�޴����� : ");

		int getMenu;

		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0'; // ����Ű ����
		sscanf(input, "%d", &getMenu);

		if (getMenu == 0)
		{
			break;
		}
		else if (getMenu == 1)
		{
			addSongInPli(playlistName);
		}
		else if (getMenu == 2)
		{
			//FILE* fp = fopen(playlistName, "r");
			deleteSong(playlistName, textFileName);
		}

	}
	return;
}


//�÷��̸���Ʈ �߰�
void addPlaylist()
{
	char pName[STRING_SIZE];
	FILE* fp = fopen("Playlist_list.txt", "r");
	while (1) {
		int duplicated = 0;
		printf("�߰��ϰ� ���� �÷��̸���Ʈ�� �̸��� �Է����ּ���. (���� �Է½� ���� �������� �̵�):");
		gets(pName);

		char temp[STRING_SIZE];
		while (fgets(temp, sizeof(temp), fp) != NULL) {
			char existingName[STRING_SIZE];
			strcpy(existingName, temp + 3);
			existingName[strcspn(existingName, "\n")] = 0; //���� ���� ����
			if (strcmp(existingName, pName) == 0) {
				printf("�̹� �����ϴ� �÷��̸���Ʈ �̸��Դϴ�.�ٸ� �Է��� �Է����ּ���.\n");
				duplicated = 1;
				break;
			}
		}

		if (!duplicated) { //�ߺ��� ������ �ݺ� ����
			break;
		}
	}

	int j = 0;
	int count = 0;
	// �Է¹��� ���ڿ��� ����� �����θ� �̷�������� Ȯ��
	while (pName[j] != '\0')
	{
		if (pName[j] == ' ' || pName[j] == '\t') {
			count++;
		}
		j++;
	}
	//���� �Է½� ���� �������� �̵�
	if (j == count) {
		if (j == count) {
			fclose(fp);
			playlistMenu();
		}
	}
	//�߰��� ��ȣ ����
	fp = fopen("Playlist_list.txt", "r");
	int num = 0;  // ������ �����ϴ� �÷��̸���Ʈ ����
	char temp[STRING_SIZE];
	while (fgets(temp, sizeof(temp), fp) != NULL) {
		if (temp[0] >= '0' && temp[0] <= '9') {
			num++;
		}
	}


	fp = fopen("Playlist_list.txt", "a");
	fprintf(fp, "\n%d. %s", num + 1, removeSpace(pName)); // ���Ͽ� �÷��̸���Ʈ �߰� 

	// �÷��̸���Ʈ �ؽ�Ʈ ���� ����
	char filename[STRING_SIZE];
	sprintf(filename, "%s.txt", removeSpace(pName));
	fp = fopen(filename, "a");

	fclose(fp);
}

//�÷��̸���Ʈ ����
void deletePlaylist()
{
	while (1)
	{
		system("cls");
		int getMenu;
		char input[STRING_SIZE];
		printf("\n�÷��̸���Ʈ ���\n\n");

		FILE* fp = fopen("Playlist_list.txt", "r");

		char buffer[MAX] = { 0, };

		int index = 1;
		if (fgets(buffer, MAX, fp) != NULL)
		{
			printf("%d. ", index);
			printf(buffer);
			index++;
		}
		memset(buffer, 0, MAX);

		printf("\n������ �÷��̸���Ʈ�� ��ȣ�� �Է����ּ��� (���� \"0\"�Է½� ���� �������� �̵�) : ");


		fseek(fp, 0, SEEK_SET);//���� �����͸� �ٽ� ������ ó������ �̵�

		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0'; // ����Ű ����

		if (sscanf(input, "%d", &getMenu) == 0)
		{
			continue;
		}//���ۺ���

		if (getMenu == 0)
		{
			fclose(fp);
			break;
		}
		else
		{
			char playlistName[MAX] = { 0, };


			while (feof(fp) == 0) //���ϴ� �ø��� �ش��ϴ� ��ȣ�� �߰��� ������ ����
			{
				int pliIndexToRemove = 1;

				fgets(playlistName, MAX, fp);
				//���ϴ� �ø��� ��Ī�� ��ȣ�ΰ� üũ
				if (getMenu == pliIndexToRemove)
				{
					fclose(fp);

					int len = 0; // strlen(pliName);
					len = strlen(playlistName);

					if (len > 0 && playlistName[len - 1] == '\n')
					{
						playlistName[len - 1] = '\0'; // ���� ���ڸ� ����
					}

					strcat(playlistName, ".txt");
					//�÷��̸���Ʈ ���(Playlist_list.txt)���� ���� �ø� �̸��� �����ֱ�
					delName(getMenu, "Playlist_list.txt"); //�ε��� ��ȣ�� �ľ��ؼ� ������

					remove(playlistName);
					break;
					//�ø������ ����(�ø� ��ȣ) ���
				}

				pliIndexToRemove++;
			}
			fclose(fp);
		}
	}

}

void delName(int index, const char* fileName)//���Ͽ��� index�� �ش��ϴ� �뷡 �Ǵ� �ø��� ����
{

	char sourcefileName[FILE_NAME] = { 0, };
	strcpy(sourcefileName, fileName);
	FILE* sourceFile = fopen(sourcefileName, "r");//Playlist_list.txt������ ����


	FILE* tempFile; //���� ������ ������ ������
	char tempName[30] = "tempFile.txt";
	char buffer[MAX];

	tempFile = fopen(tempName, "w");
	int currentLine = 1;
	int lineToRemove = index;

	while (fgets(buffer, MAX, sourceFile) != NULL)
	{
		if (currentLine != lineToRemove) {
			fputs(buffer, tempFile);
		}
		currentLine++;
	}
	fclose(sourceFile);
	fclose(tempFile);

	remove(sourcefileName);
	rename("tempFile.txt", sourcefileName);

	return;
}

void addSongInPli(char pliName[])//�÷��̸���Ʈ�� �̸��� ����
{
	while (1)
	{
		system("cls");
		printf("\n");
		char textFileName[FILE_NAME] = { 0, };
		strcpy(textFileName, pliName);

		int len = 0;
		len = strlen(textFileName);

		if (len > 0 && textFileName[len - 1] == '\n')
		{
			textFileName[len - 1] = '\0'; // ���� ���ڸ� ����
		}

		strcat(textFileName, ".txt");

		int count = 1;
		char getMenu[STRING_SIZE];

		char buffer[MAX] = { 0, };

		FILE* songList = fopen("song_list.txt", "r");//��� �뷡���� ���
		while (fgets(buffer, sizeof(buffer), songList) != NULL) {
			printf("%d. ", count);
			printf("%s", buffer);
			count++;
		}
		fclose(songList);

		memset(buffer, 0, sizeof(buffer));//���� �����

		printf("\n�÷��̸���Ʈ�� �߰��� �뷡 ��ȣ�� �Է��ϰų� \"�˻�\"�� �Է��ϼ���\n");
		printf("���� \"0\"�� �Է½� ���� �������� �̵��մϴ�. \"�˻�\"�� �Է½� �뷡�� �˻��Ͽ� �߰��� �� �ֽ��ϴ�.\n\n");
		printf("�޴� ���� : ");

		char input[STRING_SIZE];
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0'; // ����Ű ����
		sscanf(input, "%s", getMenu);

		if (!strcmp(getMenu, "�˻�"))
		{
			searchMenuInPli(textFileName);
		}
		else if (!strcmp(getMenu, "0"))
			break;
		else
		{
			char* endptr = NULL;
			int songNum = 0;
			songNum = strtol(getMenu, &endptr, 10);

			if (endptr == getMenu) {
				break;
				printf("��ȯ ����: ���ڷ� �����ϴ� ���ڿ��� �ƴմϴ�.\n");
			}
			else if (*endptr != '\0') {
				break;
				printf("��ȯ ����: ���ڷ� ��ȯ�� �Ŀ� �����ִ� ���ڿ�: %s\n", endptr);
			}
			else
			{
				int lineNumber = 0;
				if (count - 1 < songNum)//���� �뷡 ������ ū ���ڸ� ������ ������ �������ش�.
					continue;
				else
				{
					FILE* songList = fopen("song_list.txt", "r");
					FILE* playlist = fopen(textFileName, "a");

					if (playlist == NULL)
						printf("������ �� �� �����ϴ�!\n");
					while (fgets(buffer, sizeof(buffer), songList) != NULL)
					{
						lineNumber++;
						if (lineNumber == songNum) {
							fputs(buffer, playlist);
							//fputs("\n", playlist);

							fclose(playlist);
							FILE* fp = fopen(pliName, "r"); //���� �� Ŀ���� ��ġ�� �ʱ�ȭ
							//fileArrange(playlist, pliName); //��ȣ�� ����

							break; // ã�� �Ŀ��� �� �̻� �ݺ��� �ʿ䰡 �����Ƿ� �ݺ����� ����
						}
					}

				}
			}

		}

	}
	return;
}


//�÷��̸���Ʈ���� �뷡�� ���� ->���� �÷��̸���Ʈ�� file pointer�� ��������
void deleteSong(char* pliName, char* fileName) //���ڷ� ���� pliName�� ".txt"�� �������� ���� �����̴�.
{
	while (1)
	{
		int index = 1;

		system("cls");
		char playlistName[FILE_NAME] = { 0, };

		strcpy(playlistName, pliName);

		int len = 0;
		len = strlen(playlistName);

		if (len > 0 && playlistName[len - 1] == '\n')
		{
			playlistName[len - 1] = '\0'; // ���� ���ڸ� ����
		}

		FILE* fp = fopen(fileName, "r");

		int getMenu;
		char input[STRING_SIZE];

		printf("\n\n%s\n\n", playlistName);

		char buffer[MAX] = { 0, };

		while (fgets(buffer, MAX, fp) != NULL)
		{
			printf("%d. ", index);
			printf(buffer);
			index++;
		}


		//printf("\n%s\n", buffer);

		printf("\n���� \"0\"�� �Է½� ���� �������� �̵��մϴ�.\n");
		printf("�÷��̸���Ʈ���� ������ �뷡�� �ش��ϴ� ��ȣ�� �Է����ּ��� : ");

		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0'; // ����Ű ����
		sscanf(input, "%d", &getMenu);



		if (getMenu == 0)
		{
			fclose(fp);
			break;
		}
		else
		{
			fclose(fp);

			delName(getMenu, fileName);

			printf("\n");
		}
	}
}

char* removeSpace(char* str) {
	char* start = str;
	char* finish = str + strlen(str) - 1;
	//���� ����
	while (*start != '\0') {
		if ((*start == ' ') || (*start == '\t'))
			start++;
		else
			break;
	}
	//���� ����
	while (1)
	{
		if ((*finish == ' ') || (*finish == '\t'))
			finish--;
		else {
			*(finish + 1) = '\0';
			break;
		}
	}

	return start;
}
