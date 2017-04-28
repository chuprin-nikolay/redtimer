#include "MainWindow.h"

#include <QApplication>
#include <QCommandLineParser>

using namespace redtimer;
using namespace std;

int main(int argc, char* argv[])
{
    QApplication app( argc, argv );
    app.setApplicationName( "RedTimer" );

    app.setQuitOnLastWindowClosed( false );

    // Command line options
    QCommandLineParser parser;
    parser.setApplicationDescription( "Redmine Time Tracker" );
    parser.addHelpOption();
    parser.addVersionOption();

    parser.addOption( {{"p", "profile"}, "Load settings for <profile> (default: \"Default\")",
                       "profile", "Default"} );

    // Process command line options
    parser.process( app );

    app.setWindowIcon( QIcon(":/icons/clock_red.svg") );

    new MainWindow( &app, parser.value("profile") );

    return app.exec();
}
