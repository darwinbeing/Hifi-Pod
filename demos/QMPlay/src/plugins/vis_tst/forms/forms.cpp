#include "FormVis.cpp"
#include "formSetup.cpp"

FormSetup::FormSetup(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect( ui.ApplyB, SIGNAL( clicked() ), this, SLOT( ApplyB() ) );
}

MyVis::MyVis(QWidget *parent) : QWidget(parent)
{
	connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(popupMenu()));
	setContextMenuPolicy( Qt::CustomContextMenu );
	setObjectName(plugName);
	setMouseTracking(true);

	fsAct = new QAction( "Pełny ekran", this );
	fsAct->setShortcut( QKeySequence( Qt::Key_F ) );
	fsAct->setCheckable(true);
	connect(fsAct, SIGNAL(triggered()), this, SLOT(fKey()));

	setPalette( Qt::black );
	setWindowTitle("Prosta wizualizacja");

	linearGrad.setColorAt( 0.0, Qt::blue );
	linearGrad.setColorAt( 0.1, Qt::green );
	linearGrad.setColorAt( 0.5, Qt::yellow );
	linearGrad.setColorAt( 0.8, Qt::red );

	connect( this, SIGNAL( startTimerSignal( int ) ), this, SLOT( startTimerSlot( int ) ) );
}
