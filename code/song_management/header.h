#pragma once
#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <time.h>
#include <Windows.h>

void song_list_menu();//�뷡 ����Ʈ �� �޴�

void song_list_print();//�뷡 ����Ʈ ���

void song_add();//�뷡 �߰�

void song_dlt(char* filename);//�뷡 ����

void searchMenu();//�˻� �޴� ȭ��

void search();// �뷡 �˻� �Լ� ����

void searchSong(char* filename, char* searchWord, int found);

void searchTag(); //�±� �˻�

void searchZero();//�±� �˻����� 0 �Է½�

void searchWordOfTag(const char* filename, const char* tag, const char* word); //�˻��� �˻�

void playlistMenu();//�÷��̸���Ʈ ȭ�鿡 ó�� ���� ��

void printPlaylist();//�÷��̸���Ʈ�� ����Ʈ�� ���

void addPlaylist();//�÷��̸���Ʈ �߰�

void deletePlaylist();//�÷��̸���Ʈ ����

void openPlaylist(char* playlistName);//�÷��̸���Ʈ ����

void addSong();//�÷��̸���Ʈ�� �뷡 �߰�

void deleteSong();//�÷��̸���Ʈ�� �뷡 ����