// Navigation pane project template
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
using namespace bb::cascades;
using namespace bb::data;



//void save(QString x){
	/*
	//QmlDocument *qml = QmlDocument::create("main.qml");
	QVariantMap title;
	title["title"] = x;
	QVariant myData = QVariant(QVariantList() << QVariant(title));
	QDir home = QDir::home();
	QTemporaryFile file(home.absoluteFilePath("myJSONFile.json"));
	if (file.open()) {
	    jda.save(myData, &list); // check
	}
*/
//}


Q_DECL_EXPORT int main(int argc, char **argv)
{
    // this is where the server is started etc
    Note app(argc, argv);
    // localization support
    QTranslator translator;
    QString locale_string = QLocale().name();
    QString filename = QString( "Notes_%1" ).arg( locale_string );
    if (translator.load(filename, "app/native/qm")) {
        app.installTranslator( &translator );
    }


    return Application::exec();
    // when loop is exited the Application deletes the scene which deletes all its children (per qt rules for children)
}
