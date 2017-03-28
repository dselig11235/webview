#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QWebView>

/*
   XXX Add cookies
   http://stackoverflow.com/questions/3382640/how-can-i-load-session-information-into-qtwebkit
   http://stackoverflow.com/questions/5406436/qt-webkit-and-permanent-cookies
*/
class WebView : public QWebView
{
    Q_OBJECT

    public:
        WebView(QWidget *parent = 0);
    private slots:
        void handleSslErrors(QNetworkReply* reply, const QList<QSslError> &errors);
        void handleLoadFinished(bool);
};

#endif // WEBVIEW_H
