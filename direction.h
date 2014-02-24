#ifndef DIRECTION_H
#define DIRECTION_H

class Direction {
    int xDirection;
    int yDirection;
  public:
  	Direction(void);
    // GET
    int getXDirection(void);
    int getYDirection(void);
    // SET
    void setXDirection(int);
    void setYDirection(int);
    void setDirection(int, int);
    // TURN
    void turnLeft(void);
    void turnRight(void);
};

#endif