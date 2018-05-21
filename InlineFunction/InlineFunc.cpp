/*
문제 1525 퍼즐 풀이

3 * 3 표에 다음과 같이 수가 채워져 있다.오른쪽 아래 가장 끝 칸은 비어 있는 칸이다.

1 2 3
4 5 6
7 8

어떤 수와 인접해 있는 네 개의 칸 중에 하나가 비어 있으면, 수를 그 칸으로 이동시킬 수가 있다.
물론 표 바깥으로 나가는 경우는 불가능하다.
우리의 목표는 초기 상태가 주어졌을 때, 최소의 이동으로 위와 같은 정리된 상태를 만드는 것이다.다음의 예를 보자.

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

가장 윗 상태에서 세 번의 이동을 통해 정리된 상태를 만들 수 있다.이와 같이 최소 이동 횟수를 구하는 프로그램을 작성하시오.

입력
세 줄에 걸쳐서 표에 채워져 있는 아홉 개의 수가 주어진다.한 줄에 세 개의 수가 주어지며, 빈 칸은 0으로 나타낸다.

출력
첫째 줄에 최소의 이동 횟수를 출력한다.이동이 불가능한 경우 - 1을 출력한다.

예제 입력 복사
1 0 3
4 2 5
7 8 6

예제 출력 복사
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