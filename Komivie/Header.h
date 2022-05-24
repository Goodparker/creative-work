#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <glut.h>
#include <iomanip>
#include <algorithm>
using namespace std;

float winW = 1280.0;
float winH = 720.0;
float R = 0.0;
const int maxSize = 20;

int amount_vertex, amount_rib, source_vertex, target_vertex, rib_weight;
vector<vector<int>> adj_matrix(maxSize, vector<int>(maxSize));
vector<vector<int>> double_adjM_K;

void drawButton1();//Кнопка выполения алгаритма
void drawCircle(int x, int y, int R);//Круг
void drawText(int nom, int x1, int y1);//Вес ребра
void drawLine(int text, int x0, int y0, int x1, int y1);//ребро не орентир внеш граф
void drawVertex(int n);//Вершины
void setCoords(int i, int n);//Установка координат вершины в завис от размеров окна
void mouseClick(int button, int state, int x, int y);//Нажатия
void reshape(int w, int h);//Новый размер окна
void display();

class Graph
{
public:
	Graph();
	~Graph() {}
	bool IsEmpty();
	bool IsFull();
	void InsertVertex(const int& vertex);
	void InsertEdge(const int& vertex1, const int& vertex2,  int weight);
	int GetVertPos(const int& vertex);
	void Print();
	int Komiviezjor();//Само задание
	void drawGraph();//Рисование графа

private:
	vector<bool> visit;
	vector<int> min_ways;
	vector<int> vert_list;
};
Graph graph;


struct vertC//Координаты вершины
{
	int x, y;
};
vertC vC[20];

Graph::Graph()
{
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			adj_matrix[i][j] = 0;
		}
	}
}

bool Graph::IsEmpty()
{
	if (vert_list.size() != 0)
		return false;
	else
		return true;
}

bool Graph::IsFull()
{
	return (vert_list.size() == maxSize);
}

void Graph::InsertVertex(const int& vertex)
{
	if (!IsFull())
		vert_list.push_back(vertex);
	else
	{
		cout << "Граф уже заполнен, невозможно добавить новую вершину" << endl;
		return;
	}
}

int Graph::GetVertPos(const int& vertex)
{
	for (size_t i = 0; i < vert_list.size(); i++)
	{
		if (vert_list[i] == vertex)
			return i;
	}
	return -1;
}

void Graph::InsertEdge(const int& vertex1, const int& vertex2, int weight)
{
	if (GetVertPos(vertex1) != (-1) && GetVertPos(vertex2) != (-1))
	{
		int verPos1 = GetVertPos(vertex1);
		int verPos2 = GetVertPos(vertex2);
		if (adj_matrix[verPos1][verPos2] != 0 && adj_matrix[verPos2][verPos1] != 0)
		{
			cout << "Ребро между вершинами уже есть." << endl;
			return;
		}
		else
		{
			adj_matrix[verPos1][verPos2] = weight;
			adj_matrix[verPos2][verPos1] = weight;
		}
	}
	else
	{
		cout << "Обоих вершин или одной из них нет в графе." << endl;
		return;
	}
}

void Graph::Print()
{
	if (!IsEmpty())
	{
		cout << "Матрица смежности графа: " << endl;
		for (size_t i = 0; i < vert_list.size(); i++)
		{
			cout << vert_list[i] << " ";
			for (size_t j = 0; j < vert_list.size(); j++)
				cout << setw(4) << adj_matrix[i][j];
			cout << endl;
		}
	}
	else
		cout << "Граф пуст." << endl;
}

