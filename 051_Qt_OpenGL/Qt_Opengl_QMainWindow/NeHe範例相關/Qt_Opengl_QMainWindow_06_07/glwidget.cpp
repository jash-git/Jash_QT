#include "glwidget.h"

GLfloat lightAmbient[4] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat lightDiffuse[4] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat lightPosition[4]= { 0.0, 0.0, 2.0, 1.0 };

GLWidget::GLWidget(QWidget *parent):QGLWidget(parent)
{
	xRot = yRot = zRot = 0.0;
	zoom = -5.0;
	xSpeed = ySpeed = 0.0;
	
	filter = 0;
	
	light = false;
	
}

GLWidget::~GLWidget()
{}

void GLWidget::initializeGL()
{
	loadGLTextures();
	glEnable( GL_TEXTURE_2D );
	glShadeModel( GL_SMOOTH );
	glClearColor( 0.0, 0.0, 0.0, 0.5 );
	glClearDepth( 1.0 );
	glEnable( GL_DEPTH_TEST );
	glDepthFunc( GL_LEQUAL );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

	glLightfv( GL_LIGHT1, GL_AMBIENT, lightAmbient );
	glLightfv( GL_LIGHT1, GL_DIFFUSE, lightDiffuse ); 
	glLightfv( GL_LIGHT1, GL_POSITION, lightPosition );
	
	glEnable( GL_LIGHT1 );

}

