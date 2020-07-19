#ifndef IMAGEWRITE_H__
#define IMAGEWRITE_H__

#include<string>
struct vertex 																				//vertex (x,y)
{
  int x;
  int y;
};
class ImageWrite
{
public:
  ImageWrite() : m_width(0), m_height(0),m_data(0)
  {

  }
  ImageWrite(int _w,int _h);
  ~ImageWrite();
  void save(const std::string &_fname);
  void setPixel(int _x,int _y,unsigned char _r,unsigned char _g,unsigned char _b);
  void clear(unsigned char _r,unsigned char _g,unsigned char _b);
  void swapvertex(vertex &_a,vertex &_b);													//(_a.x=_b.x) and (_a.y=_b.y)
  void plotLine(vertex start,vertex end);													//Bresenhams Line Algorithm
  void swapvalues(vertex &_a);																//_a.x = _a.y and equivalent

private:
  int m_width;
  int m_height;
  unsigned char *m_data;


};

#endif
