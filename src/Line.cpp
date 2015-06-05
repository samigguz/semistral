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
        hdc->putPixel(steep ? yy : xx, steep ? xx : yy); // �� �������� ������� ���������� �� �����
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
       /*
       Jestlize A, B jsou dva ruzne body, pak vektor p = B - A nazyvame smerovy vektor primky AB.
       V nasem pripade smerovy vektor p bubeme mit dve parametricke rovnice (p(p1,p2)):
       x=p1*t+x1 kde t=(x-x1)/p1
       y=p2*t+y1 kde t=(y-y1)/p2
       */
    }
    