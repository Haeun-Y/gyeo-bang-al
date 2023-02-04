//BOJ 3190 뱀
#include <bits/stdc++.h>
using namespace std;
deque<pair<int, int>> dq;
int changeDirection(char ld, int direction)
{
	if (ld == 'L')
	{
		direction--;
		if (direction == 0)
			direction = 4;
	}
	else
	{
		direction++;
		if (direction == 5)
			direction = 1;
	}
	return direction;
}
void printDeque()
{
	for (int i = 0; i < dq.size(); i++)
		printf("%d %d\n", dq[i].first, dq[i].second);
	printf("\n");
}
void moveWithApple(vector<vector<int>>& v, int row, int col)
{
	v[row][col] = 1;
	dq.push_front(make_pair(row, col));
}
void move(vector<vector<int>> &v, int row, int col)
{
	v[row][col] = 1;
	dq.push_front(make_pair(row, col));
	int rowToDelete = dq.back().first;
	int colToDelete = dq.back().second;
	v[rowToDelete][colToDelete] = 0;
	dq.pop_back();
}
bool checkState(vector<vector<int>>& v, int row, int col)
{
	if (v[row][col] == 1)
	{
		return true;
	}

	if (v[row][col] == 2)//이동할 칸에 사과가 놓여진 상태
	{
		//printf("사과!\n");
		moveWithApple(v, row, col);
	}
	
	else//이동할 칸이 기본상태인 경우
		move(v, row, col);
	
	return false;
	
}
bool decideMoving(bool gameOver, int direction, vector<vector<int>>& v)
{
	int size = v[0].size();
	int row = dq.front().first;
	int col = dq.front().second;
	switch (direction)
	{
	case 1:
		col++;
		if (col < size)
			gameOver = checkState(v, row, col);

		else
			gameOver = true;

		break;
	case 2:
		row++;
		if (row < size)
			gameOver = checkState(v, row, col);

		else
			gameOver = true;

		break;
	case 3:
		col--;
		if (col >= 0)
			gameOver = checkState(v, row, col);

		else
			gameOver = true;

		break;
	case 4:
		row--;
		if (row >= 0)
			gameOver = checkState(v, row, col);

		else
			gameOver = true;


		break;
	}

	return gameOver;
}
int main(void)
{
	bool gameOver = false;
	int boardNum = 0, appleNum =0, sec = 0, directionNum =0;
	int direction = 1;
	//1: 오른쪽
	//2: 아래
	//3: 왼쪽
	//4: 위

	scanf("%d", &boardNum);
	scanf("%d", &appleNum);

	vector<vector<int>> v(boardNum, vector<int>(boardNum));
	v[0][0] = 1;
	//0 : 기본 상태
	//1 : 뱀이 존재하는 상태
	//2 : 사과가 놓여진 상태

	dq.push_front(make_pair(0, 0));

	for (int i = 0; i < appleNum; i++)
	{
		int row = 0, col = 0;

		scanf("%d %d", &row, &col);
		v[--row][--col] = 2;
	}

	scanf("%d", &directionNum);
	vector<pair<int, char>> directionList(directionNum);

	for (int i = 0; i < directionNum; i++)
		scanf("%d %c", &directionList[i].first, &directionList[i].second);
	

	for(int i =0; i<directionNum; i++)
	{
		sec++;
		for (int j = sec; j <= directionList[i].first; j++)
		{
			gameOver = decideMoving(gameOver, direction, v);
			sec = j;

			if (gameOver)
				break;
			
		}

		if (gameOver)
			break;

		direction = changeDirection(directionList[i].second, direction);
	}

	while(!gameOver)
	{
		gameOver = decideMoving(gameOver, direction, v);
		sec++;
		//printf("sec : %d\n", sec);

		//printDeque();
	}

	printf("%d", sec);

}
