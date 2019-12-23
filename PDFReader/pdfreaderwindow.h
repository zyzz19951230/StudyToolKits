#ifndef PDFREADERWINDOW_H
#define PDFREADERWINDOW_H

#include <QMainWindow>
#include <QToolButton>

QT_BEGIN_NAMESPACE
namespace Ui { class PDFReaderWindow; }
QT_END_NAMESPACE

class PDFReaderWindow : public QMainWindow
{
    Q_OBJECT

public:
    PDFReaderWindow(QWidget *parent = nullptr);
    ~PDFReaderWindow();

private:
    void createWidgets();
    void setupActions();
    void setupWidgets();

    Ui::PDFReaderWindow *ui;
    QTabWidget *pdfTabView;
    QWidget *pdfOutlineView;
    QDockWidget *pdfOutlineDock;
    QWidget *pdfThumbnailView;
    QDockWidget *pdfThumbnailDock;
    QWidget *pdfBookmarkView;
    QDockWidget *pdfBookmarkDock;
    QDockWidget *pdfAttachmentDock;
    QWidget *pdfAttachmentView;

    QAction *actionPdfOutlineViewToggle;
    QAction *actionPdfBookmarkViewToggle;
    QAction *actionPdfThumbnailViewToggle;
    QAction *actionPdfAttachmentViewToggle;
    QAction *actionSideToolBarToggle;
    QAction *actionMainToolBarToggle;


private slots:
    void onPdfTabAboutToClose(int index);
    void onPdfTabChanged(int index);
};
#endif // PDFREADERWINDOW_H
