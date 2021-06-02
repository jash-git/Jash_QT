#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QTimer>
#include <QImage>
#include <QPainter>
#include <QDesktopWidget>//®à­±Â^¨ú
#include <QString>
#include <QFont>
#include <QColor>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private slots:
    void slotTimer();
private:
    Ui::Widget *ui;
    QString m_StrText;
    QPixmap Pixmap_saveimage;
    QTimer *timer01;
    QImage Image_Desktop,Image_Source,Image_Show;
};

#endif // WIDGET_H
