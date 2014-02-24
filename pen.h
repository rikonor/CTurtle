#ifndef PEN_H
#define PEN_H

class Pen {
	
    bool active;
    char shape;
  public:
  	Pen(void);
    bool isActive(void);
    void activate(void);
    void deactivate(void);
    void toggle(void);
	char getShape(void);
    void setShape(char);
};

#endif