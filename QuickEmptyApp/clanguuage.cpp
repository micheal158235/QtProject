#include "clanguuage.h"

CLanguuage::CLanguuage(QObject *parent) :
    QObject(parent)
  ,m_pRoot(NULL)
{
    m_tran = new QTranslator();
    m_pRoot->rootContext()->setContextProperty("myLanguage", this); //将C++对象作为属性注册到QML
}

CLanguuage::CLanguuage(QQmlEngine* engine, QObject *parent) :
    QObject(parent)
  ,m_pRoot(engine)
{
    this->setProperty("strTag", "qianxiao");
    m_tran = new QTranslator();
    m_pRoot->rootContext()->setContextProperty("myLanguage", this); //将C++对象作为属性注册到QML
}

CLanguuage::~CLanguuage()
{
    if(NULL != m_tran)
    {
        delete m_tran;
        m_tran = NULL;
    }
}

void CLanguuage::requestChangedLanguage(LANGUAGE_TYPE type)
{
    qDebug()<<" [zhaohui] void CLanguuage::requestChangedLanguage() type = "<<type;
    QString strPath;
    switch(type)
    {
    case CLanguuage::LANGUAGE_CH:
        strPath = "language_ch.qm";
        break;
    case CLanguuage::LANGUAGE_EN:
        strPath = "language_en.qm";
        break;
    default:
        strPath = "language_en.qm";
        break;
    }

    if(NULL != m_tran)
    {
        bool ret = false;
        qDebug()<<" void CLanguuage::requestChangedLanguage() strPath = "<<strPath;
        ret = m_tran->load(strPath);

        qDebug()<<" void CLanguuage::requestChangedLanguage() A ret = "<<ret;
        ret = false;
        ret = QCoreApplication::installTranslator(m_tran);
        emit strTagChanged();
        qDebug()<<" void CLanguuage::requestChangedLanguage() B ret = "<<ret;
    }
}

QString CLanguuage::getStrTag(void)
{
    return "";
}
