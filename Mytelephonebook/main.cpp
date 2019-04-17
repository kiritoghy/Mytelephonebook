#include "Login.h"
#include "contactdb.h"
#include <QTextCodec> 
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
  QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    QApplication a(argc, argv);
    if (ConnectDB()) {
      Login w;
      w.show();
      return a.exec();
    }
}
