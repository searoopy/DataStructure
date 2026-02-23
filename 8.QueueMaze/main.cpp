


#include <iostream>
#include "location2D.h"
//#include <ConsoleApi2>
#include <Windows.h>
#include <minwindef.h>
#include "queue.h"

// 작은 맵.
//const int MAZE_SIZE = 6;
//char map[MAZE_SIZE][MAZE_SIZE] =
//{
//	{'1','1','1','1','1','1'},
//	{'e','0','1','0','0','1'},
//	{'1','0','0','0','1','1'},
//	{'1','0','1','0','1','1'},
//	{'1','0','1','0','0','x'},
//	{'1','1','1','1','1','1'}
//};

// 큰 맵.
const int MAZE_SIZE = 20;
char map[MAZE_SIZE][MAZE_SIZE] =
{
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '1', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
	{'1', '0', '0', '0', '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
	{'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1'},
	{'e', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1'},
	{'1', '0', '1', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1', '1', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', 'x'},
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
};


//방문하려는 위치가 유효한지 확인하는 함수.
bool IsValidLocation(const Location2D& location)
{
	const int row = location.row;
	const int col = location.col;


	//인덱스 범위 확인
	if (row < 0 || row >= MAZE_SIZE
		|| col < 0 || col >= MAZE_SIZE)
	{
		return false;
	}

	//이동하려는 곳이 이동 가능한지 확인.

	return (map[row][col] == '0' )|| (map[row][col] == 'x');


}

//콘솔 화면 지우는 함수
void ClearScreen()
{

	system("cls");
}


void SetConsoleColor(WORD color)
{
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE),
		color
	);
}






void PrintMap( const Location2D& playerPos, DWORD delay)
{
	Sleep(delay);

	ClearScreen();

	for (int row = 0; row < MAZE_SIZE; ++row)
	{
		for (int col = 0; col < MAZE_SIZE; ++col)
		{
			if (playerPos.col == col && playerPos.row == row)
			{
				SetConsoleColor(FOREGROUND_GREEN);
				std::cout << "P ";

				SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

				continue;
			}

			if (map[row][col] == 'x')
			{
				SetConsoleColor(FOREGROUND_RED);
				std::cout << "X ";

				SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

				continue;
			}


			


			//맵 출력 
			std::cout << map[row][col] << " ";

		}

		std::cout << "\n";


	}




}

int main()
{


	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = false;

	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&info);


	bool found = false;
	Location2D start;

	for (int row = 0; row < MAZE_SIZE; ++row)
	{
		for (int col = 0; col < MAZE_SIZE; ++col)
		{
			// 시작지점 문자 찾기.
			if (map[row][col] == 'e')
			{
				start.row = row;
				start.col = col;
				found = true;
				break;
			}

		}

		if (found)
		{
			break;
		}


	}


	//맵 출력
	PrintMap(start, 0);


	//스택 길찾기.
	Queue<Location2D, MAZE_SIZE> queue;

	//시작 위치 스택에 추가.
	queue.Enqueue(start);

	//길찾기 (dfs)
	while (!queue.IsEmpty())
	{

		//방문할 위치 꺼내기.
		Location2D current;
		if (!queue.Dequeue(current))
		{
			break;
		}

		//위치 출력.
		PrintMap(current, 500);

		//출구에 도착했는지 확인
		if (map[current.row][current.col] == 'x')
		{
			std::cout << "\n미로 탐색 성공\n";
			return 0;
		}


		//방문 및 방문한 위치 표시.
		map[current.row][current.col] = '.';

		//PrintMap(current, 500);

		//이동할 지점 스택에 추가.
		//큐에 넣을 순서는 정할수 있음.
		//상/하/좌/우 순서로 스택에 삽입.
		if (IsValidLocation(Location2D(current.row -1, current.col)))
		{
			queue.Enqueue(Location2D(current.row - 1, current.col));
		}
		if (IsValidLocation(Location2D(current.row + 1, current.col)))
		{
			queue.Enqueue(Location2D(current.row + 1, current.col));
		}
		if (IsValidLocation(Location2D(current.row , current.col-1)))
		{
			queue.Enqueue(Location2D(current.row , current.col-1));
		}
		if (IsValidLocation(Location2D(current.row, current.col + 1)))
		{
			queue.Enqueue(Location2D(current.row, current.col + 1));
		}

	}



	//길찾기 실패.......
	std::cout << "미로 탐색 실패\n";

}