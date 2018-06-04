#include <stdio.h>  
#include <string.h>  
#include <stdlib.h> 
struct student
{
	char name[20];
	int id;
	int math;
	int english;
	int computer;
};
int input(student*st);
void find(student*st, int len);
void sort(student*st, int len);
void delect(student*st, int len);
void alter(student*st,int len);
void out(student*st, int i);
void show_massage(student*st, int len);
void show_choise();
void computer_analyze(student*st, int len);
int main()
{
	int len;
	int m;
	student st[100];
	while (1)
	{
		show_choise();
		scanf("%d", &m);
		switch (m)
		{
		case 1:len = input(st);
			break;
		case 2:find(st, len);
			break;
		case 3:show_massage(st, len);
			break;
		case 4:sort(st, len);
			break;
		case 5:delect(st,len);
			len--;
			break;
		case 6:computer_analyze(st, len);
			break;
		case 7:alter(st,len);
			break;
		case 8:
		default:exit(0);
		}
	}
	return 0;
}
void show_choise()
{
	printf("1 ����ѧ����¼        2 ����ѧ��\n");
	printf("3 ���ѧ����Ϣ��      4 �ɼ�����\n");
	printf("5 ɾ��ѧ����Ϣ        6 �ɼ�����\n");
	printf("7 �޸�ѧ����Ϣ        8 �˳�ϵͳ\n");
	printf("��ѡ��\n");
}
void out(student *st, int i)
{
	printf("����    ѧ��    ��ѧ    Ӣ��    �����\n");
	printf("%s\t", st[i].name);
	printf("%d\t", st[i].id);
	printf("%d\t", st[i].math);
	printf("%d\t", st[i].english);
	printf("%d\t", st[i].computer);
	printf("\n");
}
int input(student*st)
{
	int i;
	int n;
	printf("������ѧ��������\n");
	scanf("%d", &n);
	printf("������ѧ�� ������\n");
	for (i = 0; i<n; i++)
	{
		scanf("%s", &st[i].name);
		if ((!strcmp(st[i].name, "end")))
		{
			return i;
		}
		printf("������ѧ����ѧ�ţ�\n");
		scanf("%d", &st[i].id);
		printf("������ѧ�� ��ѧ�ɼ���\n");
		scanf("%d", &st[i].math);
		printf("������ѧ�� Ӣ��ɼ���\n");
		scanf("%d", &st[i].english);
		printf("������ѧ�� ������ɼ���\n");
		scanf("%d", &st[i].computer);
	}
	system("cls");
	return i;
}
void show_massage(student*st, int len)
{
	int i;
	printf("id,name,math,english,computer:\n");
	for (i = 0; i<len; i++)
	{
		out(st, i);
	}
}
void find(student*st, int len)
{
	char tmp[20];
	int i;
	printf("������������\n");
	scanf("%s", &tmp);
	for (i = 0; i < len; i++)
	{
		if (!strcmp(st[i].name, tmp))
		{
			out(st, i);
		}
	}

}
void sort(student*st, int len)
{
	int i, j, k;
	int tmp;
	char name[20];
	int choise;
	printf("��ѡ������");
	printf("1  Ӣ��ɼ�����   2 ������ɼ�����\n");
	scanf("%d", &choise);
	if (1 == choise)
	{
		for (i = 0; i < len - 1; i++)
		{
			for (j = 0; j <len - i - 1; j++)
			{
				if (st[j].english < st[j + 1].english)
				{
					tmp = st[j].english;
					st[j].english = st[j + 1].english;
					st[j + 1].english = tmp;

					tmp = st[j].computer;
					st[j].computer = st[j + 1].computer;
					st[j + 1].computer = tmp;

					tmp = st[j].id;
					st[j].id = st[j + 1].id;
					st[j + 1].id = tmp;

					tmp = st[j].math;
					st[j].math = st[j + 1].math;
					st[j + 1].math = tmp;

					strcpy(name, st[j].name);
					strcpy(st[j].name, st[j + 1].name);
					strcpy(st[j + 1].name, name);
				}
			}
		}
		printf("id,name,math,english,computer\n");
		for (k = 0; k < len; k++)
		{
			out(st, k);
		}
	}
	else if (2 == choise)
	{
		for (i = 0; i < len - 1; i++)
		{
			for (j = 0; j < len - i - 1; j++)
			{
				if (st[j].computer < st[j + 1].computer)
				{
					tmp = st[j].computer;
					st[j].computer = st[j + 1].computer;
					st[j + 1].computer = tmp;

					tmp = st[j].english;
					st[j].english = st[j + 1].english;
					st[j + 1].english = tmp;

					tmp = st[j].id;
					st[j].id = st[j + 1].id;
					st[j + 1].id = tmp;

					tmp = st[j].math;
					st[j].math = st[j + 1].math;
					st[j + 1].math = tmp;

					strcpy(name, st[j].name);
					strcpy(st[j].name, st[j + 1].name);
					strcpy(st[j + 1].name, name);
				}
			}
		}
		printf("id,name,math,english,computer");
		for (k = 0; k < len; k++)
		{
			out(st, k);
		}
	}
	else
	{
		printf("����������������롣\n");
	}
}
void delect(student*st,int len)
{
    int nums,i;
    int result;
    printf("�������ɾ����ѧ��ѧ��:");
    scanf("%d",&nums);
	result=-1;
    for (i = 0; i<len; i++)
    {
        if (nums==st[i].id)
        {
            result = i;
			break;
        }
    }
    if (result == -1)
    {
        printf("û�и�ѧ����Ϣ!\n");
    }
    else
    {
        for(i=result; i<len-1; i++) 
        {
			strcpy(st[i].name, st[i + 1].name);
			st[i]=st[i+1];
        } 
    }
}
void alter(student*st,int len)
{
    int nums,i;
    int result;
    printf("��������޸ĵ�ѧ��ѧ��:");
    scanf("%d",&nums);
    result= -1;
    for (i = 0; i<len; i++)
    {
        if (nums == st[i].id)
        {
            result = i;
            break;
        }
    }
    if (result == -1)
    {
        printf("û�и�ѧ����Ϣ!\n");
    }
    else
    {
        printf("�����������ѧ����Ϣ��\n");
        printf("ѧ�ţ�\n");
        scanf("%d",&st[i].id);
        printf("������\n");
        scanf("%s",&st[i].name); 
        printf("��ѧ�ɼ���\n");
        scanf("%d",&st[i].math);
        printf("Ӣ��ɼ���\n");
        scanf("%d",&st[i].computer);
        printf("������ɼ���\n");
        scanf("%d",&st[i].computer);
    }
}
void computer_analyze(student*st, int len)
{
	int average1 = 0;
	int average2 = 0;
	int average3 = 0;
	int sum1 = 0;
    int sum2 = 0;
	int sum3 = 0;
	float pass1=0;
	float pass2=0;
	float pass3=0;
	int i,min1,max1,min2,max2,min3,max3;
	max1=min1=st[0].math;
	max2=min2=st[0].english;
	max3=min3=st[0].computer;
	for(i=0;i<len;i++)
	{
		sum1 += st[i].math;
	    average1 = sum1/len;
		sum2 += st[i].english;
	    average2 = sum2/len;
		sum3 += st[i].computer;
	    average3 = sum3/len;
		
		if(st[i].math>max1)
		{
			max1=st[i].math;
		}
		if(st[i].english>max2)
		{
			max2=st[i].english;
		}
		if(st[i].computer>max3)
		{
			max3=st[i].computer;
		}

		if(st[i].math<min1)
		{
			min1=st[i].math;
		}
	    if(st[i].english<min2)
		{
	    	min2=st[i].english;
		}
	     if(st[i].computer<min3)
		{
	    	min3=st[i].math;
		}
		 if(st[i].math>=60)pass1++;
		 if(st[i].english>=60)pass2++;
		 if(st[i].computer>=60)pass3++;
	}
	printf("��ѧ��Ӣ�������ɼ�ƽ���֣�");
	printf("%d\t%d\t%d\n", average1,average2,average3);
	printf("��ѧ��Ӣ�������ɼ���߷֣�");
	printf("%d\t%d\t%d\n",max1,max2,max3);
	printf("��ѧ��Ӣ�������ɼ���ͷ֣�");
	printf("%d\t%d\t%d\n",min1,min2,min3);
	printf("��ѧ��Ӣ�����������ʣ�");
	printf("%.2f\t%.2f\t%.2f\n",pass1/len,pass2/len,pass3/len);
}
