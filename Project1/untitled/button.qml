import QtQuick 2.0

Rectangle {
    id:button
    Text {
        id: buttonLable
        anchors.centerIn: parent
        text: qsTr("button Lalable")
    }
    property color buttonColor: "lightblue"
    property color buttonColor: "gold"
    property color buttonColor: "white"

    signal buttonClick()
    onButtonClick: {
        console.log(buttonLable.text + "clicked")
    }
    MouseArea{
        onClicked: buttonClick()
        hoverEnabled: true
        onEntered: parent.border.coclor = onHoverColor
        onExited: parent.border.color = borderColor
    }
    color:button.MouseArea.pressed ? Qt.darker(buttonColor,1.5):buttonColor
}
