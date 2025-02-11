﻿#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "string.h"


struct node
{
	char inf[256];  // полезная информация
	struct node* next; // ссылка на следующий элемент 
};

struct node* head = NULL, * last = NULL, * f = NULL; // указатели на первый и последний элементы списка
int dlinna = 0;

struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	printf("Введите строку: \n");   // вводим данные
	scanf("%s", s);
	if (*s == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy(p->inf, s);

	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

void spstore(void)
{
	struct node* p = NULL;
	p = get_struct();
	if (head == NULL && p != NULL)	// если списка нет, то устанавливаем голову списка
	{
		head = p;
		last = p;
	}
	else
	{
		struct node* curr = head;
		struct node* prev = NULL;

		while (curr != NULL && strlen(curr->inf) < strlen(p->inf)) {
			prev = curr;
			curr = curr->next;
		}
		if (prev == NULL) {
			p->next = head;
			head = p;
		}
		else {
			prev->next = p;
			p->next = curr;
		}
		if (p->next == NULL) {
			last = p;
		}
	}
	return;
}


/* Просмотр содержимого списка. */
void review(void)
{
	int  flag = 0;
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		flag++;
		printf("%d) %s \n", flag, struc->inf);
		struc = struc->next;
	}
	return;
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	int choice;

	while (true)
	{	
		printf("\n1. Добавить элемент в список\n");
		printf("2. Просмотр списка\n");
		printf("Выберите действие: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			spstore(); // Добавление элемента
			break;
		case 2:
			review(); // Просмотр списка
			break;
		}
	}
}