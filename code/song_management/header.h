#pragma once
#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <ctype.h>
#include <time.h>
#include <Windows.h>

#define MAX_SIZE 100000
#define STRING_SIZE 256

void song_list_menu();//�뷡 ����Ʈ �� �޴�

void song_list_print();//�뷡 ����Ʈ ���

void get_dlt_song(char* dlt_song);//������ ���ڿ� �Է� �� ����

void song_dlt(char* filename, char* dlt_song);//�뷡 ����

void search();// �뷡 �˻� �Լ� ����

int searchSong(char* filename, char* searchWord, int found);

void searchTag(); //�±� �˻�

void searchZero(const char* filename, const char* tag, const char* word);//�±� �˻����� 0 �Է½�

void searchWordOfTag(const char* filename, const char* tag, const char* word); //�˻��� �˻�

//void playlistMenu();//�÷��̸���Ʈ ȭ�鿡 ó�� ���� ��

//void printPlaylist();//�÷��̸���Ʈ�� ����Ʈ�� ���

//void addPlaylist();//�÷��̸���Ʈ �߰�

//void deletePlaylist();//�÷��̸���Ʈ ����

//void openPlaylist(char* playlistName);//�÷��̸���Ʈ ����

void add_song();//�÷��̸���Ʈ�� �뷡 �߰�

void song_dlt(const char* filename, const char* dlt_song);