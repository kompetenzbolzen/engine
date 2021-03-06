#include <unistd.h>
#include <string>

#include <termgl.h>

//#include "testobject.h"

class testobject : cObject
{
public:
	testobject()
	{
		setSize(10,5);
		cc = 0;

		drawRectangle('#', NULL, {0,0}, {9,4}, _COL_GREEN, _COL_DEFAULT);
	}

	~testobject() { destruct(); }

	virtual void onClick(sPos _pos, unsigned int _button)
	{
		cc++;
		drawText(std::to_string(cc), {2,2}, _COL_RED);

		drawPoint('Q', _pos, _COL_YELLOW);
	}

	virtual void onChar(unsigned char _c) { drawPoint(_c, {1,1}, _COL_BLUE); }
private:
	int cc;
};

int main(int argc, char* argv[])
{
	cRender render(' ', _COL_DEFAULT);
	cObjectHandler handler(&render);
	cObject ver(45,1);
	cWiremesh obj;
	testobject obj2;

	cInput input;

	unsigned int framecounter = 0;
	bool loop = true;

	if(argc > 1)
	{
			loop = false;
	}

	render.render();

	ver.drawText(DATE, {20,0}, _COL_WHITE);
	ver.drawText(VERSTRING, {0,0}, _COL_WHITE);
	int iver = handler.createObject(&ver);
	handler.moveObject(iver, {0,0}, _MOVE_ABSOLUTE);

	int x = 15;
	int y = 15;
	int z = 30;

	obj.addVector({-x,-y,z}, {2*x,0,0}, '+', _COL_RED);
	obj.addVector({-x,-y,z}, {0,2*y,0}, '+', _COL_RED);
	obj.addVector({-x,y,z}, {2*x,0,0}, '+', _COL_RED);
	obj.addVector({x,-y,z}, {0,2*y,0}, '+', _COL_RED);

	obj.addVector({-x,-y,0}, {0,0,z}, ':', _COL_RED);
	obj.addVector({x,-y,0}, {0,0,z}, ':', _COL_RED);
	obj.addVector({-x,y,0}, {0,0,z}, ':', _COL_RED);
	obj.addVector({x,y,0}, {0,0,z}, ':', _COL_RED);

	obj.addVector({-x,-y,0}, {2*x,0,0}, ',', _COL_RED);
	obj.addVector({-x,-y,0}, {0,2*y,0}, ',', _COL_RED);
	obj.addVector({-x,y,0}, {2*x,0,0}, ',', _COL_RED);
	obj.addVector({x,-x,0}, {0,2*y,0}, ',', _COL_RED);
	int imesh = handler.createWiremesh(&obj);

	int iobj2 = handler.createObject((cObject*)&obj2);
	handler.moveObject(iobj2, {3,3}, _MOVE_ABSOLUTE);

	sPos middle = render.getSize();
	middle.x /= 2;
	middle.y /= 2;

	handler.moveWiremesh(imesh,{middle.x,middle.y,0}, _MOVE_ABSOLUTE);

	while( loop )
	{
		sInputEvent ie = input.poll();

		if(ie.type != _EVENT_NULL)
		{
			if(ie.type == _EVENT_KEY)
			{
				switch (ie.c)
				{
					case 'A'://up
						handler.setCameraPosition({0,-1}, _MOVE_RELATIVE);
						break;
					case 'B'://down
						handler.setCameraPosition({0,1}, _MOVE_RELATIVE);
						break;
					case 'C'://right
						handler.setCameraPosition({1,0}, _MOVE_RELATIVE);
						break;
					case 'D'://left
						handler.setCameraPosition({-1,0}, _MOVE_RELATIVE);
						break;
				};
			}
			else if (ie.type == _EVENT_MOUSE)
			{
				if(ie.b == 0)
					handler.clickEvent({ie.x, ie.y}, 0);
			}
			else if (ie.type == _EVENT_CHAR)
			{
				//handler.charEvent(ie.c);
				switch(ie.c)
				{
					case 'w':
						handler.rotateWiremesh(imesh,{-10,0,0});
						break;
					case 's':
						handler.rotateWiremesh(imesh,{10,0,0});
						break;
					case 'a':
						handler.rotateWiremesh(imesh,{0,-10,0});
						break;
					case 'd':
						handler.rotateWiremesh(imesh,{0,10,0});
						break;
					case 'q':
						handler.rotateWiremesh(imesh,{0,0,-10});
						break;
					case 'e':
						handler.rotateWiremesh(imesh,{0,0,10});
						break;
				};
			}
			else if (ie.type == _EVENT_FUNCTION1)
			{
				return 0;
			}
			else if (ie.type == _EVENT_TERM)
			{
				return 0;
			}
		}

		handler.rotateWiremesh(imesh,{1,1,1});

		handler.write();
		render.render();
		framecounter++;

		if(loop)
			usleep(10*1000);
	}

	return 0;
}
