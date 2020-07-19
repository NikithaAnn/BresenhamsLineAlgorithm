
#  Bresenhams  Line Algorithm [![Build Status](https://travis-ci.org/dwyl/esta.svg?branch=master)](https://travis-ci.org/)

###  Nikitha  Ann  George
###  MSc  Computer  Animation  and  Visual  Effects
###  Bournemouth  University  2015  -  2016




##  Description

The  Bresenham  algorithm  is  an  incremental  scan  conversion  algorithm.  The  big  advantage  of  this  algorithm  is  that,  it  uses  only  integer  calculations.  Moving  across  the  x  axis  in  unit  intervals  and  at  each  step  choose  between  two  different  y  coordinates.



##  Algorithm


To find the best "next pixel", first we must find the distances to the two available choices from the ideal location (of the real line).

Distance between pixel-to-right and ideal pixel is:

                d1 = y - y(k)

and the distance between pixel-to-right-and-up and ideal pixel is:

                d2 = (y(k)+1) - y.

So we can simply choose subsequent pixels based on the following:

                if (d1<=d2), then choose pixel-to-right, ( x(k)+1, y(k) )

                if (d1>d2), then choose pixel-to-right-and-up, ( x(k)+1, y(k)+1 )

Bresenham  Line  Drawing  Algorithm  contains  two  phases  :
 [
    ![Bresenham Line Drawing Algorithm](https://iq.opengenus.org/content/images/2019/03/dupper_and_dlower.jpg)
    ](https://iq.opengenus.org/content/images/2019/03/dupper_and_dlower.jpg)
    [

 1. **slope(m)  <  1**
 2. **slope(m)  >=  1**



 *According to slope Decision Parameter is calculated, which is used to make decision for selection of next pixel point in both the phases.*



##  Setup
The project requires the following,


<p align="left">
  <img src="https://upload.wikimedia.org/wikipedia/commons/f/fc/Qt_logo_2013.svg" width="5%" alt="Qtcreator Icon"/>
</p> Qtcreator
<p align="left">
  <img src="https://draconisart.com/wp-content/uploads/2019/03/education.png" width="5%" alt="NCCA Icon"/>
</p>
NGL (University  Graphics  Library)






##  Output
The image file to this algorithm can be found in, BresenhamLinePrinciple/BresnhamLinePrinciple.app/Contents/MacOS, on MacOSx

![Alt  text](output/BresenhamLinePrinciple_01.png?raw=true  "BresenhamLinePrinciple_01")

Output 1: Simple Bresenham on a grid with center axis marked

![Alt  text](output/BresenhamLinePrinciple_02.png?raw=true  "BresenhamLinePrinciple_02")

Output 2: Bresenham Principle applied on all octants

