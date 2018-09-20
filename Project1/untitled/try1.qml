import QtQuick 2.0

 Rectangle{
     id:simplebutton
     color:"grey"
     width: 150; height: 75

     Text {
         id: buttonlable
         anchors.centerIn: parent
         text: qsTr("button lalable")
     }
     MouseArea{
         id:buttonMouseArea
         anchors.fill: parent
         onClicked: console.log(buttonlable.text + "clicked")
     }
}
