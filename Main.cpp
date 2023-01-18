﻿#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45

#include <stralign.h>
#include <stdlib.h>
#define pause system("pause > nul")    //그냥 내가 많이 쓰는 커맨드를 줄여준 것이다.
#define cls system("cls")    //이것 또한
void SetColor(int color);
void CursorView(char show);
void gotoxy(int x, int y);

//콘솔 창의 크기와 제목을 지정하는 함수
void SetConsoleView()
{
	system("mode con:cols=100 lines=25");
	system("title Google Dinosaurs. By BlockDMask.");
}

//커서의 위치를 x, y로 이동하는 함수
void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int GetKeyDown()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
}

//공룡을 그리는 함수
void DrawDino(int dinoY)
{
	GotoXY(0, dinoY);
	static bool legFlag = true;
	printf("                       $$$$$$$ \n");
	printf("                      $$ $$$$$$\n");
	printf("                      $$$$$$$$$\n");
	printf("               $      $$$      \n");
	printf("               $$     $$$$$$$  \n");
	printf("               $$$   $$$$$     \n");
	printf("                $$  $$$$$$$$$$ \n");
	printf("                $$$$$$$$$$$    \n");
	printf("                 $$$$$$$$$$    \n");
	printf("                   $$$$$$$$    \n");
	printf("                    $$$$$$     \n");
	if (legFlag)
	{
		printf("                   $    $$$    \n");
		printf("                   $$$           ");
		legFlag = false;
	}
	else
	{
		printf("                     $$$ $     \n");
		printf("                         $$$     ");
		legFlag = true;
	}
}

void DownDrawDino(int dinoY) { //s키를 눌렀을때
	GotoXY(0, dinoY);
	static bool legFlag = true;
	printf("                               \n");
	printf("                               \n");
	printf("                               \n");
	printf("                               \n");
	printf("                               \n");
	printf("                               \n");
	printf("                      $$$$$$$  \n");
	printf("    $                $$ $$$$$$$\n");
	printf("    $$      $$$$$$   $$$$$$$$$$\n");
	printf("     $$$   $$$$$$$$$$$$$$$$    \n");
	printf("      $$$$$$$$$$$$$$$$$$$$$$$$$\n");
	if (legFlag)
	{
		printf("       $$$ $$$$ $$$$ $$$$      \n");
		printf("         $$$  $$$  $$$  $$$    \n");
		legFlag = false;
	}
	else
	{
		printf("       $$ $$$$ $$$$ $$$$$      \n");
		printf("        $$$  $$$  $$$  $$$     \n");

		legFlag = true;
	}
}

