/*
JAVA_OPENGL,Qt_OPENGL
private IntBuffer myVertexBuffer;//頂點座標資料緩衝,X
private IntBuffer myColorBuffer;//頂點著色資料緩衝,X
private ByteBuffer myIndexBuffer;//頂點建立的索引資料緩衝,X
int vCount=0;//頂點數量,X
int iCount=0;//索引數量,X
vCount=3;//一個三角形，3個頂點,X
final int UNIT_SIZE=10000;//縮放比例,GLfloat nRange = 2000.0f;//
int []vertices=new int[]{-8*UNIT_SIZE,6*UNIT_SIZE,0, -8*UNIT_SIZE,-6*UNIT_SIZE,0,8*UNIT_SIZE,-6*UNIT_SIZE,0};,float verts[] = {0,0,0, 1000,0,0, 1000,1000,0, 0,1000,0};
//建立頂點座標資料緩存，由於不同平臺位元組順序不同，資料單元不是位元組的（上面的事整型的緩存），一定要經過ByteBuffer轉換，關鍵是通過ByteOrder設置nativeOrder(),X
ByteBuffer vbb=ByteBuffer.allocateDirect(vertices.length*4);//一個整數四個位元組，根據最新分配的區塊來建立一個有向的位元組緩衝,X
vbb.order(ByteOrder.nativeOrder());//設置這個位元組緩衝的位元組順序為本地平臺的位元組順序,X
myVertexBuffer=vbb.asIntBuffer();//轉換為int型緩衝,X
myVertexBuffer.put(vertices);//向緩衝區中放入頂點座標資料,X
myVertexBuffer.position(0);//設置緩衝區的起始位置,X
final int one=65535;//支持65535色色彩通道,X
int []colors=new int[]{one,one,one,0, one,one,one,0, one,one,one,0};,float color[] = {1,0,0, 0,1,0, 0,1,0, 1,1,1}; 
ByteBuffer cbb=ByteBuffer.allocateDirect(colors.length*4);,X
cbb.order(ByteOrder.nativeOrder());,X
myColorBuffer=cbb.asIntBuffer();,X
myColorBuffer.put(colors);,X
myColorBuffer.position(0);,X
iCount=3;,X
byte []indices=new byte[]{0,1,2};,unsigned int ind[] = {0,1,2,3};
myIndexBuffer=ByteBuffer.allocateDirect(indices.length);,X
myIndexBuffer.put(indices);,X
myIndexBuffer.position(0);,X
gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);//啟用頂點座標陣列,glEnableClientState(GL_VERTEX_ARRAY);
gl.glEnableClientState(GL10.GL_COLOR_ARRAY);//啟用頂點顏色陣列,glEnableClientState(GL_COLOR_ARRAY); 
gl.glVertexPointer//為畫筆指定頂點座標資料,glVertexPointer(3, GL_FLOAT, 0, verts);
(
		3,					//每個頂點的座標數量為3
		GL10.GL_FIXED,		//頂點座標值的類型為GL_FIXED,整型
		0,					//連續頂點座標資料之間的間隔
		myVertexBuffer		//頂點座標數量
);
gl.glColorPointer//為畫筆指定頂點 顏色資料,glColorPointer(3, GL_FLOAT, 0, color);
(
	4,
	GL10.GL_FIXED,
	0,
	myColorBuffer
);
gl.glDrawElements//繪製圖形,glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, ind);  
(
	GL10.GL_TRIANGLES,		//填充模式，這裡是以三角形方式填充
	iCount,					//頂點數量
	GL10.GL_UNSIGNED_BYTE,	//索引值的類型
	myIndexBuffer			//索引值資料
);
*/