void GLWidget::paintGL()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
	glTranslatef(  0.0,  0.0, zoom ); 
	
	glRotatef( xRot,  1.0,  0.0,  0.0 );
	glRotatef( yRot,  0.0,  1.0,  0.0 ); 
	
	glBindTexture( GL_TEXTURE_2D, texture[filter] );
	
	glBegin( GL_QUADS );
		glNormal3f( 0.0, 0.0, 1.0 );
		glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0, -1.0,  1.0 ); 
		glTexCoord2f( 1.0, 0.0 ); glVertex3f(  1.0, -1.0,  1.0 ); 
		glTexCoord2f( 1.0, 1.0 ); glVertex3f(  1.0,  1.0,  1.0 );
		glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0,  1.0,  1.0 );
	
		glNormal3f( 0.0, 0.0, -1.0 );
		glTexCoord2f( 1.0, 0.0 ); glVertex3f( -1.0, -1.0, -1.0 );
		glTexCoord2f( 1.0, 1.0 ); glVertex3f( -1.0,  1.0, -1.0 );
		glTexCoord2f( 0.0, 1.0 ); glVertex3f(  1.0,  1.0, -1.0 );
		glTexCoord2f( 0.0, 0.0 ); glVertex3f(  1.0, -1.0, -1.0 );
		
		glNormal3f( 0.0, 1.0, 0.0 );
		glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0,  1.0, -1.0 ); 
		glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0,  1.0,  1.0 );
		glTexCoord2f( 1.0, 0.0 ); glVertex3f(  1.0,  1.0,  1.0 );
		glTexCoord2f( 1.0, 1.0 ); glVertex3f(  1.0,  1.0, -1.0 );
		
		glNormal3f( 0.0, -1.0, 0.0 ); 
		glTexCoord2f( 1.0, 1.0 ); glVertex3f( -1.0, -1.0, -1.0 ); 
		glTexCoord2f( 0.0, 1.0 ); glVertex3f(  1.0, -1.0, -1.0 );
		glTexCoord2f( 0.0, 0.0 ); glVertex3f(  1.0, -1.0,  1.0 );
		glTexCoord2f( 1.0, 0.0 ); glVertex3f( -1.0, -1.0,  1.0 );
		
		glNormal3f( 1.0, 0.0, 0.0 );
		glTexCoord2f( 1.0, 0.0 ); glVertex3f(  1.0, -1.0, -1.0 ); 
		glTexCoord2f( 1.0, 1.0 ); glVertex3f(  1.0,  1.0, -1.0 );
		glTexCoord2f( 0.0, 1.0 ); glVertex3f(  1.0,  1.0,  1.0 );
		glTexCoord2f( 0.0, 0.0 ); glVertex3f(  1.0, -1.0,  1.0 );
		
		glNormal3f( -1.0, 0.0, 0.0 );
		glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0, -1.0, -1.0 ); 
		glTexCoord2f( 1.0, 0.0 ); glVertex3f( -1.0, -1.0,  1.0 );
		glTexCoord2f( 1.0, 1.0 ); glVertex3f( -1.0,  1.0,  1.0 );
		glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0,  1.0, -1.0 );
		
	glEnd();
	xRot += xSpeed;
	yRot += ySpeed;
}
void GLWidget::resizeGL(int width, int height)//void GLWidget::resizeGL(int w, int h)
{
	/*
	//	
	h = h < 1 ? 1 : h;
	glViewport( 0, 0, (GLint)w, (GLint)h );
	*/
	//版本02
	if ( height == 0 )
	{
		height = 1;
	}
	glViewport( 0, 0, (GLint)width, (GLint)height );//設定畫布大小
	/*
		GL_PROJECTION和GL_MODELVIEW 這兩個都是glMatrixMode()函數的參數

		這個函數其實就是對接下來要做什麼進行一下聲明

		如果參數是GL_PROJECTION，這個是投影的意思，就是要對投影相關進行操作，也就是把物體投影到一個平面上，就像我們照相一樣，把3維物體投到2維的平面上。這樣，接下來的語句可以是跟透視相關的函數，比如glFrustum()或gluPerspective()；

		如果參數是GL_MODELVIEW，這個是對模型視景的操作，接下來的語句描繪一個以模型為基礎的適應，這樣來設置參數，接下來用到的就是像gluLookAt()這樣的函數；

		若是GL_TEXTURE，就是對紋理相關進行操作；

		順便說下，OpenGL裏面的操作，很多是基於對矩陣的操作的，比如位移，旋轉，縮放，所以，這裏其實說的規範一點就是glMatrixMode是用來指定哪一個矩陣是當前矩陣，而它的參數代表要操作的目標，GL_PROJECTION是對投影矩陣操作，GL_MODELVIEW是對模型視景矩陣操作，GL_TEXTURE是對紋理矩陣進行隨後的操作。
	*/
	glMatrixMode( GL_PROJECTION );//投影的意思
	
	glLoadIdentity();
	
	/*
		gluPerspective		// 設置透視圖
		(
			45,			// 透視角設置為 45 度,在Y方向上以角度為單位的視野
			(GLfloat)x/(GLfloat)y,	// 窗口的寬與高比
			0.1f,			// 視野透視深度:近點1.0f
			3000.0f			// 視野透視深度:始點0.1f遠點1000.0f
		);
	*/
	gluPerspective( 45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0 );//3D一定要設定 否則無法用2D顯示3D
	
	glMatrixMode( GL_MODELVIEW );//模型視景的操作
	
	glLoadIdentity();
}
void GLWidget::loadGLTextures()
{
	QImage Image_tex, Image_buf;
	if(!Image_buf.load("NeHe.bmp"))
	{
		QImage Image_dummy( 128, 128, /*32*/QImage::Format_Indexed8);
		Image_dummy.fill( Qt::green );
		Image_buf = Image_dummy;
	}
	Image_tex = QGLWidget::convertToGLFormat( Image_buf );
	
	glGenTextures(3,&texture[0]);
	
	glBindTexture( GL_TEXTURE_2D, texture[0] );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glTexImage2D( GL_TEXTURE_2D, 0, 3, Image_tex.width(), Image_tex.height(), 0,GL_RGBA, GL_UNSIGNED_BYTE, Image_tex.bits());

	glBindTexture( GL_TEXTURE_2D, texture[1] );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glTexImage2D( GL_TEXTURE_2D, 0, 3, Image_tex.width(), Image_tex.height(), 0,GL_RGBA, GL_UNSIGNED_BYTE, Image_tex.bits());

	glBindTexture( GL_TEXTURE_2D, texture[2] );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glTexImage2D( GL_TEXTURE_2D, 0, 3, Image_tex.width(), Image_tex.height(), 0,GL_RGBA, GL_UNSIGNED_BYTE, Image_tex.bits());	
}

