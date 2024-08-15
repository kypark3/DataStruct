#include <stdio.h>
#include "Point.h"

void SetPointPos(Point *p, int xpos, int ypos) {
	p->xpos = xpos;
	p->ypos = ypos;
}
void ShowPointPos(Point *p) {
	printf("[%d , %d]\n", p->xpos, p->ypos);
}
int PointComp(Point *p1, Point *p2) {

	if (p1->xpos == p2->xpos && p1->ypos == p2->ypos)return 0;
	else if (p1->xpos == p2->xpos) return 1;
	else if (p1->ypos == p2->ypos) return 2;
	else return -1;

}