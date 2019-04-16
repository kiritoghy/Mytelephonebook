#include "Login.h"
#include "contactdb.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (ConnectDB()) {
      Login w;
      w.show();
      return a.exec();
    }
}
