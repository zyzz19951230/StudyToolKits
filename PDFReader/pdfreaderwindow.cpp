#include "pdfreaderwindow.h"
#include "ui_pdfreaderwindow.h"
#include "constants.h"
#include "qfonticon.h"


#include <QDockWidget>

PDFReaderWindow::PDFReaderWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PDFReaderWindow)
{
    ui->setupUi(this);
    createWidgets();
    setupActions();
    setupWidgets();
}

PDFReaderWindow::~PDFReaderWindow()
{
    delete ui;
}

void PDFReaderWindow::createWidgets()
{
    pdfTabView = new QTabWidget(this);
    pdfOutlineDock = new QDockWidget(this);
    pdfThumbnailDock = new QDockWidget(this);
    pdfBookmarkDock = new QDockWidget(this);
    pdfAttachmentDock = new QDockWidget(this);

}

void PDFReaderWindow::setupActions()
{
    actionPdfOutlineViewToggle = pdfOutlineDock->toggleViewAction();
    actionPdfBookmarkViewToggle = pdfBookmarkDock->toggleViewAction();
    actionPdfThumbnailViewToggle = pdfThumbnailDock->toggleViewAction();
    actionPdfAttachmentViewToggle = pdfAttachmentDock->toggleViewAction();
    actionMainToolBarToggle = ui->mainToolBar->toggleViewAction();
    actionSideToolBarToggle = ui->sideToolBar->toggleViewAction();

    actionPdfOutlineViewToggle->setIcon(QFontIcon::icon(IconMap::Outlines));
    actionPdfBookmarkViewToggle->setIcon(QFontIcon::icon(IconMap::Bookmarks));
    actionPdfThumbnailViewToggle->setIcon(QFontIcon::icon(IconMap::Thumbnails));
    actionPdfAttachmentViewToggle->setIcon(QFontIcon::icon(IconMap::Attachments));
}

void PDFReaderWindow::setupWidgets()
{
    // setup pdf tab widget
    pdfTabView->setDocumentMode(true);
    pdfTabView->setTabsClosable(true);
    pdfTabView->setMovable(true);
    setCentralWidget(pdfTabView);
    connect(pdfTabView, &QTabWidget::tabCloseRequested, this, &PDFReaderWindow::onPdfTabAboutToClose);
    connect(pdfTabView, &QTabWidget::currentChanged, this, &PDFReaderWindow::onPdfTabChanged);

    // setup docks
    pdfOutlineDock->setWindowTitle(tr("Outlines"));
    pdfOutlineDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    pdfThumbnailDock->setWindowTitle(tr("Thumbnails"));
    pdfThumbnailDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    pdfBookmarkDock->setWindowTitle(tr("Bookmarks"));
    pdfBookmarkDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    pdfAttachmentDock->setWindowTitle(tr("Attachments"));
    pdfAttachmentDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget(Qt::LeftDockWidgetArea, pdfOutlineDock);
    addDockWidget(Qt::LeftDockWidgetArea, pdfThumbnailDock);
    addDockWidget(Qt::LeftDockWidgetArea, pdfBookmarkDock);
    addDockWidget(Qt::LeftDockWidgetArea, pdfAttachmentDock);
    tabifyDockWidget(pdfOutlineDock, pdfThumbnailDock);
    tabifyDockWidget(pdfOutlineDock, pdfBookmarkDock);
    tabifyDockWidget(pdfOutlineDock, pdfAttachmentDock);
    resizeDocks({pdfOutlineDock}, {width() / 3}, Qt::Horizontal);

    // setup tool bar
    ui->sideToolBar->addAction(actionPdfOutlineViewToggle);
    ui->sideToolBar->addAction(actionPdfBookmarkViewToggle);
    ui->sideToolBar->addAction(actionPdfThumbnailViewToggle);
    ui->sideToolBar->addAction(actionPdfAttachmentViewToggle);

    // setup menu bar
    ui->menuView->addAction(actionPdfOutlineViewToggle);
    ui->menuView->addAction(actionPdfBookmarkViewToggle);
    ui->menuView->addAction(actionPdfThumbnailViewToggle);
    ui->menuView->addAction(actionPdfAttachmentViewToggle);
    ui->menuView->addSeparator();
    ui->menuView->addAction(actionMainToolBarToggle);
    ui->menuView->addAction(actionSideToolBarToggle);
}

void PDFReaderWindow::onPdfTabAboutToClose(int index)
{
    if(index < 0)
        return;
    pdfTabView->removeTab(index);

}

void PDFReaderWindow::onPdfTabChanged(int index)
{
    if(index < 0)
    {
        // no pdf opened
        return;
    }
}