int Graph::Komiviezjor()
{
	vector<vector<int>> adjMatrix_Koimviezjor(amount_vertex, vector<int>(amount_vertex));
	for (int i = 0; i < amount_vertex; i++)
	{
		for (int j = 0; j < amount_vertex; j++)
		{
			if (i == j)
			{
				adjMatrix_Koimviezjor[i][j] = 999;
			}
			else
				adjMatrix_Koimviezjor[i][j] = adj_matrix[i][j];
		}
	}
	double_adjM_K = adjMatrix_Koimviezjor;
	
	int* di = new int[amount_vertex];
	int min = 0;
	for (int i = 0; i < amount_vertex; i++)
	{
		min = 1000;

		for (int j = 0; j < amount_vertex; j++)
		{
			if (adjMatrix_Koimviezjor[i][j] < min)
			{
				min = adjMatrix_Koimviezjor[i][j];
			}
		}
		di[i] = min;
	}
	
	for (int i = 0; i < amount_vertex; i++)
	{
		for (int j = 0; j < amount_vertex; j++)
		{
			adjMatrix_Koimviezjor[i][j] -= di[i];
		}
	}

	cout << "С учетом минимума по строкам:\n";
	for (int i = 0; i < amount_vertex; i++)
	{
		cout << i + 1 << "  ";
		for (int j = 0; j < amount_vertex; j++)
		{
			cout << setw(4) << adjMatrix_Koimviezjor[i][j];
		}
		cout << endl;
	}
	cout << endl;
	//--------------------------------------------------
	
	int* dj = new int[amount_vertex];
	int min_ = 0;
	for (int i = 0; i < amount_vertex; i++)
	{
		min_ = 1000;
		for (int j = 0; j < amount_vertex; j++)
		{
			if (adjMatrix_Koimviezjor[j][i] < min_)
			{
				min_ = adjMatrix_Koimviezjor[j][i];
			}
		}
		dj[i] = min_;
	}
	for (int i = 0; i < amount_vertex; i++)
	{
		for (int j = 0; j < amount_vertex; j++)
		{
			min_ = adjMatrix_Koimviezjor[j][i] -= dj[i];
		}
	}
	
	cout << "С учетом минимумов по столбцам:\n";
	for (int i = 0; i < amount_vertex; i++)
	{
		cout << i + 1 << "  ";
		for (int j = 0; j < amount_vertex; j++)
		{
			cout << setw(4) << adjMatrix_Koimviezjor[i][j];
		}
		cout << endl;
	}
	cout << endl;

	delete[] di;
	delete[] dj;
	//-----------------------------------------------------------

	vector<vector<int>> tmp_vector = adjMatrix_Koimviezjor;

	int* di_ = new int[amount_vertex];
	int min_not_null_Str = 0;
	for (int i = 0; i < amount_vertex; i++)
	{
		int counter = 0;
		min_not_null_Str = 1000;
		for (int j = 0; j < amount_vertex; j++)
		{
			if (tmp_vector[i][j] == 0)counter++;
		}
		for (int z = 0; z < amount_vertex; z++)
		{
			if (counter < 2)
			{
				if (tmp_vector[i][z] != 0 && tmp_vector[i][z] < min_not_null_Str)
					min_not_null_Str = tmp_vector[i][z];
			}
			else
				min_not_null_Str = 0;
		}
		di_[i] = min_not_null_Str;
	}

	
	int* dj_ = new int[amount_vertex];
	int min_not_null_Stl = 0;

	for (int i = 0; i < amount_vertex; i++)
	{
		int counter = 0;
		min_not_null_Stl = 1000;
		for (int j = 0; j < amount_vertex; j++)
		{
			if (tmp_vector[j][i] == 0)counter++;
		}
		for (int z = 0; z < amount_vertex; z++)
		{
			if (counter < 2)
			{
				if (tmp_vector[z][i] != 0 && tmp_vector[z][i] < min_not_null_Stl)
					min_not_null_Stl = tmp_vector[z][i];
			}
			else
				min_not_null_Stl = 0;
		}
		dj_[i] = min_not_null_Stl;
	}


	
	for (int i = 0; i < amount_vertex; i++)
	{
		for (int j = 0; j < amount_vertex; j++)
		{
			if (tmp_vector[i][j] == 0)
			{
				tmp_vector[i][j] = di_[i] + dj_[j];
			}
		}
	}

	cout << "С четом нулевых оценок:\n";
	for (int i = 0; i < amount_vertex; i++)
	{
		cout << i + 1 << "  ";
		for (int j = 0; j < amount_vertex; j++)
		{
			cout << setw(4) << tmp_vector[i][j];
		}
		cout << endl;
	}
	cout << endl;

	delete[] di_;
	delete[] dj_;

	
	vector<vector<int>> Result(amount_vertex, vector<int>(amount_vertex));
	for (int i = 0; i < amount_vertex; i++)
	{
		for (int j = 0; j < amount_vertex; j++)
		{
			Result[i][j] = 0;
		}
	}
	

	int global_exit = 0;
	int global_i = -1;
	int global_j = -1;
	while (global_exit != amount_vertex)
	{
		int max_null = 0;
		for (int i = 0; i < amount_vertex; i++)
		{
			if (i != global_i)
			{
				for (int j = 0; j < amount_vertex; j++)
				{
					if (j != global_j)
					{
						if (tmp_vector[i][j] < 500 && adjMatrix_Koimviezjor[i][j] == 0)
						{
							if (tmp_vector[i][j] > max_null)
								max_null = tmp_vector[i][j];
						}
					}
				}
			}
		}

		for (int i = 0; i < amount_vertex; i++)
		{
			if (i != global_i)
			{
				for (int j = 0; j < amount_vertex; j++)
				{
					if (j != global_j)
					{
						if (tmp_vector[i][j] == max_null && adjMatrix_Koimviezjor[i][j] == 0)
						{
							Result[i][j] = max_null;
							tmp_vector[j][i] = 999;
							global_i = i;
							global_j = j;
							global_exit++;
						}
					}
				}
			}
		}
	}

	

	cout << "Итоговая редукция матрицы\n";
	int one = 0;
	for (int i = 0; i < amount_vertex; i++)
	{
		cout << i + 1;
		for (int j = 0; j < amount_vertex; j++)
		{
			cout << setw(4) << Result[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Минимальный путь с посещением всех вершин\n";
	int summ = 0;
	int id = 0;
	vector<int> mass_count;
	for (int i = 0; i < amount_vertex; i++)
	{
		for (int j = 0; j < amount_vertex; j++)
		{
			if (Result[i][j])
			{
				cout << i + 1 << "->" << j + 1 << "->";
				mass_count.push_back(i);
				id++;
				mass_count.push_back(j);
				id++;
			}
		}
	}
	one = mass_count[0];
	mass_count.push_back(one);
	cout << one + 1 << " = ";


	
	for (int i = 0; i < id; i++)
	{
		summ += double_adjM_K[mass_count[i]][mass_count[i + 1]];
	}
	cout << summ << ".";

	return 0;
}



//Кнопочки 
void drawButton1()
{
	glColor3f(0.560f, 0.556f, 0.972f);

	glBegin(GL_QUADS);
	glVertex2i(0, winH);
	glVertex2i(0, winH - winH / 12);
	glVertex2i(winW / 12, winH - winH / 12);
	glVertex2i(winW / 12, winH);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP);
	glVertex2i(0, winH);
	glVertex2i(0, winH - winH / 12);
	glVertex2i(winW / 12, winH - winH / 12);
	glVertex2i(winW / 12, winH);
	glEnd();

	string but1 = "Zadacha";
	string but2 = "Komiviezjora";
	glRasterPos2i(4, winH - 12);
	for (int i = 0; i < but1.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but1[i]);
	glRasterPos2i(4, winH - 32);
	for (int i = 0; i < but2.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but2[i]);
}


void drawCircle(int x, int y, int R)
{
	glColor3f(0.7f, 0.7f, 1.0f);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	float  x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawText(int nom, int x1, int y1)
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = to_string(nom);
	glRasterPos2i(x1 - 5, y1 - 5);
	for (size_t j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);
}

void drawLine(int text, int x0, int y0, int x1, int y1)
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();

	drawText(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10);
}

void drawVertex(int n)
{
	for (int i = 0; i < n; i++)
	{
		drawCircle( vC[i].x, vC[i].y, R);
		drawText(i + 1, vC[i].x, vC[i].y);
	}
}

void setCoords(int i, int n)
{
	int R_;
	int x0 = winW / 2;
	int y0 = winH / 2;
	if (winW > winH)
	{
		R = 5 * (winH / 13) / n;
		R_ = winH / 2 - R - 10;
	}
	else
	{
		R = 5 * (winW / 13) / n;
		R_ = winW / 2 - R - 10;
	}
	float theta = 2.0f * 3.1415926f * i / n;
	int y1 = R_ * cos(theta) + y0;
	int x1 = R_ * sin(theta) + x0;

	vC[i].x = x1;
	vC[i].y = y1;
}


void Graph::drawGraph()
{
	int n = vert_list.size();
	for (int i = 0; i < n; i++)
	{
		setCoords(i, n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a = adj_matrix[i][j];
			if (a != 0)
			{
				drawLine(a, vC[i].x, vC[i].y, vC[j].x, vC[j].y);
			}
		}
	}
	drawVertex(n);
}

void mouseClick(int button, int state, int x, int y)
{
	if (x <= (winW / 6) and y <= (winH / 6))//1 Кнопка
		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{
			int k = graph.Komiviezjor();
			if (k == -1)
				cout << "Ошибка";
		}
}
void setGraph()
{
	cout << "Введите кол-во вершинн графа: "; cin >> amount_vertex; cout << endl;
	cout << "Введите кол-во ребер графа: "; cin >> amount_rib; cout << endl;
	for (int i = 1; i <= amount_vertex; i++)
	{
		int* vertPtr = &i;
		graph.InsertVertex(*vertPtr);
	}

	for (int i = 0; i < amount_rib; i++)
	{
		cout << "Исходная вершина: "; cin >> source_vertex; cout << endl;
		int* source_vertPtr = &source_vertex;
		cout << "Конечная вершина: "; cin >> target_vertex; cout << endl;
		int* target_vertPtr = &target_vertex;
		cout << "Вес ребра: "; cin >> rib_weight; cout << endl;
		graph.InsertEdge(*source_vertPtr, *target_vertPtr, rib_weight);
	}
	cout << endl;
	graph.Print();
}

void reshape(int w, int h)
{
	winH = h;
	winW = w;
	glViewport(0, 0, (GLsizei)winW, (GLsizei)winH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)winW, 0, (GLdouble)winH);
	glutPostRedisplay();
}
void display()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, winW, 0, winH);
	glViewport(0, 0, winW, winH);
	glClearColor(0.93, 0.54, 0.97,0.97);
	glClear(GL_COLOR_BUFFER_BIT);

	drawButton1();
	graph.drawGraph();

	glutSwapBuffers();
}
