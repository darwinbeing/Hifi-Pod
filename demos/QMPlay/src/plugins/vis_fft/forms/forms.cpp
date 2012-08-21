#include "FormVis.cpp"
#include "formSetup.cpp"

FormSetup::FormSetup(QWidget *parent):QWidget(parent)
{
	ui.setupUi(this);
	connect( ui.ApplyB, SIGNAL( clicked() ), this, SLOT( ApplyB() ) );
}

MyVis::MyVis(QWidget *parent):QGLWidget(parent)
{
	connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(popupMenu()));
	setContextMenuPolicy( Qt::CustomContextMenu );
	setObjectName(plugName);
	setMouseTracking(true);

	fsAct = new QAction( "Pełny ekran", this );
	fsAct->setShortcut( QKeySequence( Qt::Key_F ) );
	fsAct->setCheckable(true);
	connect(fsAct, SIGNAL(triggered()), this, SLOT(fKey()));

	connect( this, SIGNAL( startTimerSignal( int ) ), this, SLOT( startTimerSlot( int ) ) );
}
MyVis::~MyVis()
{
	disconnect(fsAct, SIGNAL(triggered()), this, SLOT(fKey()));
	delete fsAct;
	disconnect( this, SIGNAL( startTimerSignal( int ) ), this, SLOT( startTimerSlot( int ) ) );
	disconnect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(popupMenu()));
}
