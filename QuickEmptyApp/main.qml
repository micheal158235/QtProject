import QtQuick 2.9
import QtQuick.Window 2.2
import QtLocation 5.6
import QtPositioning 5.6

import QtQuick.Controls 1.2
import Test.Com 1.0

Window {
    visible: true
    width: 660
    height: 360
    title: qsTr("Hello OpenStreetMap")
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

    Plugin {
        id: mapPlugin
        name: "osm" // "here"--诺基亚, "mapboxgl", "esri", ...
//        //specify plugin parameters if necessary
//        PluginParameter { name: "osm.useragent"; value: "My great Qt OSM application" }
//        PluginParameter { name: "osm.mapping.host"; value: "http://osm.tile.server.address/" }
//        PluginParameter { name: "osm.mapping.copyright"; value: "All mine" }
//        PluginParameter { name: "osm.routing.host"; value: "http://osrm.server.address/viaroute" }
//        PluginParameter { name: "osm.geocoding.host"; value: "http://geocoding.server.address" }
        PluginParameter { name: "osm.useragent"; value: "My great Qt OSM application" }
        PluginParameter { name: "osm.mapping.host"; value: "http://osm.tile.server.address/" }
        PluginParameter { name: "osm.mapping.copyright"; value: "All mine" }
        PluginParameter { name: "osm.routing.host"; value: "http://osrm.server.address/viaroute" }
        PluginParameter { name: "osm.geocoding.host"; value: "https://nominatim.openstreetmap.org/" }
    }

    Map {
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(59.91, 10.75) // Oslo
        zoomLevel: 14
    }
}
