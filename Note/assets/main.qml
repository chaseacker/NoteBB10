// Tabbed Pane project template
import bb.cascades 1.0

TabbedPane {
    showTabsOnActionBar: true
    Tab {
        title: qsTr("Tab 1")
        Page {
            id: tab1
            actions: [
                // define the actions for first tab here
                ActionItem {
                    title: qsTr("Rotate")
                    onTriggered: {
                        imgTab1.rotationZ = imgTab1.rotationZ + 90;
                    }
                },
                ActionItem {
                    title: qsTr("Break")
                    onTriggered: {
                        imgTab1.imageSource = "asset:///images/picture1br.png";
                    }
                }
            ]
            Container {
                Header {
                	title: "Notes"
                }

                // define tab content here
                ListView {
                    dataModel: XmlDataModel {
                        source: "model.xml";
                    }
                    StandardListItem:{
                        title: "RAWRAWRAWR";
                        status: "Im a dinosaur";
                    }
                    listItemComponents: [
                        ListItemComponent {
                            type: "header"

                            Label {
                                text: ListItemData.title;
                            }
                        }

                        ListItemComponent {
                            type: "item";

                            Container {
                                layout: StackLayout {
                                    orientation: Orientation.LeftToRight
                                }
                                ImageView {
                                    imageSource: ListItemData.image
                                }
                                Label {
                                    text: ListItemData.title
                                }
                            }
                        }
                    ]
                }

            }
        }
    }
    
    onCreationCompleted: {
        // this slot is called when declarative scene is created
        // write post creation initialization here
        console.log("TabbedPane - onCreationCompleted()")

        // enable layout to adapt to the device rotation
        // don't forget to enable screen rotation in bar-bescriptor.xml (Application->Orientation->Auto-orient)
        OrientationSupport.supportedDisplayOrientation = SupportedDisplayOrientation.All;
    }
}
