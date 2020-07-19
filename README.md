
#  Bresenhams  LineAlgorithm

###  Nikitha  Ann  George
###  MSc  Computer  Animation  and  Visual  Effects
###  Bournemouth  University  2015  -  2016



##  Description

The  Bresenham  algorithm  is  an  incremental  scan  conversion  algorithm.  The  big  advantage  of  this  algorithm  is  that,  it  uses  only  integer  calculations.  Moving  across  the  x  axis  in  unit  intervals  and  at  each  step  choose  between  two  different  y  coordinates.



##  Algorithm


To find the best "next pixel", first we must find the distances to the two available choices from the ideal location (of the real line). Distance between pixel-to-right and ideal pixel is: d1 = y - y(k) and the distance between pixel-to-right-and-up and ideal pixel is: d2 = (y(k)+1) - y. So we can simply choose subsequent pixels based on the following:
if (d1<=d2) then choose pixel-to-right: ( x(k)+1, y(k) )
if (d1>d2) then choose pixel-to-right-and-up: ( x(k)+1, y(k)+1 )

Bresenham  Line  Drawing  Algorithm  contains  two  phases  :

 **1. slope(m)  <  1.
 2.  slope(m)  >=  1.**
 *According to slope Decision Parameter is calculated, which is used to make decision for selection of next pixel point in both the phases.*

**Derivation of Decision Parameter Pk**

* **For slope(m) < 1 :**
         -    In below figure, the y coordinate on the mathematical line at xk+1 is
    [
    ![Bresenham Line Drawing Algorithm](https://iq.opengenus.org/content/images/2019/03/dupper_and_dlower.jpg)
    ](https://iq.opengenus.org/content/images/2019/03/dupper_and_dlower.jpg)
    [
    ![Bresenham Line Drawing Algorithm](https://iq.opengenus.org/content/images/2019/03/bresenhamline-drwaing-@---Copy.jpg)
    ](https://iq.opengenus.org/content/images/2019/03/dupper_and_dlower.jpg)


> ```
>               Y = m(Xk+1) + b
>
> ```




         -    dupper and dlower are given as

> ```
>                dlower = y − yk
>                       = m(Xk + 1) + b − Yk
>                dupper = (yk + 1) − y
>                       = Yk + 1 − m(Xk + 1) − b
>
> ```

         -    dupper and dlower are used to make a  **simple decision**  about which pixel is closer to the mathematical line. This simple decision is based on the difference between the two pixel positions.

> -   dlower − dupper = 2m(xk + 1) − 2yk + 2b − 1

         -    substitute m with dy/dx where dx and dy are the differences between the end-points.

> ```
>            dx(dlower−dupper) = dx(2dy.dx(xk + 1) − 2yk + 2b − 1)
>                              = 2dy.xk − 2dx.yk + 2dy + 2dx(2b − 1)
>                              = 2dy.xk − 2dx.yk + C
>
> ```

         -    So, a decision parameter Pk for the kth step along a line is given by −

> ```
>              pk = dx(dlower − dupper)
>                 = 2dy.xk − 2dx.yk + C
>
> ```

         -    The sign of the decision parameter Pk is the same as that of dlower−dupper.

         -    If pk is negative, choose the lower pixel, otherwise choose the upper pixel.

         -    At step k+1, the decision parameter is given as −
    * pk + 1 = 2dy.xk + 1 − 2dx.(yk+1) + C

    Subtracting pk from above statement we get −
    * pk + 1 − pk = 2dy((xk+1) − xk) − 2dx((yk+1) − yk)
    But, xk+1 is the same as (xk) + 1. Hence −
    *  **pk + 1 = pk + 2dy − 2dx((yk+1) − yk)**
    Where, (Yk+1) – Yk is either 0 or 1 depending on the sign of Pk.

         -    The first decision parameter p0 is evaluated at (x0, y0) is given as −
    *  **p0 = 2dy − dx**
* **For slope(m) > 1 && slope(m) = 1 :**

[![Bresenham Line Drawing Algorithm](https://iq.opengenus.org/content/images/2019/03/bresenhams_line_generation.jpg)](https://iq.opengenus.org/content/images/2019/03/bresenhams_line_generation.jpg)

-   Decesion parameter -
    -   **pk + 1 = pk + 2dx − 2dy((xk+1) − xk)**
-   The first decision parameter p0 is evaluated at (x0,y0) is given as −
    -   **p0 = 2dx − dy**



##  Requirements

Project  requires  Qtcreator  and  C++  with  NGL(University  Graphics  Library)






##  Output
![Alt  text](output/BresenhamLinePrinciple_01.png?raw=true  "BresenhamLinePrinciple_01")



![Alt  text](output/BresenhamLinePrinciple_02.png?raw=true  "BresenhamLinePrinciple_02")

