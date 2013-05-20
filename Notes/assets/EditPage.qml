import bb.cascades 1.0

Sheet {
    id: editSheet

    // Custom properties
    property alias title: addBar.title
    property alias hintText: itemText.hintText
    property alias text: itemText.text

    // A custom signal is triggered when the acceptAction is triggered.
    signal saveNoteItem(string text)
    Page {
        id: addPage
        titleBar: TitleBar {
            id: addBar
            title: "Add"
            visibility: ChromeVisibility.Visible
            
            dismissAction: ActionItem {
                imageSource: "asset:///images/delete.png"
                onTriggered: {
                    // Hide the Sheet.
                    editSheet.close()
                }
            }

            acceptAction: ActionItem {
                imageSource: "asset:///images/stickynote.png"
                onTriggered: {
                    editSheet.close();
                    editSheet.saveNoteItem(itemText.text);
                }
            }
        }
        Container {
            id: editPane
            property real margins: 50
            background: Color.create("#045FB4")
            //topPadding: editPane.margins
            //leftPadding: editPane.margins
            //rightPadding: editPane.margins

            layout: DockLayout {
            }

            attachedObjects: [
                
                TextStyleDefinition {
                    id: editTextStyle
                    base: SystemDefaults.TextStyles.TitleText
                }
            ]
            Container {
                TextArea {
                    id: itemText
                    hintText: "Note!"
                    //topMargin: editPane.margins
                    //bottomMargin: topMargin
                    preferredHeight: 623
                    //maxHeight: 1000
                    horizontalAlignment: HorizontalAlignment.Fill

                    textStyle {
                        base: editTextStyle.style
                    }
                }
            } // Text Area Container
        } // Edit pane Container
    } // Page
}// Sheet
