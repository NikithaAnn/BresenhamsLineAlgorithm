#include "ImageWrite.h"
#include <cassert>
#include <fstream>
#include <iostream>

ImageWrite::ImageWrite(int _w,int _h)
{
  m_width=_w;
  m_height=_h;
  m_data= new unsigned char [m_width*m_height*3];
}

ImageWrite::~ImageWrite()
{
  if(m_data !=0)
 {
    delete [] m_data;
  }
}

void ImageWrite::save(const std::string &_fname)												//Saving to file named _fname
{
      std::ofstream output;
      output.open(_fname);
      if(!output.is_open())
      {
        std::cerr<<"Problem Opening File"<<_fname<<"\n";
        exit(EXIT_FAILURE);
      }
        output<<"P3\n";
        output<<m_width<<" "<<m_height<<"\n";
        output<<"255\n";

        for(int y=0;y<m_height;y++)
        {
          for(int x=0;x<m_width;++x)
           {
            output<<(int)m_data[(y*m_width*3)+x*3]<<" ";
            output<<(int)m_data[(y*m_width*3)+x*3+1]<<" ";
            output<<(int)m_data[(y*m_width*3)+x*3+2]<<"   ";
            }

          output<<"\n";
        }

        output.close();
}

void ImageWrite::setPixel(int _x, int _y, unsigned char _r, unsigned char _g, unsigned char _b) //Illuminating pixel at (x,y)
{
      assert(_x<m_width && _y<m_height);
      unsigned int index=(_y*m_width*3)+(_x*3);
      m_data[index]=_r;
      m_data[index+1]=_g;
      m_data[index+2]=_b;
}
void ImageWrite::clear(unsigned char _r,unsigned char _g,unsigned char _b)						//Setting up a background color
{
      for(int y=0;y<m_height;++y)
      {
        for(int x=0;x<m_width;++x)
        {
          setPixel(x,y,_r,_g,_b);
        }
      }
}
void ImageWrite::swapvertex(vertex &_a,vertex &_b)												//End is Start
{
      vertex temp;
      temp.x=_a.x;
      _a.x=_b.x;
      _b.x=temp.x;

      temp.y=_a.y;
      _a.y=_b.y;
      _b.y=temp.y;

}
void ImageWrite::swapvalues(vertex &_a)
{
  int temp;
  temp=_a.x;
  _a.x=_a.y;
  _a.y=temp;
}
void ImageWrite::DrawLine(vertex start,vertex end)
{
      int _dx,_dy,y,steep=0,yinc=-1,x=0,D;

      _dx=end.x-start.x;
      _dy=end.y-start.y;

      if(abs(_dy)>abs(_dx))  																	//The line has greater height than width:steep
      {
        swapvalues(start);
        swapvalues(end);
        steep=1;
      }
      if(start.x>end.x)																			//_dx will be negative value	
       swapvertex(start,end);
        
     if(start.y<end.y)																			//We have set yinc to be an incrementing flag that increments if y2>y1 and decrements elsewise
        yinc=1;

      _dx=end.x-start.x;
      _dy=abs(end.y-start.y);

      D=2*_dy-_dx;																				//D is function for plotting next point

      y=start.y;
      for(x=start.x;x<end.x;x++)
      {
        D=D+2*_dy;
        if(steep)																				//If the line is steep,we setPixel(y,x) as we go in opposite direction
          setPixel(y,x,255,0,127);
        else
          setPixel(x,y,255,255,0);

        if(D>0)
         {
            y+=yinc;
            D=D-(2*_dx);
        }

      }

}




	
	

