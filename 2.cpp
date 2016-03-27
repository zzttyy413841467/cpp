#include<malloc.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define LENTH sizeof(struct Student)
struct Student
{
	int num;
	float score;
	struct Student *next;
};
int n;
float sum = 0;
struct Student *creat();                                         //函数声明
void output(struct Student *head);
float average(float sum);

int main()
{
	struct Student *pt;
	pt = creat();
	output(pt);
	cout << "平均分为:" << average(sum) << endl;
	return 0;
}

struct Student *creat()                                        //创建链表
{
	struct Student *head;
	struct Student *p1, *p2;
	n = 0;
	p1 = p2 = (struct Student *)malloc(LENTH);
	cout << "输入学号:" << endl;                               //输入0结束
	cin >> p1->num;
	cout << "输入成绩:" << endl;                               //输入0结束
	cin >> p1->score;
	if (p1->num < 0)
	{
		cout << "请正确输入学号:" << endl;
		cin >> p1->num;
	}
	if (p1->score < 0)                     
	{
		cout << "请正确输入成绩:" << endl;
		cin >> p1->score;
	}
	sum += p1->score;
	head = NULL;
	while (p1->num != 0)
	{
		n = n + 1;
		if (n == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct Student *)malloc(LENTH);
		cout << "输入学号:" << endl;
		cin >> p1->num;
		cout << "输入成绩:" << endl;
		cin >> p1->score;
		if (p1->num < 0)
		{
			cout << "请正确输入学号:" << endl;
			cin >> p1->num;
		}
		if (p1->score < 0)
		{
			cout << "请正确输入成绩:" << endl;
			cin >> p1->score;
		}
		sum += p1->score;
	}
	p2->next = NULL;
	return head;
}

void output(struct Student *head)                          //输出链表
{
	struct Student *p;
	cout << n << "个人的学号与成绩如下所示:" << endl;
	p = head;
	if(head!=NULL)
		while (p != NULL)
		{
			cout << p->num << "     " << p->score << endl;
			p = p->next;
		}

}

float average(float sum)                                 //计算平均数
{
	float ave;
	ave = sum / n;
	return ave;
}
