#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

void print_hand(int userleft, int userright, int comleft, int comright);
void menu(void);
int RSP(void);
void game(int Luser, int Ruser, int Lcom, int Rcom);

int main()
{
	srand((unsigned)time(NULL));

	menu();		//�޴� ���
	int Lcom = 1, Rcom = 1, Luser = 1, Ruser = 1;
	if (RSP() == 0)		//���������� �� ���ϰ��� 0�� ��(���� ��)
	{
		if (rand() % 2 + 1 == 1)
		{
			Luser += 1;
			printf("��ǻ�Ͱ� ������ ���� ���� �����߽��ϴ�.\n");
		}
		else
		{
			Ruser += 1;
			printf("��ǻ�Ͱ� ������ ������ ���� �����߽��ϴ�.\n");
		}
	}	 // 2�� �� �ϳ��� ���� ���ڸ� �ο��Ͽ� ����
	game(Luser, Ruser, Lcom, Rcom);

	system("pause");
	return 0;
}

void print_hand(int userleft, int userright, int comleft, int comright)
{
	int lefthand[6][7][10] = {			//3���� �迭�� ���� �� ��� �׸� �����
		{
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 2, 3, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
			{ 2, 3, 2, 3, 2, 3, 1, 1, 0, 0 },
			{ 1, 4, 5, 4, 5, 4, 5, 1, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 4, 3, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0 }
		},
		{
			{ 0, 0, 0, 0, 2, 3, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 1, 1, 2, 3, 0, 0 },
			{ 0, 0, 0, 0, 1, 1, 1, 1, 0, 0 },
			{ 2, 3, 2, 3, 1, 1, 1, 1, 0, 0 },
			{ 1, 4, 5, 4, 5, 4, 5, 1, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 4, 3, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0 }
		},
		{
			{ 0, 0, 2, 3, 2, 3, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 2, 3, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 1, 1, 0, 0 },
			{ 2, 3, 1, 1, 1, 1, 1, 1, 0, 0 },
			{ 1, 4, 5, 4, 5, 4, 5, 1, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 4, 3, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0 }
		},
		{
			{ 0, 0, 2, 3, 2, 3, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 2, 3, 0, 0 },
			{ 2, 3, 1, 1, 1, 1, 1, 1, 0, 0 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
			{ 1, 4, 5, 4, 5, 4, 5, 1, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 4, 3, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0 }
		},
		{
			{ 0, 0, 2, 3, 2, 3, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 2, 3, 0, 0 },
			{ 2, 3, 1, 1, 1, 1, 1, 1, 0, 0 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 2, 3 },
			{ 1, 4, 5, 4, 5, 4, 5, 1, 1, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 4, 5, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 }
		}
	};
	int righthand[6][7][10] = {
		{
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 2, 3, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 2, 3, 2, 3, 2, 3 },
			{ 0, 0, 1, 4, 5, 4, 5, 4, 5, 1 },
			{ 0, 2, 5, 0, 0, 0, 0, 0, 0, 1 },
			{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 }
		},
		{
			{ 0, 0, 0, 0, 2, 3, 0, 0, 0, 0 },
			{ 0, 0, 2, 3, 1, 1, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 2, 3, 2, 3 },
			{ 0, 0, 1, 4, 5, 4, 5, 4, 5, 1 },
			{ 0, 2, 5, 0, 0, 0, 0, 0, 0, 1 },
			{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 }
		},
		{
			{ 0, 0, 0, 0, 2, 3, 2, 3, 0, 0 },
			{ 0, 0, 2, 3, 1, 1, 1, 1, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 1, 1, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 1, 1, 2, 3 },
			{ 0, 0, 1, 4, 5, 4, 5, 4, 5, 1 },
			{ 0, 2, 5, 0, 0, 0, 0, 0, 0, 1 },
			{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 }
		},
		{
			{ 0, 0, 0, 0, 2, 3, 2, 3, 0, 0 },
			{ 0, 0, 2, 3, 1, 1, 1, 1, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 1, 1, 2, 3 },
			{ 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 0, 0, 1, 4, 5, 4, 5, 4, 5, 1 },
			{ 0, 2, 5, 0, 0, 0, 0, 0, 0, 1 },
			{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 }
		},
		{
			{ 0, 0, 0, 0, 2, 3, 2, 3, 0, 0 },
			{ 0, 0, 2, 3, 1, 1, 1, 1, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 1, 1, 2, 3 },
			{ 2, 3, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 4, 5, 4, 5, 4, 5, 1 },
			{ 1, 4, 5, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 }
		}
	};
	int comlefthand[6][7][10], comrighthand[6][7][10];  //��ǻ���� ��
	int i, j, k;
	for (i = 0; i < 6; i++)
		for (j = 0; j < 7; j++)
			for (k = 0; k < 10; k++)
			{
				comlefthand[i][6 - j][k] = righthand[i][j][k];
				comrighthand[i][6 - j][k] = lefthand[i][j][k];	//��ǻ���� ���� ������ �տ� 180�� ����������� ����� ���� �� �ٲٱ�
			}
	for (i = 0; i < 6; i++)
		for (j = 0; j < 7; j++)
			for (k = 0; k < 10; k++)
			{						//���� ������ �� ���� �ʴ� ���� ���� ��ü
				if (comlefthand[i][j][k] == 2)
					comlefthand[i][j][k] = 4;
				else if (comlefthand[i][j][k] == 3)
					comlefthand[i][j][k] = 5;
				else if (comlefthand[i][j][k] == 4)
					comlefthand[i][j][k] = 2;
				else if (comlefthand[i][j][k] == 5)
					comlefthand[i][j][k] = 3;
				if (comrighthand[i][j][k] == 2)
					comrighthand[i][j][k] = 4;
				else if (comrighthand[i][j][k] == 3)
					comrighthand[i][j][k] = 5;
				else if (comrighthand[i][j][k] == 4)
					comrighthand[i][j][k] = 2;
				else if (comrighthand[i][j][k] == 5)
					comrighthand[i][j][k] = 3;
			}
	for (j = 0; j < 7; j++)		 //���ں��� ���� �Ǵ� ���� �Է�.
	{	
		i = comright;
		printf("\n");
		for (k = 0; k < 10; k++)
		{
			switch (comrighthand[i][j][k]) 
			{
			case 1:printf("��"); break;
			case 2:printf("��"); break;
			case 3:printf("��"); break;
			case 4:printf("��"); break;
			case 5:printf("��"); break;
			default: printf(" "); break;
			}
		}
		printf(" ");
		i = comleft;
		for (k = 0; k < 10; k++)
		{
			switch (comlefthand[i][j][k])
			{
			case 1:printf("��"); break;
			case 2:printf("��"); break;
			case 3:printf("��"); break;
			case 4:printf("��"); break;
			case 5:printf("��"); break;
			default: printf(" "); break;
			}
		}
	}
	for (j = 0; j < 7; j++)
	{
		i = userleft;
		printf("\n");
		for (k = 0; k < 10; k++)
		{
			switch (lefthand[i][j][k])
			{
			case 1:printf("��"); break;
			case 2:printf("��"); break;
			case 3:printf("��"); break;
			case 4:printf("��"); break;
			case 5:printf("��"); break;
			default: printf(" "); break;
			}
		}
		printf(" ");
		i = userright;
		for (k = 0; k < 10; k++)
		{
			switch (righthand[i][j][k])
			{
			case 1:printf("��"); break;
			case 2:printf("��"); break;
			case 3:printf("��"); break;
			case 4:printf("��"); break;
			case 5:printf("��"); break;
			default: printf(" "); break;
			}
		}
	}
	printf("\n");
}
void menu(void)
{
	printf("-----------------------------------------������ ����-----------------------------------------\n\n");
	printf("���� ��Ģ : ���ݹ����� ģ ����� �� �հ��� ����+���� ���� �հ��� ������� �հ����� �ɴ�.\n");
	printf("            ������ 1 - 1�̸� �� �տ��� ��� �հ����� ��� �� ���� �ƿ�. \n");
	printf("            ���� ������ 2 �̻��̸� �հ��� ��迭�� �� �� ������ ���ݱ��� ��뿡�� �Ѱ��ش�.\n");
	printf("            �� ���� ��� �ƿ� ó���Ǹ� �й�� ���ÿ� ���� ��.\n");
	printf("            ���� ���� : �� �ո� ����� �� ��ġ�� �ٲٱ�� �����̴�.\n\n");
	printf("                             < ENTERŰ�� ���� ������ �����մϴ�.> ");

	while (1)
	{
		char ch = _getch();
		if (ch == 13)		//����Ű �Է� ��
		{			
			system("cls");	//ȭ�� û��
			break;
		}
	}
}
int RSP(void)
{
	printf("���� ���ϱ� ���� ������������ �մϴ�.\n");
	Sleep(2000);	//2�� ����
	system("cls");
	printf("����, ����, �� �� �ϳ��� ������ : ");
	char usersel[20];
	int ruser, rcom, user;
A:	scanf("%s", usersel);
	if (strcmp(usersel, "����") == 0)
		ruser = 1;
	else if (strcmp(usersel, "��") == 0)
		ruser = 2;
	else if (strcmp(usersel, "����") == 0)
		ruser = 3;
	else
	{
		printf("�߸� �Է��ϼ̽��ϴ�.\n�ٽ� �Է��Ͻʽÿ� : ");
		goto A;
	}
	rcom = rand() % 3 + 1;
	if (rcom == 1)
		printf("��ǻ�� : ����\n");
	else if (rcom == 2)
		printf("��ǻ�� : ��\n");
	else
		printf("��ǻ�� : ����\n"); //3���� �ϳ��� �������� �����Ͽ� ��ǻ���� ����,����,�� ����

	if (rcom == ruser)
	{
		printf("�����ϴ�.\n�ٽ� ���ֽʽÿ� : ");
		goto A;
	}
	else if (rcom - ruser == 1 || (ruser == 3 && rcom == 1)) //����,��,���� �� ������� 1,2,3�̶� �� �� �������ڰ� ��ǻ�ͺ��� 1 ������ ���� �� �̿�. �� 4�� �����Ƿ� 3�϶��� ���� ���� ����
	{
		printf("�����ϴ�.\n��ǻ�Ͱ� ���� �����մϴ�.\n");
		user = 0;
	}
	else
	{
		printf("�̰���ϴ�.\n");
		user = 1;
	}
	Sleep(2000);
	system("cls");
	return user;
}
void game(int Luser, int Ruser, int Lcom, int Rcom)
{
	while (!(Luser == 0 && Ruser == 0 || Lcom == 0 && Rcom == 0)) //������ �������ʿ��� ���� �ݺ��� �̿�. ��ǻ�ͳ� ������ ����� ��� ������ �� �ݺ��� ����
	{
	B:	print_hand(Luser, Ruser, Lcom, Rcom); //���� �� �հ� ��ǻ���� �� ����Ʈ
		char sel1[15], sel2[15];
		if (Luser != 0 && Ruser != 0) //������ ��� ��� ������ ���� ���
		{
		E:	printf("1. ����\n2. �� ���ġ\n���� : ");
			int attsel0;
			scanf("%d", &attsel0);
			if (attsel0 == 1) //����
			{
				if (Lcom != 0 && Rcom != 0) //��ǻ�Ͱ� ��� ��� ���� ��
				{
					printf("��ǻ���� �޼հ� ������ �� ������ �� : ");
					scanf("%s", sel1);
					printf("������ �޼հ� ������ �� ������ �� : ");
					scanf("%s", sel2);
				}
				else if (Lcom == 0)  //��ǻ���� �޼��� ��� ������ ��
				{
					printf("��ǻ���� �������� �����մϴ�.\n");
					strcpy(sel1, "������");
					printf("������ �޼հ� ������ �� ������ �� : ");
					scanf("%s", sel2);
				}
				else if (Rcom == 0)  //��ǻ���� �������� ��� ������ ��
				{
					printf("��ǻ���� �޼��� �����մϴ�.\n");
					strcpy(sel1, "�޼�");
					printf("������ �޼հ� ������ �� ������ �� : ");
					scanf("%s", sel2);
				}
				if (strcmp(sel1, "�޼�") == 0)  //�Է¹��� ������ ���� �޼��� ��
				{
					if (strcmp(sel2, "�޼�") == 0)
						Lcom += Luser;
					else if (strcmp(sel2, "������") == 0)
						Lcom += Ruser;
					else
					{
						system("cls");
						printf("�߸� �Է��ϼ̽��ϴ�.\n");
						Sleep(1000);
						system("cls");
						goto B;
					}
				}
				else if (strcmp(sel1, "������") == 0)
				{
					if (strcmp(sel2, "�޼�") == 0)
						Rcom += Luser;
					else if (strcmp(sel2, "������") == 0)
						Rcom += Ruser;
					else
					{
						system("cls");
						printf("�߸� �Է��ϼ̽��ϴ�.\n");
						Sleep(1000);
						system("cls");
						goto B;
					}
				}
				else
				{
					system("cls");
					printf("�߸� �Է��ϼ̽��ϴ�.\n");
					Sleep(1000);
					system("cls");
					goto B;
				}
			}
			else if (attsel0 == 2) //���ġ
			{
				printf("1. �޼տ��� ����������\n2. �����տ��� �޼�����\n���� : ");
				int crossnum;
				scanf("%d", &crossnum);
				if (crossnum == 1)
				{
					int movenum01;
					while (1)
					{
						printf("�޼տ��� ���������� �󸶳� �̵���Ű�ڽ��ϱ�? : ");
						scanf("%d", &movenum01);
						if (movenum01 >= 1 && movenum01 <= Luser && movenum01 + Ruser < 5) //�Է��� ���� 1~�޼հ����� �̳�, �Է¼�+�����հ������� 5���̸��� ��
						{
							Luser -= movenum01;
							Ruser += movenum01;
							break;	//�ݺ��� Ż��
						}
						else
							printf("�߸� �Է��ϼ̽��ϴ�.\n");
					}
				}
				else if (crossnum == 2)
				{
					int movenum02;
					while (1)
					{
						printf("�����տ��� �޼����� �󸶳� �̵���Ű�ڽ��ϱ�? : ");
						scanf("%d", &movenum02);
						if (movenum02 >= 1 && movenum02 <= Ruser && movenum02 + Luser < 5) //�Է��� ���� 1~�����հ����� �̳�, �Է¼�+�޼հ������� 5���̸��� ��
						{
							Luser += movenum02;
							Ruser -= movenum02;
							break;
						}
						else
							printf("�߸� �Է��ϼ̽��ϴ�.\n");
					}
				}
			}
			else
			{
				printf("�߸� �Է��ϼ̽��ϴ�.\n�ٽ� �Է����ֽʽÿ� : \n");
				goto E;
			}
		}
		else if (Luser == 0) //������ �޼��� ��� �������
		{
		C:	printf("1. ����\n2. �� ���ġ\n���� : ");
			int attsel;
			scanf("%d", &attsel);
			if (attsel == 1) //����
			{
				if (Lcom == 0)
				{
					printf("��ǻ���� �������� �����մϴ�.\n");
					strcpy(sel1, "������");
					printf("������ ���������� �����մϴ�.\n");
					strcpy(sel2, "������");
				}
				else if (Rcom == 0)
				{
					printf("��ǻ���� �޼��� �����մϴ�.\n");
					strcpy(sel1, "�޼�");
					printf("������ ���������� �����մϴ�.\n");
					strcpy(sel2, "������");
				}
				else
				{
					printf("��ǻ���� �޼հ� ������ �� ������ �� : ");
					scanf("%s", sel1);
					printf("������ ���������� �����մϴ�.\n");
					strcpy(sel2, "������");
				}
				if (strcmp(sel1, "�޼�") == 0)
				{
					if (strcmp(sel2, "�޼�") == 0)
						Lcom += Luser;
					else if (strcmp(sel2, "������") == 0)
						Lcom += Ruser;
					else
					{
						system("cls");
						printf("�߸� �Է��ϼ̽��ϴ�.\n");
						Sleep(1000);
						system("cls");
						goto B;
					}
				}
				else if (strcmp(sel1, "������") == 0)
				{
					if (strcmp(sel2, "�޼�") == 0)
						Rcom += Luser;
					else if (strcmp(sel2, "������") == 0)
						Rcom += Ruser;
					else
					{
						system("cls");
						printf("�߸� �Է��ϼ̽��ϴ�.\n");
						Sleep(1000);
						system("cls");
						goto B;
					}
				}
				else
				{
					system("cls");
					printf("�߸� �Է��ϼ̽��ϴ�.\n");
					Sleep(1000);
					system("cls");
					goto B;
				}
			}
			else if (attsel == 2) //���ġ
			{
				if (Ruser == 1)
				{
					printf("�հ��� ������ 2�� �̻��̿��� �մϴ�.\n"); //��Ģ�� �հ��� �ϳ��� �� ��ġ�̵��� �Ұ���.
					goto C;
				}
				int movenum001;
				while (1)
				{
					printf("�����տ��� �޼����� �󸶳� �̵���Ű�ڽ��ϱ�? : ");
					scanf("%d", &movenum001);
					if (movenum001 == Ruser)
						printf("%d���� ���� ���ڸ� �̵���ų �� �ֽ��ϴ�.\n", Ruser);           //��Ģ�� ��ġ�� �̵� �����̹Ƿ� ��� �հ��� �̵� ����
					else if (movenum001 >= 1 && movenum001 <= Ruser && movenum001 + Luser < 5) //�Է��� ���� 1~�����հ����� �̳�, �Է¼�+�޼հ������� 5���̸��� ��
					{
						Luser += movenum001;
						Ruser -= movenum001;
						break;
					}
					else
						printf("�߸� �Է��ϼ̽��ϴ�.\n");
				}
			}
			else
			{
				printf("�߸� �Է��ϼ̽��ϴ�.\n ");
				goto C;
			}
		}
		else if (Ruser == 0)
		{
		D:	printf("1. ����\n2. �� ���ġ\n���� : ");
			int attsel2;
			scanf("%d", &attsel2);
			if (attsel2 == 1) //����
			{
				if (Lcom == 0)
				{
					printf("��ǻ���� �������� �����մϴ�.\n");
					strcpy(sel1, "������");
					printf("������ �޼����� �����մϴ�.\n");
					strcpy(sel2, "�޼�");
				}
				else if (Rcom == 0)
				{
					printf("��ǻ���� �޼��� �����մϴ�.\n");
					strcpy(sel1, "�޼�");
					printf("������ �޼����� �����մϴ�.\n");
					strcpy(sel2, "�޼�");
				}
				else
				{
					printf("��ǻ���� �޼հ� ������ �� ������ �� : ");
					scanf("%s", sel1);
					printf("������ �޼����� �����մϴ�.\n");
					strcpy(sel2, "�޼�");
				}
				if (strcmp(sel1, "�޼�") == 0)
				{
					if (strcmp(sel2, "�޼�") == 0)
						Lcom += Luser;
					else if (strcmp(sel2, "������") == 0)
						Lcom += Ruser;
					else
					{
						system("cls");
						printf("�߸� �Է��ϼ̽��ϴ�.\n");
						Sleep(1000);
						system("cls");
						goto B;
					}
				}
				else if (strcmp(sel1, "������") == 0)
				{
					if (strcmp(sel2, "�޼�") == 0)
						Rcom += Luser;
					else if (strcmp(sel2, "������") == 0)
						Rcom += Ruser;
					else
					{
						system("cls");
						printf("�߸� �Է��ϼ̽��ϴ�.\n");
						Sleep(1000);
						system("cls");
						goto B;
					}
				}
				else
				{
					system("cls");
					printf("�߸� �Է��ϼ̽��ϴ�.\n");
					Sleep(1000);
					system("cls");
					goto B;
				}
			}
			else if (attsel2 == 2) //���ġ
			{
				if (Luser == 1)
				{
					printf("�հ��� ������ 2�� �̻��̿��� �մϴ�.\n");
					goto D;
				}
				int movenum2;
				while (1)
				{
					printf("�޼տ��� ���������� �󸶳� �̵���Ű�ڽ��ϱ�? : ");
					scanf("%d", &movenum2);
					if (movenum2 == Luser)
						printf("%d���� ���� ���ڸ� �̵���ų �� �ֽ��ϴ�.\n", Luser);
					else if (movenum2 >= 1 && movenum2 <= Luser && movenum2 + Ruser < 5) //�Է��� ���� 1~�޼հ����� �̳�, �Է¼�+�����հ������� 5���̸��� ��
					{
						Luser -= movenum2;
						Ruser += movenum2;
						break;
					}
					else
						printf("�߸� �Է��ϼ̽��ϴ�.\n");
				}
			}
			else
			{
				printf("�߸� �Է��ϼ̽��ϴ�.\n");
				goto D;
			}
		}
		system("cls");
		if (Rcom >= 5)
			Rcom = 0;
		else if (Lcom >= 5)
			Lcom = 0;
		else if (Luser >= 5)
			Luser = 0;
		else if (Ruser >= 5)
			Ruser = 0;
		if (Luser == 0 && Ruser == 0 || Lcom == 0 && Rcom == 0)  //������ ������ ���� ��, ��ǻ���� �� ���� while���� ������ �������� ���ϴ� ��� while�� Ż��
			break;
		print_hand(Luser, Ruser, Lcom, Rcom);
		Sleep(2000);
		system("cls");
		if (Lcom == 0)	//��ǻ�� �޼��� ��� ������ ��
		{
			if (Luser == 0 && Rcom + Ruser >= 5) //������ �޼ո� ��� �������¿��� ������ ������ ���� �� ��� �� �� ���� ��(��ǻ���� �¸� ����)
			{
				printf("��ǻ�Ͱ� ������ ������ ������ ������ ���� �����߽��ϴ�.\n");
				Ruser += Rcom;
			}
			else if (Ruser == 0 && Rcom + Luser >= 5) //������ �����ո� ��� �������¿��� ������ �޼� ���� �� ��� �� �� ���� ��(��ǻ���� �¸� ����)
			{
				printf("��ǻ�Ͱ� ������ ������ ������ ���� ���� �����߽��ϴ�.\n");
				Luser += Rcom;
			}
			else if ((Rcom + Luser >= 5 || Rcom + Ruser >= 5 || Rcom + Rcom + Ruser >= 5 || Rcom + Rcom + Luser >= 5) && Rcom >= 2)
			{	//��ǻ���� �����հ����� �ΰ��̻��̸�, ���� ��ǻ���� ���� �����ϰų� ��ǻ�Ͱ� ������ �� ��ǻ���� ���� ������ ��.	
				printf("��ǻ�Ͱ� ������ �տ��� ���� ������ %d��ŭ �̵����׽��ϴ�.\n", Rcom / 2);
				Lcom = Lcom + Rcom / 2; //�ݸ�ŭ �հ��� �̵�
				Rcom = Rcom - Rcom / 2;
			}
			else if (Luser == 0) //��ǻ���� �¸� ������ ���� ���ϰ� ���� ���� �Ʒ� ������ �� ����
			{
				printf("��ǻ�Ͱ� ������ ������ ������ ������ ���� �����߽��ϴ�.\n");
				Ruser += Rcom;
			}
			else if (Ruser == 0)
			{
				printf("��ǻ�Ͱ� ������ ������ ������ ���� ���� �����߽��ϴ�.\n");
				Luser += Rcom;
			}
			else
			{
				printf("��ǻ�Ͱ� ������ ������ ");
				if (Rcom + Luser >= 5 && Rcom + Ruser < 5) //��ǻ�Ͱ� ���� ���� �� �հ����� ��� �� �� �ְ� ���� �Ͽ� ������ ���
				{
					printf("������ ���� ���� �����߽��ϴ�.\n");
					Luser += Rcom;
				}
				else if (Rcom + Ruser >= 5 && Rcom + Luser < 5)
				{
					printf("������ ������ ���� �����߽��ϴ�.\n");
					Ruser += Rcom;
				}
				else
				{
					if (rand() % 2 + 1 == 1)
					{
						printf("������ ���� ���� �����߽��ϴ�.\n");
						Luser += Rcom;
					}
					else
					{
						printf("������ ������ ���� �����߽��ϴ�.\n");
						Ruser += Rcom;
					}
				}
			}
		}
		else if (Rcom == 0) //��ǻ�� �������� ��� ������ ��
		{
			if (Luser == 0 && Lcom + Ruser >= 5) //��ǻ���� �¸� ����
			{
				printf("��ǻ�Ͱ� ���� ������ ������ ������ ���� �����߽��ϴ�.\n");
				Ruser += Lcom;
			}
			else if (Ruser == 0 && Lcom + Luser >= 5) //��ǻ���� �¸� ����
			{
				printf("��ǻ�Ͱ� ���� ������ ������ ���� ���� �����߽��ϴ�.\n");
				Luser += Lcom;
			}
			else if ((Lcom + Luser >= 5 || Lcom + Ruser >= 5 || Lcom + Lcom + Ruser >= 5 || Lcom + Lcom + Luser >= 5) && Lcom >= 2)
			{	//��ǻ���� �޼հ����� �ΰ��̻��̸�, ���� ��ǻ���� ���� �����ϰų� ��ǻ�Ͱ� ������ �� ��ǻ���� ���� ������ ��.	
				printf("��ǻ�Ͱ� ���� �տ��� ������ ������ %d��ŭ �̵����׽��ϴ�.\n", Lcom / 2);
				Rcom = Rcom + Lcom / 2;
				Lcom = Lcom - Lcom / 2;
			}
			else if (Ruser == 0)
			{
				printf("��ǻ�Ͱ� ���� ������ ������ ���� ���� �����߽��ϴ�.\n");
				Luser += Lcom;
			}
			else if (Luser == 0)
			{
				printf("��ǻ�Ͱ� ���� ������ ������ ���� ���� �����߽��ϴ�.\n");
				Ruser += Lcom;
			}
			else
			{
				printf("��ǻ�Ͱ� ���� ������ ");
				if (Lcom + Luser >= 5 && Lcom + Ruser < 5)
				{
					printf("������ ���� ���� �����߽��ϴ�.\n");
					Luser += Lcom;
				}
				else if (Lcom + Ruser >= 5 && Lcom + Luser < 5)
				{
					printf("������ ������ ���� �����߽��ϴ�.\n");
					Ruser += Lcom;
				}
				else
				{
					if (rand() % 2 + 1 == 1)
					{
						printf("������ ���� ���� �����߽��ϴ�.\n");
						Luser += Lcom;
					}
					else
					{
						printf("������ ������ ���� �����߽��ϴ�.\n");
						Ruser += Lcom;
					}
				}
			}
		}
		else //��ǻ���� ����� ��� ������� ��
		{
			if (Lcom + Luser >= 5 && Lcom + Ruser < 5) //��ǻ�Ͱ� �޼����� �����ϰ� ������ �޼հ����� ��� �� �� ���� ��
			{
				printf("��ǻ�Ͱ� ���� ������ ������ ���� ���� �����߽��ϴ�.\n");
				Luser += Lcom;
			}
			else if (Lcom + Ruser >= 5 && Lcom + Luser < 5) //��ǻ�Ͱ� �޼����� �����ϰ� ������ �����հ����� ��� �� �� ���� ��
			{
				printf("��ǻ�Ͱ� ���� ������ ������ ������ ���� �����߽��ϴ�.\n");
				Ruser += Lcom;
			}
			else if (Rcom + Ruser >= 5 && Rcom + Luser < 5) //��ǻ�Ͱ� ���������� �����ϰ� ������ �����հ����� ��� �� �� ���� ��
			{
				printf("��ǻ�Ͱ� ������ ������ ������ ������ ���� �����߽��ϴ�.\n");
				Ruser += Rcom;
			}
			else if (Rcom + Luser >= 5 && Rcom + Ruser < 5) //��ǻ�Ͱ� ���������� �����ϰ� ������ �޼հ����� ��� �� �� ���� ��
			{
				printf("��ǻ�Ͱ� ������ ������ ������ ���� ���� �����߽��ϴ�.\n");
				Luser += Rcom;
			}
			else if ((Luser + Lcom >= 5 && Luser <= 3 || Ruser + Lcom >= 5 && Ruser <= 3) && Rcom + Lcom / 2 < 5)
			{	//���� �����ϰ�, �Ű��� �� ���� ������ �� ���� �հ����� 4���̻��̸� �հ��� �ϳ��� ������ ������ �����ϰ����� 3�� ���Ϸ� ���ġ�ص� ������ ���. ���� �������� �޾Ƶ� 5�� ������ ���.
				printf("��ǻ�Ͱ� ���� �տ��� ������ ������ %d��ŭ �̵����׽��ϴ�.\n", Lcom / 2);
				Rcom = Rcom + Lcom / 2;
				Lcom = Lcom - Lcom / 2;
			}
			else if ((Luser + Rcom >= 5 && Luser <= 3 || Ruser + Rcom >= 5 && Ruser <= 3) && Lcom + Rcom / 2 < 5)
			{	//���� �����ϰ�, ���� �հ����� 3�� ���Ϸ� ���ġ�ص� ������ ���. ���� �޼��� �޾Ƶ� 5�� ������ ���.
				printf("��ǻ�Ͱ� ������ �տ��� ���� ������ %d��ŭ �̵����׽��ϴ�.\n", Rcom / 2);
				Lcom = Lcom + Rcom / 2;
				Rcom = Rcom - Rcom / 2;
			}
			else
			{
				if (Lcom + Luser + Rcom < 5 && Lcom + Luser + Lcom < 5 && Luser != 0) //������ ���ʼ��� �����ϰ� ���Ŀ� ���ݹ޾Ƶ� ������ ��
				{
					printf("��ǻ�Ͱ� ���� ������ ������ ���� ���� �����߽��ϴ�.\n");
					Luser += Lcom;
				}
				else if (Lcom + Ruser + Rcom < 5 && Lcom + Ruser + Lcom < 5 && Ruser != 0) //������ �����ʼ��� �����ϰ� ���Ŀ� ���ݹ޾Ƶ� ������ ��
				{
					printf("��ǻ�Ͱ� ���� ������ ������ ������ ���� �����߽��ϴ�.\n");
					Ruser += Lcom;
				}
				else if (Rcom + Ruser + Rcom < 5 && Rcom + Ruser + Lcom < 5 && Ruser != 0) //������ �����ʼ��� �����ϰ� ���Ŀ� ���ݹ޾Ƶ� ������ ��
				{
					printf("��ǻ�Ͱ� ������ ������ ������ ������ ���� �����߽��ϴ�.\n");
					Ruser += Rcom;
				}
				else if (Rcom + Luser + Rcom < 5 && Rcom + Luser + Lcom < 5 && Luser != 0) //������ ���ʼ��� �����ϰ� ���Ŀ� ���ݹ޾Ƶ� ������ ��
				{
					printf("��ǻ�Ͱ� ������ ������ ������ ���� ���� �����߽��ϴ�.\n");
					Luser += Rcom;
				}
				else
				{
					if (rand() % 2 + 1 == 1) //���� ����
					{
						printf("��ǻ�Ͱ� ���� ������ ");
						if (Ruser == 0)
						{
							printf("������ ���� ���� �����߽��ϴ�.\n");
							Luser += Lcom;
						}
						else if (Luser == 0)
						{
							printf("������ ���� ���� �����߽��ϴ�.\n");
							Ruser += Lcom;
						}
						else
						{
							if (rand() % 2 + 1 == 1)
							{
								printf("������ ���� ���� �����߽��ϴ�.\n");
								Luser += Lcom;
							}
							else
							{
								printf("������ ������ ���� �����߽��ϴ�.\n");
								Ruser += Lcom;
							}
						}
					}
					else
					{
						printf("��ǻ�Ͱ� ������ ������ ");
						if (Luser == 0)
						{
							printf("������ ������ ���� �����߽��ϴ�.\n");
							Ruser += Rcom;
						}
						else if (Ruser == 0)
						{
							printf("������ ���� ���� �����߽��ϴ�.\n");
							Luser += Rcom;
						}
						else
						{
							if (rand() % 2 + 1 == 1)
							{
								printf("������ ���� ���� �����߽��ϴ�.\n");
								Luser += Rcom;
							}
							else
							{
								printf("������ ������ ���� �����߽��ϴ�.\n");
								Ruser += Rcom;
							}
						}
					}
				}
			}
		}
		if (Rcom >= 5)
			Rcom = 0;
		else if (Lcom >= 5)
			Lcom = 0;
		else if (Luser >= 5)
			Luser = 0;
		else if (Ruser >= 5)
			Ruser = 0;
	}

	if (Luser == 0 && Ruser == 0) //������ ����� ��� ������ ��
	{
		print_hand(Luser, Ruser, Lcom, Rcom);
		printf("�й��Ͽ����ϴ�.\n");
	}
	else if (Lcom == 0 && Rcom == 0) //��ǻ���� ����� ��� ������ ��
	{
		print_hand(Luser, Ruser, Lcom, Rcom);
		printf("�¸��Ͽ����ϴ�.\n");
	}
}