//나무를 그리는 함수
void DrawTree(int treeX)
{
	GotoXY(treeX, TREE_BOTTOM_Y);
	printf("$$$$");
	GotoXY(treeX, TREE_BOTTOM_Y + 1);
	printf(" $$ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 2);
	printf(" $$ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 3);
	printf(" $$ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 4);
	printf(" $$ ");
}

//(v2.0) 충돌 했을때 게임오버 그려줌
void DrawGameOver(const int score)
{
	system("cls");
	int x = 60;
	int y = 8;
	printf("\n\n");
	printf(" ================================================================================================================== \n\n");
	printf("                                    =========== G A M E O V E R ===========                                         \n\n");
	printf("                                                   SCORE : %d                                                       \n\n", score);
	printf(" ================================================================================================================== \n\n");
	printf("\n\n\n\n\n\n\n\n\n");
	system("pause");
}

//(v2.0) 충돌했으면 true, 아니면 false
bool isCollision(const int treeX, const int dinoY)
{
	//트리의 X가 공룡의 몸체쪽에 있을때,
	//공룡의 높이가 충분하지 않다면 충돌로 처리
	GotoXY(0, 0);
	printf("treeX : %d, dinoY : %d", treeX, dinoY); //이런식으로 적절한 X, Y를 찾습니다.
	if (10 <= treeX && treeX <= 14 && dinoY > 8)
	{
		return true;
	}
	return false;
}

//수정
void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void gotoxy(int x, int y) {

	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetConsoleView1()
{
	CursorView(0);    //커서의 깜빡임을 숨겨준다.
	system("COLOR 0F");    //화면 배경을 검정, 글씨 색깔을 하얀색으로 설정해 준다.
	system("mode con cols=120 lines=30 | title MyGame");
	printf("\n");
	printf(" ================================================================================================================== \n");
	printf("||                                                                                                                ||\n");
	printf("||                                                                                                                ||\n");
	printf("||                #     #     #######     #             #####      #####      ##   ##     #######                 ||\n");
	printf("||                #  #  #     #           #            #          #     #     # # # #     #                       ||\n");
	printf("||                # # # #     ######      #            #          #     #     #  #  #     ######                  ||\n");
	printf("||                # # # #     #           #            #          #     #     #     #     #                       ||\n");
	printf("||                 #   #      #######     #######       #####      #####      #     #     #######                 ||\n");
	printf("||                                                                                                                ||\n");
	printf("||                                                                                                                ||\n");
	printf(" ================================================================================================================== \n");
	printf("\n");
	gotoxy(25, 13); printf("1. 게임시작 ");
	gotoxy(50, 13); printf("2. 랭킹 ");
	gotoxy(75, 13); printf("3. 게임종료");
	printf("\n\n\n");
}

void start() {
	for (int n = 3; n >= 0; --n) {
		cls;
		if (n == 0) {
			printf("\n");
			printf(" ================================================================================================================== \n");
			printf("||                                                                                                                ||\n");
			printf("||                                                                                                                ||\n");
			printf("||                             #######     #######        #        ######      #######                            ||\n");
			printf("||                             #              #          # #       #     #        #                               ||\n");
			printf("||                             #######        #         #####      ######         #                               ||\n");
			printf("||                                   #        #        #     #     #    #         #                               ||\n");
			printf("||                             #######        #        #     #     #     #        #                               ||\n");
			printf("||                                                                                                                ||\n");
			printf("||                                                                                                                ||\n");
			printf(" ================================================================================================================== \n");
			printf("\n");
		}
		else if (n == 1) {
			printf("\n");
			printf(" ================================================================================================================== \n");
			printf("||                                                                                                                ||\n");
			printf("||                                                                                                                ||\n");
			printf("||                                                        ##                                                      ||\n");
			printf("||                                                       # #                                                      ||\n");
			printf("||                                                         #                                                      ||\n");
			printf("||                                                         #                                                      ||\n");
			printf("||                                                      #######                                                   ||\n");
			printf("||                                                                                                                ||\n");
			printf("||                                                                                                                ||\n");
			printf(" ================================================================================================================== \n");
			printf("\n");
		}
		else if (n == 2) {
			printf("\n");
			printf(" ================================================================================================================== \n");
			printf("||                                                                                                                ||\n");
			printf("||                                                                                                                ||\n");
			printf("||                                                      #######                                                   ||\n");
			printf("||                                                            #                                                   ||\n");
			printf("||                                                      #######                                                   ||\n");
			printf("||                                                      #                                                         ||\n");
			printf("||                                                      #######                                                   ||\n");
			printf("||                                                                                                                ||\n");
			printf("||                                                                                                                ||\n");
			printf(" ================================================================================================================== \n");
			printf("\n");
		}
		else if (n == 3) {
			printf("\n");
			printf(" ================================================================================================================== \n");
			printf("||                                                                                                                ||\n");
			printf("||                                                                                                                ||\n");
			printf("||                                                      #######                                                   ||\n");
			printf("||                                                            #                                                   ||\n");
			printf("||                                                      #######                                                   ||\n");
			printf("||                                                            #                                                   ||\n");
			printf("||                                                      #######                                                   ||\n");
			printf("||                                                                                                                ||\n");
			printf("||                                                                                                                ||\n");
			printf(" ================================================================================================================== \n");
			printf("\n");
		}
		Sleep(1000);
	}
}

//

int main()
{
	int POS = 0;	//0 - 게임시작, 1 - 랭킹, 2 - 게임 종료
	SetConsoleView1();
	while (true) {
		if (GetAsyncKeyState(VK_LEFT))
			if (POS == 0) POS = 2;
			else POS -= 1;
		else if (GetAsyncKeyState(VK_RIGHT))
			if (POS == 2) POS = 0;
			else POS += 1;
		else if (GetAsyncKeyState(VK_RETURN))//엔터를 눌렀을 때
			break;
		switch (POS) {
		case 0:
			SetColor(11);
			gotoxy(25, 13); printf("1. 게임시작 ");
			SetColor(15);
			gotoxy(50, 13); printf("2. 랭킹 ");
			gotoxy(75, 13); printf("3. 게임종료");
			break;
		case 1:
			gotoxy(25, 13); printf("1. 게임시작 ");
			SetColor(11);
			gotoxy(50, 13); printf("2. 랭킹 ");
			SetColor(15);
			gotoxy(75, 13); printf("3. 게임종료");
			break;
		case 2:
			gotoxy(25, 13); printf("1. 게임시작 ");
			gotoxy(50, 13); printf("2. 랭킹 ");
			SetColor(11);
			gotoxy(75, 13); printf("3. 게임종료");
			SetColor(15);
			break;
		default: break;
		}
		Sleep(100);
	}
	cls;

	//SetConsoleView();
	if (POS == 0) {//구글디노
		while (true)		//(v2.0) 게임 루프
		{
			start();//게임시작대기

			//게임 시작시 초기화
			bool isJumping = false;
			bool isBottom = true;
			bool isDown = false;
			const int gravity = 3;

			int dinoY = DINO_BOTTOM_Y;
			int treeX = TREE_BOTTOM_X;

			int score = 0;
			clock_t start, curr;	//점수 변수 초기화
			start = clock();		//시작시간 초기화

			while (true)	//한 판에 대한 루프
			{
				//(v2.0) 충돌체크 트리의 x값과 공룡의 y값으로 판단
				if (isCollision(treeX, dinoY))
					break;

				//z키가 눌렸고, 바닥이 아닐때 점프
				if (GetKeyDown() == 'w' && isBottom)
				{
					isJumping = true;
					isBottom = false;
				}

				//점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.
				if (isJumping)
				{
					dinoY -= gravity;
				}
				else
				{
					dinoY += gravity;
				}

				//Y가 계속해서 증가하는걸 막기위해 바닥을 지정.
				if (dinoY >= DINO_BOTTOM_Y)
				{
					dinoY = DINO_BOTTOM_Y;
					isBottom = true;
				}

				//나무가 왼쪽으로 (x음수) 가도록하고
				//나무의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.
				treeX -= 2;
				if (treeX <= 0)
				{
					treeX = TREE_BOTTOM_X;
				}

				//점프의 맨위를 찍으면 점프가 끝난 상황.
				if (dinoY <= 3)
				{
					isJumping = false;
				}
				if (GetKeyDown() == 's') {
					DownDrawDino(dinoY);
				}
				else DrawDino(dinoY);		//draw dino
				DrawTree(treeX);		//draw Tree


				//(v2.0)
				curr = clock();			//현재시간 받아오기
				if (((curr - start) / CLOCKS_PER_SEC) >= 1)	// 1초가 넘었을
				{
					score++;	//스코어 UP
					start = clock();	//시작시간 초기화
				}
				Sleep(60);
				system("cls");	//clear

				//(v2.0) 점수출력을 1초마다 해주는것이 아니라 항상 출력해주면서, 1초가 지났을때 ++ 해줍니다.
				GotoXY(22, 0);	//커서를 가운데 위쪽으로 옮긴다. 콘솔창이 cols=100이니까 2*x이므로 22정도 넣어줌
				printf("Score : %d ", score);	//점수 출력해줌.
			}

			//(v2.0) 게임 오버 메뉴
			DrawGameOver(score);
		}
	}
	else if (POS == 1) {//랭킹

	}
	else puts("게임종료를 눌렀습니다.");//게임종료

	return 0;
}