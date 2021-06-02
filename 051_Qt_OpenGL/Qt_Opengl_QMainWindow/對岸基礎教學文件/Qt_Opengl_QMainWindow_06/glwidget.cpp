#include "glwidget.h"
#include <math.h>
#include "GLFun.h"

GLfloat nRange = 2000.0f;//
GLWidget::GLWidget(QWidget *parent):QGLWidget(parent)
{}

GLWidget::~GLWidget()
{}

void GLWidget::initializeGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
	qglClearColor( Qt::black );//設定背景色
}

void GLWidget::paintGL()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	///////////////////////////////////////////////////////////	
	glPushMatrix();  //附屬伸長連桿一
	{	
		glTranslatef(0.0f,0.0f,0.0f);
		glColor3ub(100.0f,100.0f,100.0f);
		drawRetc(400.0f,400.0f,400.0f);
	}	
	glPopMatrix();		
}
void GLWidget::resizeGL(int w, int h)
{
	h = h < 1 ? 1 : h;
	glViewport( 0, 0, (GLint)w, (GLint)h );//設定GL畫面大小和視窗同動
	
	// Reset projection matrix stack
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	/*視口變換
	glFrustum
	gluPerspective
	glOrtho			宣告 : glOrtho(left, right, bottom, top, near, far)
	*/	
	if (w <= h) 
		glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange*2, nRange*2);
    else 
		glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange*2, nRange*2);

	// Reset Model view matrix stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}
