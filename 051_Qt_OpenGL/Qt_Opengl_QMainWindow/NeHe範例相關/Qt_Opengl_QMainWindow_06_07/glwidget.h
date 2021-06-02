#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QtOpenGL>
#include <QImage>
#include <Qt/qgl.h>


class GLWidget : public QGLWidget
{
public:
	GLWidget(QWidget *parent);
	
	GLuint texture[3];
	GLuint filter;
	//bool fullscreen;
	GLfloat xRot, yRot, zRot;
	GLfloat zoom; 
	GLfloat xSpeed, ySpeed;
	bool light;
	
	~GLWidget();
	void initializeGL(); 
	void paintGL();
	void resizeGL(int w, int h);
	void loadGLTextures();
};

#endif // GLWIDGET_H
