/*
���� 1525 ���� Ǯ��

3 * 3 ǥ�� ������ ���� ���� ä���� �ִ�.������ �Ʒ� ���� �� ĭ�� ��� �ִ� ĭ�̴�.

1 2 3
4 5 6
7 8

� ���� ������ �ִ� �� ���� ĭ �߿� �ϳ��� ��� ������, ���� �� ĭ���� �̵���ų ���� �ִ�.
���� ǥ �ٱ����� ������ ���� �Ұ����ϴ�.
�츮�� ��ǥ�� �ʱ� ���°� �־����� ��, �ּ��� �̵����� ���� ���� ������ ���¸� ����� ���̴�.������ ���� ����.

1   3
4 2 5
7 8 6

1 2 3
4   5
7 8 6

1 2 3
4 5
7 8 6

1 2 3
4 5 6
7 8

���� �� ���¿��� �� ���� �̵��� ���� ������ ���¸� ���� �� �ִ�.�̿� ���� �ּ� �̵� Ƚ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�� �ٿ� ���ļ� ǥ�� ä���� �ִ� ��ȩ ���� ���� �־�����.�� �ٿ� �� ���� ���� �־�����, �� ĭ�� 0���� ��Ÿ����.

���
ù° �ٿ� �ּ��� �̵� Ƚ���� ����Ѵ�.�̵��� �Ұ����� ��� - 1�� ����Ѵ�.

���� �Է� ����
1 0 3
4 2 5
7 8 6

���� ��� ����
3
*/

#include<iostream>
#include<map>
#include<string>
#include<queue>

using namespace std;

int main(void)
{
	int temp, start;
	int now_num, next_num, loc;
	string now, next;

	start = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> temp;

		if (temp == 0)
			temp = 9;

		start = (start * 10) + temp;
	}

	queue<int> q;
	q.push(start);
	map<int, int> dist;
	dist[start] = 0;


	while (!q.empty())
	{
		now_num = q.front();
		q.pop();

		now = to_string(now_num);	//#include<string>
		loc = now.find("9");

		if (loc - 3 > 0)
		{
			next = now;
			swap(next[loc], next[loc - 3]);

			next_num = stoi(next);

			if (dist.count(next_num) == 0)
			{
				dist[next_num] = dist[now_num] + 1;
				q.push(next_num);
			}
		}

		if (loc + 3 < 9)
		{
			next = now;
			swap(next[loc], next[loc + 3]);

			next_num = stoi(next);

			if (dist.count(next_num) == 0)
			{
				dist[next_num] = dist[now_num] + 1;
				q.push(next_num);
			}
		}

		if (loc - 1 > 0)
		{
			next = now;
			swap(next[loc], next[loc - 1]);

			next_num = stoi(next);

			if (dist.count(next_num) == 0)
			{
				dist[next_num] = dist[now_num] + 1;
				q.push(next_num);
			}
		}
		if (loc + 1 < 9)
		{
			next = now;
			swap(next[loc], next[loc + 1]);

			next_num = stoi(next);

			if (dist.count(next_num) == 0)
			{
				dist[next_num] = dist[now_num] + 1;
				q.push(next_num);
			}
		}

	}//end while

	if (dist.count(123456789))
		cout << dist[123456789] << endl;
	else
		cout << -1;

	for (;;);
	//return 0;
}