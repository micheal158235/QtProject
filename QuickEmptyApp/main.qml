import QtQuick 2.9
import QtQuick.Window 2.2

//import QtQuick 2.3
//import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import Test.Com 1.0

//Window {
//    visible: true
//    width: 640
//    height: 480
//    title: qsTr("Hello World")
//}

Window {
    visible: true
    width: 660
    height: 360
  Button
  {
     id:chineseBtn
     width:330
     height:30
     text:qsTrId("CON_TXT002")+myLanguage.strTag
     onClicked:
     {
        myLanguage.requestChangedLanguage(ZH.LANGUAGE_CN)//qml中访问C++方法
        console.log(" zh chinese button clicked")
     }
  }

  Button
  {
      id:englishBtn
      x:330
      width:330
      height:30
      text:qsTrId("CON_TXT003")+myLanguage.strTag
      onClicked:
      {
          myLanguage.requestChangedLanguage(ZH.LANGUAGE_EN)//qml中访问C++枚举
          console.log(" zh english button clicked.")
      }
  }


  Text {
      font.pixelSize: 24
      text: qsTrId("CON_TXT001")+myLanguage.strTag//qml中访问C++属性
      color: "#6e16e0"
      anchors.centerIn: parent
  }

  Image{

  }
}
