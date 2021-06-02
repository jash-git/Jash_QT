#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QList>
#include <QImage>
#include <Qt/qgl.h>
#include <QtOpenGL>
#include <QString>
class GLWidget : public QGLWidget
{
public:
	GLWidget(QWidget *parent);

	~GLWidget();
	void initializeGL();
	void paintGL();
	void resizeGL(int w, int h);
	
	void DrawBall(float scale,int angle_Span);//畫球體
	void DrawCylinder(float length,float circle_radius,float degreespan);//畫紋理圓柱
	void DrawTaper(float height1,float circle_radius1,float degreespan1,int col1);//畫紋理三角錐
	float getVectorLength(float x,float y,float z);//法向量規格化，求模長度	
	void initLight0();//設定GL燈光
	void initMaterialWhite();//材質為白色時什麼顏色的光照在上面就將體現出什麼顏色
	
	GLuint texture[1];//紋理
	void initTexture();//初始化紋理
	void DrawTextureTRIANGLES(float scale);//畫紋理三角形
	
	void initGreenLight();//初始化綠色燈
	void initRedLight();//初始化紅色燈
	void initMaterial();////初始化材質
	int lightAngleGreen;//轉動綠燈
	int lightAngleRed;//轉動紅燈
	void DrawTextureBall(float scale,int angle_Span);//畫球體
	void RunTimeLog(int intStep,char *chrNote);
	GLfloat xRot, yRot, zRot;
	GLfloat zoom; 
	bool light;
};

#endif // GLWIDGET_H
