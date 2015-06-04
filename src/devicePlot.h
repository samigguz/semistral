/* 
 * File:   devicePlot.h
 * Author: 
 *
 * Created on 2 Июнь 2015 г., 23:56
 */



#ifndef DEVICEPLOT_H
#define	DEVICEPLOT_H



class devicePlot {
public:
    devicePlot(){M=N=0;};
    
		devicePlot(int m,int n):M(m),N(n)
		{
			array=new char *[m];

	           for (int i = 0; i < m; i++)
                    array[i] = new char [n];
                    for(int i=0;i<m;i++)
	              for (int j=0;j<n;j++)
	                {
	                  array[i][j]=' ';
	                }
			
		}
		
		void putPixel(int X, int Y) { putPixel(X,Y,'*'); }
		
		void putPixel(int X, int Y, char znak) {
		  
		  if (  X >=0 && X < N && Y>=0 && Y<M )
		  { 
		    array[Y][X]=znak;
		  }  
		  
		}
	virtual	void print(void);
        virtual	void fill(int,int,int,int, char);
                
        void printInfo();
            
             char **array;
	private:
		int M;
		int N;
		
	 	

};

#endif	/* DEVICEPLOT_H */

