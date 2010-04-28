#include <QtGui>
#include "Editor.h"

int Editor::numDocuments = 0;

Editor::Editor(QWidget *parent )
        : QTextEdit(parent){
    action = new QAction(this); 
    action->setCheckable(true);
    isUntitle = true;
    CurFile = tr("Untitle Document ");
    document()->setModified(false);
//    connect(document(), SIGNAL(ContentsChanged()), this, SLOT(documentWasModified()));
    connect(action, SIGNAL(textChanged()), this, SLOT(documentWasModified()));
//    (qobject_cast<QMainWindow *>(parent()))->setWindowTitle(CurFile + "[*]");
    action->setText(CurFile);
    setAttribute(Qt::WA_DeleteOnClose);
    
}
void Editor::documentWasModified(){
    document()->setModified(true);
}
bool Editor::openFile(){
    if(Ok_ToContinue()){
        QString fileName = QFileDialog::getOpenFileName(this, tr("Choose File to open"), ".",
                                                       tr("Txt Files (*.txt)\n"
                                                         "All (*)"));
    if(fileName.isEmpty())
        return false;
    
    loadFile(fileName);
    }
    return true;
}

bool Editor::Ok_ToContinue(){
    if(document()->isModified()){
        int r = QMessageBox::warning(this, tr("Save Changes?"),
                            tr("The document has been modified. \n"
                            "Do you want to save your changes?"),
                            QMessageBox::Yes | QMessageBox::Default,
                            QMessageBox::No,
                            QMessageBox::Cancel | QMessageBox::Escape);
        if(r == QMessageBox::Yes || r == QMessageBox::No)
            return true;
        else  
            return false;
    }else
        return true;
}
bool Editor::loadFile(QString &fileName){
    return true;   
}
