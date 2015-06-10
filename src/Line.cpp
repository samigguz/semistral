/* 
 * File:   Line.cpp
 * Author: andrew
 * 
 * Created on 3 Июнь 2015 г., 0:47
 */

#include "Line.h"


void Line::show(devicePlot *hdc )
 {
    //std::cout << "Line " << std::endl;    
    bool steep =abs(y - Y) > abs(x - X); //zkontrolujeme rust useku na ose x a y
    //odrazeme linii sikmo, pokud uhel sklonu je prilis velky
    if (steep)
    {   
        ///<vemenime X a Y
        swap(X, Y); 
        swap(x, y);
    }
    //jestlize linie roste zprava doleva,vemenime zacatek a konec useku
    if (X > x)
    {
        swap(X, x);
        swap(Y, y);
    }
    int dx = x - X;
    int dy = abs(y - Y);
    int error = dx / 2; // tady se pouziva optimalizace - vynasobeni dx, abychom se zbavili zbytecnych zlomku
    int ystep = (Y < y) ? 1 : -1; ///<zvolime smer rustu souradnice Y
    int yy = Y;
    for (int xx = X; xx <= x; xx++)
    {
        ///<vratime souradnice na svoje mista
        hdc->putPixel(steep ? yy : xx, steep ? xx : yy); 
        error -= dy;
        if (error < 0)
        {
            yy += ystep;
            error += dx;
        }
    }
 }


void Line::show(devicePlot hdc )
 {
    //std::cout << "Line " << std::endl;    
    bool steep =abs(y - Y) > abs(x - X); // ��������� ���� ������� �� ��� ��� � �� ��� �����
    // �������� ����� �� ���������, ���� ���� ������� ������� �������
    if (steep)
    {   //������ � � � �������
        swap(X, Y); // ����������� ��������� �������� � ��������� ������� ��� �������
        swap(x, y);
    }
    // ���� ����� ����� �� ����� �������, �� ������ ������ � ����� ������� �������
    if (X > x)
    {
        swap(X, x);
        swap(Y, y);
    }
    int dx = x - X;
    int dy = abs(y - Y);
    int error = dx / 2; // ����� ������������ ����������� � ���������� �� dx, ����� ���������� �� ������ ������
    int ystep = (Y < y) ? 1 : -1; // �������� ����������� ����� ���������� y
    int yy = Y;
    for (int xx = X; xx <= x; xx++)
    {
        hdc.putPixel(steep ? yy : xx, steep ? xx : yy); // �� �������� ������� ���������� �� �����
        error -= dy;
        if (error < 0)
        {
            yy += ystep;
            error += dx;
        }
    }
 }

void  Line::swap(int &a, int &b) {
    	int tmp = a;
    	a = b;
    	b = tmp;
    }


   void Line::setCoordinates (int x1,int y1, int x2,int y2 ) {
    	X=x1;
    	Y=y1;
    	
    	x=x2;
	y=y2;
    }
   
   
   
    Line::Line(int x1,int y1, int x2,int y2 ):plotPoint(x1,y1){
       x=x2;
       y=y2;
  
    }
    