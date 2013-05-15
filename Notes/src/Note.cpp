#include "Note.h"
#include "applicationui.hpp"
#include <bb/cascades/Application>
#include <bb/data/JsonDataAccess>
#include <QString>
#include <QtCore/QObject>
#include <bb/cascades/GroupDataModel>
#include <bb/cascades/QListDataModel>
#include <bb/cascades/ListView>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/ListView>
#include <bb/cascades/ActivityIndicator>
#include <bb/system/InvokeManager>
#include <bb/system/InvokeRequest>
#include <bb/system/InvokeTargetReply>
#include <bb/cascades/Page>
#include <bb/cascades/TextField>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/NavigationPane>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/data/DataSource>
#include <bb/system/SystemDialog>
#include <bb/data/DataSource>

using namespace bb::cascades;
using namespace bb::data;
using namespace bb::system;

Note::Note(int argc, char **argv) :
          Application(argc, argv)
{

	QmlDocument *qml = QmlDocument::create("asset:///main.qml");
	        qml->setContextProperty("app", qml);
	        NavigationPane *nav = qml->createRootObject<NavigationPane>();

	        	    // Get the ListView from QML and setup a DataModel from the JSON data.
	        	    // Connect to the stampList triggered signal to the onListTriggered Slot function.
	    ListView *noteList = nav->findChild<ListView*>("noteList");
	        	    JsonDataAccess jda;

	        	   QVariantList mainList = jda.load("app/native/assets/Notes.json").value<QVariantList>();

	        	    GroupDataModel *noteModel = new GroupDataModel(QStringList() << "title");
	        	    noteModel->insertList(mainList);

	        	    noteList->setDataModel(noteModel);

	        	    qDebug("DEBUG Works");
	        	    // Create the application scene.
	        	    Application::instance()->setScene(nav);


}

void Note::addNoteItem(const QString itemTitle)
{
	qDebug("myAction() addNOte is called...");
    QVariantMap itemMap;
    itemMap["title"] = QVariant(itemTitle);
        // Add the new item to the data list.
        mainList.insert(0, itemMap);
        saveData();




}
bool Note::saveData()
{
	//JsonDataAccess jda;
	//QVariantList mainList = jda.load("app/native/assets/Notes.json").value<QVariantList>();
	qDebug("myAction() Save is called...");
    jda.save(mainList, "app/native/assets/Notes.json");

    if (jda.hasError()) {
        bb::data::DataAccessError error = jda.error();
        qDebug() << "JSON loading error: " << error.errorType() << ": " << error.errorMessage();
        return false;
    }

    return true;
}
Note::~Note()
{

}

