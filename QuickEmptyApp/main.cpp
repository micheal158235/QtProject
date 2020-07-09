#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "clanguuage.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<CLanguuage>("Test.Com", 1, 0, "ZH"); //将C++类CLanguuage注册到QML
    CLanguuage lang(&engine);
    lang.requestChangedLanguage(CLanguuage::LANGUAGE_CH );

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;



    return app.exec();
}
