/*
JAVA_OPENGL,Qt_OPENGL
private IntBuffer myVertexBuffer;//���I�y�и�ƽw��,X
private IntBuffer myColorBuffer;//���I�ۦ��ƽw��,X
private ByteBuffer myIndexBuffer;//���I�إߪ����޸�ƽw��,X
int vCount=0;//���I�ƶq,X
int iCount=0;//���޼ƶq,X
vCount=3;//�@�ӤT���ΡA3�ӳ��I,X
final int UNIT_SIZE=10000;//�Y����,GLfloat nRange = 2000.0f;//
int []vertices=new int[]{-8*UNIT_SIZE,6*UNIT_SIZE,0, -8*UNIT_SIZE,-6*UNIT_SIZE,0,8*UNIT_SIZE,-6*UNIT_SIZE,0};,float verts[] = {0,0,0, 1000,0,0, 1000,1000,0, 0,1000,0};
//�إ߳��I�y�и�ƽw�s�A�ѩ󤣦P���O�줸�ն��Ǥ��P�A��Ƴ椸���O�줸�ժ��]�W�����ƾ㫬���w�s�^�A�@�w�n�g�LByteBuffer�ഫ�A����O�q�LByteOrder�]�mnativeOrder(),X
ByteBuffer vbb=ByteBuffer.allocateDirect(vertices.length*4);//�@�Ӿ�ƥ|�Ӧ줸�աA�ھڳ̷s���t���϶��ӫإߤ@�Ӧ��V���줸�սw��,X
vbb.order(ByteOrder.nativeOrder());//�]�m�o�Ӧ줸�սw�Ī��줸�ն��Ǭ����a���O���줸�ն���,X
myVertexBuffer=vbb.asIntBuffer();//�ഫ��int���w��,X
myVertexBuffer.put(vertices);//�V�w�İϤ���J���I�y�и��,X
myVertexBuffer.position(0);//�]�m�w�İϪ��_�l��m,X
final int one=65535;//���65535���m�q�D,X
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
gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);//�ҥγ��I�y�а}�C,glEnableClientState(GL_VERTEX_ARRAY);
gl.glEnableClientState(GL10.GL_COLOR_ARRAY);//�ҥγ��I�C��}�C,glEnableClientState(GL_COLOR_ARRAY); 
gl.glVertexPointer//���e�����w���I�y�и��,glVertexPointer(3, GL_FLOAT, 0, verts);
(
		3,					//�C�ӳ��I���y�мƶq��3
		GL10.GL_FIXED,		//���I�y�ЭȪ�������GL_FIXED,�㫬
		0,					//�s���I�y�и�Ƥ��������j
		myVertexBuffer		//���I�y�мƶq
);
gl.glColorPointer//���e�����w���I �C����,glColorPointer(3, GL_FLOAT, 0, color);
(
	4,
	GL10.GL_FIXED,
	0,
	myColorBuffer
);
gl.glDrawElements//ø�s�ϧ�,glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, ind);  
(
	GL10.GL_TRIANGLES,		//��R�Ҧ��A�o�̬O�H�T���Τ覡��R
	iCount,					//���I�ƶq
	GL10.GL_UNSIGNED_BYTE,	//���ޭȪ�����
	myIndexBuffer			//���ޭȸ��
);
*/