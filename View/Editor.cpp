#include <QtGui>
#include <iostream>
#include "Editor.h"

int Editor::numUntitleDocuments = 0;

Editor::Editor(QWidget *parent )
        : QTextEdit(parent){

    numUntitleDocuments++;

    action = new QAction(this);
    action->setCheckable(true);
    
    isUntitle = true;
    curFile = tr("Untitle Document %1").arg(numUntitleDocuments);
    document()->setModified(false);
    
    connect(document(), SIGNAL(contentsChanged()), this, 
                        SLOT(documentWasModified()));

    setDocumentTitle(curFile);
    setAttribute(Qt::WA_DeleteOnClose);
}

Editor::~Editor() {
    emit copyAvailable (false);
    emit undoAvailable (false);
    emit redoAvailable (false);
    if (numUntitleDocuments > 0)
        numUntitleDocuments--;
}

void Editor::documentWasModified(){
    document()->setModified (true);
    setWindowTitle (strippedFileName (curFile) + "[*]" );
    setWindowModified (true);
    emit textChanged();
} 

bool Editor::openFile(){
    if(Ok_ToContinue()){
        QString fileName = QFileDialog::getOpenFileName(this, 
                                                tr("Choose File to open"), ".",
                                                       tr("Txt Files (*.txt)\n"
                                                         "All (*)"));
    if(fileName.isEmpty())
        return false;

    loadFile(fileName);
    }
    return true;
}

bool Editor::Ok_ToContinue (){
    if (document()->isModified() ){
        int r = QMessageBox::warning(this, tr("Save Changes?"),
                            tr("The document has been modified. \n"
                            "Do you want to save your changes?"),
                            QMessageBox::Yes | QMessageBox::Default,
                            QMessageBox::No,
                            QMessageBox::Cancel | QMessageBox::Escape);
        if (r == QMessageBox::No)
            return true;
        else if (r == QMessageBox::Yes)
            saveFile();
            else
                return false;
    } else
        return true;
}

bool Editor::loadFile (QString &fileName){
    QFile file (fileName);

    if (!file.open (QFile::ReadOnly | QFile::Text) ) {
        QMessageBox::warning (this, tr("Application"), 
                              tr("Cannot write file %1: \n %2.") 
                               .arg(fileName)
                               .arg(file.errorString() ) );
        return false;
    }

    QTextStream in (&file);

    QApplication::setOverrideCursor(Qt::WaitCursor);
    setPlainText (in.readAll() );
    QApplication::restoreOverrideCursor();

    setCurrentFile (fileName);
    return true;
} 

void Editor::setCurrentFile (const QString& fileName) {
    curFile = fileName;
    isUntitle = false;
    numUntitleDocuments--;

    document()->setModified (false);
    setWindowTitle (tr ("%1 ").arg(strippedFileName (curFile)) );
    setWindowModified (false);
    emit textChanged();
}

bool Editor::saveFile () {
   if (isUntitle == true) 
       return saveAs();
    else
        return save(curFile);
}

bool Editor::saveAs () {
    QString fileName = QFileDialog::getSaveFileName (this, tr("Save Document"),
                                     ".", tr("Text files (*.txt)" ) );
    if (fileName.isEmpty() )
        return false;

    return save (fileName);
}

QString Editor::strippedFileName (const QString& completeFileName) {
    return QFileInfo (completeFileName).fileName();
}

bool Editor::writeFile (const QString& fileName) {
    QFile file(fileName);
    
    if (!file.open (QFile::WriteOnly | QFile::Text) ) {
        QMessageBox::warning (this, tr("Application"), 
                              tr("Cannot write file %1: \n %2.") 
                               .arg(fileName)
                               .arg(file.errorString() ) );
        return false;
    } 

    QTextStream out (&file);
    QApplication::setOverrideCursor (Qt::WaitCursor);
    out << toPlainText ();
    QApplication::restoreOverrideCursor();
    return true;
} 

bool Editor::save (const QString& fileName) {
    if (!writeFile (fileName) )
        return false; //an error happened

    setCurrentFile (fileName);
    return true;
} 
