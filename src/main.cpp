//References:
//http://www.roguebasin.com/index.php?title=Bresenham%27s_Line_Algorithm
//https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
//THIS PROGRAM CREATES A FILE BresenhamLinePrinciple.ppm TO IMPLEMENT BRESENHAMS LINE ALGORITHM
//THE FILE Test.ppm CREATES A BLANK COLORED IMAGE
#include<iostream>
#include<cstdlib>
#include "BresnhamLinePrinciple.h"
int main()
{
  std::cout<<"------------Image Created---------\n";
  BresnhamLinePrinciple myImage(400,400);
  myImage.clear(211,211,211);

  myImage.drawGrid();
  myImage.plotLine({10,395},{395,10}, false);
  myImage.save("BresenhamLinePrinciple_01.ppm");

  myImage.clear(47,79,79);

   for(int a = 5; a < 395; a+=5)												//A FOR LOOP THAT CREATES A LINED IMAGE TO SCREEN TO CHECK IF FUNCTION WORKS FOR ALL OCTANTS
   {
     myImage.plotLine({200,200},{5,a}, true);
   }
   for(int b = 5; b < 395; b+=5)
   {
     myImage.plotLine({200,200},{b,5},true);
   }

   for(int c = 5; c < 395; c+=5)
   {
     myImage.plotLine({200,200},{395,c},true);
   }

   for(int d = 5; d < 395; d+=5)
   {
     myImage.plotLine({200,200},{d,395},true);
   }


  //myImage.plotLine(200,200,400,400);
  //myImage.plotLine({200,0},{200,200});
  myImage.save("BresenhamLinePrinciple_02.ppm");
  return EXIT_SUCCESS;
}
