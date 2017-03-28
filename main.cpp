#include <QtGui>
#include <stdlib.h>
#include "webview.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    WebView view;
    view.show();
    view.setUrl(QUrl(argv[1]));
    view.resize(1024, 768);
    return app.exec();
}

