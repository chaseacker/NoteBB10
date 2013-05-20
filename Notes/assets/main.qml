// Navigation pane project template

import bb.cascades 1.0
import bb.data 1.0

NavigationPane {
    id: navigationPane
    Page {
        id: root
        Container {
            background: Color.create(CCCCCC)
           // ImageView {
            //    imageSource: "asset:///upper-bar_v1.png"
            //}

            ListView {
                id: myList
                objectName: "noteList"
                contextActions: [
                    ActionSet {
                        DeleteActionItem {
                            title: "Delete"
                            onTriggered: {
                                app.deleteNoteItem(myList.selected());
                            }
                        }
                    }
                ]
                onTriggered: {
                    var selectedItem = dataModel.data(indexPath);
                    var page = notePage.createObject();
                    page.item = selectedItem;
                    navigationPane.push(page);
                }
                
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
                

                // Add appearance definitions for the list items using the
                // listItemComponents list
                listItemComponents: [
                    
                    ListItemComponent {
                        
                        StandardListItem {
        
                        }
                    }
                    
                ]

                

            } // end of ListView
            layout: StackLayout {
            }
            attachedObjects: [
                EditPage {
                    // A sheet is used to add new items to the list, which is the same sheet used to edit items
                    id: addNew

                    onSaveNoteItem: {
                        app.addNoteItem(text);
                    }
                },
                ComponentDefinition {
                    // A Component definition of the Page used to display more details on the Bucket item.
                    id: notePage
                    source: "notePage.qml"
                }
            ]
            onCreationCompleted: {
                //dataSource.load();
            }
        }

        actions: [
            ActionItem {

                // An ActionItem for adding more items to the list
                title: "Add"
                imageSource: "asset:///images/icon_068.png"
                ActionBar.placement: ActionBarPlacement.OnBar
                onTriggered: {
                    addNew.open()
                    addNew.text = "";
                }
                property Page secondPage
                function getSecondPage() {
                    if (! secondPage) {
                        secondPage = secondPageDefinition.createObject();
                    }
                    return secondPage;
                }
                attachedObjects: [
                    ComponentDefinition {
                        id: secondPageDefinition
                        source: "DetailsPage.qml"
                    }
                ]

            }
        ]
    }

    onCreationCompleted: {
        // this slot is called when declarative scene is created
        // write post creation initialization here
        console.log("NavigationPane - onCreationCompleted()");

        // enable layout to adapt to the device rotation
        // don't forget to enable screen rotation in bar-bescriptor.xml (Application->Orientation->Auto-orient)
        OrientationSupport.supportedDisplayOrientation = SupportedDisplayOrientation.All;
    }
}
