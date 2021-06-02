#include "glwidget.h"
#include <math.h>
#include "GLFun.h"
#include <stdio.h>

#define PI 3.14159265
GLfloat nRange = 2000.0f;//GL畫面大小深度

GLWidget::GLWidget(QWidget *parent):QGLWidget(parent)
{}

GLWidget::~GLWidget()
{}

void GLWidget::initializeGL()
{
	////////////////////////////////////////////////////////
	RunTimeLog(1,"initializeGL()");
	//onSurfaceCreated_start
	 //關閉抗震動 
	glDisable(GL_DITHER);
	//設置特定Hint專案的模式，這裡為設置為使用快速模式
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_FASTEST);
	//設置螢幕背景色黑色RGBA
	glClearColor(0,0,0,0);
	//設置著色模型為平滑著色   
	glShadeModel(GL_SMOOTH);//GL10.GL_SMOOTH  GL10.GL_FLAT
	 //啟用深度測試
	glEnable(GL_DEPTH_TEST);
	
	glEnable(GL_LIGHTING);//允許光照
	
	initGreenLight();//初始化綠色燈
	initRedLight();//初始化紅色燈
	initMaterial();//初始化材質
	
	initTexture();//初始化紋理
	//onSurfaceCreated_end
	///////////////////////////////////////////////////////
	lightAngleGreen=0;//轉動綠燈
	lightAngleRed=90;//轉動紅燈
}
void GLWidget::initGreenLight()
{
	RunTimeLog(2,"initGreenLight()");
	glEnable(GL_LIGHT0);//打開0號燈  
	
	//環境光設置
	float ambientParams[]={0.1f,0.1f,0.1f,1.0f};//光參數 RGBA
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientParams);            
	
	//散射光設置
	float diffuseParams[]={0.0f,1.0f,0.0f,1.0f};//光參數 RGBA
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseParams); 
	
	//反射光設置
	float specularParams[]={1.0f,1.0f,1.0f,1.0f};//光參數 RGBA
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularParams);
	
}
void GLWidget::initRedLight()
{
	RunTimeLog(0,"initRedLight()");
	glEnable(GL_LIGHT1);//打開1號燈  
	
	//環境光設置
	float ambientParams[]={0.2f,0.2f,0.2f,1.0f};//光參數 RGBA
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambientParams);            
	
	//散射光設置
	float diffuseParams[]={1.0f,0.0f,0.0f,1.0f};//光參數 RGBA
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseParams); 
	
	//反射光設置
	float specularParams[]={1.0f,1.0f,1.0f,1.0f};//光參數 RGBA
	glLightfv(GL_LIGHT1, GL_SPECULAR, specularParams);
}
void GLWidget::initMaterial()
{
	RunTimeLog(4,"initMaterial()");
	//材質為白色時什麼顏色的光照在上面就將體現出什麼顏色
	//環境光為白色材質
	float ambientMaterial[] = {1.0f, 1.0f, 1.0f, 1.0f};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientMaterial);
	//散射光為白色材質
	float diffuseMaterial[] = {1.0f, 1.0f, 1.0f, 1.0f};
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseMaterial);
	//高光材質為白色
	float specularMaterial[] = {1.0f, 1.0f, 1.0f, 1.0f};
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularMaterial);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100.0f);
}
void GLWidget::initTexture()
{
	RunTimeLog(5,"initTexture()");
	QImage Image_tex, Image_buf;
	if(!Image_buf.load("jiaotong.png"))
	{
		QImage Image_dummy( 128, 128, /*32*/QImage::Format_Indexed8);
		Image_dummy.fill( Qt::green );
		Image_buf = Image_dummy;
	}
	Image_tex = QGLWidget::convertToGLFormat( Image_buf );
	
	//gl.glGenTextures(1, textures, 0);
	glGenTextures(1,&texture[0]);
	
	//gl.glBindTexture(GL10.GL_TEXTURE_2D, currTextureId);
	glBindTexture( GL_TEXTURE_2D, texture[0] );

	//gl.glTexParameterf(GL10.GL_TEXTURE_2D,GL10.GL_TEXTURE_MAG_FILTER,GL10.GL_LINEAR);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	//gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MIN_FILTER,GL10.GL_NEAREST);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	//gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_WRAP_S,GL10.GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
	//gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_WRAP_T,GL10.GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
	
	//GLUtils.texImage2D(GL10.GL_TEXTURE_2D, 0, bitmapTmp, 0);
	/*
	void glTexImage2D(	GLenum  	target,
 	GLint  	level,
 	GLint  	internalFormat,//決應圖片顏色
 	GLsizei  	width,
 	GLsizei  	height,
 	GLint  	border,
 	GLenum  	format,
 	GLenum  	type,
 	const GLvoid *  	data);
 	*/
	glTexImage2D( GL_TEXTURE_2D, 0, 3, Image_tex.width(), Image_tex.height(), 0,GL_RGBA, GL_UNSIGNED_BYTE, Image_tex.bits());
}
void GLWidget::DrawTextureTRIANGLES(float scale)
{
	RunTimeLog(6,"DrawTextureTRIANGLES(float scale)");
	int UNIT_SIZE=1;   	
	int vCount=3;//頂點的數量    
	float vertices[]=//頂點座標資料陣列
	{
		(2.0*scale*UNIT_SIZE),0.0,0.0,
		(-2*scale*UNIT_SIZE),0.0,0.0,
		0.0,(4*scale*UNIT_SIZE),0.0
	};	
	float textureCoors[]=//頂點紋理S、T座標值陣列
	{
		0.0,1.0,
		1.0,1.0,
		0.5,0.0
	}; 
	//允許使用頂點陣列
	//gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	//為畫筆指定頂點座標資料
	/*
	gl.glVertexPointer
	(
		3,				//每個頂點的座標數量為3  xyz 
		GL10.GL_FIXED,	//頂點座標值的類型為 GL_FIXED
		0, 				//連續頂點座標資料之間的間隔
		mVertexBuffer	//頂點座標資料
	);
	*/
	glVertexPointer(
				3,			//每個頂點的座標數量為3  xyz 
				GL_FLOAT,	//頂點座標值的類型為 GL_FIXED
				0, 			//連續頂點座標資料之間的間隔
				vertices	//頂點座標資料
	);
	//開啟紋理
	//gl.glEnable(GL10.GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);  
	
	//允許使用紋理陣列
	//gl.glEnableClientState(GL10.GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	//為畫筆指定紋理uv座標資料
	/*
	gl.glTexCoordPointer
	(
		2, 					//每個頂點兩個紋理座標資料 S、T
		GL10.GL_FLOAT, 		//資料類型
		0, 					//連續紋理座標資料之間的間隔
		mTextureBuffer		//紋理座標資料
	);
	*/
	glTexCoordPointer
	(
		2, 				//每個頂點兩個紋理座標資料 S、T
		GL_FLOAT, 		//資料類型
		0, 				//連續紋理座標資料之間的間隔
		textureCoors	//紋理座標資料
	);
	
	//為畫筆綁定指定名稱ID紋理		
	//gl.glBindTexture(GL10.GL_TEXTURE_2D,textureId);   
	glBindTexture( GL_TEXTURE_2D, texture[0] );
	
	//繪製圖形
	/*
	gl.glDrawArrays
	(
		GL10.GL_TRIANGLES, 
		0, 
		vCount
	);
	gl.glDisable(GL10.GL_TEXTURE_2D);//關閉紋理
	*/
	glDrawArrays
	(
		GL_TRIANGLES, 
		0, 
		vCount
	);
	glDisable(GL_TEXTURE_2D);//關閉紋理
}
void GLWidget::initMaterialWhite()
{
	RunTimeLog(7,"initMaterialWhite()");
	//環境光為白色材質
	float ambientMaterial[] = {0.4f, 0.4f, 0.4f, 1.0f};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientMaterial);
	//散射光為白色材質
	float diffuseMaterial[] = {0.8f, 0.8f, 0.8f, 1.0f};
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseMaterial);
	//高光材質為白色
	float specularMaterial[] = {1.0f, 1.0f, 1.0f, 1.0f};
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularMaterial);
	//高光反射區域,數越大高亮區域越小越暗
	float shininessMaterial[] = {0.5f};
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininessMaterial);
}
void GLWidget::initLight0()
{
	RunTimeLog(8,"initLight0()");
	glEnable(GL_LIGHT0);//打開0號燈  
	//環境光設置
	float ambientParams[]={0.1f,0.1f,0.1f,1.0f};//光參數 RGBA
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientParams);            
	//散射光設置
	float diffuseParams[]={0.5f,0.5f,0.5f,1.0f};//光參數 RGBA
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseParams); 
	//反射光設置
	float specularParams[]={1.0f,1.0f,1.0f,1.0f};//光參數 RGBA
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularParams);     	
}
void GLWidget::DrawBall(float scale,int angle_Span)
{
	RunTimeLog(9,"DrawBall(float scale,int angle_Span)");	
	int vCount=0;
	int iCount=0;
	int UNIT_SIZE=1;
	int angleSpan=angle_Span;//將球進行單位切分的角度
	float fltDataBuf;
	QList<float> alVertix;//存放頂點座標的ArrayList
	for(int vAngle=-90;vAngle<=90;vAngle+=angleSpan)
	{//垂直方向angleSpan度一份
		for(int hAngle=0;hAngle<360;hAngle+=angleSpan)//水準方向angleSpan度一份
		{//縱向橫向各到一個角度後計算對應的此點在球面上的座標
			double xozLength=scale*UNIT_SIZE*cos(vAngle*PI/180);
			float x=(xozLength*cos(hAngle*PI/180));
			float z=(xozLength*sin(hAngle*PI/180));
			float y=(scale*UNIT_SIZE*sin(vAngle*PI/180));
			//將計算出來的XYZ座標加入存放頂點座標的ArrayList
			alVertix << x << y << z;

		}
	}
	vCount=alVertix.size()/3;//頂點的數量為座標值數量的1/3，因為一個頂點有3個座標
	//將alVertix中的座標值轉存到一個int陣列中
	float *vertices=new float[vCount*3];//頂點
	float *Normal=new float[vCount*3];//法向量
	for(int i=0;i<alVertix.size();i++)
	{
		fltDataBuf=alVertix[i];
		vertices[i]=fltDataBuf;
		Normal[i]=fltDataBuf;
	}
	/*
		//建立頂點座標資料緩衝
		//vertices.length*4是因為一個整數四個位元組
		ByteBuffer vbb = ByteBuffer.allocateDirect(vertices.length*4);
		vbb.order(ByteOrder.nativeOrder());//設置位元組順序
		mVertexBuffer = vbb.asIntBuffer();//轉換為int型緩衝
		mVertexBuffer.put(vertices);//向緩衝區中放入頂點座標資料
		mVertexBuffer.position(0);//設置緩衝區起始位置    
		//建立頂點法向量資料緩衝
		//vertices.length*4是因為一個float四個位元組
		ByteBuffer nbb = ByteBuffer.allocateDirect(vertices.length*4);
		nbb.order(ByteOrder.nativeOrder());//設置位元組順序
		mNormalBuffer = vbb.asIntBuffer();//轉換為int型緩衝
		mNormalBuffer.put(vertices);//向緩衝區中放入頂點座標資料
		mNormalBuffer.position(0);//設置緩衝區起始位置
		//特別提示：由於不同平臺位元組順序不同資料單元不是位元組的一定要經過ByteBuffer
		//轉換，關鍵是要通過ByteOrder設置nativeOrder()，否則有可能會出問題 
	*/
	//三角形建構索引資料初始化==========begin==========================
	QList<int> alIndex;
	int row=(180/angleSpan)+1;//球面切分的行數
	int col=360/angleSpan;//球面切分的列數
	for(int i=0;i<row;i++)
	{//對每一行迴圈
		if(i>0&&i<row-1)
		{//中間行
			for(int j=-1;j<col;j++)
			{//中間行的兩個相鄰點與下一行的對應點構成三角形
				int k=i*col+j;
				alIndex << (k+col);
				alIndex << (k+1);
				alIndex << (k);		
			}
			for(int j=0;j<col+1;j++)
			{//中間行的兩個相鄰點與上一行的對應點構成三角形				
				int k=i*col+j;
				alIndex << (k-col);
				alIndex << (k-1);
				alIndex << (k);	
			}
		}
	}
	iCount=alIndex.size();
	unsigned int *indices=new unsigned int[alIndex.size()];
	for(int i=0;i<alIndex.size();i++)
	{
		indices[i]=alIndex[i];
	} 
	/*
		//建立三角形構造索引資料緩衝
		mIndexBuffer = ByteBuffer.allocateDirect(indices.length);
		mIndexBuffer.put(indices);//向緩衝區中放入三角形構造索引資料
		mIndexBuffer.position(0);//設置緩衝區起始位置
		//三角形構造索引資料初始化==========end==============================
	*/
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glVertexPointer(
				3,			//每個頂點的座標數量為3  xyz 
				GL_FLOAT,	//頂點座標值的類型為 GL_FIXED
				0, 			//連續頂點座標資料之間的間隔
				vertices	//頂點座標資料
	);
	//為畫筆指定頂點法向量數據

	
	glNormalPointer(GL_FLOAT, 0, Normal);
	//*
	//繪製圖形
	//線段連接的空心圓
	glDrawElements(
			GL_LINE_STRIP, 		//以三角形方式填充
			iCount, 			//一共icount/3個三角形，iCount個頂點
			GL_UNSIGNED_INT, 	//索引值的尺寸
			indices				//索引值資料
	);	
	//*/
	
	/*
	//繪製圖形
	//三角形的實心圓
	glDrawElements(
			GL_TRIANGLES, 		//以三角形方式填充
			iCount, 			//一共icount/3個三角形，iCount個頂點
			GL_UNSIGNED_INT, 	//索引值的尺寸
			indices				//索引值資料
	);	
	//*/
	//*/	
	//////////////////////////////////////////////////////
	delete [] vertices;
	delete [] Normal;
	delete [] indices;
}
void GLWidget::paintGL()
{
	RunTimeLog(10,"paintGL()");
	//清除顏色緩存
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//設置當前矩陣為模式矩陣
	glMatrixMode(GL_MODELVIEW);
	//設置當前矩陣為單位矩陣
	glLoadIdentity(); 
	
	glEnable(GL_LIGHT0);//打開0號燈 
	glEnable(GL_LIGHT1);//打開1號燈 
	//設定綠色光源的位置
	float lxGreen=7.0*cos(lightAngleGreen*PI/180);
	float lzGreen=7.0*sin(lightAngleGreen*PI/180);
	float positionParamsGreen[] ={lxGreen,0,lzGreen,1};//最後的1表示使用定位光
	//設定紅色光源的位置
	float lyRed=7.0*cos(lightAngleRed*PI/180);
	float lzRed=7.0*sin(lightAngleRed*PI/180);
	float positionParamsRed[]={0,lyRed,lzRed,1};//最後的1表示使用定位光
	glLightfv(GL_LIGHT0,GL_POSITION, positionParamsGreen);
	glLightfv(GL_LIGHT1, GL_POSITION, positionParamsRed);
	
	glPushMatrix();//保護變換矩陣現場
	
	glTranslatef(  0.0,  0.0, zoom ); 
	glRotatef( xRot,  1.0,  0.0,  0.0 );
	glRotatef( yRot,  0.0,  1.0,  0.0 ); 
	//DrawTextureBall(1000.0f,18.0f);
	//DrawCylinder(1000.0,500.0,18.0);
	DrawTaper(2000.0,1000.0,18,10);
	
	glPopMatrix();//恢復變換矩陣現場
}
void GLWidget::resizeGL(int w, int h)
{
	RunTimeLog(11,"resizeGL(int w, int h)");
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
void GLWidget::DrawTextureBall(float scale,int angle_Span)
{
	RunTimeLog(12,"DrawTextureBall(float scale,int angle_Span)");
	int vCount=0;
	int UNIT_SIZE=1;
	int angleSpan=angle_Span;//將球進行單位切分的角度
	float fltDataBuf;
	QList<float> alVertix;//存放頂點座標的ArrayList
	for(int vAngle=-90;vAngle<=90;vAngle+=angleSpan)
	{//垂直方向angleSpan度一份
		for(int hAngle=0;hAngle<360;hAngle+=angleSpan)//水準方向angleSpan度一份
		{//縱向橫向各到一個角度後計算對應的此點在球面上的座標
			double xozLength=scale*UNIT_SIZE*cos(vAngle*PI/180);
			float x=(xozLength*cos(hAngle*PI/180));
			float z=(xozLength*sin(hAngle*PI/180));
			float y=(scale*UNIT_SIZE*sin(vAngle*PI/180));
			//將計算出來的XYZ座標加入存放頂點座標的ArrayList
			alVertix << x << y << z;

		}
	}
	vCount=alVertix.size()/3;//頂點的數量為座標值數量的1/3，因為一個頂點有3個座標
	//將alVertix中的座標值轉存到一個int陣列中
	float *vertices=new float[vCount*3];//頂點
	//float *Normal=new float[vCount*3];//法向量
	for(int i=0;i<alVertix.size();i++)
	{
		fltDataBuf=alVertix[i];
		vertices[i]=fltDataBuf;
		//Normal[i]=fltDataBuf;
	}	
	alVertix.clear();
	QList<float> alTexture;//紋理
	int row=(180/angleSpan)+1;//球面切分的行數
	int col=360/angleSpan;//球面切分的列數
	for(int i=0;i<row;i++)//對每一行迴圈
	{
		if(i>0&&i<row-1)
		{//中間行
			for(int j=-1;j<col;j++)
				{//中間行的兩個相鄰點與下一行的對應點構成三角形
					int k=i*col+j;
					//第1個三角形頂點					
					alVertix<<(vertices[(k+col)*3]);
					alVertix<<(vertices[(k+col)*3+1]);
					alVertix<<(vertices[(k+col)*3+2]);					
					alTexture<<(0.0f);
					alTexture<<(0.0f);
					
					//第2個三角形頂點		
					alVertix<<(vertices[(k+1)*3]);
					alVertix<<(vertices[(k+1)*3+1]);
					alVertix<<(vertices[(k+1)*3+2]);					
					alTexture<<(1.0f);
					alTexture<<(1.0f);
					
					//第3個三角形頂點
					alVertix<<(vertices[k*3]);
					alVertix<<(vertices[k*3+1]);
					alVertix<<(vertices[k*3+2]);	
					alTexture<<(1.0f);
					alTexture<<(0.0f);
				}
				for(int j=0;j<col+1;j++)
				{//中間行的兩個相鄰點與上一行的對應點構成三角形				
					int k=i*col+j;
					
					//第1個三角形頂點					
					alVertix<<(vertices[(k-col)*3]);
					alVertix<<(vertices[(k-col)*3+1]);
					alVertix<<(vertices[(k-col)*3+2]);					
					alTexture<<(1.0f);
					alTexture<<(1.0f);
					
					//第2個三角形頂點					
					alVertix<<(vertices[(k-1)*3]);
					alVertix<<(vertices[(k-1)*3+1]);
					alVertix<<(vertices[(k-1)*3+2]);					
					alTexture<<(0.0f);
					alTexture<<(0.0f);
					
					//第3個三角形頂點					
					alVertix<<(vertices[k*3]);
					alVertix<<(vertices[k*3+1]);
					alVertix<<(vertices[k*3+2]);					
					alTexture<<(0.0f);
					alTexture<<(1.0f);    
				}
			}
		}
	
	delete [] vertices;
	vCount=alVertix.size()/3;//頂點的數量為座標值數量的1/3，因為一個頂點有3個座標
	vertices=new float[vCount*3];
	float *Normal=new float[vCount*3];//法向量
	for(int i=0;i<alVertix.size();i++)
	{
		fltDataBuf=alVertix[i];
		vertices[i]=fltDataBuf;
		Normal[i]=fltDataBuf;
	}	
	//建立紋理座標緩衝
	float *textureCoors=new float[alTexture.size()];//頂點紋理值陣列
	for(int i=0;i<alTexture.size();i++) 
	{
		textureCoors[i]=alTexture[i];
	}
	glEnable(GL_LIGHT0);//打開0號燈 
	glEnable(GL_LIGHT1);//打開1號燈 
	//允許使用頂點陣列
	glEnableClientState(GL_VERTEX_ARRAY);
	//為畫筆指定頂點座標資料
	glVertexPointer
	(
			3,				//每個頂點的座標數量為3  xyz 
			GL_FLOAT,	//頂點座標值的類型為 GL_FIXED
			0, 				//連續頂點座標資料之間的間隔
			vertices	//頂點座標資料
	);

	//允許使用法向量陣列
	glEnableClientState(GL_NORMAL_ARRAY);
	//為畫筆指定頂點法向量數據
	glNormalPointer(GL_FLOAT, 0, Normal);	

	//開啟紋理
	glEnable(GL_TEXTURE_2D);   
	//允許使用紋理ST座標緩衝
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	//為畫筆指定紋理ST座標緩衝
	glTexCoordPointer(2, GL_FLOAT, 0, textureCoors);
	//設定當前紋理
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	//繪製圖形
	glDrawArrays
	(
			GL_TRIANGLES, 		//以三角形方式填充
			0, 			 		//開始點編號
			vCount				//頂點數量
	); 
	glEnable(GL_LIGHT0);//打開0號燈 
	glEnable(GL_LIGHT1);//打開1號燈 
////////////////////////////////////////////////////////////
	delete [] vertices;
	delete [] Normal;
	delete [] textureCoors;
}
void GLWidget::DrawCylinder(float length1,float circle_radius1,float degreespan1)//畫紋理圓柱
{
	float fltlength;
	float fltcircle_radius;
	float fltdegreespan;

	
	fltlength=length1;
	fltcircle_radius=circle_radius1;
	fltdegreespan=degreespan1;

	float fltcollength=(float)(fltlength/fltdegreespan);
	int intspannum=(int)(360.0f/fltdegreespan);
	
	QList<float> listval;//存放頂點座標 ArrayList //ArrayList<Float> val=new ArrayList<Float>();
	QList<float> listial;//法向量存放列表 ArrayList<Float> ial=new ArrayList<Float>();
	listval.clear();
	listial.clear();
	
	for(float fltcircle_degree=360.0f;fltcircle_degree>0.0f;fltcircle_degree-=fltdegreespan)//迴圈行
	{
			float x1 =(float)(-fltlength/2);
			float y1=(float) (fltcircle_radius*sin(fltcircle_degree*PI/180));
			float z1=(float) (fltcircle_radius*cos(fltcircle_degree*PI/180));
			
			float a1=0;
			float b1=y1;
			float c1=z1;
			float l1=getVectorLength(a1, b1, c1);//模長
			a1=a1/l1;//法向量規格化
			b1=b1/l1;
			c1=c1/l1;
			
			float x2 =(float)(-fltlength/2);
			float y2=(float) (fltcircle_radius*sin((fltcircle_degree-fltdegreespan)*PI/180));
			float z2=(float) (fltcircle_radius*cos((fltcircle_degree-fltdegreespan)*PI/180));
			
			float a2=0;
			float b2=y2;
			float c2=z2;
			float l2=getVectorLength(a2, b2, c2);//模長
			a2=a2/l2;//法向量規格化
			b2=b2/l2;
			c2=c2/l2;
			
			float x3 =(float)(fltlength/2);
			float y3=(float) (fltcircle_radius*sin((fltcircle_degree-fltdegreespan)*PI/180));
			float z3=(float) (fltcircle_radius*cos((fltcircle_degree-fltdegreespan)*PI/180));
			
			float a3=0;
			float b3=y3;
			float c3=z3;
			float l3=getVectorLength(a3, b3, c3);//模長
			a3=a3/l3;//法向量規格化
			b3=b3/l3;
			c3=c3/l3;
			
			float x4 =(float)(fltlength/2);
			float y4=(float) (fltcircle_radius*sin((fltcircle_degree*PI/180)));
			float z4=(float) (fltcircle_radius*cos((fltcircle_degree*PI/180)));
			
			float a4=0;
			float b4=y4;
			float c4=z4;
			float l4=getVectorLength(a4, b4, c4);//模長
			a4=a4/l4;//法向量規格化
			b4=b4/l4;
			c4=c4/l4;
			
			listval <<x1<<y1<<z1;//val.add(x1);val.add(y1);val.add(z1);//兩個三角形，共6個頂點的座標
			listval <<x2<<y2<<z2;//val.add(x2);val.add(y2);val.add(z2);
			listval <<x4<<y4<<z4;//val.add(x4);val.add(y4);val.add(z4);
			
			listval <<x2<<y2<<z2;//val.add(x2);val.add(y2);val.add(z2);
			listval <<x3<<y3<<z3;//val.add(x3);val.add(y3);val.add(z3);
			listval <<x4<<y4<<z4;//val.add(x4);val.add(y4);val.add(z4);
			
			listial <<a1<<b1<<c1;//ial.add(a1);ial.add(b1);ial.add(c1);//頂點對應的法向量
			listial <<a2<<b2<<c2;//ial.add(a2);ial.add(b2);ial.add(c2);
			listial <<a4<<b4<<c4;//ial.add(a4);ial.add(b4);ial.add(c4);
			
			listial <<a2<<b2<<c2;//ial.add(a2);ial.add(b2);ial.add(c2);
			listial <<a3<<b3<<c3;//ial.add(a3);ial.add(b3);ial.add(c3);
			listial <<a4<<b4<<c4;//ial.add(a4);ial.add(b4);ial.add(c4);
	}
	int vCount=0;
	vCount=listval.size()/3;//確定頂點數量
	float *vertexs=new float[vCount*3];//頂點
	//頂點
	for(int i=0;i<vCount*3;i++)
	{
		vertexs[i]=listval[i];
	}
	//法向量
	float *normals=new float[vCount*3];
	for(int i=0;i<vCount*3;i++)
	{
		normals[i]=listial[i];
	}
	////自動切分紋理產生紋理陣列的方法
	float *textures=new float[intspannum*6*2]; 	
	float REPEAT=2;
	float sizeh=1.0f/intspannum;//行數
	int c=0;
	for(int i=0;i<intspannum;i++)
	{
		//每行列一個矩形，由兩個三角形構成，共六個點，12個紋理座標
		float t=i*sizeh;

		textures[c++]=0;
		textures[c++]=t;
		textures[c++]=0;
		textures[c++]=t+sizeh; 
	
		textures[c++]=REPEAT;
		textures[c++]=t;
	
		textures[c++]=0;
		textures[c++]=t+sizeh;
		
		textures[c++]=REPEAT;
		textures[c++]=t+sizeh;   
			
		textures[c++]=REPEAT;
		textures[c++]=t;
	}
	////
	glEnable(GL_LIGHT0);//打開0號燈 
	glEnable(GL_LIGHT1);//打開1號燈 
	//允許使用頂點陣列
	glEnableClientState(GL_VERTEX_ARRAY);
	//為畫筆指定頂點座標資料
	glVertexPointer
	(
			3,				//每個頂點的座標數量為3  xyz 
			GL_FLOAT,	//頂點座標值的類型為 GL_FIXED
			0, 				//連續頂點座標資料之間的間隔
			vertexs	//頂點座標資料
	);

	//允許使用法向量陣列
	glEnableClientState(GL_NORMAL_ARRAY);
	//為畫筆指定頂點法向量數據
	glNormalPointer(GL_FLOAT, 0, normals);	

	//開啟紋理
	glEnable(GL_TEXTURE_2D);   
	//允許使用紋理ST座標緩衝
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	//為畫筆指定紋理ST座標緩衝
	glTexCoordPointer(2, GL_FLOAT, 0, textures);
	//設定當前紋理
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	//繪製圖形
	glDrawArrays
	(
			GL_TRIANGLES, 		//以三角形方式填充
			0, 			 		//開始點編號
			vCount				//頂點數量
	); 
	glEnable(GL_LIGHT0);//打開0號燈 
	glEnable(GL_LIGHT1);//打開1號燈 
////////////////////////////////////////////////////////////
	delete []vertexs;
	delete []normals;
	delete []textures;
}

float GLWidget::getVectorLength(float x,float y,float z)//法向量規格化，求模長度
{
	float pingfang=x*x+y*y+z*z;
	float length=(float)sqrt(pingfang);
	return length;
}
void GLWidget::RunTimeLog(int intStep,char *chrNote)
{
	FILE *pflog;
	pflog=fopen("RunTimeLog.txt","a");
	fprintf(pflog,"%d\t%s\n",intStep,chrNote);
	fclose(pflog);
}
void GLWidget::DrawTaper(float height1,float circle_radius1,float degreespan1,int col1)//畫紋理三角錐
{
	int intvCount;//頂點數量
	
	float fltheight;//圓柱長度
	float fltcircle_radius;//圓錐底面半徑
	float fltdegreespan;  //圓截環每一份的度數大小
	int intcol;//圓錐平均切分的塊數
	fltheight=height1;
	fltcircle_radius=circle_radius1;
	fltdegreespan=degreespan1;	//表示多少度切割一份
	intcol=col1;				//表示height分幾份切割
	float fltspanHeight=(float)(fltheight/intcol);//圓錐每塊所占的高度
	int intspannum=(int)(360.0f/fltdegreespan);
	float fltspanR=(float)(fltcircle_radius/intcol);//半徑單位長度
	float fltnormalHeight=(fltheight*fltcircle_radius*fltcircle_radius)/(fltheight*fltheight+fltcircle_radius*fltcircle_radius);//法向量點所在圓截面的高度
	float fltnormalR=(fltheight*fltheight*fltcircle_radius)/(fltheight*fltheight+fltcircle_radius*fltcircle_radius);//法向量點所在圓截面的半徑
	QList<float> listval;//存放頂點座標 ArrayList //ArrayList<Float> val=new ArrayList<Float>();
	QList<float> listial;//法向量存放列表 ArrayList<Float> ial=new ArrayList<Float>();
	listval.clear();
	listial.clear();
	for(float fltcircle_degree=360.0f;fltcircle_degree>0.0f;fltcircle_degree-=fltdegreespan)//迴圈行
	{
		for(int j=0;j<intcol;j++)//迴圈列
		{
			float fltcurrentR=j*fltspanR;//當前截面的圓半徑
			float fltcurrentHeight=fltheight-j*fltspanHeight;//當前截面的高度
			
			float x1=(float) (fltcurrentR*cos((fltcircle_degree*PI/180)));
			float y1=fltcurrentHeight;
			float z1=(float) (fltcurrentR*sin((fltcircle_degree*PI/180)));
			
			float a1=(float) (fltnormalR*cos((fltcircle_degree*PI/180)));
			float b1=fltnormalHeight;
			float c1=(float) (fltnormalR*sin((fltcircle_degree*PI/180)));
			float l1=getVectorLength(a1, b1, c1);//模長
			a1=a1/l1;//法向量規格化
			b1=b1/l1;
			c1=c1/l1;
			
			float x2=(float) ((fltcurrentR+fltspanR)*cos((fltcircle_degree*PI/180)));
			float y2=fltcurrentHeight-fltspanHeight;
			float z2=(float) ((fltcurrentR+fltspanR)*sin((fltcircle_degree*PI/180)));
			
			float a2=(float) (fltnormalR*cos((fltcircle_degree*PI/180)));
			float b2=fltnormalHeight;
			float c2=(float) (fltnormalR*sin((fltcircle_degree*PI/180)));
			float l2=getVectorLength(a2, b2, c2);//模長
			a2=a2/l2;//法向量規格化
			b2=b2/l2;
			c2=c2/l2;
			
			float x3=(float) ((fltcurrentR+fltspanR)*cos((fltcircle_degree-fltdegreespan)*PI/180));
			float y3=fltcurrentHeight-fltspanHeight;
			float z3=(float) ((fltcurrentR+fltspanR)*sin((fltcircle_degree-fltdegreespan)*PI/180));
			
			float a3=(float) (fltnormalR*cos((fltcircle_degree-fltdegreespan)*PI/180));
			float b3=fltnormalHeight;
			float c3=(float) (fltnormalR*sin((fltcircle_degree-fltdegreespan)*PI/180));
			float l3=getVectorLength(a3, b3, c3);//模長
			a3=a3/l3;//法向量規格化
			b3=b3/l3;
			c3=c3/l3;
			
			float x4=(float) ((fltcurrentR)*cos((fltcircle_degree-fltdegreespan)*PI/180));
			float y4=fltcurrentHeight;
			float z4=(float) ((fltcurrentR)*sin((fltcircle_degree-fltdegreespan)*PI/180));
			
			float a4=(float) ((fltnormalR)*cos((fltcircle_degree-fltdegreespan)*PI/180));
			float b4=fltnormalHeight;
			float c4=(float) ((fltnormalR)*sin((fltcircle_degree-fltdegreespan)*PI/180));
			float l4=getVectorLength(a4, b4, c4);//模長
			a4=a4/l4;//法向量規格化
			b4=b4/l4;
			c4=c4/l4;
			
			listval<< x1 << y1 << z1;//兩個三角形，共6個頂點的座標
			listval<< x2 << y2 << z2;
			listval<< x4 << y4 << z4;
			
			listval<< x2 << y2 << z2;
			listval<< x3 << y3 << z3;
			listval<< x4 << y4 << z4;
			
			listial<< a1 << b1 << c1;//頂點對應的法向量
			listial<< a2 << b2 << c2;
			listial<< a4 << b4 << c4;
			
			listial<< a2 << b2 << c2;
			listial<< a3 << b3 << c3;
			listial<< a4 << b4 << c4;
		}
	}	
	intvCount=listval.size()/3;//確定頂點數量	
	//頂點
	float *fltvertexs=new float[intvCount*3];
	for(int i=0;i<intvCount*3;i++)
	{
		fltvertexs[i]=listval[i];
	}
	//法向量
	float *fltnormals=new float[intvCount*3];
	for(int i=0;i<intvCount*3;i++)
	{
		fltnormals[i]=listial[i];
	}
	////自動切分紋理產生紋理陣列的方法
	int bw;
	int bh;
	bw=intspannum;
	bh=intcol;
	float *textures=new float[bw*bh*6*2]; 	
	float sizew=1.0f/bw;//列單位長度
	float sizeh=1.0f/bh;//行單位長度
	int c=0;
	for(int j=0;j<bw;j++)
	{
		for(int i=0;i<bh;i++)
		{
				//每行列一個矩形，由兩個三角形構成，共六個點，12個紋理座標
			float s=j*sizew;
			float t=i*sizeh;
			
			textures[c++]=s;
			textures[c++]=t;		 
			textures[c++]=s;
			textures[c++]=t+sizeh;
    			
    		textures[c++]=s+sizew;
    		textures[c++]=t; 
    		   			
    		textures[c++]=s;
    		textures[c++]=t+sizeh;
    		
    		textures[c++]=s+sizew;
    		textures[c++]=t+sizeh;   
    		
    		textures[c++]=s+sizew;
    		textures[c++]=t;
    	}
    }
	////
	glEnable(GL_LIGHT0);//打開0號燈 
	glEnable(GL_LIGHT1);//打開1號燈 
	//允許使用頂點陣列
	glEnableClientState(GL_VERTEX_ARRAY);
	//為畫筆指定頂點座標資料
	glVertexPointer
	(
			3,				//每個頂點的座標數量為3  xyz 
			GL_FLOAT,	//頂點座標值的類型為 GL_FIXED
			0, 				//連續頂點座標資料之間的間隔
			fltvertexs	//頂點座標資料
	);

	//允許使用法向量陣列
	glEnableClientState(GL_NORMAL_ARRAY);
	//為畫筆指定頂點法向量數據
	glNormalPointer(GL_FLOAT, 0, fltnormals);	

	//開啟紋理
	glEnable(GL_TEXTURE_2D);   
	//允許使用紋理ST座標緩衝
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	//為畫筆指定紋理ST座標緩衝
	glTexCoordPointer(2, GL_FLOAT, 0, textures);
	//設定當前紋理
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	//繪製圖形
	glDrawArrays
	(
			GL_TRIANGLES, 		//以三角形方式填充
			0, 			 		//開始點編號
			intvCount				//頂點數量
	); 
	glEnable(GL_LIGHT0);//打開0號燈 
	glEnable(GL_LIGHT1);//打開1號燈 
////////////////////////////////////////////////////////////
	delete [] fltvertexs;
	delete [] fltnormals;
	delete [] textures;
}