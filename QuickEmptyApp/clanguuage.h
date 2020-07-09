#ifndef CLANGUUAGE_H
#define CLANGUUAGE_H

#include <QObject>
#include <QTranslator>
#include <QtQml>
#include <QQmlEngine>
#include <QDebug>
#include <QCoreApplication>
#include <QQmlApplicationEngine>
#include <QString>

class CLanguuage : public QObject
{
    Q_OBJECT
public:
    typedef enum
    {
        LANGUAGE_CH,
        LANGUAGE_EN,
        LANHUAGE_NUM,
    }LANGUAGE_TYPE;
    Q_ENUMS(LANGUAGE_TYPE) //注册枚举到QML

    explicit CLanguuage(QObject *parent = 0);
    explicit CLanguuage(QQmlEngine* engine, QObject *parent = 0);
    ~CLanguuage();

    Q_PROPERTY(QString strTag READ getStrTag  NOTIFY strTagChanged) //注册有个属性到QML,Q_PROPERTY有多个参数，我们只说我们常用参数
    Q_INVOKABLE void requestChangedLanguage(LANGUAGE_TYPE type);    //注册一个方法到QMl

    QString getStrTag(void);
signals:
    void strTagChanged(void);
public slots:

private:
    QQmlEngine*         m_pRoot;
    QTranslator*        m_tran;
};

#endif // CLANGUUAGE_H
