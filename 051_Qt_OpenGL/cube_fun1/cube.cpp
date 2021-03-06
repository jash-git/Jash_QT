#include <qcolordialog.h>

#include "cube.h"
#include "GLFun.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
Cube::Cube(QWidget *parent, const char *name)
    : QGLWidget(QGLFormat(QGL::SampleBuffers),parent)
{
    //setFormat(QGLFormat(DoubleBuffer | DepthBuffer));
    rotationX = 0;
    rotationY = 0;
    rotationZ = 0;
    /*
    faceColors[0] = red;
    faceColors[1] = green;
    faceColors[2] = blue;
    faceColors[3] = cyan;
    faceColors[4] = yellow;
    faceColors[5] = magenta;
    */
}

void Cube::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0,0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
	//////////////////////////////////////////
	static GLfloat  ambientLight[]	= { 1.0f, 1.0f, 1.0f, 1.0f };	
	static GLfloat  diffuseLight[]	= { 0.7f, 0.7f, 0.7f, 1.0f };
	static GLfloat  specular[]		= { 0.7f, 0.7f, 0.7f, 1.0f };	//燈光性質
	static GLfloat  specref []		= { 0.5f, 0.5f, 0.2f, 1.0f };	//反射性質
	static float normal[3];//設定法向量
	glFrontFace(GL_CCW);			// Counter clock-wise polygons face out
	glDisable(GL_CULL_FACE);		// Do not calculate inside of jet
	glShadeModel(GL_SMOOTH);


	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
	glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
	glEnable(GL_LIGHT0);
	
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);//將多邊形設為具有反射性質	
	glMateriali(GL_FRONT, GL_SHININESS, 128);//設定反射性質的亮度
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );//設定桌布顏色	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//清除螢幕動作

}

void Cube::resizeGL(int width, int height)
{
	GLfloat nRange = 100.0f;

	// Prevent a divide by zero
	if(height == 0)
		height = 1;

	// Set Viewport to window dimensions
    glViewport(0, 0, width, height);

	// Reset projection matrix stack
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
    if (width <= height) 
		glOrtho (-nRange, nRange, -nRange*height/width, nRange*height/width, -nRange, nRange);
    else 
		glOrtho (-nRange*height/width, nRange*height/width, -nRange, nRange, -nRange, nRange);

	// Reset Model view matrix stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void Cube::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw();
}

void Cube::draw()
{
	glPushMatrix();  //附屬伸長連桿一
	{	
		glTranslatef(0.0f,0.0f,0.0f);
    	glRotatef(rotationX, 1.0, 0.0, 0.0);
    	glRotatef(rotationY, 0.0, 1.0, 0.0);
    	glRotatef(rotationZ, 0.0, 0.0, 1.0);
		glColor3ub(200.0f,100.0f,100.0f);
		drawRetc(10.0f,10.0f,100.0f);
		}	
	glPopMatrix();	
	/*
    static const GLfloat coords[6][4][3] = {
        { { +1.0, -1.0, +1.0 }, { +1.0, -1.0, -1.0 },
          { +1.0, +1.0, -1.0 }, { +1.0, +1.0, +1.0 } },
        { { -1.0, -1.0, -1.0 }, { -1.0, -1.0, +1.0 },
          { -1.0, +1.0, +1.0 }, { -1.0, +1.0, -1.0 } },
        { { +1.0, -1.0, -1.0 }, { -1.0, -1.0, -1.0 },
          { -1.0, +1.0, -1.0 }, { +1.0, +1.0, -1.0 } },
        { { -1.0, -1.0, +1.0 }, { +1.0, -1.0, +1.0 },
          { +1.0, +1.0, +1.0 }, { -1.0, +1.0, +1.0 } },
        { { -1.0, -1.0, -1.0 }, { +1.0, -1.0, -1.0 },
          { +1.0, -1.0, +1.0 }, { -1.0, -1.0, +1.0 } },
        { { -1.0, +1.0, +1.0 }, { +1.0, +1.0, +1.0 },
          { +1.0, +1.0, -1.0 }, { -1.0, +1.0, -1.0 } }
    };

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(rotationX, 1.0, 0.0, 0.0);
    glRotatef(rotationY, 0.0, 1.0, 0.0);
    glRotatef(rotationZ, 0.0, 0.0, 1.0);

    for (int i = 0; i < 6; ++i) {
        glLoadName(i);
        glBegin(GL_QUADS);
        qglColor(faceColors[i]);
        for (int j = 0; j < 4; ++j) {
            glVertex3f(coords[i][j][0], coords[i][j][1],
                       coords[i][j][2]);
        }
        glEnd();
    }
	//*/
}

void Cube::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void Cube::mouseMoveEvent(QMouseEvent *event)
{
    GLfloat dx = (GLfloat)(event->x() - lastPos.x()) / width();
    GLfloat dy = (GLfloat)(event->y() - lastPos.y()) / height();

    if (event->button() & Qt::LeftButton) {
        rotationX += 180 * dy;
        rotationY += 180 * dx;
        updateGL();
    } else if (event->button() & Qt::RightButton) {
        rotationX += 180 * dy;
        rotationZ += 180 * dx;
        updateGL();
    }
    lastPos = event->pos();
}

void Cube::mouseDoubleClickEvent(QMouseEvent *event)
{
    int face = faceAtPosition(event->pos());
    if (face != -1) {
        QColor color = QColorDialog::getColor(faceColors[face],
                                              this);
        if (color.isValid()) {
            faceColors[face] = color;
            updateGL();
        }
    }
}

int Cube::faceAtPosition(const QPoint &pos)
{
    const int MaxSize = 512;
    GLuint buffer[MaxSize];
    GLint viewport[4];

    glGetIntegerv(GL_VIEWPORT, viewport);
    glSelectBuffer(MaxSize, buffer);
    glRenderMode(GL_SELECT);

    glInitNames();
    glPushName(0);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluPickMatrix((GLdouble)pos.x(),
                  (GLdouble)(viewport[3] - pos.y()),
                  5.0, 5.0, viewport);
    GLfloat x = (GLfloat)width() / height();
    glFrustum(-x, x, -1.0, 1.0, 4.0, 15.0);
    draw();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    if (!glRenderMode(GL_RENDER))
        return -1;
    return buffer[3];
}

