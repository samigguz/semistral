/* 
 * File:   Line.cpp
 * Author: andrew
 * 
 * Created on 3 Июнь 2015 г., 0:47
 */

#include "Line.h"

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

