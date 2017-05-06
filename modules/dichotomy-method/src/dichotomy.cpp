#include <include/dichotomy.h>
#include <iostream>
//За унимодальную функцию примем y = afactor*(x+bfactor)^2 + cfactor
double Dichotomy::findMin(int afactor,int bfactor, int cfactor,
     double leftBorder, double rightBorder, double eps)
{
    double c = (leftBorder + rightBorder)/2;
    double x = 0, y = 0;
    double funcValueC = afactor*(c+bfactor)*(c+bfactor) + cfactor;
    while(rightBorder - leftBorder > eps)
    {
        x = (leftBorder + c)/2;
        double funcValueX = afactor*(x+bfactor)*(x+bfactor) + cfactor;
        y = (c + rightBorder)/2;
        double funcValueY = afactor*(y+bfactor)*(y+bfactor) + cfactor;
        if ((funcValueX < funcValueY) && (funcValueX < funcValueC))
            {
                rightBorder = c;
                c = x;
                funcValueC = funcValueX;
            }
        else if ((funcValueC < funcValueX) && (funcValueC < funcValueY))
            {
                leftBorder = x;
                rightBorder = y;
            }
        else
            {
                leftBorder = c;
				c = y;
                funcValueC = funcValueY;
            }

        //Поскольку метод Дихотомии должен вернуть отрезок, на котором
        //должен находиться минимум, возьмём за оценку решения его середину
    }
	return (leftBorder + rightBorder) / 2;
}
