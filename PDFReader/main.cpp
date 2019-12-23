#include "pdfreaderwindow.h"
#include "QFontIcon/qfonticon.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFontIcon::addFont("://res/iconfont.ttf");
    PDFReaderWindow w;
    w.show();
    return a.exec();
}
