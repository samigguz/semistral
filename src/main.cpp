/* 
 * File:   main.cpp
 * Author: 
 *
 * Created on 3 Июнь 2015 г., 0:11
 */

#include <cstdlib>
#include <iostream>

#include "devicePlot.h"
#include "plotPoint.h"
#include "Line.h"
#include "painter.h"
#include "interpretator.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    interpretator mainInterpretator("example1.guz","example1.out");
    
    mainInterpretator.doIt();
    
        //devicePlot hdc(35,35);
     /*   
        painter canvas;
        canvas.setHDC( hdc);
        
        
        
        
	  //Circle a(15,15,7);
	//Rectangle r(1,1,1,10);
	//Ellipse e(0,5,25,20);
		plotPoint a(19,1);a.show(hdc);a.fill(hdc,'|');
	plotPoint b(3,12);b.show(hdc);
	plotPoint c(30,1);c.show(hdc);c.fill(hdc,'|');
	plotPoint c2(3,11);c2.show(hdc);c2.fill(hdc,'@');
	
	
	Line x(18,2,20,2);x.show(hdc);
	Line y(17,3,21,3);y.show(hdc);
    Line z(18,4,21,4);z.show(hdc);
    Line q(29,2,31,2);q.show(hdc);
	Line w(28,3,32,3);w.show(hdc);
	Line e(27,4,30,4);e.show(hdc);
	Line r(19,5,29,5);r.show(hdc);
	Line t(20,6,30,6);t.show(hdc);
	Line u(21,7,30,7);u.show(hdc);
	
	Line i(21,8,30,8);i.show(hdc);
	Line o(21,9,23,9);o.show(hdc);
		Line ooo(25,9,31,9);ooo.show(hdc);
		
    Line p(20,10,30,10);p.show(hdc);
    Line s(19,11,30,11);s.show(hdc);
	Line d(19,12,22,12);d.show(hdc);
	Line ddd(25,12,31,12);ddd.show(hdc);
	Line f(3,13,4,13);f.show(hdc);
	Line g(26,13,30,13);g.show(hdc);
	Line h(3,14,5,14);h.show(hdc);
	Line j(24,14,30,14);j.show(hdc);
	
		Line k(4,15,28,15);k.show(hdc);
	Line l(5,16,28,16);l.show(hdc);
    Line v(5,17,27,17);v.show(hdc);
    Line n(5,18,26,18);n.show(hdc);
	Line m(4,19,12,19);m.show(hdc);
	Line ee(16,19,21,19);ee.show(hdc);
	Line rr(23,19,27,19);rr.show(hdc);
	Line tt(3,20,9,20);tt.show(hdc);
	Line uu(15,20,19,20);uu.show(hdc);
	
	Line xx(24,20,27,20);xx.show(hdc);
	Line yy(2,21,4,21);yy.show(hdc);
    Line zz(7,21,9,21);zz.show(hdc);
    Line qq(14,21,17,21);qq.show(hdc);
	Line ww(25,21,28,21);ww.show(hdc);
	Line e1(1,22,3,22);e1.show(hdc);
	
	Line r1(8,22,10,22);r1.show(hdc);
	Line t1(14,22,16,22);t1.show(hdc);
	Line u1(26,22,28,22);u1.show(hdc);
	Line x1(0,23,2,23);x1.show(hdc);
	Line y1(0,24,2,24);y1.show(hdc);
    Line z1(0,25,2,25);z1.show(hdc);
    
    Line q1(1,26,3,26);q1.show(hdc);
	Line w1(3,27,4,27);w1.show(hdc);
	Line e2(10,23,15,23);e2.show(hdc);
	Line r2(11,24,14,24);r2.show(hdc);
	Line t2(11,25,16,25);t2.show(hdc);
	Line u2(10,26,12,26);u2.show(hdc);
		Line x2(16,26,17,26);x2.show(hdc);
	Line y2(10,27,11,27);y2.show(hdc);
    Line z2(27,23,29,23);z2.show(hdc);
    Line q2(28,24,30,24);q2.show(hdc);
	Line w2(29,25,31,25);w2.show(hdc);
	Line e3(30,26,31,26);e3.show(hdc);
	Line r3(23,19,27,19);r3.show(hdc);
	Line t3(3,20,9,20);t3.show(hdc);
	Line u3(15,20,19,20);u3.show(hdc);
	
	
	Line y22(7,14,20,14);y22.show(hdc);
    Line z22(8,13,18,13);z22.show(hdc);
    Line q22(9,12,16,12);q22.show(hdc);
	
	plotPoint c3(19,12);c3.show(hdc);c3.fill(hdc,'@');
	plotPoint c4(20,12);c4.show(hdc);c4.fill(hdc,'.');
	plotPoint c5(21,12);c5.show(hdc);c5.fill(hdc,'.');
	plotPoint c6(22,12);c6.show(hdc);c6.fill(hdc,')');
	plotPoint c7(23,9);c7.show(hdc);c7.fill(hdc,'(');
	plotPoint c8(25,9);c8.show(hdc);c8.fill(hdc,')');
	
	plotPoint ca(24,9);ca.show(hdc);ca.fill(hdc,'.');
	
	plotPoint ww1(23,8);ww1.show(hdc);ww1.fill(hdc,'"');
	plotPoint ggg(24,8);ggg.show(hdc);ggg.fill(hdc,'"');
	plotPoint c18(25,8);c18.show(hdc);c18.fill(hdc,'"');
        
        
        canvas.paint( new Line(0,0,10,10) );
        */
	//hdc.print();
	//b.print();
	return 0;
}

