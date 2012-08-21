#include <QPainter>
struct MyVis : public QWidget
{
	protected:
		void paintEvent( QPaintEvent* )
		{
			QPen pen;
			QColor color;
			QPainter painter(this);

			color.setRgb( 0.4 * 255, 0.2 * 255, 0.5 * 255 );
			pen.setColor( color );
			painter.setPen(pen);
			painter.drawLine
			(
				0,
				mn * height() / 2,
				width(),
				mn * height() / 2
			);

			color.setRgb( 0.4 * 255, 0.7 * 255, 0.4 * 255 );
			pen.setColor( color );
			painter.setPen(pen);
			for ( int s = 0 ; s < len/2-1 ; s++ )
				painter.drawLine
				(
					+( s / ( len / 2. ) )          * width( ),
					-( filterFunc[s] - 2. ) / 2.   * height() - 0.49,
					+( ( s + 1 ) / ( len / 2. ) )  * width( ),
					-( filterFunc[s+1] - 2. ) / 2. * height() - 0.49
				);
		}
};
MyVis Vis;

#include "formSetup.cpp"

FormSetup::FormSetup(QWidget * parent):QWidget(parent)
{
	ui.setupUi(this);
	connect( ui.swB, SIGNAL( clicked() ), this, SLOT( swB() ) );
	connect( ui.clrB, SIGNAL( clicked() ), this, SLOT( clrB() ) );
	connect( ui.dwnB, SIGNAL( clicked() ), this, SLOT( dwnB() ) );
	connect( ui.upB, SIGNAL( clicked() ), this, SLOT( upB() ) );
	connect( ui.enabledB, SIGNAL( clicked() ), this, SLOT( enabledB() ) );
	connect( ui.sl0, SIGNAL( valueChanged(int) ), this, SLOT( sl0() ) );
	connect( ui.sl1, SIGNAL( valueChanged(int) ), this, SLOT( sl1() ) );
	connect( ui.sl2, SIGNAL( valueChanged(int) ), this, SLOT( sl2() ) );
	connect( ui.sl3, SIGNAL( valueChanged(int) ), this, SLOT( sl3() ) );
	connect( ui.sl4, SIGNAL( valueChanged(int) ), this, SLOT( sl4() ) );
	connect( ui.sl5, SIGNAL( valueChanged(int) ), this, SLOT( sl5() ) );
	connect( ui.sl6, SIGNAL( valueChanged(int) ), this, SLOT( sl6() ) );
	connect( ui.sl7, SIGNAL( valueChanged(int) ), this, SLOT( sl7() ) );
	connect( ui.sl8, SIGNAL( valueChanged(int) ), this, SLOT( sl8() ) );
	connect( &timEq, SIGNAL( timeout() ), this, SLOT( _timEq() ) );
	connect( ui.glW, SIGNAL( clicked() ), this, SLOT( _glW() ) );
}
