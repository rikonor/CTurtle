#ifndef POSITION_H
#define POSITION_H

class Position {
    int x, y;
  public:
  	Position(void);
    void setXY (int,int);
    int getX (void);
    int getY (void);
};

#endif