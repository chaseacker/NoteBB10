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
		Application(argc, argv) {

	QmlDocument *qml = QmlDocument::create("asset:///main.qml");
	qml->setContextProperty("app", this);
	NavigationPane *nav = qml->createRootObject<NavigationPane>();
	QVariantList x;

	ListView *noteList = nav->findChild<ListView*>("noteList");
	QString mJsonAssetsPath = "app/native/assets/Notes.json";
	JsonDataAccess jda;
	QStringList pathSplit = mJsonAssetsPath.split("/");
	QString fileName = pathSplit.last();
	QString dataFolder = QDir::homePath();

	// The path to the file in the data folder
	mJsonDataPath = dataFolder + "/" + fileName;
	QFile file(mJsonDataPath);
	QVariantList mainList;
	mainList = jda.load(mJsonDataPath).value<QVariantList>();
	x = mainList;
	//GroupDataModel *noteModel;
	noteModel = new GroupDataModel(QStringList() << "title");
	noteModel->insertList(mainList);
	qml->setContextProperty("noteModel", noteModel);
	noteList->setDataModel(noteModel);
	qDebug("DEBUG Works");
	// Create the application scene.
	Application::instance()->setScene(nav);

}

void Note::addNoteItem(const QString itemTitle) {
	QVariantMap itemMap;
	itemMap["title"] = QVariant(itemTitle);
	x = jda.load(mJsonDataPath).value<QVariantList>();
	x.append(itemMap);
	noteModel->clear();
	noteModel->insertList(x);
	saveData();
}
void Note::editNoteItem(const QVariant item, const QString newItemTitle){
	x = jda.load(mJsonDataPath).value<QVariantList>();
	QVariantMap itemMap = item.toMap();
	int itemDataIndex = x.indexOf(itemMap);
	QVariantList itemIndex = noteModel->find(itemMap);
	itemMap["title"] = newItemTitle;
	x.replace(itemDataIndex, itemMap);
	noteModel->updateItem(itemIndex, itemMap);
	saveData();
}
bool Note::saveData() {
	JsonDataAccess jda;
	jda.save(x, mJsonDataPath);

	if (jda.hasError()) {
		bb::data::DataAccessError error = jda.error();
		qDebug() << "JSON loading error: " << error.errorType() << ": "
				<< error.errorMessage();
		return false;
	}

	return true;
}
void Note::deleteNoteItem(const QVariantList &indexPath) {
	QVariant modelItem = noteModel->data(indexPath);
	x = jda.load(mJsonDataPath).value<QVariantList>();
	int itemDataIndex = x.indexOf(modelItem);
	x.removeAt(itemDataIndex);
	noteModel->removeAt(indexPath);
	saveData();

}
Note::~Note() {

}

