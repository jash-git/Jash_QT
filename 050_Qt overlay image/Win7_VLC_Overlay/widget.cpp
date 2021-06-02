#include "widget.h"
#include "ui_widget.h"
const int px_text = 640;
const int py_text = 20;
int gint_x;
bool gblnre;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer01=new QTimer(this);
    connect(timer01,SIGNAL(timeout()),this,SLOT(slotTimer()));
    timer01->start(30);
    m_StrText="中文中文中文中文中文";
    gint_x=640;
    gblnre=false;
}

Widget::~Widget()
{
    delete ui;
}
void Widget::slotTimer()
{
    Pixmap_saveimage= QPixmap::grabWindow(QApplication::desktop()->winId());
    Image_Desktop=Pixmap_saveimage.toImage();

    QSize resultSize(640, 480);
    Image_Source = QImage(resultSize, QImage::Format_ARGB32_Premultiplied);
    Image_Source=Image_Desktop.copy(0,0,resultSize.width(),resultSize.height());

    Image_Show = QImage(resultSize, QImage::Format_ARGB32_Premultiplied);
    QPainter::CompositionMode mode = QPainter::CompositionMode_Overlay;
    QPainter painter(&Image_Show);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(Image_Show.rect(), Qt::transparent);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);

    if(gint_x>-250)//一個中文字在18字 25
    {
        gint_x--;
    }
    else
    {
        gint_x=640;
    }
    QFont font( "標楷體", 18, QFont::Bold );
    painter.setFont(font);
    //painter.setPen(QPen(Qt::white, 20));
    painter.drawText(gint_x, py_text, m_StrText);
    painter.setCompositionMode(mode);
    painter.drawImage(0, 0, Image_Source);
    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
    //painter.fillRect(Image_Show.rect(), Qt::white);
    painter.end();

    ui->resultLabel->setPixmap(QPixmap::fromImage(Image_Show));
}
