/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

import QtQuick 2.1

Item {
    id: rangeMover
    anchors.fill: parent
    signal rangeDoubleClicked()

    property color handleColor: "#fe869cd1"
    property color rangeColor:"#444a64b8"
    property color dragColor:"#664a64b8"
    property color borderColor:"#cc4a64b8"
    property color dragMarkerColor: "#fe4a64b8"
    property color singleLineColor: "#fe4a64b8"

    property alias rangeLeft: leftRange.x
    property alias rangeRight: rightRange.x
    readonly property alias rangeWidth: selectedRange.width

    Rectangle {
        id: selectedRange

        x: leftRange.x
        width: rightRange.x - leftRange.x
        height: parent.height

        color: width > 1 ? (dragArea.pressed ? dragColor : rangeColor) : singleLineColor
    }

    Rectangle {
        id: leftRange

        onXChanged: {
            if (dragArea.drag.active)
                rightRange.x = x + dragArea.origWidth;
        }

        x: 0
        height: parent.height
        width: 1
        color: borderColor

        Rectangle {
            id: leftBorderHandle
            height: parent.height
            anchors.right: parent.left
            width: 7
            color: handleColor
            visible: false
            Image {
                source: "range_handle.png"
                x: 2
                width: 4
                height: 9
                fillMode: Image.Tile
                y: parent.height / 2 - 4
            }
        }

        states: State {
            name: "highlighted"
            PropertyChanges {
                target: leftBorderHandle
                visible: true
            }
        }

        MouseArea {
            anchors.fill: leftBorderHandle

            drag.target: leftRange
            drag.axis: "XAxis"
            drag.minimumX: 0
            drag.maximumX: rangeMover.width
            drag.onActiveChanged: drag.maximumX = rightRange.x

            hoverEnabled: true

            onEntered: {
                parent.state = "highlighted";
            }
            onExited: {
                if (!pressed) parent.state = "";
            }
            onReleased: {
                if (!containsMouse) parent.state = "";
            }
        }
    }

    Rectangle {
        id: rightRange

        x: 1
        height: parent.height
        width: 1
        color: borderColor

        Rectangle {
            id: rightBorderHandle
            height: parent.height
            anchors.left: parent.right
            width: 7
            color: handleColor
            visible: false
            Image {
                source: "range_handle.png"
                x: 2
                width: 4
                height: 9
                fillMode: Image.Tile
                y: parent.height / 2 - 4
            }
        }

        states: State {
            name: "highlighted"
            PropertyChanges {
                target: rightBorderHandle
                visible: true
            }
        }

        MouseArea {
            anchors.fill: rightBorderHandle

            drag.target: rightRange
            drag.axis: "XAxis"
            drag.minimumX: 0
            drag.maximumX: rangeMover.width
            drag.onActiveChanged: drag.minimumX = leftRange.x

            hoverEnabled: true

            onEntered: {
                parent.state = "highlighted";
            }
            onExited: {
                if (!pressed) parent.state = "";
            }
            onReleased: {
                if (!containsMouse) parent.state = "";
            }
        }
    }

    MouseArea {
        id: dragArea
        property double origWidth: 0

        anchors.fill: selectedRange
        drag.target: leftRange
        drag.axis: "XAxis"
        drag.minimumX: 0
        drag.maximumX: rangeMover.width - origWidth
        drag.onActiveChanged: origWidth = selectedRange.width
        onDoubleClicked: parent.rangeDoubleClicked()
    }
}
