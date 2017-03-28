#include "webview.h"
#include <QNetworkReply>
#include <QtDebug>
#include <QSslError>
#include <stdlib.h>

WebView::WebView(QWidget *parent) :
    QWebView(parent)
{
    load(QUrl("https://gmail.com"));

    connect(this, SIGNAL(loadFinished(bool)),
            this, SLOT(handleLoadFinished(bool)));
    connect(page()->networkAccessManager(),
            SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError> & )),
            this,
            SLOT(handleSslErrors(QNetworkReply*, const QList<QSslError> & )));  
}

void WebView::handleLoadFinished(bool ok) {
    printf("LOADED\n");
}

void WebView::handleSslErrors(QNetworkReply* reply, const QList<QSslError> &errors)
{
    qDebug() << "handleSslErrors: ";
    foreach (QSslError e, errors)
    {
        qDebug() << "ssl error: " << e;
    }

    reply->ignoreSslErrors();
}
