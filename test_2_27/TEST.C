#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��ӡ����һ�����������ÿ��Ԫ��
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//����һ�������������������������������͵�����Ԫ��
//�����ͣ��ַ��������Ԫ�أ��ṹ�����͵Ľṹ���Ա
//�����widthָ����һ������Ԫ����ռ���ֽ���
//��Ϊchar���͵�һ���ַ�ռ��һ���ֽڣ�һ��������ռ�ĸ��ֽڣ�
//��ô�����ĸ�char�͵��ֽ�Ҳ����һ��widthʵ�ֽ���һ������Ԫ��
void swap(char* s1, char* s2, size_t width)
{
	size_t i = 0;
	for (i = 0; i < width; i++)
	{
		char temp = *s1;
		*s1 = *s2;
		*s2 = temp;
		s1++;//������һ���ֽ�֮����������ƶ���ֱ��������width���ֽ�
		s2++;
	}
}
//����һ����������ʹ�����Զ����һ��������
//�������Ҫ��ʲô���͵����ݾ���Ҫ�Ѹú����Ĳ���p1,p2
//ǿת����Ӧ���͵�ָ����бȽ�
int cmp_int(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}
void bubble_sort(void* base, size_t count, size_t width, int (*cmp_int)(const void*, const void*))
{
	size_t i = 0;//����iΪ�޷�������
	for(i = 0; i < count; i++)
	{
		int flag = 1;//�����������������
		size_t j = 0;//����jΪ�޷�������
		for (j = 0; j < count - i - 1; j++)
		{
			//Ĭ���������������Ҫ�ųɽ���ֻ��Ҫ��">0"�޸ĳ�"<0"
			if (cmp_int((char*)base + j * width, (char*)base + (j + 1) * width)>0)
			{
				flag = 0;
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
		if (flag == 1)//�������ѭ������Ԫ��һ�ζ�û�н�����
		{	         //˵��������flagû�б���ֵΪ0,������Ҫ��������Ľ���������
		
			break;
		}
	}
}
int main()
{
	//ʹ��ð�������˼��ģ��ʵ��qsort��ʹ�÷���
	int arr[] = { 4,3,1,0,2,5,8,6,10,9,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);//������Ĵ�С�����ж��ٸ�Ԫ��
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	print(arr, sz);//��ӡ����������
	return 0;
}