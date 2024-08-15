#ifndef __POINT_H__
#define __POINT_H__

typedef struct _point {
	int xpos;
	int ypos;
}Point;

void SetPointPos(Point *p, int xpos, int ypos);
void ShowPointPos(Point *p);
int PointComp(Point *p1, Point *p2);

#endif // !__POINT_H__
