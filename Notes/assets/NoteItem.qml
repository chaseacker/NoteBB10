import bb.cascades 1.0

StandardListItem{
    id: noteItem
    title: ListItemData.title
    imageSpaceReserved: false
    contextActions: [
        ActionSet {  
            DeleteActionItem {
                title: "Delete"
                onTriggered: {
                    app.deleteNoteItem(indexPath);
                }
            }

        }
    ]

}