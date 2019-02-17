#include <iostream>
#include <conio.h>//Позволяет взять функцию, которая будет отслеживать, что нажал юзер и не будет закрывать терминал

using namespace std;

bool GameOver;
const int width = 20;//Высота поля
const int height = 20;//Ширина поля
int x, y;//Координаты местоположения самой змейки
int fruitX, fruitY;//Координаты фруктов
int score;//Очки
int tailX[100], tailY[100];//Координаты хвоста
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
void Setup() {//При старте настраивает все нужные параметры
	GameOver = false;
	dir = STOP;
	x = width / 2 -1;
	y = height / 2 -1;
	fruitX = rand() % width;
	fruitY = rand() % width;
	score = 0;
}

void Draw() {//Прорисовка
	system("cls");//Очищает терминал каждый раз когда мы будем вызывать Draw
	for (int i = 0; i < width + 1; i++) //Верхняя граница
		cout << "#";
		cout << endl;
	
	
		for (int i = 0; i < height; i++) {//Боковая граница
			for (int j = 0; j < width; j++) {//Проверка каждой ячейки по ширине
				if ( j == 0 || j == width - 1)//ИЛИ нужно для заполнения последней ячейки
					cout << "#";
				if (i == y && j == x)
					cout << "0";
				else if (i == fruitY && j == fruitX)
					cout << "*";
				else {
					bool print = false;
					for (int k = 0; k < nTail; k++) {
						if (tailX[k] == j && tailY[k] == i) {
							print = true;
							cout << "o";
						}
						}
					if(!print)
					cout << " ";
				}
			}
			cout << endl;
		}


		for (int i = 0; i < width + 1; i++) //Нижняя граница
			cout << "#";
			cout << endl;
			cout << "Your Score Is: " << score << endl;
	
}

void Input() {  //Отслеживает все поступающие нажатия
	if (_kbhit()) {//Возвращает ИСТИНУ, если юзер нажал на какую-либо клавишу
		switch (_getch())//Эта функция ипроверяет какую кнопку нажал юзер
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT; 
			break;
		case 's':
			dir = DOWN;
			break;
		case 'w':
			dir = UP;
			break;
		case 'x':
			GameOver = true;
			break;
		}

	}
	
}

void Logic() { //Выполнение всей логики для игры
	int prevX = tailX[0];//Предыдущая позиция по X
	int prevY = tailY[0];
	int prev2X, prev2Y;//Переменные необходимые для помещения в них знаений следующего элемента
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < nTail; i++) {
		
		prev2X = tailX[i];//Обработка всего хваста
		prev2Y = tailY[i];

		tailX[i] = prevX;
		tailY[i] = prevY;

		prevX = prev2X;
		prevY = prev2Y;//По сюда
	}


	switch (dir) 
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case DOWN:
		y++;
		break;
	case UP:
		y--;
		break;
	}
	
	if (x >= width-1)//ТП за пределы карты
		x = 0;
	else if (x < 0)
		x = width - 2;

	if (y >= height)
		y = 0;
	else if (y < 0)
		y = height - 1;//по сюда

	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == x && tailY[i] == y)
			GameOver = true;
	}

	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % width;
		nTail++;
	}
}
	int main() {
	Setup();
	while (!GameOver) {
		Draw();
		Input();
		Logic();
	}


	return 0;
}